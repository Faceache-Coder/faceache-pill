#include "������ͷ�ļ�.h"
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
		printf("��Ӯ��!!!\n");
	}
	else if (judge(board, ROW, COL) == '#')
	{
		printf("������!!!\n");
	}
	else
	{
		printf("ƽ��~~~\n");
	}
}
int main()
{
	srand((unsigned int)time(NULL));//���һ������
	int input;
	do
	{
		menu();
		printf("������0��1:");
		scanf("%d", &input);
		if (input == 1)
		{
			printf("��Ϸ��ʼ\n");
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

	} while (input != 0);
	return  0;
}