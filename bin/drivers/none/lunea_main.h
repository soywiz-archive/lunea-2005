#include <lunea_debug.h>

int main(int argc, char **argv) {
	mouse_struct ms;
	mouse = &ms;
	/*
	long hResLength;
	const char *hResPtr;
	hResPtr = GetDataResourceFromName("test.lun", hResLength);
	std::cout << "Contents: " << hResPtr << " (" << hResLength << ") \n";

	//DebugResources();

	return 0;
	*/

	LUNEA_DEBUG std::cout << "Starting [1]\n";
	MAIN_PROCESS_LIST = new LPROCESS_LIST();
	LUNEA_DEBUG std::cout << "Starting [2]\n";
	TEMP_PROCESS_LIST = new LPROCESS_LIST();
	LUNEA_DEBUG std::cout << "Starting [3]\n";

	new start();

	LUNEA_DEBUG std::cout << "Starting [4]\n";

	while (true) {
		LUNEA_DEBUG std::cout << "Running [moveTo]\n";
		TEMP_PROCESS_LIST->moveTo(MAIN_PROCESS_LIST);
		LUNEA_DEBUG std::cout << "Running [execute]\n";
		MAIN_PROCESS_LIST->execute();
		LUNEA_DEBUG std::cout << "Running [draw]\n";
		MAIN_PROCESS_LIST->draw();

		if (MAIN_PROCESS_LIST->length() == 0) {
			LUNEA_DEBUG std::cout << "Length\n";
			break;
		}
	}

	LUNEA_DEBUG std::cout << "Ending\n";

	return 0;
}