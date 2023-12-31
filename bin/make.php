<?php
	require_once(dirname(__FILE__) . '/compile.php');

	echo "Lunea - Lunea Compiler Version 0.1.1 for windows\n";
	echo "Copyright (C) Carlos Ballesteros Velasco 2005. All rights reserved.\n";
	echo "\n";

	$get_error = false;

	$params = $argv;
	array_shift($params);

	//$project = $params[0];

	// PATH al proyecto que se desea compilar

	$__sl = -1;
	if (isset($params[0]) && strlen($params[0]) && ($__sl = sizeof(get_file_list($params[0], array('lun'))))) {
		$project = $params[0];
	} else {
		if ($__sl == 0) {
			die("Error : el directorio no contiene ficheros *.lun (compruebe que el directorio es correcto)\n");
		} else {
			echo "usage: lunea directory...\n";
			echo "\n";
			die("Error : no se especificó el directorio del proyecto: ej. lunea \"..\\myproject\"\n");
		}
	}

	$current_driver = 'none';

	// PATHS
	$lunea_path           = dirname(__FILE__);
	$cpp_path             = $lunea_path . "\\bin\\cpp";
	$cpp_bin_path         = $cpp_path . "\\bin";
	$cpp_include_path     = $cpp_path . "\\include_s";
	$cpp_include_path2    = $cpp_path . "\\include";
	$cpp_lib_path         = $cpp_path . "\\lib_s";
	$cpp_lib_path2        = $cpp_path . "\\lib";
	$cl_path              = $cpp_bin_path . "\\cl.exe";
	$rc_path              = $cpp_bin_path . "\\rc.exe";
	$link_path            = $cpp_bin_path . "\\link.exe";
	$base_path            = $lunea_path . "\\base";
	$driver_path          = $lunea_path . "\\drivers";

	// PROJECT NAME
	$project = str_replace('\\', '/', trim($project));
	if (substr($project, -1, 1) == '/' ) $project = substr($project, 0, -1);

	$project_name = substr($project, strlen(dirname($project)) + 1);
	$exe_file = $project_name . '.exe';

	// OBTIENE LOS ICONOS
	$icons = get_file_list($project, array('ico'));
	$icon = sizeof($icons) ? $icons[0] : NULL;

	echo "Proyecto: {$project}...";
	$list = get_file_list($project, array('lun'));
	echo ' (' . sizeof($list) . ') ';
	echo " [Ok]\n";
	foreach ($list as $file) {
		echo "    - " . substr($file, strlen($project) + 1) . "\n";
	}
	echo "\n";


	// LUN -> CPP (COMPILING)
	echo "Convirtiendo código a C++...";
	$cpp_code = makeCppFromLuneaSources($list);

	echo " [Ok]\n";

	echo "Configuración:\n";

	$resourceList = array();

	$versionComments    = 'Comments';
	$versionCompany     = 'Company';
	$versionDesc        = 'Description';
	$versionVersion     = '0, 0, 0, 1';
	$versionIName       = 'InternalName';
	$versionCopyright   = 'Copyright';
	$versionTrademarks  = 'Trademarks';
	$versionPName       = 'ProductName';
	$versionPVersion    = '0, 0, 0, 1';

	foreach ($configList as $kl) {
		list($name, $value) = $kl;
		$name = strtolower(trim($name));
		$value = stripslashes(substr($value, 1, -1));

		echo "    {$name}: {$value}\n";

		switch ($name) {
			case 'output':          $exe_file          = $value; break;
			case 'driver':          $current_driver    = $value; break;
			case 'icon':            $icon              = $project . '\\' . $value; break;
			case 'comments':        $versionComments   = $value; break;
			case 'companyname':     $versionCompany    = $value; break;
			case 'filedescription': $versionDesc       = $value; break;
			case 'fileversion':     $versionVersion    = $value; break;
			case 'internalname':    $versionIName      = $value; break;
			case 'legalcopyright':  $versionCopyright  = $value; break;
			case 'legaltrademarks': $versionTrademarks = $value; break;
			case 'productname':     $versionPName      = $value; break;
			case 'productversion':  $versionPVersion   = $value; break;
			case 'resource':        $resourceList[]    = $value; break;
		}
	}

	echo "\n";

	$resourceListT = array();
	foreach ($resourceList as $rres) {
		$res = $project . '\\' . $rres;
		//echo "$res\n";
		$data = glob($res);
		if (is_array($data)) {
			foreach ($data as $file) {
				$cfile = substr($file, strlen($project) + 1);
				$resourceListT[] = $cfile;
				//echo "$cfile\n";
			}
		} else {
			echo "(notice : no hay ficheros '" . $rres . "')\n";
		}
	}
	$resourceList = $resourceListT;

	// INFORMACIÓN PARA LA COMPILACIÓN

	$cdriver_path         = $driver_path . "\\" . $current_driver;
	$cdriver_lib_path     = $cdriver_path . "\\lib";
	$cdriver_include_path = $cdriver_path . "\\include";

	$params_c  = ' /nologo /c';
	$params_c .= ' -I"' . $cpp_include_path     . '"';
	$params_c .= ' -I"' . $cpp_include_path2    . '"';
	$params_c .= ' -I"' . $base_path            . '"';
	$params_c .= ' -I"' . $cdriver_path         . '"';
	$params_c .= ' -I"' . $cdriver_include_path . '"';
	$params_c .= ' /Fd"./temp/"';

	if (file_exists($cdriver_path . '/version.txt')) {
		$cdriver_version = strtolower(trim(file_get_contents($cdriver_path . '/version.txt')));
		if ($cdriver_version != 'lunea1') {
			die("Error versión del driver desconocida o anticuada (" . $cdriver_version . ")");
		}
	} else {
		die("Error versión del driver desconocida");
	}

	if (file_exists($cdriver_path . '/compile.txt')) {
		$params_c .= ' ' . file_get_contents($cdriver_path . '/compile.txt');
	} else {
		$params_c .= ' /D "WIN32" /D "NDEBUG" /D "_CONSOLE"';
		$params_c .= ' /MD /O1 /Op /GL /GA /FD /EHsc /MD /GS /W3 /Wp64 /TP';
	}

	$params_l  = ' /NOLOGO /PDB:"./temp/"';
	$params_l .= ' /LIBPATH:"' . $cpp_lib_path     . '"';
	$params_l .= ' /LIBPATH:"' . $cpp_lib_path2    . '"';
	$params_l .= ' /LIBPATH:"' . $cdriver_lib_path . '"';
	if (file_exists($cdriver_path . '/compile.txt')) {
		$params_l .= ' ' . file_get_contents($cdriver_path . '/link.txt');
	} else {
		$params_l .= ' /INCREMENTAL:NO';
		//$params_l .= ' /SUBSYSTEM:WINDOWS /MACHINE:X86';
		$params_l .= ' /SUBSYSTEM:CONSOLE /MACHINE:X86';
		$params_l .= ' MSVCRT.LIB';
	}


	// RESOURCES
	echo "Compilando recursos (" . sizeof($resourceList) . ") {\n";
	foreach ($resourceList as $file) {
		echo "    {$file}\n";
	}
	echo '}';
	$rc = make_rc_file(
		$icon,
		$resourceList
	);
	echo " [Ok]\n";

	echo "\n";

	// GENERANDO LISTA DE RECURSOS

	if (sizeof($resource_ids) == 0) {
		$resource_ids = array(0 => '');
	}

	$code_resources1  = '';
	$code_resources2  = '';

	$code_resources1 .= "int __resources_count = " . (int)sizeof($resource_ids) . ";\n\n";
	$code_resources1 .= "char *__resources_files[] = {\n";
	$code_resources2 .= "int __resources_ids[] = {\n";
	foreach ($resource_ids as $k => $v) {
		$code_resources1 .= "\t\"" . addslashes($v) . "\",\n";
		$code_resources2 .= "\t{$k},\n";
	}
	$code_resources1 .= "};\n\n";
	$code_resources2 .= "};\n\n";
	//$resource_ids =

	$cpp_code = $code_resources1 . $code_resources2 . "\n\n" . $cpp_code;

	file_put_contents('temp/compile.cpp', $cpp_code);

	//exit;

	// APPLICATION
	compile_exec($cl_path . ' /Fo"./temp/compile.obj"' . $params_c . ' "temp/compile.cpp" /O');

	// APPLICATION_ERROR
	if ($get_error) die("Compilación parada por error\n");

	file_put_contents('temp/compile.rc', $rc);
	compile_exec($rc_path . ' /fo"' . $lunea_path . '\\temp\\compile.res" /i"' . $cpp_include_path . '" "' . $lunea_path . '\\temp\\compile.rc"');

	$tolink = array();
	// KERNEL
	foreach (get_file_list(array($base_path, $cdriver_path), array('c', 'cpp')) as $cfile) {
		compile_exec($cl_path . ' /Fo"./temp/"' . $params_c . ' "' . $cfile . '"');

		$crfile = basename($cfile);

		$tolink[] = '"temp/' . substr($crfile, 0, strrpos($crfile, '.')) . '.obj"';
	}

	// LINKING
	echo "Enlazando ({$exe_file})...";
	compile_exec(
		$link_path . $params_l .
		' "temp/compile.obj" "temp/compile.res" '
		. implode(' ', $tolink)
		//'"temp/lunea_bitmap.obj" "temp/lunea_lprocess.obj" "temp/lunea_lprocess_base.obj" "temp/lunea_lprocess_list.obj" "temp/lunea_string.obj"'
		. ' /OUT:"' . $project . '/' . $exe_file . '"',
		true
	);
	echo " [Ok]\n";

	exit;

	function compile_exec($exec, $hide_warnings = false) {
		global $get_error;

		//echo "\n$exec\n\n";
		$d = popen($exec, 'r');
		while ($line = fgets($d)) {
			$line = trim($line);
			if ($hide_warnings && strpos(strtolower($line), ': warning') !== false) continue;
			if (strpos(strtolower($line), ': fatal error') !== false) {
				$get_error = true;
				//throw(new Exception($line));
			}
			if (strpos(strtolower($line), ': error') !== false) {
				$get_error = true;
				//throw(new Exception($line));
			}
			echo $line . "\n";
		}
		pclose($d);
	}

	function get_file_list($path, $extensions = array()) {
		$retval = array();

		if (sizeof($extensions) == 0) return $retval;

		if (is_array($path)) {
			foreach ($path as $cpath) {
				foreach (get_file_list($cpath, $extensions) as $file) $retval[] = $file;
			}

			return $retval;
		}

		if ($dir = opendir($path)) {
			while ($file = readdir($dir)) {
				if ($file == '.' || $file == '..') continue;
				if (!is_file($path . '/' . $file)) continue;

				if (strpos($file, '.') === false) {
					$ext = '';
				} else {
					list(,$ext) = explode('.', $file, 2);
				}

				$found = false;
				foreach ($extensions as $cext) {
					if (strcasecmp($cext, $ext) == 0) { $found = true; break; }
				}

				if (!$found) continue;

				$retval[] = $path . "\\" . $file;
			}
			closedir($dir);
		}

		return $retval;
	}

	function make_rc_file($icon = '', $resources = array()) {
		global $versionComments;
		global $versionCompany;
		global $versionDesc;
		global $versionVersion;
		global $versionIName;
		global $versionCopyright;
		global $versionTrademarks;
		global $versionPName;
		global $versionPVersion;
		global $exe_file;

		global $project;
		global $resource_ids;

		$resource_ids = array();

		$cres  = 100;

		$res  = '';

		if (!file_exists($icon)) {
			echo "(notice : el icono no existe)";
			$icon = false;
		}

		// ICONO
		$cres++;

		if ($icon) $res .= "#define IDI_ICON1                       " . $cres . "\n";
		foreach ($resources as $resource) {
			$cres++;
			$res .= "#define IDR_DATA" . $cres . "                       " . $cres . "\n";
		}

		$res .= "#define APSTUDIO_READONLY_SYMBOLS\n";
		$res .= "#include \"afxres.h\"\n";
		$res .= "#undef APSTUDIO_READONLY_SYMBOLS\n";

		$res .= "#if !defined(AFX_RESOURCE_DLL) || defined(AFX_TARG_ESN)\n";
		$res .= "#ifdef _WIN32\n";

		// LANGUAGE
		$res .= "LANGUAGE LANG_NEUTRAL, SUBLANG_NEUTRAL\n";

		$res .= "#pragma code_page(1252)\n";
		$res .= "#endif\n";

		$cres = 101;
		foreach ($resources as $resource) {
			$cres++;
			list($name, $ext) = explode('.', basename($resource), 2);
			$ext = strtolower(trim($ext));
			//if ($ext == 'ico') {
			//	$res .= "IDR_DATA" . $cres . "               ICON                    \"" . $resource . "\"\n";
			//} else {
			//	$res .= "IDR_DATA" . $cres . "                 void*                      \"" . $resource . "\"\n";
			//}
			$resource_ids[$cres] = $resource;
			$res .= "IDR_DATA" . $cres . "                 void*                      \"" . addslashes(str_replace("/", "\\", $project) . "\\" . $resource) . "\"\n";
		}


		$res .= "1 TEXTINCLUDE\n";
		$res .= "BEGIN\n";
		$res .= "    \"#include \"\"afxres.h\"\"\\r\\n\"\n";
		$res .= "    \"\\0\"\n";
		$res .= "END\n";

		$res .= "2 TEXTINCLUDE\n";
		$res .= "BEGIN\n";
		$res .= "    \"\\r\\n\"\n";
		$res .= "    \"\\0\"\n";
		$res .= "END\n";

		$res .= "#endif\n";

		// ICONO
		if ($icon) $res .= "IDI_ICON1               ICON                    \"" . addslashes($icon) . "\"\n";

		// VERSIONINFO
		$res .= "VS_VERSION_INFO VERSIONINFO\n";
		$res .= " FILEVERSION 1,0,0,1\n";
		$res .= " PRODUCTVERSION 1,0,0,1\n";
		$res .= " FILEFLAGSMASK 0x17L\n";
		$res .= "#ifdef _DEBUG\n";
		$res .= " FILEFLAGS 0x1L\n";
		$res .= "#else\n";
		$res .= " FILEFLAGS 0x0L\n";
		$res .= "#endif\n";
		$res .= " FILEOS 0x4L\n";
		$res .= " FILETYPE 0x0L\n";
		$res .= " FILESUBTYPE 0x0L\n";
		$res .= "BEGIN\n";
		$res .= "    BLOCK \"StringFileInfo\"\n";
		$res .= "    BEGIN\n";
		$res .= "        BLOCK \"0c0a04b0\"\n";
		$res .= "        BEGIN\n";
		$res .= "            VALUE \"Comments\", \""         . addslashes($versionComments) . "\"\n";
		$res .= "            VALUE \"CompanyName\", \""      . addslashes($versionCompany) . "\"\n";
		$res .= "            VALUE \"FileDescription\", \""  . addslashes($versionDesc) . "\"\n";
		$res .= "            VALUE \"FileVersion\", \""      . addslashes($versionVersion) . "\"\n";
		$res .= "            VALUE \"InternalName\", \""     . addslashes($versionIName) . "\"\n";
		$res .= "            VALUE \"LegalCopyright\", \"("  . addslashes($versionCopyright) . "\"\n";
		$res .= "            VALUE \"LegalTrademarks\", \""  . addslashes($versionTrademarks) . "\"\n";
		$res .= "            VALUE \"OriginalFilename\", \"" . addslashes($exe_file) . "\"\n";
		$res .= "            VALUE \"ProductName\", \""      . addslashes($versionPName) . "\"\n";
		$res .= "            VALUE \"ProductVersion\", \""   . addslashes($versionPVersion) . "\"\n";
		$res .= "        END\n";
		$res .= "    END\n";
		$res .= "    BLOCK \"VarFileInfo\"\n";
		$res .= "    BEGIN\n";
		$res .= "        VALUE \"Translation\", 0xc0a, 1200\n";
		$res .= "    END\n";
		$res .= "END\n";

		return $res;
	}
?>