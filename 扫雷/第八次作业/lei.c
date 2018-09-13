#include "lei.h"
void meun()
{
	printf("***********************\n");
	printf("*****    1.play   *****\n");
	printf("*****    0.exit   *****\n");
	printf("***********************\n");
}
void display(char board[ROWS][COLS],int rows,int cols)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows-1; i++)
	{
		printf("%2d", i);
	}
	printf("\n---------------------\n");
	for (i = 1; i < rows-1;i++)
	{
		printf("%d|", i);
		for (j = 1; j < cols-1; j++)
	    {
			printf("%2c", board[i][j]);
		}
		printf("\n");
	}
}
int get_mine_count(char mine[ROWS][COLS], int x, int y)         //统计雷的个数
{
	return (mine[x - 1][y - 1] - '0' + mine[x - 1][y] - '0' + mine[x - 1][y + 1] - '0' + mine[x][y - 1] - '0' + mine[x][y + 1] - '0' + mine[x + 1][y - 1] - '0' + mine[x + 1][y] - '0' + mine[x + 1][y + 1] - '0');
}
void set_mine(char mine[ROWS][COLS], int rows, int cols)
{
	int count = 0;
	count = MINE_COUNT;
	int x, y;
	while (count)
	{
		x = rand() % 9 + 1; 
		y = rand() % 9 + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
int count_board(char board[ROWS][COLS], int rows, int cols)
{
	int count = 0;
	int i, j;
	for (i = 1; i < rows-1; i++)		
	{
		for (j = 1; j < cols-1; j++)
		{
			if (board[i][j] == '*')
			count++;
		}
	}
	return count;	
}
int move_board(char board[ROWS][COLS], char mine[ROWS][COLS], int x, int y)
{
	if ((1 <= x && x <= ROW) && (1 <= y && y <= COL))
	{
		int ret = get_mine_count(mine, x, y);
		if (ret == 0)
		{
			board[x][y] = ' ';
			//printf("%d,%d\n", x, y);
			if (board[x - 1][y - 1] == '*')
			{
				move_board(board, mine, x - 1, y - 1);
			}
			if (board[x - 1][y] == '*')
			{
				move_board(board, mine, x - 1, y);
			}
			if (board[x - 1][y + 1] == '*')
			{
				move_board(board, mine, x - 1, y + 1);
			}
			if (board[x][y + 1] == '*')
			{
				move_board(board, mine, x, y + 1);
			}
			if (board[x + 1][y + 1] == '*')
			{
				move_board(board, mine, x + 1, y + 1);
			}
			if (board[x + 1][y] == '*')
			{
				move_board(board, mine, x + 1, y);
			}
			if (board[x + 1][y - 1] == '*')
			{
				move_board(board, mine, x + 1, y - 1);
			}
			if (board[x][y - 1] == '*')
			{
				move_board(board, mine, x, y - 1);
			}
		}
		else
			board[x][y] = ret + '0';
	}
	return 0;
}
