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

//判断输赢
//玩家赢 返回*，电脑赢返回#，平局返回Q，继续游戏返回
// void IsWin(char board[ROW][COL], int row, int col)
// {
//     int i=0;
//     //判断行
//     for(i=0;i<row;i++)
//     {
//         if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
//         {
//             if(board[i][0]=='*')
//             {
//                 return '*';
//             }
//             else if(board[i][0]=='#')
//             {
//                 return '#';
//             }
//         }
//     }

//     //判断列
//     for(i=0;i<col;i++)
//     {
//         if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
//         {
//             if(board[0][i]=='*')
//             {
//                 return '*';
//             }
//             else if(board[0][i]=='#')
//             {
//                 return '#';
//             }
//         }
//     }

//     //判断对角线
//     if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
//     {
//         if(board[0][0]=='*')
//         {
//             return '*';
//         }
//         else if(board[0][0]=='#')
//         {
//             return '#';
//         }
//     }
//     if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
//     {
//         if(board[0][2]=='*')
//         {
//             return '*';
//         }
//         else if(board[0][2]=='#')
//         {
//             return '#';
//         }
//     }

//     //判断平局
//     int n=0;
//     for(i=0;i<row;i++)
//     {
//         for(n=0;n<col;n++)
//         {
//             if(board[i][n]!=' ')
//             {
//                 continue;
//             }
//             else
//             {
//                 return 'C';//继续游戏
//             }
//         }
//     }
//     return 'Q';//平局
// }



int IsFull(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0; //未满
            }
        }
    }
    return 1; //已满
}
void IsWin(char board[ROW][COL], int row, int col)
{
    //行
    int i = 0;
    for (i = 0; i < row; i++)
    {
    if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][1] != ' ')
    {
       return board[i][1];

    }
    }

    //列
    int j = 0;
    for (j = 0; j < col; j++)
    {
    if(board[0][j]==board[1][j] && board[1][j]==board[2][j] && board[1][j] != ' ')
    {
       return board[1][j];
    }

    /左对角线
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[1][1] != ' ')
    {
       return board[1][1];
    }
    //右对角线
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[1][1] != ' ')
    {
       return board[1][1];
    }
    }
    //平局
    if(IsFull(board,row,col))
    {
        return 'Q';
    }
    return 'C'; //继续游戏
}