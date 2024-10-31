#define _CRT_SECURE_NO_WARNINGS
#include "header.h"


int main()
{
	game g;
	g.gameloop();
	return 0;
}



void setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

// player is '@'
pos findPlayer(game g)
{
	int i, j;
	for (i = 0; i < g.maze.size(); i++) {
		for (j = 0; j < g.maze[i].size(); j++) {
			if (g.maze[i][j] == '@')
			{
				return { j,i };
			}
		}
	}

}

void fileToVec(game g)
{
	std::string line;
	std::ifstream infile("input.txt");

	while (std::getline(infile, line)) {
		std::vector<char> row;

		for (char& c : line) {
			if (c != ',') {
				row.push_back(c);
			}
		}

		g.maze.push_back(row);
	}

}

void printMaze(game g) {
	for (std::vector<char>& row : g.maze) {
		for (char& c : row) {
			std::cout << c;
		}

		std::cout << '\n';
	}
}
