#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>

int main()
{
	char choise,ch;
	while (true)
	{
		std::cout << "Choose one of the following programes\na. Average and Sum of an array.\nb. tallest and shortest word.\nc. treasure game.\nd. exit.\ne. cls\nf. ASCII of a character\n";
		std::cin >> choise;
		switch (choise)
		{
		case 'a':
			AandS();
			break;
		case 'b':
			TandS();
			break;
		case 'c':
			tgame();
			break;
		case 'd':
			return 0;
		case 'e':
			Windows("cls");
			break;
		case 'f':
			ascii();
			break;
		default:
			break;
		}
		std::cout << "----------------------------------------------------\n";
	}
}
