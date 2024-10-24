#include <iostream>
#include <Windows.h>
#include "Header.h"

int main()
{
    int choise,x,y;
	char c;
    std::cout << "choose a number of the following\n1. time table of n\n2. factorial\n3. power\n4. inventory\n5. cls\n6. exit\n";
	std::cin >> choise;
	switch (choise)
	{
	case 1:
		std::cout << "enter a number ";
		std::cin >> x;
		TimeTable(x);
		break;
	case 2:
		std::cout << "enter a number ";
		std::cin >> x;
		std::cout << "do you want to use pointers [y,n] ";
		std::cin >> c;
		switch (c)
		{
		case 'y':
			factp(&x);
			break;
		case 'n':
			x = fact(x);
			break;
		default:
			break;
		}
		std::cout << "the result is " << x << "\n";
		break;
	case 3:
		std::cout << "enter a number ";
		std::cin >> x;
		std::cout << "enter the power ";
		std::cin >> y;
		std::cout << "do you want to use pointers [y,n] ";
		std::cin >> c;
		switch (c)
		{
		case 'y':
			Powp(&x,y);
			break;
		case 'n':
			x = Pow(x,y);
			break;
		default:
			break;
		}
		std::cout << "the result is " << x << "\n";
		break;
	case 4:
		handleinventory();
		break;
	case 5:
		system("cls");
		break;
	case 6:
		return 0;
		break;
	default:
		break;
	}
	main();
}

