#include "lei.h"
void game()
{
    char mine[ROWS][COLS];   //定义雷数组
	char board[ROWS][COLS];  //定义显示数组
	int i, j;                              //初始化
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			mine[i][j] = '0';
			board[i][j] = '*';
		}
	}
	display(board,ROWS,COLS);
	set_mine(mine, ROWS, COLS);
	display(mine, ROWS, COLS);
	play_game(mine,board);
}
int main()
{
	int input = 0;
    srand((unsigned )time(NULL));
	do
	{
		meun();
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("选择错误！请重新选择。\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}
