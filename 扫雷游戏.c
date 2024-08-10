#include "扫雷头文件.h"
void initboard(char board[ROW][COL], int row, int col)//清空棋盘,将二维数组每一个元素替换为空格
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
void displayboard(char board[ROW][COL], int row, int col)//生成棋盘的格
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
void putbomb(char arr[ROW][COL], int row, int col)//放置"炸弹"
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
			if (arr[i][j] != '#')//判断一个空周围"炸弹"的数量
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
				char num = '0' + n;//将int形式的n转化成char形式,和arr数组对应以打印该数字的字符
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
		printf("请输入坐标:");
		scanf("%d %d", &r, &c);
		if (board[r-1][c-1] == ' ')
		{
			board[r-1][c-1] = arr[r-1][c-1];
			break;
		}
		else
		{
			printf("\n该空已显示,请重新输入\n");
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