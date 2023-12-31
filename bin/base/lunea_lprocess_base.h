#pragma once
#include <lunea_debug.h>

#include <vector>
#include <map>
#include <setjmp.h>

using namespace std;

class LPROCESS;

class LPROCESS_BASE {
protected:
	map<const char*,int>  __action_list;
	vector<jmp_buf*> __jump_data;
	vector<bool>     __jump_control;
	int              __jump_active;
	int              __jump_current;

	void __init();
	void __deinit();

	LPROCESS *father, *son, *bigbro, *smallbro;

	void __addAction(const char *name, int id);

public:
	int __getIdActionByName(const char *name);

	enum Status { run, kill, sleep, freeze };

	int      x;
	int      y;

	int      z;
	int      priority;

	Status   status;

	int      _z;
	int      _priority;

	int      action;

	void __process();

	virtual void draw() = 0;
	virtual void execute() = 0;
};