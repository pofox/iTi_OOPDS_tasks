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

std::vector<int> InsetionSort(std::vector<int> numbers)
{
	int j;
	for (int i = 1; i < numbers.size(); i++)
	{
		int key = numbers[i];
		j = i - 1;
		while(j >= 0 && key < numbers[j])
		{
			numbers[j + 1] = numbers[j];
			j--;
		}
		numbers[j + 1] = key;
	}
	return numbers;
}

std::vector<int> MergSort(std::vector<int> numbers)
{
	int size = numbers.size();
	if (size == 2)
	{
		if (numbers[0] > numbers[1])
		{
			Swap(&numbers, 0, 1);
			return numbers;
		}
	}
	if (size == 1) return numbers;

	int divider = size / 2;
	std::vector vec1;
	std::vector vec2;

	for (int i = 0; i < divider; i++)
	{
		vec1.push_back(numbers[i]);
	}
	for (int i = divider; i < size; i++)
	{
		vec2.push_back(numbers[i]);
	}
	vec1 = MergSort(vec1);
	vec2 = MergSort(vec2);
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
	InsetionSort(&arr);
	PrintVector(arr);
}

