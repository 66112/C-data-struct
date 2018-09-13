//#include "stdio.h"
//#include "stdlib.h"
//#include "time.h"
//#define MINE_COUNT 10
//#define ROW 10
//#define COL 10
//void meun()
//{
//	printf("***********************\n");
//	printf("*****    1.play   *****\n");
//	printf("*****    0.exit   *****\n");
//	printf("***********************\n");
//}
//void set_mine(char mine[ROW + 2][COL + 2], int row, int col)    //设置雷
//{
//	int count = MINE_COUNT;
//	int x, y;
//	while (count)
//	{
//		x = rand() % 10 + 1;  //产生1~10的数
//		y = rand() % 10 + 1;
//		if (mine[x][y] == '0')
//		{
//			mine[x][y] = '1';
//			count--;
//		}
//	}
//}
//void display(char board[ROW + 2][COL + 2], int row, int col)  //显示界面
//{
//	int i, j;
//	printf("    ");
//	for (i = 1; i < row - 1; i++)
//	{
//		printf("%d|", i);
//	}
//	printf("\n  --------------------------\n");
//	for (i = 1; i<row-1; i++)
//	{
//		printf("%2d|", i);
//		for (j = 1; j < col - 1; j++)
//		{
//			printf("%2c", board[i][j]);
//		}
//		printf("\n");
//	}
//}
//int get_mine_count(char mine[ROW + 2][COL + 2],int x,int y )         //统计雷的个数
//{
//	return (mine[x - 1][y - 1] - '0' + mine[x - 1][y] - '0' + mine[x - 1][y + 1] - '0' + mine[x][y - 1] - '0' + mine[x][y + 1] - '0' + mine[x + 1][y - 1] - '0' + mine[x + 1][y] - '0' + mine[x + 1][y + 1] - '0');
//}
//void play_game(char mine[ROW+2][COL+2],char board[ROW+2][COL+2])
//{
//	while (1)
//	{
//		printf("请输入坐标（x,y）：");
//		int x, y;
//		int count = 0;
//		scanf("%d%d", &x, &y);
//		if ((1 <= x&&x <= ROW) && (1 <= x&&x <= COL))
//		{
//			if (mine[x][y] == '1')
//			{
//				printf("你被炸死了！\n");
//				//display(mine, ROW + 2, COL + 2);
//				break;
//			}
//			else
//			{
//				int ret = get_mine_count(mine, x, y);
//				board[x][y] = ret + '0';      //1+'0'='1'
//				if (ret == 0)                //坐标周围没有雷，可以展开
//				{
//					board[x][y] = board[x - 1][y - 1] = board[x - 1][y] = board[x - 1][y + 1] = board[x][y - 1] =
//					board[x][y + 1] = board[x + 1][y - 1] = board[x + 1][y] = board[x + 1][y + 1] = ' ';
//				}
//				count++;
//				display(board, ROW + 2, COL + 2);
//				if (count ==MINE_COUNT)
//				{
//					printf("恭喜你！你赢了\n");
//					display(mine, ROW + 2, COL + 2);
//					break;
//				}
//			}
//		}
//		else
//			printf("输入错误！\n");
//	}
//}
//void game()
//{
//	char mine[ROW + 2][COL + 2];   //定义雷数组
//	char board[ROW + 2][COL + 2];  //定义显示数组
//	int i, j;                              //初始化
//	for (i = 0; i < ROW + 2; i++)
//	{
//		for (j = 0; j < COL + 2; j++)
//		{
//			mine[i][j] = '0';
//			board[i][j] = '*';
//		}
//	}
//	set_mine(mine, ROW + 2, COL + 2);
//	display(board, ROW + 2, COL + 2);
//	play_game(mine, board);
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned )time(NULL));
//	do
//	{
//		meun();
//		printf("请选择:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("选择错误！请重新选择。\n");
//			break;
//		}
//	} while (input);
//	system("pause");
//	return 0;
//}