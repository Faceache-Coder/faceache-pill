#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define ROW 6
#define COL 6
#define bomb 6

#include <stdio.h>
#include <stdlib.h>;
#include <time.h>;
#include<windows.h>

void initboard(char board[ROW][COL], int row, int col);
void displayboard(char board[ROW][COL], int row, int col);
void player(char board[ROW][COL],char arr[ROW][COL], int row, int col);
void putbomb(char arr[ROW][COL], int row, int col);
void putnumber(char arr[ROW][COL],int row,int col);
int isbomb(char board[ROW][COL], int row,int col);