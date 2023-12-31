<?php
	class LuneaParser {
		private $tokens;
		private $lines;
		private $pos;
		private $varnum;
		private $step;

		// Lunea
		public  $configList  = array();
		private $processList = array();
		private $pointerList = array();
		private $prototypes  = array();
		private $processes   = array();
		private $ccode       = array();

		private function __construct() {
		}

		static function loadFromString($data) {
			$lp = new LuneaParser();
			array_shift($rtokens = token_get_all('<?php ' . $data));

			$lp->tokens = array();
			$lp->lines  = array();
			$line = 1;

			foreach ($rtokens as $token) {
				$token = is_array($token) ? $token[1] : $token;
				if (($c = substr_count($token, "\n")) == 0) {
					$c = substr_count($token, "\r");
				}
				$line += $c;

				if (substr(trim($token), 0, 2) == '//') continue;
				if (substr(trim($token), 0, 2) == '/*') continue;

				if (strlen(trim($token))) {
					$lp->tokens[] = trim($token);
					$lp->lines[]  = $line;
				}
			}

			$lp->reset();

			return $lp;
		}

		function next() {
			$this->pos++;
			if ($this->pos >= sizeof($this->tokens) - 1) return false;
			$val = $this->tokens[$this->pos];
			return $val;
		}

		function prev() {
			$this->pos--;
			if ($this->pos == 0) return false;
			$val = $this->tokens[$this->pos];
			return $val;
		}

		function current() {
			if ($this->pos >= sizeof($this->tokens)) return false;
			return $this->tokens[$this->pos];
		}

		function currentLine() {
			if ($this->pos >= sizeof($this->tokens)) return $this->lines[sizeof($this->tokens) - 1] + 1;
			return $this->lines[$this->pos];
		}

		function reset() {
			$this->pos    = 0;
			$this->varnum = 0;
		}

		function makeError($id, $needed, $line) {
			throw(new Exception('Error E' . $id . ' en línea (' . $this->currentLine() . ') se esperaba (' . $needed . ') y se encontró: "' . $this->current() . '" lanzado por ' . __FILE__ . ' (' . $line . ')'));
		}

		function makeError2($id, $needed, $line) {
			throw(new Exception('Error E' . $id . ' en línea (' . $this->currentLine() . ') : [' . $needed . '] lanzado por ' . __FILE__ . ' (' . $line . ')'));
		}

		function makeCpp($externPointers = array()) {
			$this->pointerList = array();
			if (is_array($externPointers)) {
				foreach ($externPointers as $v) $this->pointerList[$v] = false;
			}

			$this->step = 0;
			$this->processLevel1();
			$this->reset();
			$this->step = 1;
			$this->prototypes = array();
			$this->ccode      = array();
			$this->processes  = array();
			$this->processLevel1();

			return array(
				implode("\n", $this->prototypes),
				implode("\n", $this->ccode),
				implode("\n", $this->processes)
			);

			/*
			$retval  = '';
			$retval .= implode("\n", $this->prototypes);
			$retval .= implode("\n", $this->ccode);
			$retval .= implode("\n", $this->processes);

			return $retval;
			*/
		}

		function processLevel1() {
			while (($token = $this->current()) !== false) {
				switch (strtolower($token)) {
					case 'config':
						if ($this->next() != '{') $this->makeError('C0002', '{', __LINE__);
						$this->next();
						$this->processLevel2C();
						if ($this->current() != '}') $this->makeError('C0003', '}', __LINE__);
					break;
					case 'process':
						$name = strtolower(trim($this->next()));
						if ($this->next() != '(') $this->makeError('C0006', '(', __LINE__);
						$cparam = array();
						$params = array();
						while (($token = $this->next()) != ')') {
							if ($token == ',') {
								$params[] = $cparam;
								$cparam   = array();
							} else {
								$cparam[] = $token;
							}
							// check in
						}

						if (sizeof($cparam)) { $params[] = $cparam; $cparam = array(); }

						if ($this->next() != '{') $this->makeError('C0002', '{', __LINE__);
						$this->next();
						$this->processLevel2L($name, $params);
						if ($this->current() != '}') $this->makeError('C0003', '}', __LINE__);
					break;
					case '__cpp':
						if ($this->next() != '{') $this->makeError('C0002', '{', __LINE__);
						$this->next();
						$code = $this->processLevel2RAW();
						if ($this->step == 1) {
							//print_r(implode('', $code));exit;
							$this->ccode[] = implode('', $code);
						}
						if ($this->current() != '}') $this->makeError('C0003', '}', __LINE__);
					break;
					default:
						$this->makeError('C0001', 'config/process/__cpp');
					break;
				}

				$this->next();
			}
		}

		function processLevel2C() {
			while (($token = $this->current()) !== false) {
				if ($token == '}') {
					break;
				} else {
					$name = $token;

					if ($this->next() != ':') $this->makeError('C0004', ':', __LINE__);

					$value = $this->next();

					if ($this->next() != ';') $this->makeError('C0005', ';', __LINE__);

					if ($this->step == 1) {
						$this->configList[] = array($name, $value);
					}
				}

				$this->next();
			}

			//print_r($this->configList);
		}

		function processLevel2RAW() {
			if ($this->step == 1) {
				$retval = array();
			} else {
				$retval = false;
			}

			$open_count = 1;
			$cline = $this->currentLine();
			while (($token = $this->current()) !== false) {
				if ($token == '{') {
					$open_count++;
				} else if ($token == '}') {
					$open_count--;
					if ($open_count <= 0) {
						break;
					}
				}

				if ($this->step == 1) {
					if ($cline != $this->currentLine()) $retval[] = "\n";

					switch (strtolower($token)) {
						case 'echo':    $token = 'std::cout <<'; break;
						default:
							if (isset($this->processList[strtolower($token)]) || isset($this->pointerList[$token])) {
								$token .= ' *';
							}
						break;
					}

					$retval[] = $token . ' ';
				}

				$cline = $this->currentLine();

				$this->next();
			}

			return $retval;
		}

		function getParams($params) {
			$retval = ' ';
			for ($n = 0; $n < sizeof($params); $n++) {
				foreach ($params[$n] as $par) {
					$retval .= $par . ' ';
				}
				if ($n < sizeof($params) - 1) $retval .= ', ';
			}

			return $retval;
		}

		function getParams2($params) {
			$retval = ' ';
			for ($n = 0; $n < sizeof($params); $n++) {
				for ($m = 0; $m < sizeof($params[$n]); $m++) {
					$par = $params[$n][$m];
					if ($m == sizeof($params[$n]) - 1) $retval .= '__pvar__';
					$retval .= $par . ' ';
				}
				if ($n < sizeof($params) - 1) $retval .= ', ';
			}

			return $retval;
		}

		function getPrototypes($code) {
			$retval = array();

			$open_count = 0; $out = true; $cout = true;
			for ($n = 0; $n < sizeof($code); $n++) {
				$token = $code[$n];

				if ($token == '=') {
					if ($out) {
						$cout = false;
						continue;
					}
				} else if ($token == ';') {
					$cout = true;
				} else if ($token == '{') {
					$open_count++;

					if ($out) {
						$retval[] = ';';
					}

					$out = false;
				} else if ($token == '}') {
					$open_count--;
					if ($open_count == 0) {
						$out = true;
						continue;
					}
				}

				if ($out && $cout) {
					$retval[] = $token;
				}
			}

			//print_r($retval);

			return $retval;
		}

		function getDefininitions($process, $code) {
			$retrel = array(
				array(),
				array()
			);
			$retval = array();

			$open_count = 0; $out = true;
			$set_value = false;
			for ($n = 0; $n < sizeof($code); $n++) {
				$token = $code[$n];

				if ($token == '=' && $open_count == 0) {
					$set_value = true;
					$temp = array_pop($retval);
					$retval = array();
					array_push($retval, $temp);
					//array_push($retval, $process . '::' . array_pop($retval));
				} else if ($token == '{') {
					$open_count++;

					if ($open_count == 1) {
						$close_brack = 0;
						for ($m = sizeof($retval) - 1; $m > 0; $m--) {
							$ctoken = $retval[$m];
							if ($ctoken == ')') {
								$close_brack++;
							} else if ($ctoken == '(') {
								$close_brack--;
								if ($close_brack == 0) {
									$retval[$m - 1] = $process . '::' . $retval[$m - 1];
									break;
								}
							}
						}
					}
				} else if ($token == '}') {
					$open_count--;
				}

				if ($out) {
					$retval[] = $token;
				}


				if ($open_count == 0) {
					if ($token == '}') {
						foreach ($retval as $k) $retrel[1][] = $k;
						$retval = array();
					} else if ($token == ';') {
						if ($set_value) {
							foreach ($retval as $k) $retrel[0][] = $k;
							$set_value = false;
						}
						$retval = array();
					}
				}

			}

			//print_r($retrel);

			return $retrel;
		}

		function processLevel2L($name, $params) {
			if ($this->step == 0) {
				if (isset($this->processList[$name])) {
					$this->makeError2('C0007', 'Ya existe el nombre del proceso ("' . $name . '")', __LINE__);
				}

				$this->processList[$name] = array();
				$this->processList[$name]['params'] = $params;
				$this->processList[$name]['actions'] = array();
			} else if ($this->step == 1) {
				$param_prototype = '';
				$this->translate = array(array());
				if (sizeof($params)) {
					//print_r($params);
					//$t1 = 0;
					foreach ($params as $k => $param) {
						$pname = array_pop($param);
						$type = implode(' ', $param);
						if (isset($this->processList[strtolower($type)]) || isset($this->pointerList[$type])) {
							$params[$k][sizeof($param) - 1] .= ' *';
							$type = $type . ' *';
						}

						//$params[$k][sizeof($param)] = $params[$k][sizeof($param)];

						//$t1++;
						//$this->translate[0][$pname] = '_rvar' . $t1;

						//echo "$type $pname\n";
					}
				}
				$this->varnum = 0;
				$actions = array();
				$actionNames = array();
				$draw_code = array();
				$inabody = array();
			}

			$cline = $this->currentLine();

			$open_count = 1;
			while (($token = $this->current()) !== false) {
				if ($token == '{') {
					$open_count++;
				} else if ($token == '}') {
					$open_count--;
					if ($open_count <= 0) break;
				}

				switch (strtolower($token)) {
					case 'action':
						$aname = strtolower(trim($this->next()));
						if ($this->next() != '{') $this->makeError('C0002', '{', __LINE__);
						$this->next();
						$code = $this->processLevel3A($name, $aname);

						if ($this->step == 1) {
							$actions[] = $code;
							$actionNames[] = $aname;
						}

						if ($this->current() != '}') $this->makeError('C0003', '}', __LINE__);
					break;
					case 'draw':
						if ($this->next() != '{') $this->makeError('C0002', '{', __LINE__);
						$this->next();
						$code = $this->processLevel3D($name);
						if ($this->step == 1) {
							$draw_code = $code;
						}
						if ($this->current() != '}') $this->makeError('C0003', '}', __LINE__);
					break;
					case 'frame':
						$this->makeError2('C0010', 'No se puede usar la estructura de control "frame" fuera de los métodos "action"', __LINE__);
					break;
					default:
						if ($this->step == 1) {
							if ($cline != $this->currentLine()) $inabody[] = "\n";
							if (isset($this->processList[strtolower($token)]) || isset($this->pointerList[$token])) {
								$token .= ' *';
							}

							switch (strtolower($token)) {
								case 'echo': $token = 'std::cout <<'; break;
							}

							//echo "INABODY: $token\n";

							$inabody[] = $token;
						}
					break;
				}

				$cline = $this->currentLine();

				$this->next();
			}

			if ($this->step == 1) {
				// PROTOTITPO

				$cproto  = '';
				if (sizeof($params)) {
					//$cproto .= "PROCESS_PROTOTYPE_BEGIN_PARAMS({$name}, (" . $this->getParams2($params) . "));\n";
$cproto .="
class {$name} : public LPROCESS { public:
	~{$name}();
	{$name}(" . $this->getParams2($params) . ");
	virtual void execute();
	virtual void draw();

";
				} else {
					$cproto .= "PROCESS_PROTOTYPE_BEGIN({$name});\n";
				}

				$cproto .= implode(' ', $this->getPrototypes($inabody)) . "\n";
				//echo implode(' ', $this->getPrototypes($inabody));

				$cproto2 = '';
				$cproto3 = '';
				if (is_array($actions) && sizeof($actions)) {
					$pn = 0;
					foreach ($actions as $action) {
						if (isset($action['defs']) && sizeof($action['defs'])) {
							//print_r($action['defs']);
							foreach ($action['defs'] as $def) {
								$cproto3 .= "\t";
								foreach ($def[0] as $c) $cproto3 .= $c . ' ';
								$cproto3 .= $def[1];
								foreach ($def[2] as $c) $cproto3 .= ' ' . $c;
								$cproto3 .= ";\n";
							}
							$cproto3 .= "\n";
						}

						$cproto2 .= "\tACTION_PROTOTYPE({$pn});\n";
						$pn++;
					}
				}

				foreach ($params as $param) {
					switch ($param[sizeof($param) - 1]) {
						case 'father': case 'son': case 'bigbro': case 'smallbro':
						case 'x': case 'y': case 'z': case 'priority': case 'status':
						case 'action':
							continue 2;
						break;
					}
					$cproto3 .= "\t";
					foreach ($param as $k) $cproto3 .= $k . ' ';
					$cproto3 .= ";\n";
				}
				$cproto3 .= "\n";

				$cproto .= $cproto3 . $cproto2;

				$cproto .= "PROCESS_PROTOTYPE_END;\n\n";

				//echo $cproto;

				$this->prototypes[] = $cproto;

				// PROCESOS

				$cprocess = '';

				// $cproto .= "PROCESS_PROTOTYPE_BEGIN_PARAMS({$name}, (" . $this->getParams($params) . "))\n";

				if (sizeof($params)) {
					//die($name);
					//$cprocess .= "PROCESS_DEFINE_BEGIN_PARAMS({$name}, {$pn}, (" . $this->getParams2($params) . "));\n";
$cprocess .= "
	{$name}::~{$name}() { this->LPROCESS::__deinit(); }
	{$name}::{$name}(" .  $this->getParams2($params). ")  {
		LUNEA_DEBUG std::cout << \"LPROCESS::init() [1]\\n\";
		this->LPROCESS::__init();
		LUNEA_DEBUG std::cout << \"LPROCESS::init() [2]\\n\";
		for (int n = 0; n < {$pn}; n++) {
			this->__jump_control.push_back(false);
			this->__jump_data.push_back((jmp_buf *)malloc(sizeof(jmp_buf)));
		}
		LUNEA_DEBUG std::cout << \"LPROCESS::init() [3]\\n\";
";
				} else {
					$cprocess .= "PROCESS_DEFINE_BEGIN({$name}, {$pn});\n";
				}

				for ($n = 0; $n < sizeof($actionNames); $n++) {
					$cprocess .= "\tDEFINE_ACTION_ID({$n}, \"" . $actionNames[$n] . "\");\n";
				}

				list($set_variables, $methods) = $this->getDefininitions($name, $inabody);

				// __pvar__

				foreach ($params as $param) {
					$mmname = $param[sizeof($param) - 1];
					$cprocess .= "\t{$mmname} = __pvar__{$mmname};\n";
				}

				$cprocess .= implode(' ', $set_variables) . "\n";

				$cprocess .= "\n";

				$cprocess .= "PROCESS_DEFINE_END;\n";

				$cprocess .= implode(' ', $methods) . "\n";

				$cprocess .= "\n";

				$cprocess .= "ACTION_LIST_BEGIN(" . $name . ");\n";

				for ($n = 0; $n < sizeof($actionNames); $n++) {
					$cprocess .= "\tACTION_LIST_ADD({$n});\n";
				}

				$cprocess .= "ACTION_LIST_END;\n";

				$cprocess .= "\n";

				for ($n = 0; $n < sizeof($actionNames); $n++) {
					$cprocess .= "\tACTION_BEGIN(" . $name . ", {$n});\n";
					$cprocess .= implode('', $actions[$n]['code']) . "\n";
					$cprocess .= "\tACTION_END;\n\n";
				}

				$cprocess .= "\tDRAW_BEGIN({$name});\n";
				$cprocess .= implode('', $draw_code) . "\n";
				$cprocess .= "DRAW_END;\n\n";

				$this->processes[] = $cprocess;
			}
		}

		function processLevel3A($pname, $name) {
			if ($this->step == 1) {
				$return = array(
					'defs' => array(),
					'code' => array()
				);

				$defs = &$return['defs'];
				$code = &$return['code'];
			} else {
				$return = false;
			}

			if ($this->step == 0) {
				if (in_array($name, $this->processList[$pname]['actions'])) {
					$this->makeError2('C0008', 'Ya existe el nombre de la acción ("' . $name . '") en el proceso (' . $pname . ')', __LINE__);
				}

				$this->processList[$pname]['actions'][] = $name;
			}

			$open_count = 1;
			$type = false;
			$ltype = 0;
			$typec = array();
			$typem = array();
			$typen = '';
			$cline = $this->currentLine();
			$btoken = '';
			$casting = false;
			while (($token = $this->current()) !== false) {
				if ($token == '{') {
					if ($this->step == 1) array_unshift($this->translate, array());
					$open_count++;
				} else if ($token == '}') {
					if ($this->step == 1) array_shift($this->translate);
					$open_count--;
					if ($open_count <= 0) break;
				}

				if ($this->step == 1) {
					if ($cline != $this->currentLine()) {
						$code[] = "\n";
					}

					if ($token == 'new') $type = -2;

					if ($type == 1) {
						while (($token = $this->current()) == '*') {
							$typec[] = $token;
							$this->next();
						}
						$typen = $token;

						if ($casting) {
							//echo "ST: " . $this->prev() . ", $token\n"; $this->next();
							if ($token != ')') $casting = false;
						}

						//$this->prev();

						if ($casting) {
							//print_r($typec);
							//$code[] = 'ÑÑ';
							$code[] = implode(' ', $typec) . ' ';
						} else {
							while (($ct = $this->next()) == '[') {
								$typem[] = $ct;
								while (($ct = $this->next()) != ']') $typem[] = $ct;
								$typem[] = $ct;
							}

							$this->varnum++;

							$this->translate[0][$typen] = '_var' . $this->varnum;
							$typen = $this->translate[0][$typen];


							$defs[] = array($typec, $typen, $typem);

							if ($this->current() != ';') {
								$code[] = $typen . ' ';
							} else {
								$this->next();
							}

							$type = false;
							continue;
						}
					}

					if ($type >= 0) {
						if (!$type) {
							if (sizeof($typec) || sizeof($typem)) {
								$typec = array();
								$typem = array();
								$typen = '';
							}
						}

						if ($token == ')') {
							$casting = false;
						}

						$type = false;
						switch (strtolower($token)) {
							case 'const':
							case 'unsigned':
								$type = 2;
								$typec[] = $token;
								$this->next();
								continue 2;
							case 'int': case 'char': case 'float': case 'double': case 'void':
								if ($btoken == '(') $casting = true;
								$typec[] = $token;
								$type = 1;
							break;
							default:
								if (isset($this->processList[strtolower($token)]) || isset($this->pointerList[$token])) {
									if ($btoken == '(') $casting = true;
									$typec[] = $token;
									$typec[] = '*';
									$type = 1;
								}
							break;
						}

						if ($type) {
							$this->next();
							continue;
						}
					} else {
						$type++;
					}

					for ($nx = 0; $nx < sizeof($this->translate); $nx++) {
						if (isset($this->translate[$nx][$token])) {
							/*
							echo "CHECK FOR: $token\n";
							for ($ny = 0; $ny < sizeof($this->translate); $ny++) {
								print_r($this->translate[$ny]);
							}
							echo "\n\n";
							*/
							$token = $this->translate[$nx][$token];
							break;
						}
					}

					switch (strtolower($token)) {
						case 'jaction':  $token = 'ACTION_JUMP';  break;
						case 'joaction': $token = 'ACTION_JUMP_OBJECT';  break;
						case 'frame':    $token = 'FRAME';        break;
						case 'return':   $token = 'execute_end';  break;
						case 'echo':     $token = 'std::cout <<'; break;
						case '.':        $token = '->';           break;
						case '->':       $token = '.';            break;
					}

					$code[] = $token . ' ';

					//echo "L3A: {$token}\n";
				}

				$cline = $this->currentLine();
				$btoken = $token;
				$this->next();
			}

			return $return;
		}

		function processLevel3D($pname) {
			if ($this->step == 1) {
				$retval = array();
			} else {
				$retval = false;
			}

			if ($this->step) {
				if (isset($this->processList[$pname]['draw'])) {
					$this->makeError2('C0009', 'Ya existe "draw" en el proceso (' . $pname . ')', __LINE__);
				}

				$this->processList[$pname]['draw'] = 'done';
			}

			$open_count = 1;
			while (($token = $this->current()) !== false) {
				if ($token == '{') {
					$open_count++;
				} else if ($token == '}') {
					$open_count--;
					if ($open_count <= 0) {
						break;
					}
				}

				if ($token == 'frame') {
					$this->makeError2('C0010', 'No se puede usar la estructura de control frame en el método draw', __LINE__);
				}

				if ($this->step == 1) {
					switch (strtolower($token)) {
						case 'echo':    $token = 'std::cout <<'; break;
						case '.':       $token = '->';           break;
						case '->':      $token = '.';            break;
						default:
							if (isset($this->processList[strtolower($token)]) || isset($this->pointerList[$token])) {
								$token .= ' *';
							}
						break;
					}

					$retval[] = $token . ' ';
				}

				$this->next();
			}

			return $retval;
		}
	}

	/*
	function makeCppFromLuneaSources($source, $raw = false) {
		if (is_array($source)) {
			$data = array('', '', '');
			foreach ($source as $src) {
				list($l1, $l2, $l3) = makeCppFromLuneaSources($source, $raw);
				$data[0] .= $l1;
				$data[1] .= $l2;
				$data[2] .= $l3;
			}
		} else {
			$data = file_get_contents($source);
			$parser = LuneaParser::loadFromString($data);
			$data = $parser->makeCpp();
		}

		return $raw ? $data : implode("\n", $data);
	}
	*/

	function normalizeDir($dir) {
		$dir = str_replace("\\", '/', $dir);
		$path = array();
		foreach (explode('/', $dir) as $k) {
			if ($k == '.') continue;
			else if ($k == '..') array_pop($path);
			else $path[] = $k;
		}
		return implode('/', $path);
	}

	function makeCppFromLuneaSources($source, $raw = false) {
		if (is_array($source)) {
			$processed = array();
			//$data = array('', '', '');
			$code = '';
			foreach ($source as $src) {
				$real_file = strtolower(trim(normalizeDir(dirname(dirname(__FILE__) . "/" . $src)) . '/' . basename($src)));
				if (in_array($real_file, $processed)) continue;
				$processed[] = $real_file;

				$code .= file_get_contents($src) . "\n";
			}
		} else {
			$code = file_get_contents($source);
		}

		$parser = LuneaParser::loadFromString($code);
		$data = $parser->makeCpp(
			array('Bitmap', 'Music', 'Sound', 'Font')
		);

		global $configList;

		$configList = $parser->configList;

		return $raw ? $data : "#include <lunea_header1.h>\n#include <lunea_header.h>\n" . implode("\n", $data) . "#include <lunea_main.h>\n";
	}
?>