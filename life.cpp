#include "life.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void instructions()
{
	cout << "Welcome to game of life." << endl;
	cout << "This game uses a grid of size " 
	     << maxrow << " by " << maxcol << "in which " << endl;
	cout << "each cell can either be occupied by an organism or not." << endl;
	cout << "The occupied cell change from generation to generation" << endl;
	cout << "according to the number of neighbouring cells which are alive." << endl;
}

void Life::initialize()
{
	int row, col;

	for (int i = 0; i <= maxrow + 1; ++i)
		for (int j = 0; j <= maxcol + 1; ++j)
			grid[i][j] = 0;

	cout << "List the coordinates for living cells." << endl;
	cout << "Terminate the list with the special pair -1 -1" << endl;
	cin >> row >> col;

	while (row != -1 || col != -1) {
		if (row >= 1 && row <= maxrow)
			if (col >= 1 && col <= maxcol)
				grid[row][col] = 1;
			else
				cout << "Col " << col << " is out of range." << endl;
		else
			cout << "Row " << row << " is out of range." << endl; 
		cin >> row >> col;
	}
}

void Life::print()
{
	for (int i = 1; i <= maxrow; ++i)
	{
		for (int j = 1; j <= maxcol; ++j)
			cout << (grid[i][j] ? '*' : ' ');
		cout << endl;
	}
}

void Life::update()
{
	int new_grid[maxrow + 2][maxcol + 2];

	for (int i = 1; i <= maxrow; ++i)
		for (int j = 1; j <= maxcol; ++j)
			switch (neighboud_count(i,j)) {
				case 2:
					new_grid[i][j] = grid[i][j];
					break;
				case 3:
					new_grid[i][j] = 1;
					break;
				default:
					new_grid[i][j] = 0;
					break;
			}

	for (int i = 1; i <= maxrow; ++i)
		for (int j = 1; j <= maxcol; ++j)
			grid[i][j] = new_grid[i][j];
}

int Life::neighboud_count(int row, int col)
{
	int count = 0;
	for (int i = row - 1; i <= row + 1; ++i)
		for (int j = col - 1; j <= col + 1; ++j)
			count += grid[i][j];

	count -= grid[row][col];
	return count;
}