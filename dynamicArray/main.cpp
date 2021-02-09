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

	tBinaryTree<int>::node *foundNode;

	numbers.search(7, foundNode);

	return 0;
}