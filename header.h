#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <vector>
struct pos
{
	int x;
	int y;
};

class game
{
	pos playerpos;
public:
	std::vector<std::vector<char>> maze;
	void gameloop();
	void updateplayerpos(pos p);
};

pos findPlayer(game g);
void setCursorPosition(int x, int y);
void fileToVec(game g);
void printMaze(game g);

/*--------------------------------------------------------------*/
class ComplexNumber
{
    float x;
    float y;
public:
    static int count;
    ComplexNumber(float a,float b);
    ComplexNumber(float a);
    ComplexNumber();
    ComplexNumber(const ComplexNumber& z);
    void SetRe(float a);
    void SetIm(float b);
    float GetRe() const;
    float GetIm() const;
    ~ComplexNumber();
};

ComplexNumber Add(ComplexNumber z1,ComplexNumber z2);

ComplexNumber Sub(ComplexNumber z1,ComplexNumber z2);

ComplexNumber Mul(ComplexNumber z1,ComplexNumber z2);

void display(ComplexNumber z1);
