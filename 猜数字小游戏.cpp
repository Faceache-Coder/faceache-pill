#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu()
{
	printf("				\n");
	printf("	1.play		\n");
	printf("	0.exit		\n");
	printf("				\n");
}
void game()
{
	printf("开始游戏\n");
	int r=rand()%101,a,i=0;
	do
	{
		printf("输入一个0~100的整数:");
		scanf("%d", &a);
		i++;
		if (a < r)
			printf("%d有点小了!\n",a);
		else if (a > r)
			printf("%d太大了!\n",a);
		else
			printf("猜对啦!你猜了%d次\n还要继续吗?\n",i);
	} while (a != r);

}

int main() 
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入0或1:");
		scanf("%d", &input);
		if (input == 1)
		{
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

	} while (input!=0);
	return  0;
}