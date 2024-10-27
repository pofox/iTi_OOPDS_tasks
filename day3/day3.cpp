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
		std::cout << "Name : " << name << " ID : " << ID << "\n";
	}
};

struct DLinkedList
{
	Node* first = nullptr;
	Node* last = nullptr;
	int size = 0;
	void add(Node* node)
	{
		size++;
		node->next = nullptr;
		if (first == nullptr)
		{
			first = node;
			last = node;
			node->prev = nullptr;
			return;
		}
		node->prev = last;
		last->next = node;
		last = node;
	}
	void removeat(int idx)
	{
		size--;
		Node* node = first;
		while (idx > 0)
		{
			node = node->next;
			idx--;
		}
		if (node->prev != first->prev) (node->prev)->next = node->next;
		if (node->prev == first->prev) first = node->next;
		if (node->next != last->next) (node->next)->prev = node->prev;
		if (node->next == last->next) last = node->prev;
	}
	int find(int id)
	{
		Node* node = first;
		int idx = 0;
		while (id != node->ID)
		{
			if (node->next == last->next) return -1;
			node = node->next;
			idx++;
		}
		return idx;
	}
	void replaceAt(Node* newnode, int idx)
	{
		Node* node = first;
		while (idx > 0)
		{
			node = node->next;
			idx--;
		}
		if (node->prev != first->prev) (node->prev)->next = newnode;
		if (node->prev == first->prev)
		{
			first = newnode;
			newnode->next = node->next;
		}
		if (node->next != last->next) (node->next)->prev = newnode;
		if (node->next == last->next)
		{
			last = newnode;
			newnode->prev = node->prev;
		}
	}
	void printall()
	{
		Node* node = first;
		while (node->next != last->next)
		{
			node->printemployee();
			node = node->next;
		}
		node->printemployee();
	}
	DLinkedList MergeSort(DLinkedList d)
	{
		DLinkedList out;
		if (d.size == 2)
		{
			if (d.first->ID > d.last->ID)
			{
				out.add(d.last);
				out.add(d.first);
				return out;
			}
			return d;
		}
		if (d.size == 1) return d;

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
			l2.add(node);
			node = node->next;
		}

		int i = 0;
		l1 = MergeSort(l1);
		l2 = MergeSort(l2);

		Node* j = l1.first;
		Node* k = l2.first;
		for (; i < d.size && j != l1.last->next && k != l2.last->next; i++)
		{
			if (j->ID < k->ID)
			{
				out.add(j);
				j = j->next;
			}
			else
			{
				out.add(k);
				k = k->next;
			}
		}
		while (j != l1.last->next)
		{
			out.add(j);
			j = j->next;
		}
		while (k != l2.last->next)
		{
			out.add(k);
			k = k->next;
		}
		return out;
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
	list = list.MergeSort(list);
	list.printall();
}

