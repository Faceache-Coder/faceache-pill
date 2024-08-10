#include "ɨ��ͷ�ļ�.h"
void initboard(char board[ROW][COL], int row, int col)//�������,����ά����ÿһ��Ԫ���滻Ϊ�ո�
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void displayboard(char board[ROW][COL], int row, int col)//�������̵ĸ�
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1) {
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}

}
void putbomb(char arr[ROW][COL], int row, int col)//����"ը��"
{
	int i = 0;
	for (i = 0; i < bomb; i++)
	{
		int x = rand() % row;
		int y = rand() % col;
		while (1)
		{
			int x = rand() % row;
			int y = rand() % col;
			if (arr[x][y] == ' ')
			{
				arr[x][y] = '#';
				break;
			}
		}

	}
}
void putnumber(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row;i++)
	{
		for(j=0;j<col;j++)
		{
			if (arr[i][j] != '#')//�ж�һ������Χ"ը��"������
			{
				int n = 0;
				if (arr[i - 1][j - 1] == '#')
					n++;
				if (arr[i - 1][j] == '#')
					n++;
				if (arr[i - 1][j + 1] == '#')
					n++;
				if (arr[i][j - 1] == '#')
					n++;
				if (arr[i][j + 1] == '#')
					n++;
				if (arr[i+1][j - 1] == '#')
					n++;
				if (arr[i + 1][j] == '#')
					n++;
				if (arr[i + 1][j + 1] == '#')
					n++;
				char num = '0' + n;//��int��ʽ��nת����char��ʽ,��arr�����Ӧ�Դ�ӡ�����ֵ��ַ�
				arr[i][j] =num;
		}
			
		}
	}
}
void player(char board[ROW][COL], char arr[ROW][COL], int row, int col)
{
	int r = 0;
	int c = 0;
	while (1)
	{
		printf("����������:");
		scanf("%d %d", &r, &c);
		if (board[r-1][c-1] == ' ')
		{
			board[r-1][c-1] = arr[r-1][c-1];
			break;
		}
		else
		{
			printf("\n�ÿ�����ʾ,����������\n");
		}
	}
	displayboard(board, ROW, COL);
}
int isbomb(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++) 
		{
			if (board[i][j] == "#")
			{
				return 1;
				break;
			}
			else
			{
				return 0;
			}
		}
	}

}