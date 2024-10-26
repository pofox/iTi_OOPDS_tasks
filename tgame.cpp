#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
void setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}
void cls()
{
	// Get the Win32 handle representing standard output.
	// This generally only has to be done once, so we make it static.
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD topLeft = { 0, 0 };

	// std::cout uses a buffer to batch writes to the underlying console.
	// We need to flush that to the console because we're circumventing
	// std::cout entirely; after we clear the console, we don't want
	// stale buffered text to randomly be written out.
	std::cout.flush();

	// Figure out the current width and height of the console window
	if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
		// TODO: Handle failure!
		abort();
	}
	DWORD length = csbi.dwSize.X * csbi.dwSize.Y;

	DWORD written;

	// Flood-fill the console with spaces to clear it
	FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);

	// Reset the attributes of every character to the default.
	// This clears all background colour formatting, if any.
	FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);

	// Move the cursor back to the top left for the next sequence of writes
	SetConsoleCursorPosition(hOut, topLeft);
}
void SetColor(int textColor, int bgColor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}
void AandS()
{
	int arr[5],sum=0;
	float ave;
	std::cout<<"enter five integers\n";
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		sum += arr[i];
	}
	ave = (float)sum / 5;
	printf("the sum is %d\nthe average is %f\n", sum, ave);
}
void TandS()
{
	std::string a[5];
	int len[5] = {};
	int maxin = 0;
	int minin = 0;
	printf("enter five words\n");
	for (int i = 0; i < 5; i++)
	{
		std::cin>>a[i];
	}
	for (int i = 0; i < 5; i++)
	{
		len[i] = strlen(a[i].c_str());
	}
	for (int i = 0; i < 5; i++)
	{
		if (len[maxin] < len[i]) maxin = i;
		if (len[minin] > len[i]) minin = i;
	}
	printf("the longest word is :%s\nthe shortest word is:%s\n", a[maxin].c_str(), a[minin].c_str());
}
void ascii()
{
	char ch[50];
	std::cout << "enter characters\n";
	std::cin >> ch;
	std::cout << "the ASCII of " << ch << " is : ";
	for (int i = 0; ch[i] != '\0'; i++)
	{
		std::cout << (int)ch[i] << "\t";
	}
	std::cout << std::endl;
}
void tgame()
{
	bool win = false;
	struct Pos{
		int x;
		int y;
	}pos = { 5,5 };
	Pos t = { 100,20 };
	char mov;
	char scr[29][120];
	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			scr[i][j] = ' ';
			if (j == 0 || j == 119) scr[i][j] = '\|';
			if (i == 0 || i == 28) scr[i][j] = '-';
		}
	}
	scr[t.y][t.x] = 'x';
	cls();
	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			if (j == 0 || j == 119) SetColor(15, 1);
			if (i == 0 || i == 28) SetColor(15, 1);
			if (i == t.y && j == t.x) SetColor(7, 6);
			std::cout << scr[i][j];
			SetColor(7, 0);
		}
		std::cout << std::endl;
	}
	do {
		setCursorPosition(pos.x, pos.y);
		std::cout << "@";
		mov = _getch();
		if (scr[pos.y][pos.x] == ' ')
		{
			setCursorPosition(pos.x, pos.y);
			std::cout << ' ';
		}
		switch (mov)
		{
		case 'a':
			if (scr[pos.y][pos.x-1]==' ') pos.x -= 1;
			if (scr[pos.y][pos.x - 1] == 'x') win = true;
			break;
		case 'd':
			if (scr[pos.y][pos.x+1]==' ') pos.x += 1;
			if (scr[pos.y][pos.x + 1] == 'x') win = true;
			break;
		case 'w':
			if (scr[pos.y-1][pos.x]==' ') pos.y -= 1;
			if (scr[pos.y - 1][pos.x] == 'x') win = true;
			break;
		case 's':
			if (scr[pos.y+1][pos.x]==' ') pos.y += 1;
			if (scr[pos.y + 1][pos.x] == 'x') win = true;
			break;
		default:
			break;
		}
	} while (!win);
	cls();
	std::cout << "congratulations!!!\n\a";
}
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
			cls();
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
