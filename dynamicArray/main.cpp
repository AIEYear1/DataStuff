#include "tVector.h"
#include "tForwardList.h"
#include "tList.h"
#include "tBinaryTree.h"
#include "Hash.h"

int main()
{
	tList<int> numbers;

	tList<int> copy;

	//invoke copy assign
	copy = numbers;

	numbers.remove(1);

	// this should succeed and return 2, but fails
	// the state of the list is now invalid
	//
	// head and tail are now null
	copy.back();

	return 0;
}