#include "lei.h"
void game()
{
    char mine[ROWS][COLS];   //����������
	char board[ROWS][COLS];  //������ʾ����
	int i, j;                              //��ʼ��
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
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}
