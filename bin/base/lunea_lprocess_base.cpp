#include <lunea_define.h>
#include <lunea_lprocess_base.h>
#include <lunea_lprocess.h>
#include <lunea_lprocess_list.h>
#include <iostream>

void LPROCESS_BASE::__addAction(const char *name, int id) {
	__action_list[name] = id;
}

int LPROCESS_BASE::__getIdActionByName(const char *name) {
	return __action_list[name];
}

void LPROCESS_BASE::__init() {
	LUNEA_DEBUG std::cout << "LPROCESS_BASE::__init() [1]\n";

	_priority = priority = _z = z = y = x = 0;
	//this->__jump_control = false;
	this->status = Status::run;

	LUNEA_DEBUG std::cout << "LPROCESS_BASE::__init() [2]" << "\n";

	// Se crea la jerarquía de procesos
	this->father   = CURRENT_PROCESS;
	this->bigbro   = (this->father && this->father->son) ? this->father->son : 0;

	LUNEA_DEBUG std::cout << "LPROCESS_BASE::__init() [3]\n";

	this->smallbro = 0;
	this->action   = 0;
	this->__jump_current = 0;

	LUNEA_DEBUG std::cout << "LPROCESS_BASE::__init() [4]" << this->bigbro << "\n";

	if (this->bigbro) this->bigbro->smallbro = (LPROCESS *)this;
	if (this->father) this->father->son      = (LPROCESS *)this;

	this->son = 0;

	LUNEA_DEBUG std::cout << "LPROCESS_BASE::__init() [5]\n";

	TEMP_PROCESS_LIST->insert((LPROCESS *)this);

	LUNEA_DEBUG std::cout << "LPROCESS_BASE::__init() [6]\n";
}

void LPROCESS_BASE::__deinit() {
	LUNEA_DEBUG std::cout << "LPROCESS_BASE::__deinit()\n";

	// Se restaura la anterior jerarquía de procesos

	// Se elimina la referencia de padre->hijo
	if (this->father->son == this) this->father->son = this->bigbro;
	// Se elimina la referencia de hermano mayor->hermano menor
	if (this->bigbro)   this->bigbro->smallbro = this->smallbro;
	// Se elimina la referencia de hermano menor->hermano mayor
	if (this->smallbro) this->smallbro->bigbro = this->bigbro;
	// Se elimina la referencia de hermano hijo->padre (huerfano)
	if (this->son)      this->son->father      = 0;

	/*
	for (int n = 0; n < (int)this->__jump_data.size(); n++) {
		delete this->__jump_data[n];
	}
	*/
}

void LPROCESS_BASE::__process() {
	// VOID
}