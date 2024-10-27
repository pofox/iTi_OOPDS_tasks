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
	for (int i = 0; i < numbers->size() - 1; i++)
	{
		for (int j = 1; j < (*numbers).size() - i; j++)
		{
			if ((*numbers)[i + j] > (*numbers)[j]) Swap(numbers, i, j);
		}
	}
}

void PrintVector(std::vector<int> numbers)
{
	for (int i = 0; i < numbers.size(); i++)
	{
		std::cout << numbers[i] << "\t";
	}std::cout << "\n";
}
int main()
{
    std::cout << "Hello World!\n";
}

