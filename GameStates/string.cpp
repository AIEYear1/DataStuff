#include "string.h"

string::string()
{
	str = new char[1]{ '\0' };
	size = 0;
}
string::string(char *text)
{
	size = strLength(text);
	str = new char[size + 1];

	for (int x = 0; x < size; ++x)
	{
		str[x] = text[x];
	}
	str[size] = '\0';
}
string::string(const char *text)
{
	size = strLength(text);
	str = new char[size + 1];

	for (int x = 0; x < size; ++x)
	{
		str[x] = text[x];
	}
	str[size] = '\0';
}

string::string(const string &other)
{
	size = other.size;

	str = new char[size + 1];

	for (int x = 0; x < size; ++x)
	{
		str[x] = other.str[x];
	}
	str[size] = '\0';
}
string &string::operator=(const string &other)
{
	size = other.size;

	str = new char[size + 1];

	for (int x = 0; x < size; ++x)
	{
		str[x] = other.str[x];
	}
	str[size] = '\0';

	return *this;
}
string::~string()
{
	delete[] str;
}

void string::append(string rhs)
{
	char *tmpString = new char[size + rhs.size + 1];

	for (int x = 0; x < size; x++)
	{
		tmpString[x] = str[x];
	}
	for (int x = 0; x < rhs.size + 1; x++)
	{
		tmpString[x + size] = rhs.str[x];
	}
	size += rhs.size;
	tmpString[size] = '\0';

	delete[] str;
	str = tmpString;
}
void string::trimEnd(int trimLength)
{
	size -= trimLength;
	char *tmpString = new char[size + 1];

	for (int x = 0; x < size; ++x)
	{
		tmpString[x] = str[x];
	}
	tmpString[size] = '\0';

	delete[] str;
	str = tmpString;
}
size_t string::strLength(string string)
{
	size_t toReturn = 0;
	char tmpChar = string.str[0];

	while (tmpChar != '\0')
	{
		toReturn++;
		tmpChar = string.str[toReturn];
	}

	return toReturn;
}
size_t string::strLength(const char *string)
{
	size_t toReturn = 0;
	char tmpChar = string[0];

	while (tmpChar != '\0')
	{
		toReturn++;
		tmpChar = string[toReturn];
	}

	return toReturn;
}

string::operator char *()
{
	return str;
}