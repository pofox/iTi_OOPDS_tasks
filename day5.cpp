#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <Windows.h>
#include <string>
#include "header.h"

ComplexNumber Add(ComplexNumber z1,ComplexNumber z2)
{
    ComplexNumber out(0,0);
    out.x = z1.x + z2.x;
    out.y = z1.y + z2.y;
    return out;
}

ComplexNumber Sub(ComplexNumber z1,ComplexNumber z2)
{
    ComplexNumber out(0,0);
    out.x = z1.x - z2.x;
    out.y = z1.y - z2.y;
    return out;
}

ComplexNumber Mul(ComplexNumber z1,ComplexNumber z2)
{
    ComplexNumber out(0,0);
    out.x = z1.x * z2.x - z1.y * z2.y;
    out.y = z1.x * z2.y + z1.y * z2.x;
    return out;
}

void CompNum()
{
    ComplexNumber z1(1,2);
	ComplexNumber z2(3,4);
	ComplexNumber result(0,0);
    std::cout<<"z1 = "<<z1.x<<"+i"<<z1.y<<"\n";
    std::cout<<"z2 = "<<z2.x<<"+i"<<z2.y<<"\n";
    result = Add(z1,z2);
    std::cout<<"z1+z2 = "<<result.x;
	if (result.y>0) std::cout<<"+";
    std::cout<<result.y<<"i\n";
    result = Sub(z1,z2);
    std::cout<<"z1-z2 = "<<result.x;
	if (result.y>0) std::cout<<"+";
    std::cout<<result.y<<"i\n";
    result = Mul(z1,z2);
    std::cout<<"z1*z2 = "<<result.x;
	if (result.y>0) std::cout<<"+";
    std::cout<<result.y<<"i\n";
}



int main()
{
	char choise,ch;
	while (true)
	{
		std::cout << "Choose one of the following programes\na. Complex Numbers.\nb. tallest and shortest word.\nc. treasure game.\nd. exit.\ne. cls\nf. ASCII of a character\n";
		std::cin >> choise;
		switch (choise)
		{
		case 'a':
			CompNum();
			break;
		case 'b':
			//TandS();
			break;
		case 'c':
			//tgame();
			break;
		case 'd':
			return 0;
		case 'e':
			//Windows("cls");
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
