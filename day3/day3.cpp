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

void PrintVector(std::vector<int> numbers)
{
	for (int i = 0; i < numbers.size(); i++)
	{
		std::cout << numbers[i] << "\t";
	}
	std::cout << "\n";
}

int BinSearch(std::vector<int> numbers, int num)
{
	int high = numbers.size() - 1;

	for (int low = 0; low <= high;)
	{
		int mid = (high + low) / 2;
		if (num == numbers[high]) return high;
		if (num == numbers[mid]) return mid;
		if (num < numbers[mid]) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}

struct Node
{
	int num;
	char name[10];
	int ssn;
	Node* next;
	void printNode()
	{
		std::cout << "Name : " << name << " | " << "Number : " << num << "\n";
	}
};

struct LinkedList
{
	Node* first = NULL;
	Node* lastInserted = NULL;
	void InitList(Node firstNode)
	{
		first = &firstNode;
		lastInserted = first;
	}
	void PushBack(Node node)
	{
		if (first == NULL)
		{
			first = &node;
			lastInserted = &node;
			return;
		}f


		lastInserted = &node;
		/*Node* i = first;
		while (i->next != NULL)
		{
			i = i->next;
		}
		i->next = &node;*/
	}
	void PrintList()
	{
		Node* current = first;
		while (current != NULL)
		{
			current->printNode();
			current = current->next
		}
	}
};

int main()
{
	//std::vector<int> arr = { 4,3,6,2,6,7,3,9,-2 };
	//PrintVector(arr);
	//arr = MergeSort(arr);
	//PrintVector(arr);
	//std::cout << BinSearch(arr, -2) << "\n";

	Node nod;
	nod.name = "ssss";
	nod.num = 5;
	nod.ssn = 30;

	Node m;
	m.name = "cvcv";
	m.num = 4;
	m.ssn = 40;

	LinkedList list;

	list.PushBack(nod);
	list.PushBack(m);

	list.PrintList();
}

