#include "tVector.h"
#include "tForwardList.h"

int main()
{
	tForwardList<int> numbers;

	numbers.push_front(5);
	numbers.push_front(6);
	numbers.push_front(7);
	numbers.push_front(8);

	numbers.remove(6);

	int val = numbers.front();

	tForwardList<int> numbers2;
	numbers2 = numbers;

	return 0;
}