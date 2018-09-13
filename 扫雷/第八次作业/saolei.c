//#include "stdio.h"
//#include "stdlib.h"
//#include "time.h"
//#define ROW 10
//#define COL 10
//void meun()
//{
//	printf("***********************\n");
//	printf("*****    1.play   *****\n");
//	printf("*****    0.exit   *****\n");
//	printf("***********************\n");
//}
//void meun1()
//{
//	printf("***********************\n");
//	printf("*****    1.easy   *****\n");
//	printf("*****    2.hard   *****\n");
//	printf("*****    0.exit   *****\n");
//	printf("***********************\n");
//}
//void choice_diffculty()
//{
//	void game1();
//	void game2();
//	int input = 0;
//	do
//	{
//		meun1();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game1();
//			break;
//		case 2:
//			game2();
//			break;
//		case 0:
//			break;
//		default:
//			printf("输入无效！请重新选择!");
//			break;
//		}
//	} while (input);
//}
//void display(char board[ROW+2][COL+2], int row,int col)
//{
//	int i=0;
//	int j = 0;
//	for (i = 0; i <col-1; i++)
//	{
//		printf("%2d", i);
//	}
//	printf("\n");
//	for (i = 1; i < row - 1;i++)
//	{
//		printf("%2d", i);
//		for (j = 1; j < col - 1; j++)
//		{
//			printf("%2c", board[i][j]);
//		}
//		printf("\n");
//	}
//}  
//void set_mine(char mine[ROW + 2][COL + 2], int row, int col, int Mine_count)
//{
//	int x, y;
//	int count = Mine_count;
//	while (count)
//	{
//		x = rand() % 10 + 1;
//		y = rand() % 10 + 1;
//		if (mine[x][y] == '0')
//		{
//			mine[x][y] = '1';
//			count--;
//		}
//	}
//}
//int get_mine_count(char mine[ROW + 2][COL + 2], int x, int y)
//{
//	return (mine[x - 1][y - 1] - '0' + mine[x - 1][y] - '0' + mine[x - 1][y + 1] - '0' + mine[x][y - 1] - '0'
//		+ mine[x][y + 1] - '0' + mine[x + 1][y - 1] - '0' + mine[x + 1][y] - '0' + mine[x + 1][y + 1] - '0');
//}
//void move_mine(char mine[ROW][COL],char board[ROW][COL],int x, int y)
//{
//	int i = x, j = y;
//	while (1)
//	{
//		int x = rand() % ROW + 1;
//		int y = rand() % COL + 1;
//		if (mine[x][y] == '0')
//		{
//			mine[x][y] = '1';
//			break;
//		}
//	}
//	int ret = get_mine_count(mine, i, j);
//	if (ret == 0)
//	{
//		board[i][j] = board[i - 1][j - 1] = board[i - 1][j] = board[i - 1][j + 1] = board[i][j - 1] =
//			board[i][j + 1] = board[i + 1][j - 1] = board[i + 1][j + 1] = board[i + 1][j] = ' ';
//		display(board, ROW + 2, COL + 2);
//		display(mine, ROW + 2, COL + 2);
//	}
//	else
//	{
//		board[i][j] = ret + '0';
//		display(board, ROW + 2, COL + 2);
//		display(mine, ROW + 2, COL + 2);
//	}
//}
//int count_board(char board[ROW][COL], int row, int col)
//{
//	int count = 0;
//	int i, j;
//	for (i = 1; i < row-1; i++)
//	{
//		for (j = 1; j < col-1; j++)
//		{
//			if (board[i][j] == '*')
//				count++;
//		}
//	}
//	return count;
//}
//void play_game(char board[ROW + 2][COL + 2], char mine[ROW + 2][COL + 2],int Mine_count)
//{
//	int x, y;
//	printf("请输入坐标（x,y）:>");
//	scanf("%d%d", &x, &y);
//	if (mine[x][y] == '1')
//	{
//		move_mine(mine,board,x,y);
//	}
//	while (1)
//	{
//		printf("请输入坐标（x,y）:>");
//		scanf("%d%d", &x, &y);
//		if ((x <= ROW&&x >= 1) && (y <= COL&&y >= 1))
//		{
//			if (mine[x][y] == '1')
//			{
//				printf("你被炸死了！\n");
//				display(mine, ROW + 2, COL + 2);
//				break;
//			}
//			else
//			{
//				int ret = get_mine_count(mine, x, y);
//				if (ret == 0)
//				{
//					board[x][y] = board[x - 1][y - 1] = board[x - 1][y] = board[x - 1][y + 1] = board[x][y - 1] =
//					board[x][y + 1] = board[x + 1][y - 1] = board[x + 1][y + 1] = board[x + 1][y] = ' ';
//					display(board, ROW + 2, COL + 2);
//					display(mine, ROW + 2, COL + 2);
//				}
//				else
//				{
//					board[x][y] = ret + '0';
//					display(board, ROW + 2, COL + 2);
//					display(mine, ROW + 2, COL + 2);
//				}
//			}
//			if (Mine_count == count_board(board, ROW + 2, COL + 2))
//			{
//				printf("你赢了！\n");
//				break;
//			}
//		}
//		else
//			printf("输入错误！\n");
//	}
//}
//void game1()
//{
//	int x, y;
//	int Mine_count = 1;
//	char board[ROW + 2][COL + 2];
//	char mine[ROW + 2][COL + 2];
//	int i, j;
//	for (i = 0; i < ROW +2; i++)
//	{
//		for (j = 0; j < COL +2; j++)
//		{
//			mine[i][j] = '0';
//			board[i][j] = '*';
//		}
//	}
//	display(board,ROW+2,COL+2);
//	set_mine(mine, ROW + 2, COL + 2, Mine_count);
//	display(mine, ROW + 2, COL + 2);
//	printf("----------------------------\n");
//	play_game(board, mine,Mine_count);
//}
//void game2()
//{
//	int Mine_count = 99;
//	int x, y;
//	char board[ROW + 2][COL + 2];
//	char mine[ROW + 2][COL + 2];
//	int i, j;
//	for (i = 0; i < ROW + 2; i++)
//	{
//		for (j = 0; j < COL + 2; j++)
//		{
//			mine[i][j] = '0';
//			board[i][j] = '*';
//		}
//	}
//	display(board, ROW + 2, COL + 2);
//	set_mine(mine, ROW + 2, COL + 2, Mine_count);
//	display(mine, ROW + 2, COL + 2);
//	printf("----------------------------\n");
//	play_game(board, mine,Mine_count);
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		meun();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			choice_diffculty();
//			break; 
//		case 0:
//			break;
//		default:
//			printf("输入无效！请重新选择!");
//			break;
//		}
//	} while (input);
//	return 0;
//}
