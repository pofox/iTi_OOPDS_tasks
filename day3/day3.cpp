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
	void add(const std::string& name, int ID)
{
    Node* node = new Node{name, ID};
    size++;
    if (first == nullptr)
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
		Node* nod = first;
		int i=0;
		while (i<size)
		{
			nod->printemployee();
			nod = nod->next;
			i++;
		}
	}
	DLinkedList MergeSort(DLinkedList d)
	{
		DLinkedList out;
		if (d.size == 2)
		{
			if (d.first->ID > d.last->ID)
			{
				out.add(d.last->name,d.last->ID);
				out.add(d.first->name,d.first->ID);
				return out;
			}
			return d;
		}
		if (d.size == 1) return d;

		DLinkedList l1;
		DLinkedList l2;

		Node* node = d.first;
		//Node* node2 = nullptr;
		for (int i = 0; i < d.size / 2; i++)
		{
			//node2 = node->next;
			l1.add(node->name,node->ID);
			node = node->next;
		}
		for (int i = d.size / 2; i < d.size; i++)
		{
			l2.add(node->name,node->ID);
			node = node->next;
		}

		int i,idx1,idx2;
		l1 = MergeSort(l1);
		l2 = MergeSort(l2);
		i=idx1=idx2=0;

		Node* j = l1.first;
		Node* k = l2.first;
		for (; i < d.size && idx1 < l1.size && idx2 < l2.size; i++)
		{
			if (j->ID < k->ID)
			{
				out.add(j->name,j->ID);
				j = j->next;
				idx1++;
			}
			else
			{
				out.add(k->name,k->ID);
				k = k->next;
				idx2++;
			}
		}
		while (idx1 < l1.size)
		{
			out.add(j->name,j->ID);
			j = j->next;
			idx1++;
		}
		while (idx2 < l2.size)
		{
			out.add(k->name,k->ID);
			k = k->next;
			idx2++;
		}
		return out;
	}
	void deleteDLL()
	{
		Node* current = first;
		while (current != nullptr)
		{
			Node* nextNode = current->next;
			delete current;
		    current = nextNode;
		}
	}
};

int main()
{
	DLinkedList list;

	Node a = { "mohamed",2 };
	Node b = { "khaled",4 };
	Node c = { "Amr",1 };
	Node d = { "Ali",3 };

	list.add(a.name,a.ID);
	list.add(b.name,b.ID);
	list.add(c.name,c.ID);
	list.add(d.name,d.ID);
	list.printall();
	list = list.MergeSort(list);
	list.printall();
	list.deleteDLL();
}

