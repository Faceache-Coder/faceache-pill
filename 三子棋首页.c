#include "三子棋头文件.h"
void menu()
{
	printf("******************\n");
	printf("******1.play******\n");
	printf("******0.exit******\n");
	printf("******************\n");
}
void game()
{
	char board[ROW][COL] = {0};
	initboard(board,ROW,COL);
	displayboard(board, ROW, COL);
	while (1)
	{
		human(board, ROW, COL);
		if (judge(board, ROW, COL) != 'c')
		{
			break;
		}
		computer(board, ROW, COL);
		if (judge(board,ROW,COL) != 'c')
		{
			break;
		}
	}
	if (judge(board, ROW, COL) == '*')
	{
		printf("你赢啦!!!\n");
	}
	else if (judge(board, ROW, COL) == '#')
	{
		printf("你输啦!!!\n");
	}
	else
	{
		printf("平局~~~\n");
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