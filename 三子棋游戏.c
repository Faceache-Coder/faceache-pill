#include "三子棋头文件.h"
void initboard(char board[ROW][COL], int row, int col)//清空棋盘,将二维数组每一个元素替换为空格
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for(j=0;j<col;j++)
		{
			board[i][j] = ' ';
		}
	}
}
void displayboard(char board[ROW][COL], int row, int col)//生成棋盘的格
{
	int i=0;
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
void human(char board[ROW][COL],int row,int col)
{
	printf("<<我方回合>>\n");
	int x= 0;
	int y = 0;
	while (1)
	{
		printf("请输入落子坐标:>");
		scanf("%d %d",&x,&y);
		if (x > 0 && x<=row+1 && y>0 && y<=col+1)//判断落子点是否合法
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该位置已有棋子,我方无法落子");
			}
		}
		else
		{
			printf("输入错误,请重新输入\n");
		}
	}
	displayboard(board, ROW, COL);
}
void computer(char board[ROW][COL], int row, int col)
{
	Sleep(300);//等待,使程序执行不显得突兀
	printf("<<电脑回合>>\n");
	Sleep(300);
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
	displayboard(board, ROW, COL);
}
char judge(char board[ROW][COL], int row, int col)//判断棋局状态
{
	int i = 0;
	for(i=0;i<row;i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
		return board[0][0];
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
		return board[0][i];
	if (isfull(board,ROW,COL))
		return 'a';
	return 'c';
}
int isfull(char board[ROW][COL], int row, int col)//判断棋盘上是否还有空间
{
	int i = 0;
	int j = 0;
	for(i=0;i<row;i++)
	{
	for(j=0;j<col;j++)
	{
		if (board[i][j] == ' ')
		{
			return 0;
		}
	}
	}
	return 1;
}