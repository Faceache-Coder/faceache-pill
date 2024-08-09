#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define ROW 3
#define COL 3

#include <stdio.h>
#include <stdlib.h>;
#include <time.h>;
#include<windows.h>

void initboard(char board[ROW][COL], int row, int col);
void displayboard(char board[ROW][COL], int row, int col);
void human(char board[ROW][COL],int row,int col);
void computer(char board[ROW][COL], int row, int col);
char judge(char board[ROW][COL], int row, int col);
int isfull(char board[ROW][COL], int row, int col);