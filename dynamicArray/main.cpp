#include "tVector.h"
#include "tForwardList.h"
#include "tList.h"

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