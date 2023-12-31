#pragma once

#include <lunea_debug.h>

#include <iostream>
#include <stdio.h>
#include <setjmp.h>
#include <lunea_lprocess_base.h>
#include <lunea_lprocess_list.h>

// EXTERN
//#include <lunea_bitmap.h>
//#include <lunea_music.h>

// RESOURCES

int GetResourceIDFromName(const char *file) {
	LUNEA_DEBUG std::cout << "MSTEP 1\n";
	for (int n = 0; n < __resources_count; n++) {
		LUNEA_DEBUG std::cout << "MSTEP 3[" << n << ", " << __resources_count << "]\n";
		if (strcmp(__resources_files[n], file) == 0) return __resources_ids[n];
	}
	LUNEA_DEBUG std::cout << "MSTEP 4\n";

	return 0;
}

#include <windows.h>

#pragma warning( disable : 4312 )

int create_file_from_resource(const char *resname, char *fname) {
	long length;
	FILE *fd;
	void *ptr = (void *)GetDataResourceFromName(resname, length);

	if (length == 0) return -1;

	tmpnam(fname);
	int ln = strlen(fname);

	char *ext = strrchr(resname, '.');
	int ln2 = strlen(ext) + 1;

	for (int n = 0; n < ln2; n++) fname[ln + n] = ext[n];

	if ((fd = fopen(fname, "wb")) == 0) return -1;
	fwrite(ptr, 1, length, fd);
	fclose(fd);

	return 0;
}

void delete_file_created_from_resource(char *fname) {
	remove(fname);
}

const char *GetDataResourceEx(const char *resn, int id, long &hResLength) {
	HMODULE hModule;
	HRSRC   hResInfo;
	HGLOBAL hResData;
	void*   hResPtr;

	hResLength = 0;

	LUNEA_DEBUG std::cout << "ASTEP 1\n";
	if ((hModule    = GetModuleHandle(NULL)) == 0) return 0;
	LUNEA_DEBUG std::cout << "ASTEP 2\n";
	if ((hResInfo   = FindResourceEx(hModule, (LPCSTR)resn, (LPCSTR)id, 0)) == 0) return 0;
	LUNEA_DEBUG std::cout << "ASTEP 3\n";
	if ((hResLength = SizeofResource(hModule, hResInfo)) == 0) return 0;
	LUNEA_DEBUG std::cout << "ASTEP 4\n";
	if ((hResData   = LoadResource(hModule, hResInfo)) == 0) return 0;
	LUNEA_DEBUG std::cout << "ASTEP 5\n";
	if ((hResPtr    = LockResource(hResData)) == 0) return 0;
	LUNEA_DEBUG std::cout << "ASTEP 6\n";

	return (const char *)hResPtr;
}

const char *GetDataResource(int id, long &hResLength) {
	return GetDataResourceEx("VOID*", id, hResLength);
}

const char *GetDataResourceFromName(const char *file, long &hResLength) {
	LUNEA_DEBUG std::cout << "CSTEP 1\n";
	return GetDataResource(GetResourceIDFromName(file), hResLength);
}

// /RESOURCES


void __none() {
	std::cout << "";
}

#define FRAME\
	{\
		LUNEA_DEBUG std::cout << "FRAME [1]\n";\
		this->__jump_control[this->__jump_current] = true; \
		LUNEA_DEBUG std::cout << "FRAME [2]\n";\
		this->__jump_active = setjmp(*this->__jump_data[this->__jump_current]);\
		LUNEA_DEBUG std::cout << "FRAME [3]\n";\
		if (this->__jump_active == 0) return;\
		LUNEA_DEBUG std::cout << "FRAME [4]\n";\
		__none();\
	}

#define execute_init(id)\
	LUNEA_DEBUG std::cout << "execute_init [1]\n";\
	this->__jump_current = id;\
	if (this->status != Status::run) return; else if (this->__jump_control[id]) longjmp(*this->__jump_data[id], 1);\
	LUNEA_DEBUG std::cout << "execute_init [2]\n";

#define execute_end\
	LUNEA_DEBUG std::cout << "execute_end [1]\n";\
	this->status = Status::kill;\
	LUNEA_DEBUG std::cout << "execute_end [2]\n";\
	return;

#define DRAW_BEGIN(init)\
	void init::draw() {

#define DRAW_END\
	}

#define ACTION_BEGIN(init, id)\
	void init::execute_##id() { execute_init(id);

#define ACTION_END\
	execute_end; }

#define ACTION_JUMP(aname)\
	this->action = __getIdActionByName(aname);\
	FRAME;

#define ACTION_JUMP_OBJECT(object, aname)\
	object->action = object->__getIdActionByName(aname);

#define PROCESS_PROTOTYPE_BEGIN(init)\
	class init : public LPROCESS { public:\
		~init();\
		init();\
		virtual void execute();\
		virtual void draw();

#define PROCESS_PROTOTYPE_BEGIN_PARAMS(init, params)\
	class init : public LPROCESS { public:\
		~init();\
		init(params);\
		virtual void execute();\
		virtual void draw();

#define PROCESS_PROTOTYPE_END\
	}

#define ACTION_PROTOTYPE(id)\
		virtual void execute_##id();

#define PROCESS_DEFINE_BEGIN(init, actioncount)\
	init::~init() { this->LPROCESS::__deinit(); }\
	init::init()  {\
		LUNEA_DEBUG std::cout << "LPROCESS::init() [1]\n";\
		this->LPROCESS::__init();\
		LUNEA_DEBUG std::cout << "LPROCESS::init() [2]\n";\
		for (int n = 0; n < actioncount; n++) {\
			this->__jump_control.push_back(false);\
			this->__jump_data.push_back((jmp_buf *)malloc(sizeof(jmp_buf)));\
		}\
		LUNEA_DEBUG std::cout << "LPROCESS::init() [3]\n";

#define PROCESS_DEFINE_BEGIN_PARAMS(init, actioncount, params)\
	init::~init() { this->LPROCESS::__deinit(); }\
	init::init(params)  {\
		LUNEA_DEBUG std::cout << "LPROCESS::init() [1]\n";\
		this->LPROCESS::__init();\
		LUNEA_DEBUG std::cout << "LPROCESS::init() [2]\n";\
		for (int n = 0; n < actioncount; n++) {\
			this->__jump_control.push_back(false);\
			this->__jump_data.push_back((jmp_buf *)malloc(sizeof(jmp_buf)));\
		}\
		LUNEA_DEBUG std::cout << "LPROCESS::init() [3]\n";

#define PROCESS_DEFINE_END\
		this->action = __getIdActionByName("main"); \
	}

#define PROCESS_END };

#define ACTION_LIST_BEGIN(init)\
	void init::execute() {

#define ACTION_LIST_END\
	}

#define ACTION_LIST_ADD(id)\
		if (action == id) { execute_##id(); return; }

#define DEFINE_ACTION_ID(id, exeproc)\
	LUNEA_DEBUG std::cout << "DEFINE_ACTION_ID(id, " << exeproc << ")\n";\
	__addAction(exeproc, id);

/*
	ACTION_LIST_BEGIN;
	ACTION_LIST_ADD(0, main);
	ACTION_LIST_END;
*/

LPROCESS      *CURRENT_PROCESS   = 0;
LPROCESS_LIST *MAIN_PROCESS_LIST = 0;
LPROCESS_LIST *TEMP_PROCESS_LIST = 0;


// EXTERN

#include <lunea_header1.h>