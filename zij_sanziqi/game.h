#pragma once	
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3


void InteBorrad(char borrad[ROW][COL], int row, int col);

void DisBorrad(char borrad[ROW][COL], int row, int col);

void PlayerMore(char borrad[ROW][COL], int row, int col);

void ComputerMore(char borrad[ROW][COL], int row, int col);

//判断输赢
//玩家赢 返回*，电脑赢返回#，平局返回Q，继续游戏返回C
char IsWin(char board[ROW][COL], int row, int col);







