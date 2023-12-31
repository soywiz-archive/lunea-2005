#pragma once
#include <lunea_debug.h>

#include <vector>
#include <lunea_lprocess.h>

using namespace std;

class LPROCESS_LIST {
private:
	vector<LPROCESS*> listZ;
	vector<LPROCESS*> listPriority;

public:
	void insert(LPROCESS* p);
	void insert(LPROCESS_LIST* pl);
	void moveTo(LPROCESS_LIST* pl);
	void clear();
	void updateZ(LPROCESS* p);
	void updatePriority(LPROCESS* p);
	int  length();
	void execute();
	void draw();
};

extern LPROCESS_LIST *MAIN_PROCESS_LIST;
extern LPROCESS_LIST *TEMP_PROCESS_LIST;