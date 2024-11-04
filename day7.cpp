#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <math.h>
#include <vector>

class GeometricShape {
public:
	virtual float Area()
	{
		return 0;
	}
};

class Circle : public GeometricShape {
public:
	float r;
	float Area()
		override
	{
		return M_PI * r * r;
	}
};

class Triangle : public GeometricShape {
public:
	float base,hight;
	float Area()
		override
	{
		return 0.5 * base * hight;
	}
};

class Rect : public GeometricShape {
public:
	float base, hight;
	float Area()
		override
	{
		return base * hight;
	}
};

class Square : public GeometricShape {
public:
	float side;
	float Area()
		override
	{
		return side * side;
	}
};


float Area(GeometricShape* c)
{
	return c->Area();
}

void D7()
{
	Circle c;
	Triangle t;
	Rect r;
	Square s;
	c.r = 1;
	t.base = 1;
	t.hight = 2;
	r.base = 1;
	r.hight = 2;
	s.side = 2;
	std::cout << "The Area of the circle is " << Area(&c) << "\n";
	std::cout << "The Area of the triangle is " << Area(&t) << "\n";
	std::cout << "The Area of the rectangle is " << Area(&r) << "\n";
	std::cout << "The Area of the square is " << Area(&s) << "\n";
}

int main()
{
	char choise, ch;
	while (true)
	{
		std::cout << "Choose one of the following programes\na. day7.\nb. .\nc. .\nd. exit.\ne. cls\nf. .\n";
		std::cin >> choise;
		switch (choise)
		{
		case 'a':
			D7();
			break;
		case 'b':
			//C2();
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

