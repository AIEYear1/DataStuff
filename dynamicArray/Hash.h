#pragma once
#include <cstdint>

template <typename T>
uint32_t hash(const T &val);

template<>
uint32_t hash<uint32_t>(const uint32_t &val)
{
	return val * 2654435761;
}
//template<>									*COMMENTED OUT FOR x86 BUILDS REMOVE COMMENTING FOR x64 BUILDS*
//uint32_t hash<size_t>(const size_t &val)
//{
//	return hash((uint32_t)val);
//}
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
