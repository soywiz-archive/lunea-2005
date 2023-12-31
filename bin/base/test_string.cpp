#include <stdio.h>
#include <string>
/*
#include "lunea_string.h"
#include "lunea_base.h"
*/

using namespace std;

/*
void echo(String str) {
	//printf("%s", str.pointer());
}

void echo(String *str) {
	//printf("%s", str->pointer());
}
*/

int main() {
	int str = sizeof("pru\0eba");

	printf("%i", str);

	//echo(file_get_contents("test_string.cpp"));
	//echo(String("hola") + String("hola2"));

	return 0;
}