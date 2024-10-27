#include <iostream>
#include <vector>
#include <string>

struct Node
{
	std::string name;
	int ID;
	Node* next = nullptr;
	Node* prev = nullptr;
	void printemployee()
	{
		std::cout << "Name : " << name << "ID : " << ID << "\n";
	}
};

struct DLinkedList
{
	Node* first=NULL;
	Node* last=NULL;
	int size = 0;
	void add(Node* node)
	{
		size++;
		if (first == NULL)
		{
			first = node;
			last = node;
			return;
		}
		node->prev = last;
		last->next = node;
		last = node;
	}
	void removeat(int idx)
	{
		size--;
		Node* node=first;
		while (idx >= 0)
		{
			node = node->next;
			idx--;
		}
		if (node->prev != NULL) *(node->prev)->next = node->next;
		if (node->prev == NULL) first = node->next;
		if (node->next != NULL) *(node->next)->prev = node->prev;
		if (node->next == NULL) last = node->prev;
	}
	int find(int id)
	{
		Node* node = first;
		int idx = 0;
		while (id != node->ID)
		{
			if (node->next == NULL) return -1;
			node = node->next;
			idx++;
		}
		return idx;
	}
	void replaceAt(Node* newnode, int idx)
	{
		Node* node = first;
		while (idx >= 0)
		{
			node = node->next;
			idx--;
		}
		if (node->prev != NULL) *(node->prev)->next = newnode;
		if (node->prev == NULL) 
		{ 
			first = newnode;
			newnode->next = node->next;
		}
		if (node->next != NULL) *(node->next)->prev = newnode;
		if (node->next == NULL) 
		{
			last = newnode;
			newnode->prev = node->prev;
		}
	}
	void printall()
	{
		Node* node = first;
		while (node->next != NULL)
		{
			node->printemployee();
		}
	}
	DLinkedList MergeSort(DLinkedList d)
	{
		if (d.size == 2)
		{
			if (d.first->ID > (*(d.first)->next).ID)
			{
				Node* node=d.first;
				replaceAt(*(d.first)->next, 0);
				replaceAt(node, 1);
				return d;
			}
			return d;
		}
		if (size == 1) return d;

		DLinkedList l1;
		DLinkedList l2;

		Node* node = d.first;
		for (int i = 0; i < d.size / 2; i++)
		{
			l1.add(node);
			node = node->next;
		}
		for (int i = d.size / 2; i < d.size; i++)
		{
			l2.add(d);
			node = node->next;
		}

		l1 = MergeSort(l1);
		l2 = MergeSort(l2);

		int i;
		Node* j = l1.first;
		Node* k = l2.first;
		i = j = k = 0;
		for (; i < d.size && j->next != NULL && k->next != NULL; i++)
		{
			if (j->ID < k->ID)
			{
				d.replaceAt(j, i);
				j = j->next;
			}
			else
			{
				d.replaceAt(k, i);
				k = k->next;
			}
		}
		while (j != NULL)
		{
			d.replaceAt(j,i)
			i++;
			j = j->next;
		}
		while (k != NULL)
		{
			d.replaceAt(k, i);
			i++;
			k = k->next;
		}
	}
};

int main()
{
	DLinkedList list;

	Node a = { "mohamed",1 };
	Node b = { "khaled",3 };
	Node c = { "Amr",2 };

	list.add(&a);
	list.add(&b);
	list.add(&c);
	list.printall();
}

