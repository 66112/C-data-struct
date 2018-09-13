#include "lei.h"
void play_game(char mine[ROWS][COLS], char board[ROWS][COLS])
{
	int count = 1;
	int x, y, m, n;
	int ret = 0;
	while (count == 1)
	{
		printf("���������꣨x,y����");
		scanf("%d%d", &x, &y);
		int k = 0;
		if ((1 <= x && x <= ROW) && (1 <= y && y <= COL) && (board[x][y] != ' '))
		{
			if (mine[x][y] == '1')
			{
				mine[x][y] = '0';
				while (1)
				{
					m = rand() % 9 + 1;
					n = rand() % 9 + 1;
					if (m != x && n != y && mine[m][n] == '0')
					{
						mine[m][n] = '1';
						break;
					}
				}
				int k = get_mine_count(mine, x, y);
				board[x][y] = k + '0';  //1+'0'='1'
				if (k == 0)                //������Χû���ף�����չ��
				{
					/*board[x][y] = board[x - 1][y - 1] = board[x - 1][y] = board[x - 1][y + 1] = board[x][y - 1] =
						board[x][y + 1] = board[x + 1][y - 1] = board[x + 1][y] = board[x + 1][y + 1] = ' ';*/
					move_board(board, mine, x, y);
				}
				if (MINE_COUNT == count_board(board, ROWS, COLS))
				{
					printf("��ϲ�㣡��Ӯ��\n");
					display(mine, ROWS, COLS);
					break;
				}
				display(board, ROWS, COLS);
				//display(mine, ROWS, COLS);
			}
			else
			{
				int k = get_mine_count(mine, x, y);
				board[x][y] = k + '0';      //1+'0'='1'
				if (k == 0)                //������Χû���ף�����չ��
				{
					/*board[x][y] = board[x - 1][y - 1] = board[x - 1][y] = board[x - 1][y + 1] = board[x][y - 1] =
						board[x][y + 1] = board[x + 1][y - 1] = board[x + 1][y] = board[x + 1][y + 1] = ' ';*/
					move_board(board, mine, x, y);
				}
				if (MINE_COUNT == count_board(board, ROWS, COLS))
				{
					printf("��ϲ�㣡��Ӯ��\n");
					display(mine, ROWS, COLS);
					break;
				}
				display(board, ROWS, COLS);
			}
			count++;
		}
		else
			printf("�������\n");
	}
	while (count != 1)
	{
		printf("���������꣨x,y��:>");
		int x, y;
		scanf("%d%d", &x, &y);
		if ((1 <= x&&x <= ROW) && (1 <= y&&y <= COL) && (board[x][y] != ' '))
		{
			if (mine[x][y] == '1')
			{
				printf("�㱻ը���ˣ�\n");
				display(mine, ROWS, COLS);
				break;
			}
			else
			{
				int ret = get_mine_count(mine, x, y);
				if (ret == 0)                //������Χû���ף�����չ��
				{
					/*if (board[x][y] == '*')
						board[x][y] = ' ';
					if (board[x - 1][y - 1] == '*')
						board[x - 1][y - 1] = ' ';
					if (board[x - 1][y] == '*')
						board[x - 1][y] = ' ';
					if (board[x - 1][y + 1] == '*')
						board[x - 1][y + 1] = ' ';
					if (board[x][y - 1] == '*')
						board[x][y - 1] = ' ';
					if (board[x][y + 1] == '*')
						board[x][y + 1] = ' ';
					if (board[x + 1][y - 1] == '*')
						board[x + 1][y - 1] = ' ';
					if (board[x + 1][y] == '*')
						board[x + 1][y] = ' ';
					if (board[x + 1][y + 1] == '*')
						board[x + 1][y + 1] = ' ';*/
					move_board(board, mine, x, y);
				}
				else
				{
					board[x][y] = ret + '0';
				}
				display(board, ROWS, COLS);
				if ( MINE_COUNT == count_board(board,ROWS,COLS) )
				{
					printf("��ϲ�㣡��Ӯ��\n");
					display(mine, ROWS, COLS);
					break;
				}
			}
		}
		else
			printf("�������\n");
	}
}
