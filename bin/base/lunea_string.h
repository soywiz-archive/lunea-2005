#pragma once

class String {
public:
	char *ptr;
	int slength;

	String();

	void StringConstructor(char* ptr, int length);

	String(char *ptr);
	String(char* ptr, int length);
	~String();
	int length();
	String* substr(int pos);
	String* substr(int pos, int length);
	String* ltrim();
	String* rtrim();
	String* trim();
	String* concat(String* str);
    char* pointer();
};