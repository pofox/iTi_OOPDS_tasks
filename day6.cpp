#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <vector>

class Position {
public:
	float x, y;
};

class Sowrd {
public:
	int power;
};

class Creature {
public:
	Position position;          //composition
	int health;
	void TakeDamage(int a = 1) {
		health -= a;
	}
};

class npc : public Creature {   //inharetance
public:
	std::string dialog;
	void Interact() {
		std::cout << dialog << "\n";
	}
};

class player : public Creature {
	Sowrd s;
	void Attack(Creature e) {
		if (e.position.x - position.x < 10)
		{
			e.TakeDamage(s.power);
		}
	}
};

class car {
	Creature driver;            //Aggregation
};

class enemy : public Creature {
	player* p;                  //Association
	Sowrd s;
	void Attack() {
		if (p->position.x - position.x < 10)
		{
			p->TakeDamage(s.power);
		}
	}
};

void C2() {
	player p;
	npc n1;
	enemy e;
	p.health = e.health = n1.health = 100;
	n1.dialog = "Hello there";
	std::cout << "player\'s health is " << p.health << "\n";
	std::cout << "npc\'s health is " << p.health << "\n";
	std::cout << "enemy\'s health is " << p.health << "\n";
	n1.Interact();
	p.TakeDamage();
	e.TakeDamage();
	n1.TakeDamage();
	std::cout << "player\'s health is " << p.health << "\n";
	std::cout << "npc\'s health is " << p.health << "\n";
	std::cout << "enemy\'s health is " << p.health << "\n";
}



class ComplexNumber {
public:
	float x, y;
	ComplexNumber(float xval, float yval) :
		x(xval),
		y(yval)
	{}
	ComplexNumber(const ComplexNumber& original)
	{
		x = original.x;
		y = original.y;
	}
	ComplexNumber operator+(ComplexNumber& right)
	{
		return ComplexNumber(x + right.x, y + right.y);
	}
	ComplexNumber& operator++()
	{
		x++;
		y++;
		return *this;
	}
	ComplexNumber& operator--()
	{
		x--;
		y--;
		return *this;
	}
	ComplexNumber operator++(int)
	{
		ComplexNumber temp = *this;
		++x;
		++y;
		return temp;
	}
	ComplexNumber operator--(int)
	{
		ComplexNumber temp = *this;
		--x;
		--y;
		return temp;
	}
	ComplexNumber operator-(ComplexNumber& right)
	{
		return ComplexNumber(x - right.x, y - right.y);
	}
	ComplexNumber operator*(ComplexNumber& right)
	{
		return ComplexNumber((x * right.x) - (y * right.y), y * right.x + x * right.y);
	}
	bool operator==(ComplexNumber& right)
	{
		return (x == right.x && y == right.y);
	}
	bool operator!=(ComplexNumber& right)
	{
		return (x != right.x || y != right.y);
	}
	void operator=(const ComplexNumber& right)
	{
		x = right.x;
		y = right.y;
	}
	operator float()
	{
		return x * x - y * y;
	}
};

void comp()
{
	ComplexNumber z1 = ComplexNumber(1, 2);
	ComplexNumber z2 = ComplexNumber(5, 6);
	ComplexNumber result = z1 + z2;
	std::cout << "z1 = " << z1.x << "+" << z1.y << "i\n";
	result = z1++;
	std::cout << "z1 = " << z1.x << "+" << z1.y << "i\n";
	std::cout << "z1++ = " << result.x << "+" << result.y << "i\n";
	result = ++z1;
	std::cout << "z1 = " << z1.x << "+" << z1.y << "i\n";
	std::cout << "++z1 = " << result.x << "+" << result.y << "i\n";
	result = z2--;
	std::cout << "z2 = " << z2.x << "+" << z2.y << "i\n";
	std::cout << "z2-- = " << result.x << "+" << result.y << "i\n";
	result = --z2;
	std::cout << "z2 = " << z2.x << "+" << z2.y << "i\n";
	std::cout << "--z2 = " << result.x << "+" << result.y << "i\n";
	std::cout << "z2 = " << z2.x << "+" << z2.y << "i\n";
	result = z1 + z2;
	std::cout << "z1 + z2 = " << result.x << "+" << result.y << "i\n";
	result = (z2 - z1);
	std::cout << "z2 - z1 = " << result.x << "+" << result.y << "i\n";
	result = (z1 * z2);
	std::cout << "z2 * z1 = " << result.x << "+" << result.y << "i\n";
	std::cout << "|z1| = " << z1 << "\n";
	std::cout << "(z1 == z2) = " << (z1 == z2) << "\n";
	std::cout << "(z1 != z2) = " << (z1 != z2) << "\n";
}

int main()
{
	char choise, ch;
	while (true)
	{
		std::cout << "Choose one of the following programes\na. Complex Numbers.\nb. Challenge 2.\nc. .\nd. exit.\ne. cls\nf. .\n";
		std::cin >> choise;
		switch (choise)
		{
		case 'a':
			comp();
			break;
		case 'b':
			C2();
			break;
		case 'c':
			break;
		case 'd':
			return 0;
		case 'e':
			system("cls");
			break;
		case 'f':
			//ascii();
			break;
		default:
			break;
		}
		std::cout << "----------------------------------------------------\n";
	}
}

