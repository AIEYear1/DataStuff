#pragma once
class string
{
private:

public:
	char *str;
	size_t size;

	string();
	string(char *text);
	string(const char *text);

	string(const string &other);
	string &operator=(const string &other);
	~string();

	void append(string str);
	void trimEnd(int trimLength);
	size_t strLength(string string);
	size_t strLength(const char *string);

	operator char *();
};

