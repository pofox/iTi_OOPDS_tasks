#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string>
#include "header.h"

void CompNum()
{
    ComplexNumber z1,z2,result;
    z1.ComplexNumber(1,2);
    z2.ComplexNumber(3,4);
    std::cout<<"z1 = "<<z1.x<<"+i"<<z1.y<<"\n";
    std::cout<<"z2 = "<<z2.x<<"+i"<<z2.y<<"\n";
    result = Add(z1,z2);
    std::cout<<"z1+z2 = "<<result.x<<"+i"<<result.y<<"\n";
    result = Sub(z1,z2);
    std::cout<<"z1-z2 = "<<result.x<<"+i"<<result.y<<"\n";
    result = Mult(z1,z2);
    std::cout<<"z1*z2 = "<<result.x<<"+i"<<result.y<<"\n";
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
			Windows("cls");
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
