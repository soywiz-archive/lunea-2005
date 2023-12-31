#include <stdio.h>
#include <stdlib.h>
#include "lunea_string.h"

/*
String file_get_contents(String name) {
	String retval = String();

	FILE *fd;
	if (fd = fopen(name.pointer(), "rb")) {
		fseek(fd, 0, SEEK_END);
		retval.slength = ftell(fd);
		fseek(fd, 0, SEEK_SET);
		retval.ptr = (char *)malloc(retval.slength + 1);

		fread(retval.ptr, retval.slength, 1, fd);
		fclose(fd);
	}

	return retval;
}
*/
String *file_get_contents(String name) {
	String *retval = new String();

	FILE *fd;
	if (fd = fopen(name.pointer(), "rb")) {
		fseek(fd, 0, SEEK_END);
		retval->slength = ftell(fd);
		fseek(fd, 0, SEEK_SET);
		retval->ptr = (char *)malloc(retval->slength + 1);

		fread(retval->ptr, retval->slength, 1, fd);
		fclose(fd);
	}

	return retval;
}

class File {
private:
	FILE *fp;

public:
	File(String *str, String *type);
};