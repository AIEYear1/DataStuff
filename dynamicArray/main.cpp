#include "tVector.h"
#include "tForwardList.h"
#include "tList.h"
#include <cstdint>

template <typename T>
uint32_t hash(const T &val);

int main()
{
	tVector<int> numbers;

	numbers.push_back(5);
	numbers.push_back(6);
	numbers.push_back(7);
	numbers.push_back(8);

	numbers.at(6);

	int val = numbers.at(0);

	tVector<int> numbers2;
	numbers2 = numbers;

	return 0;
}

template<>
uint32_t hash<uint32_t>(const uint32_t &val)
{
	return val * 2654435761;
}
template<>
uint32_t hash<size_t>(const size_t &val)
{
	return hash((uint32_t)val);
}
template<>
uint32_t hash<int>(const int &val)
{
	return hash((uint32_t)val);
}
template<>
uint32_t hash<char>(const char &val)
{
	return hash((uint32_t)val);
}
template<>
uint32_t hash<bool>(const bool &val)
{
	return hash((uint32_t)val);
}
template<size_t N>
uint32_t hash(const char(&string)[N])
{
	uint32_t toReturn = 0;

	for (int x = 0; x < N; ++x)
	{
		toReturn ^= hash((char)string[x]);
	}

	return toReturn;
}