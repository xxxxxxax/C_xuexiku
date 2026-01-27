#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"





void InitBoard(char board[ROW][COL], int row, int col)
{
    int i =0;
    int j =0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            board[i][j]=' ';
        }
    }
}

//列无法改变的版本
// void DisplayBoard(char board[ROW][COL], int row, int col)
// {
//     int i=0;
//     for(i=0;i<row;i++)
//     {
//         printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
//         if(i<row-1)
//         {
//             printf("---|---|---\n");
//     }
// }

//行列都可以改变的版本
void DisplayBoard(char board[ROW][COL], int row, int col)
{
    int i=0;
    int j=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf(" %c ",board[i][j]);
            if(j<col-1)
            {
                printf("|");
            }
        }
        printf("\n");
        if(i<row-1)
        {
            for(j=0;j<col;j++)
            {
                printf("---");
                if(j<col-1)
                {
                    printf("|");
                }
            }
            printf("\n");
        }
    }
}

void PlayerMore(char board[ROW][COL], int row, int col)
{
    printf("玩家下棋！\n");
    int x=0;
    int y=0;
    printf("请输入你要下棋的坐标(行 列):>");
    scanf("%d %d",&x,&y);
    if(x>=1 && x<=row && y>=1 && y<=col)
    {
        if(board[x-1][y-1]==' ')
        {
            board[x-1][y-1]='*';
        }
        else
        {
            printf("该位置已被占用，请重新输入！\n");
            PlayerMore(board,row,col);
        }
    }
    else
    {
        printf("输入坐标非法，请重新输入！\n");
        PlayerMore(board,row,col);
    }
}

void ComputerMore(char board[ROW][COL], int row, int col)
{
    printf("电脑下棋！\n");
    int x=0;
    int y=0;
    while(1)
    {
        x=rand()%row;
        y=rand()%col;
        if(board[x][y]==' ')
        {
            board[x][y]='#';
            break;
        }
    }
}