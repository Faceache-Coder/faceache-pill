#define ROW 10
#define COL 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initboard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            board[i][j] = '.';
        }
    }
}
void walkboard(char board[ROW][COL])
{
    int r = 0;
    int c = 0;
    board[r][c] = 'A';
    int d[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
    char flag = 'B';
    do
    {
        int dir = rand() % 4;
        int nr = r + d[dir][0];
        int nc = c + d[dir][1];
        int o = 0;
        if (r > 0 && board[r - 1][c] == '.')++o;
        if (c > 0 && board[r][c - 1] == '.')++o;
        if (r < ROW - 1 && board[r + 1][c] == '.')++o;
        if (c < COL - 1 && board[r][c + 1] == '.')++o;
        if (o == 0)return;
        if (nr >= 0 && nr < ROW && nc >= 0 && nc < COL && board[nr][nc] == '.') {
            r = nr;
            c = nc;
            board[r][c] = flag;
            ++flag;
        }
    } while (flag <= 'Z');

}
void displayboard(char board[ROW][COL], int row, int col)
{
    int i, j;
    for (i = 0; i < row; ++i)
    {
        for (j = 0; j < col; ++j)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    srand((unsigned int)time(NULL));
    char board[ROW][COL];
    initboard(board, ROW, COL);
    walkboard(board);
    displayboard(board, ROW, COL);
    return 0;
}
