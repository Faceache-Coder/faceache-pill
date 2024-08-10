#include "扫雷头文件.h"
void menu()
{
	printf("******************\n");
	printf("******1.play******\n");
	printf("******0.exit******\n");
	printf("******************\n");
}
void game()
{
	char arr[ROW][COL];
	char board[ROW][COL];
	int i = 0;
	initboard(arr, ROW, COL);
	initboard(board, ROW, COL);
	putbomb(arr, ROW, COL);
	putnumber(arr, ROW, COL);
	displayboard(board,ROW, COL);
	while (1) 
	{
		player(board,arr,ROW,COL);
		i++;
		if (isbomb(board, ROW, COL))
		{
			printf("啊偶,踩到地雷了~~~\n");
			break;
		}
		if (i == ROW * COL - bomb)
		{
			printf("耶,你排掉了所有的地雷!!!\n");
			break;
		}
	}
}
int main()
{
	srand((unsigned int)time(NULL));//随机一个种子
	int input;
	do
	{
		menu();
		printf("请输入0或1:");
		scanf("%d", &input);
		if (input == 1)
		{
			printf("游戏开始\n");
			game();
		}
		else if (input == 0)
		{
			printf("游戏正在退出\n");
		}
		else
		{
			printf("输入错误,请重新输入\n");
		}

	} while (input != 0);
	return  0;
}