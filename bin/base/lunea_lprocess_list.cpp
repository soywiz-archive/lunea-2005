#include "lunea_lprocess_list.h"
#include <iostream>

void LPROCESS_LIST::insert(LPROCESS* p) {
	LUNEA_DEBUG std::cout << "LPROCESS_LIST::insert(LPROCESS* p)\n";
	this->listZ.push_back(p);
	this->listPriority.push_back(p);
	p->_z        = (int)this->listZ.size() - 1;
	p->_priority = (int)this->listPriority.size() - 1;
	updateZ(p);
	updatePriority(p);
	//std::cout << "insert";
}

void LPROCESS_LIST::insert(LPROCESS_LIST* pl) {
	LUNEA_DEBUG std::cout << "LPROCESS_LIST::insert(LPROCESS_LIST* pl)\n";
	int len = pl->length();
	//std::cout << "INSERT (" << len << ")\n";
	for (int n = 0; n < len; n++) this->insert(pl->listZ[n]);
}

void LPROCESS_LIST::moveTo(LPROCESS_LIST* pl) {
	LUNEA_DEBUG std::cout << "LPROCESS_LIST::moveTo(LPROCESS_LIST* pl)\n";
	pl->insert(this);
	clear();
}

void LPROCESS_LIST::clear() {
	LUNEA_DEBUG std::cout << "LPROCESS_LIST::clear()\n";
	listZ.clear();
	listPriority.clear();
}

void LPROCESS_LIST::updateZ(LPROCESS* p) {
	LUNEA_DEBUG std::cout << "LPROCESS_LIST::updateZ(LPROCESS* p)\n";
	int len = (int)listZ.size();

	while ((p->_z > 0) && (listZ[p->_z]->z < listZ[p->_z - 1]->z)) {
		LPROCESS *temp = listZ[p->_z - 1];
		listZ[p->_z - 1] = listZ[p->_z];
		listZ[p->_z] = temp;
		p->_z--;
	}

	while ((p->_z < len - 1) && (listZ[p->_z + 1]->z < listZ[p->_z]->z)) {
		LPROCESS *temp = listZ[p->_z + 1];
		listZ[p->_z + 1] = listZ[p->_z];
		listZ[p->_z] = temp;
		p->_z++;
	}
}

void LPROCESS_LIST::updatePriority(LPROCESS* p) {
	LUNEA_DEBUG std::cout << "LPROCESS_LIST::updatePriority(LPROCESS* p)\n";
	int len = (int)listPriority.size();

	while ((p->_priority > 0) && (listPriority[p->_priority]->priority < listPriority[p->_priority - 1]->priority)) {
		LPROCESS *temp = listPriority[p->_priority - 1];
		listPriority[p->_priority - 1] = listPriority[p->_priority];
		listPriority[p->_priority] = temp;
		p->_priority--;
	}

	while ((p->_priority < len - 1) && (listPriority[p->_priority + 1]->priority < listPriority[p->_priority]->priority)) {
		LPROCESS *temp = listPriority[p->_priority + 1];
		listPriority[p->_priority + 1] = listPriority[p->_priority];
		listPriority[p->_priority] = temp;
		p->_priority++;
	}
}

int LPROCESS_LIST::length() {
	LUNEA_DEBUG std::cout << "LPROCESS_LIST::length()\n";
	return (int)listZ.size();
}

void LPROCESS_LIST::execute() {
	LUNEA_DEBUG std::cout << "LPROCESS_LIST::execute()\n";
	int len = this->length();
	//std::cout << "EXECUTE: " << len << "\n";
	for (int n = 0; n < len; n++) {
		LUNEA_DEBUG std::cout << "LPROCESS_LIST::execute() [1]\n";
		CURRENT_PROCESS = listPriority[n];
		LUNEA_DEBUG std::cout << "LPROCESS_LIST::execute() [2]\n";
		CURRENT_PROCESS->execute();
		LUNEA_DEBUG std::cout << "LPROCESS_LIST::execute() [3]\n";
		updateZ(listPriority[n]);
		LUNEA_DEBUG std::cout << "LPROCESS_LIST::execute() [4]\n";
	}
}

void LPROCESS_LIST::draw() {
	LUNEA_DEBUG std::cout << "LPROCESS_LIST::draw()\n";
	//std::cout << "DRAW: " << len << "\n";
	for (int n = 0; n < (int)listZ.size(); n++) {
		CURRENT_PROCESS = listPriority[n];

		// Se ignora si el proceso está dormido
		if (CURRENT_PROCESS->status == LPROCESS::Status::sleep) continue;

		// Se elimina si el proceso está borrado
		LUNEA_DEBUG std::cout << "ESTADO PROCESO (" << n << ") : " << CURRENT_PROCESS->status << "\n";
		if (CURRENT_PROCESS->status == LPROCESS::Status::kill) {
			LUNEA_DEBUG std::cout << "PROC[1] \n";

			int _z = CURRENT_PROCESS->_z;
			int _priority = CURRENT_PROCESS->_priority;

			LUNEA_DEBUG std::cout << "PROC[2] (" << n << ", " << _priority << ") \n";

			listPriority.erase(listPriority.begin() + _priority);

			LUNEA_DEBUG std::cout << "PROC[3] (" << n << ", " << _z << ") \n";

			listZ.erase(listZ.begin() + _z);

			LUNEA_DEBUG std::cout << "PROC[4] \n";

			delete(CURRENT_PROCESS);

			LUNEA_DEBUG std::cout << "PROC[5] \n";

			LUNEA_DEBUG std::cout << "ELIMITADO PROCESO: " << (int)listZ.size() << "\n";
			LUNEA_DEBUG std::cout << "' '        '  '  : " << (int)listPriority.size() << "\n";

			if (n > 0) {
				n--;
			}

			for (int m = _priority; m < (int)listPriority.size(); m++) {
				listPriority[m]->_priority--;
			}

			for (int m = _z; m < (int)listZ.size(); m++) {
				listZ[m]->_z--;
			}

			continue;
		}
	}

	//for (int n = 0; n < (int)listZ.size(); n++) {
	for (int n = (int)listZ.size() - 1; n >= 0; n--) {
		CURRENT_PROCESS = listZ[n];

		CURRENT_PROCESS->__process();
		CURRENT_PROCESS->draw();
		updatePriority(listZ[n]);
	}
}
