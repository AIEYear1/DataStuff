#include <iostream>

#include "stopwatch.h"

#include <thread>
#include <chrono>

void bubbleSort(int *numbers, size_t numbersLength)
{
	bool swapped = true;
	while (swapped)
	{
		swapped = false;
		for (size_t j = 1; j < numbersLength; ++j)
		{
			if (numbers[j - 1] > numbers[j])
			{
				int temp = numbers[j - 1];

				// swap
				numbers[j - 1] = numbers[j];
				numbers[j] = temp;

				swapped = true;
			}
		}
	}
}

// bubble sort
//   worst-case
//    O(n^2) comp
//    O(n^2) swaps
//   best-case
//    O(n) comparisons
//    O(1) swaps
// insertion sort
//   worst-case
//    O(n^2) comp
//    O(n^2) swaps
//   best-case  
//    O(n) comparisons
//    O(1) swaps

int main()
{
	stopwatch demoTimer;

	int numbersLength = 1000000;
	int *numbers = new int[numbersLength];

	for (size_t i = 0; i < numbersLength; ++i)
	{
		// worst-case evaluation
		//numbers[i] = numbersLength - i;
		numbers[i] = i;
	}

	std::cout << "number generation done" << std::endl;

	demoTimer.start();

	bubbleSort(numbers, numbersLength);

	demoTimer.stop();

	std::cout << demoTimer.millisecondCount() << std::endl;
	std::cout << demoTimer.secondsCount() << std::endl;

	return 0;
}