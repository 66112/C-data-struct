//#include "stdio.h"
//int main()
//{
//	int h = 0;
//	printf("ÊäÈëÐÐÊý:");
//	scanf("%d", &h);
//	int a[20][20] = { 1 };
//	int i, j;
//	for (i = 0; i < h; i++)
//	{
//		a[i][0] = 1;
//		a[i][i] = 1;
//		for (j = 1; j < i; j++)
//		{
//			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
//		}
//	}
//	for (i = 0; i < h; i++)
//	{
//		for (j = 0; j < h - i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j <= i; j++)
//		{
//			printf("%2d", a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}