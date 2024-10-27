#include <iostream>
#include <vector>
#include <string>

std::vector<int> MergeSort(std::vector<int> numbers)
{
	int size = numbers.size();
	if (size == 2)
	{
		if (numbers[0] > numbers[1])
		{
			Swap(&numbers, 0, 1);
			return numbers;
		}
		return numbers;
	}
	if (size == 1) return numbers;

	std::vector<int> vec1;
	std::vector<int> vec2;

	for (int i = 0; i < size / 2; i++)
	{
		vec1.push_back(numbers[i]);
	}
	for (int i = size / 2; i < size; i++)
	{
		vec2.push_back(numbers[i]);
	}

	vec1 = MergeSort(vec1);
	vec2 = MergeSort(vec2);

	int i, j, k;
	i = j = k = 0;
	for(; i < size && j < size / 2 && k < size - (int)(size / 2); i++)
	{
		if (vec1[j] < vec2[k])
		{
			numbers[i] = vec1[j];
			j++;
		}
		else
		{
			numbers[i] = vec2[k];
			k++;
		}
	}
	while (j < size / 2)
	{
		numbers[i] = vec1[j];
		i++;
		j++;
	}
	while (k < size - (int)(size / 2))
	{
		numbers[i] = vec2[k];
		i++;
		k++;
	}
	return numbers;
}

struct Node
{
	std::string name;
	int ID;
	Node* next;
	Node* prev;
	void printemployee()
	{
		std::cout<<"Name : "<< name<<"ID : "<< ID<<"\n";
	}
}

struct DLinkedList
{
	Node* first=NULL;
	Node* last=NULL;
	void add(Node* node)
	{
		
	}
}

int main()
{
	
}

