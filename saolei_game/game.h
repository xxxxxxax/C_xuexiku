#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2
#deefine EASY_COUNT 10

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

void DisplayBoard(char board[ROWS][COLS], int row, int col);

void SetMine(char board[ROWS][COLS], int row, int col);

void FindMine(char mine_map[ROWS][COLS], char show_map[ROWS][COLS],int row, int col);