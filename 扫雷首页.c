#include "ɨ��ͷ�ļ�.h"
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
			printf("��ż,�ȵ�������~~~\n");
			break;
		}
		if (i == ROW * COL - bomb)
		{
			printf("Ү,���ŵ������еĵ���!!!\n");
			break;
		}
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