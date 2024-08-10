#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define ROW 10
#define COL 10
#define bomb 10

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