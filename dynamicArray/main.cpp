#include "tVector.h"
#include "tForwardList.h"
#include "tList.h"
#include "tBinaryTree.h"
#include "Hash.h"

int main()
{
	tList<int> numbers;
	numbers.push_front(1);
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(3);

	numbers.remove(2);

	numbers.pop_back(); // drops 3
	numbers.pop_back(); // drops 3

	int last = numbers.back(); // this should be 1, but it instead returns 2

	return 0;
}