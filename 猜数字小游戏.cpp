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
	printf("��ʼ��Ϸ\n");
	int r=rand()%101,a,i=0;
	do
	{
		printf("����һ��0~100������:");
		scanf("%d", &a);
		i++;
		if (a < r)
			printf("%d�е�С��!\n",a);
		else if (a > r)
			printf("%d̫����!\n",a);
		else
			printf("�¶���!�����%d��\n��Ҫ������?\n",i);
	} while (a != r);

}

int main() 
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("������0��1:");
		scanf("%d", &input);
		if (input == 1)
		{
			game();
		}
		else if (input == 0)
		{
			printf("��Ϸ�����˳�\n");
		}
		else
		{
			printf("�������,����������\n");
		}

	} while (input!=0);
	return  0;
}