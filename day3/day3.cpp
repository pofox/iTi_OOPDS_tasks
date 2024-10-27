#include <iostream>
#include <vector>

void Swap(std::vector<int>* numbers, int idx1, int idx2)
{
	(*numbers)[idx1] ^= (*numbers)[idx2];
	(*numbers)[idx2] ^= (*numbers)[idx1];
	(*numbers)[idx1] ^= (*numbers)[idx2];
}

void BubbleSort(std::vector<int>* numbers)
{
	for (int i = 0; i < (*numbers).size() - 1; i++)
	{
		for (int j = 0; j < (*numbers).size() - i - 1; j++)
		{
			if ((*numbers)[j] > (*numbers)[j+1]) Swap(numbers, j, j + 1);
		}
	}
}



void PrintVector(std::vector<int> numbers)
{
	for (int i = 0; i < numbers.size(); i++)
	{
		std::cout << numbers[i] << "\t";
	}
	std::cout << "\n";
}

int main()
{
	std::vector<int> arr = { 4,3,6,2,6,7,3,9 };
	PrintVector(arr);
	BubbleSort(&arr);
	PrintVector(arr);
}

