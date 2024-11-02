#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <vector>

class ComplexNumber {
public:
	float x, y;
	ComplexNumber(float xval,float yval) :
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
	ComplexNumber operator-(ComplexNumber& right)
	{
		return ComplexNumber(x - right.x, y - right.y);
	}
	ComplexNumber operator*(ComplexNumber& right)
	{
		return ComplexNumber((x * right.x) - (y * right.y) , y * right.x + x * right.y);
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
		//auto v = ComplexNumber(x + right.x, y + right.y);
		//return v;
	}
	operator float()
	{
		return x*x - y*y;
	}
};

void comp()
{
	ComplexNumber z1 = ComplexNumber(1, 2);
	ComplexNumber z2 = ComplexNumber(5, 6);
	ComplexNumber result = z1 + z2;
	std::cout << "z1 = " << z1.x << "+" << z1.y << "i\n";
	std::cout << "z2 = " << z2.x << "+" << z2.y << "i\n";
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
		std::cout << "Choose one of the following programes\na. Complex Numbers.\nb. .\nc. .\nd. exit.\ne. cls\nf. .\n";
		std::cin >> choise;
		switch (choise)
		{
		case 'a':
			comp();
			break;
		case 'b':
			//TandS();
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

