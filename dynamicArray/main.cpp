#include "tVector.h"

int main()
{
	tVector<int> numbers;

	numbers.push_back(5);

	int val = numbers.at(0);

	return 0;
}