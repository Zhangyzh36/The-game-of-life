#ifndef LIFE_H
#define LIFE_H

void instructions();

const int maxrow = 20;
const int maxcol = 60;

class Life {
public:
	void initialize();
	void print();
	void update();
private:
	int grid[maxrow + 2][maxcol + 2];
	int neighboud_count(int row, int col);
};

#endif