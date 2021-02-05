#include "tVector.h"
#include "tForwardList.h"
#include "tList.h"
#include "tBinaryTree.h"
#include "Hash.h"


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