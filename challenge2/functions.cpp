#include <iostream>

struct item
{
	char name[10];
};

struct inventory
{
	item items[10];
	int number[10];
	void add(item a,int count,int idx)
	{
		items[idx] = a;
		number[idx] = count;
	}
	void remove(int count,int idx)
	{
		number[idx] -= count;
	}
	void display()
	{
		for (int i = 0; i < 10; i++)
		{
			if (number[i] <= 0) continue;
			std::cout << "item : " << items[i].name << " count : " << number[i] << " index " << i << "\n";
		}
	}
}inv;

void TimeTable(int n)
{
	for (int i = 1; i <= 10; i++)
	{
		std::cout << n << " * " << i << " = " << i * n << "\n";
	}
}
int fact(int n)
{
	if (n < 2) return 1;
	return n * fact(n - 1);
}
void factp(int* n)
{
	int m = *n;
	if (m < 2)
	{
		*n = 1;
		return;
	}
	m--;
	factp(&m);
	*n *= m;
}
int Pow(int a, int b)
{
	if (b == 1) return a;
	return a * Pow(a, b-1);
}
void Powp(int* a, int b)
{
	int m = *a;
	if (b == 1)
	{
		return;
	}
	Powp(&m,b-1);
	*a *= m;
}
void handleinventory()
{
	item a[10];
	int count = 0;
	while (true)
	{
		int ch,id,n,id2;
		std::cout << "1. creat item\n2. view items\n3. add to inventory\n4. remove from inventory\n5. view inventory\n6. to main menu\n";
		std::cin >> ch;
		switch (ch)
		{
		case 1:
			std::cout << "enter item name : ";
			std::cin >> a[count].name;
			count++;
			break;
		case 2:
			for (int i = 0; i < count; i++)
			{
				std::cout << "item : " << a[i].name << " index " << i << "\n";
			}
			break;
		case 3:
			std::cout << "enter item index ";
			std::cin >> id;
			std::cout << "enter how much do you want to add ";
			std::cin >> n;
			std::cout << "enter where do you want to add it ";
			std::cin >> id2;
			inv.add(a[id],n,id2);
			break;
		case 4:
			std::cout << "enter where do you want to remove from ";
			std::cin >> id;
			std::cout << "enter how much do you want to remove ";
			std::cin >> n;
			inv.remove(n,id);
			break;
		case 5:
			inv.display();
			break;
		case 6:
			return;
			break;
		default:
			break;
		}
	}
}