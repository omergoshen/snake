#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define ROWS 25
#define COLS 75
struct SnakeNode
{
	int x;
	int y;
	struct SnakeNode *next;
};


// terminal escape codes/ANSI escape codes (or ANSI escape sequences)
// "\x1B" is the escape character that tells your terminal that what comes next is not meant to be printed on the screen, 
// but rather a command to the terminal (or most likely terminal emulatoion).

// Turn escape codes ON.
void init(void);
// Print the Board.
void printBoard();
void move();

// Moves the cursor to position (x,y) on screen.
// Parameters:
//     x: the row of the posiiton.
//     y: the column of the posiiton.
void gotoxy(int x, int y);

// Delays the execution of the program.
// Parameters:
//     secs: the length of the delay in seconds. 
void sleep(float secs);

int main() {



}

// Turn escape codes ON.
void init(void) {
	system("cls");
}

// Moves the cursor to position (x,y) on screen.
// Parameters:
//     x: the row of the posiiton.
//     y: the column of the posiiton.
void gotoxy(int x, int y) {
	printf("\x1b[%d;%df", x, y);
}

// Delays the execution of the program.
// Parameters:
//     secs: the length of the delay in seconds. 
void sleep(float secs) {
	clock_t clocks_start = clock();

	while (clock() - clocks_start < secs*CLOCKS_PER_SEC)
		;
}
void printBoard() {
	int row, col;
	for (row = 1; row <= ROWS; row++)
	{
		for (col = 1; col <= COLS; col++)
		{
			if (row == 1 || row == ROWS || col == 1 || col == COLS)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
void move() {
	char c = 'd', prevC = 'd';
	int row = ROWS / 2, col = COLS / 2;

	while (true)
	{
		gotoxy(row, col);
		printf("@");
		sleep(1);
		init();

		if (_kbhit())
			c = _getch();

		if (c != 'd' && c != 'a' && c != 'w' && c != 's')
			c = prevC;

		switch (c) {
		case 'd':
			col++;
			break;
		case 'a':
			col--;
			break;
		case 'w':
			row--;
			break;
		case 's':
			row++;
			break;
		}
		prevC = c;
	}
}

