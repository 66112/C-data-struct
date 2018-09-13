//#include "stdio.h"
//#include "time.h"
//#include "stdlib.h"
//#define ROWS 3
//#define COLS 3
//void menu()
//{
//	printf("**********************************************\n");
//	printf("**********    1.  玩家  VS 电脑   ************\n");
//	printf("**********    2.  玩家1 VS 玩家2  ************\n");
//	printf("**********    3.    退出游戏      ************\n");
//	printf("**********************************************\n");
//}
//void init_board(char board[ROWS][COLS], int rows, int cols)   //初始化函数
//{
//	int i, j;
//	for (i = 0; i < rows; i++)
//	{
//		for (j = 0; j < cols; j++)
//		{
//			board[i][j] = ' ';
//		}
//	}
//}
//void show_board(char board[ROWS][COLS], int rows, int cols)  //棋盘展开
//{
//	int i=0;
//	for (int i = 0; i < rows; i++)
//	{
//		printf("%2c|%2c|%2c\n", board[i][0], board[i][1], board[i][2]);
//		if (i != rows - 1)
//			printf("--|--|--\n");
//	}
//}
//void com_move(char board[ROWS][COLS],int rows,int cols)   //电脑走
//{
//	int x = 0, y = 0;
//	printf("电脑走:\n");
//	while (1)
//	{
//		x = rand() % rows;
//		y = rand() % cols;
//		if (board[x][y] == ' ')
//		{
//			board[x][y] = 'O';
//			return;
//		}
//	}
//}
//void player1_move(char board[ROWS][COLS], int rows, int cols)   //玩家1走
//{
//	int x = 0, y = 0;
//	while (1)
//	{
//		printf("玩家1走：");
//		printf("请输入坐标x和y:");
//		scanf("%d%d", &x, &y);
//		if (x >= 1 && x <= rows&&y >= 1 && y <= cols)
//		{
//			if (board[x - 1][y - 1] == ' ')
//			{
//				board[x - 1][y - 1] = 'X';
//				break;
//			}
//			else
//			{
//				printf("输入位置有子！请重新输入。\n");
//			}
//		}
//		else
//		{
//			printf("错误！！！请重新输入！\n");
//		}
//	}
//}
//void player2_move(char board[ROWS][COLS], int rows, int cols)     // 玩家2走
//{
//	int x = 0, y = 0;
//	while (1)
//	{
//		printf("玩家2走：");
//		printf("请输入坐标x和y:");
//		scanf("%d%d", &x, &y);
//		if (x >= 1 && x <= rows&&y >= 1 && y <= cols)
//		{
//			if (board[x - 1][y - 1] == ' ')
//			{
//				board[x - 1][y - 1] = 'X';
//				break;
//			}
//			else
//			{
//				printf("输入位置有子！请重新输入。\n");
//			}
//		}
//		else
//		{
//			printf("错误！！！请重新输入！\n");
//		}
//	}
//}
//int is_full(char board[ROWS][COLS], int rows, int cols)  //检测可以再走否
//{
//	int i, j;
//	for (i = 0; i < rows; i++)
//	{
//		for (j = 0; j < cols; j++)
//		{
//			if (board[i][j] == ' ')
//				return 0;
//		}
//	}
//	return 1;
//}
//char check_win(char board[ROWS][COLS], int rows, int cols)  //检测输赢
//{
//	int i;
//	for (i = 0; i < rows; i++)
//	{
//		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
//			return board[i][1];
//	}
//	for (i = 0; i < cols; i++)
//	{
//		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
//			return board[1][i];
//	}
//	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
//		return board[1][1];
//	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
//		return board[1][1];
//	else if (is_full(board, rows, cols))
//		return 'q';
//	return 0;
//}
//void game1()  //游戏过程
//{
//	char win = 0;
//	char board[ROWS][COLS];
//	init_board(board, ROWS, COLS);
//	do
//	{
//		com_move(board, ROWS, COLS);
//		show_board(board, ROWS, COLS);
//		win = check_win(board, ROWS, COLS);
//		if (win != 0)
//			break;
//		player1_move(board, ROWS, COLS);
//		show_board(board, ROWS, COLS);
//		win = check_win(board, ROWS, COLS);
//	} while (win == 0);
//	if (win == 'X')
//		printf("玩家胜!\n");
//	if (win == 'O')
//		printf("电脑胜！\n");
//	if (win == 'q')
//		printf("平局！ 再接再励！\n");
//}
//void game2()  //游戏过程
//{
//	char win = 0;
//	char board[ROWS][COLS];
//	init_board(board, ROWS, COLS);
//	show_board(board, ROWS, COLS);
//	do
//	{
//		player1_move(board, ROWS, COLS);
//		show_board(board, ROWS, COLS);
//		win = check_win(board, ROWS, COLS);
//		if (win != 0)
//			break;
//		player2_move(board, ROWS, COLS);
//		show_board(board, ROWS, COLS);
//		win = check_win(board, ROWS, COLS);
//	} while (win == 0);
//	if (win == 'X')
//		printf("玩家2胜!\n");
//	if (win == 'O')
//		printf("玩家1胜！\n");
//	if (win == 'q')
//		printf("平局！ 再接再励！\n");
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned)time(NULL));
//	do
//	{
//		menu();
//	    printf("请选择>:");
//	    scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game1();
//			break;
//		case 2:
//			game2();
//			break;
//		case 3:
//			break;
//		default:
//			printf("选择错误，请重新输入！\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//	#ifndef _SZQ_GAME_H_
//#define _SZQ_GAME_H_
//#include "stdio.h"
//#include "time.h"
//#include "stdlib.h"
//#define ROWS 3
//#define COLS 3
//void init_board(char board[ROWS][COLS], int rows, int cols);
//#endif 