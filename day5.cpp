#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <Windows.h>
//#include <string>
#include "header.h"

int ComplexNumber::count = 0;

ComplexNumber Add(ComplexNumber z1,ComplexNumber z2)
{
    ComplexNumber out;
    out.SetRe(z1.GetRe() + z2.GetRe());
    out.SetIm(z1.GetIm() + z2.GetIm());
    return out;
}

ComplexNumber Sub(ComplexNumber z1,ComplexNumber z2)
{
    ComplexNumber out;
    out.SetRe(z1.GetRe() - z2.GetRe());
    out.SetIm(z1.GetIm() - z2.GetIm());
    return out;
}

ComplexNumber Mul(ComplexNumber z1,ComplexNumber z2)
{
    ComplexNumber out;
    out.SetRe(z1.GetRe() * z2.GetRe() - z1.GetIm() * z2.GetIm());
    out.SetIm(z1.GetRe() * z2.GetIm() + z1.GetIm() * z2.GetRe());
    return out;
}

void display(ComplexNumber z)
{
	std::cout<<z.GetRe();
	if (z.GetIm()>=0) std::cout<<"+";
    std::cout<<z.GetIm()<<"i\n";
}

void CompNum()
{
    ComplexNumber z1;
	z1 = ComplexNumber(1);
	std::cout<<"count : "<<ComplexNumber::count<<"\n";
	ComplexNumber z2;
	z2 = ComplexNumber(3,4);
	std::cout<<"count : "<<ComplexNumber::count<<"\n";
	ComplexNumber result;
	std::cout<<"count : "<<ComplexNumber::count<<"\n";
    std::cout<<"z1 = ";
	display(z1);
	std::cout<<"\n";
    std::cout<<"z2 = ";
	display(z2);
	std::cout<<"\n";
    result = Add(z1,z2);
    std::cout<<"z1+z2 = ";
	display(result);
    std::cout<<"\n";
    result = Sub(z1,z2);
    std::cout<<"z1-z2 = ";
	display(result);
    std::cout<<"\n";
    result = Mul(z1,z2);
    std::cout<<"z1*z2 = ";
	display(result);
    std::cout<<"\n";
	std::cout<<"count : "<<ComplexNumber::count<<"\n";
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
