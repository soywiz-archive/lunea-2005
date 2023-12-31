#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "lunea_string.h"

String::String() { }

void String::StringConstructor(char* ptr, int length) {
	if (length < 0) {
		ptr += length;
		length = -length;
	}

	this->ptr = (char *)malloc(length + 1);

	memcpy(this->ptr, ptr, length);
	this->ptr[this->slength = length] = 0;
}

String::String(char *ptr) {
	StringConstructor(ptr, (int)strlen(ptr));
}

String::String(char* ptr, int length) {
	StringConstructor(ptr, length);
}

String::~String() {
	free(this->ptr);
}

int String::length() {
	return this->slength;
}

String* String::substr(int pos) {
	while (pos < 0) pos += this->slength;
	return substr(pos, this->slength - pos);
}

String* String::substr(int pos, int length) {
	if (length < 0) {
		pos += length;
		length = -length;
	}

	while (pos < 0) pos += this->slength;

	if (pos + length > this->slength) length = this->slength - pos;

	return new String(this->ptr + pos, length);
}

String* String::ltrim() {
	for (int n = 0; n < this->slength; n++) {
		char c = this->ptr[n];
		if (c == ' ' || c == '\t' || c == '\r' || c == '\n') continue;
		return this->substr(n);
	}

	return new String("");
}

String* String::rtrim() {
	for (int n = this->slength - 1; n > 0; n--) {
		char c = this->ptr[n];
		if (c == ' ' || c == '\t' || c == '\r' || c == '\n') continue;
		return this->substr(0, n);
	}

	return new String("");
}

String* String::trim() {
	return this->ltrim()->rtrim();
}

String* String::concat(String* str) {
	String *retval = new String();

	retval->ptr = (char *)malloc(this->slength + str->slength + 1);
	retval->ptr[retval->slength = this->slength + str->slength] = 0;
	memcpy(retval->ptr, this->ptr, this->slength);
	memcpy(retval->ptr + this->slength, str->ptr, str->slength);

	return retval;
}

char* String::pointer() {
	return this->ptr;
}