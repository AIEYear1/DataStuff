#include "tVector.h"
#include "tForwardList.h"
#include "tList.h"
#include "tBinaryTree.h"
#include <cstdint>

template <typename T>
uint32_t hash(const T &val);

int main()
{
	tBinaryTree<int> numbers;

	numbers.insert(5);
	numbers.insert(6);
	numbers.insert(7);
	numbers.insert(8);

	tBinaryTree<int>::node deets;

	bool val = numbers.search(6, deets);

	tBinaryTree<int> numbers2;
	numbers2 = numbers;
	tBinaryTree<int> numbers3 = numbers2;

	return 0;
}

template<>
uint32_t hash<uint32_t>(const uint32_t &val)
{
	return val * 2654435761;
}
//template<>
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