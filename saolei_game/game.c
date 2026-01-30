#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
                board[i][j] = set;
           
        }
    }
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    printf("-------扫雷游戏-------\n");
    for (j = 0; j < col; j++)
    {
        printf("%d ", j);
    }
    printf("\n");

    for (i = 1; i < row; i++)
    {
        printf("%d ", i);
        for (j = 1; j < col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("-------扫雷游戏-------\n");

}


void SetMine(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT; //雷的数量
    while (count)
    {
        //随机生成雷的位置
        int x = rand() % row + 1; //1~row
        int y = rand() % col + 1; //1~col
        // if (board[x][y] == '1')
        // {
        //     continue; //已经有雷了，重新生成
        // }
        // else
        // {
        //     board[x][y] = '1'; //布置雷
        //     count--;
        // }//等价写法
        if(board[x][y]=='0')
        {
            board[x][y] = '1'; //布置雷
            count--;
        }
    }
}

// void FindMine(char mine_map[ROWS][COLS], char show_map[ROWS][COLS],int row, int col)
// {
//     int x = 0;
//     int y = 0;
//     int win = 0; //记录排查出的雷的数量
//     while (win < (row * col - EASY_COUNT))
//     {
//         printf("请输入排查雷的坐标:>");
//         scanf("%d%d", &x, &y);
//         //判断坐标是否合法
//         if (x >= 1 && x <= row && y >= 1 && y <= col)
//         {
//             //判断是否是雷
//             if (mine_map[x][y] == '1')
//             {
//                 printf("很遗憾，你被炸死了！\n");
//                 DisplayBoard(mine_map, row, col);
//                 break;
//             }
//             else
//             {
//                 //计算周围雷的数量
                
//                 int count = 0;
//                 int i = 0;
//                 int j = 0;
//                 for (i = x - 1; i <= x + 1; i++)
//                 {
//                     for (j = y - 1; j <= y + 1; j++)
//                     {
//                     可选：排除自身，不加也不影响当前项目功能
//                               if (i == x && j == y)
//                                   continue;
//                         if (mine_map[i][j] == '1')
//                         {
//                             count++;
//                         }
//                     }
//                 }
//                 show_map[x][y] = count + '0';
//                 DisplayBoard(show_map, row, col);
//                 win++;
//             }
//         }
//         else
//         {
//             printf("输入坐标非法，请重新输入！\n");
//         }
//     }
//     if (win == (row * col - EASY_COUNT))
//     {
//         printf("恭喜你，排查完所有雷，你赢了！\n");
//         DisplayBoard(mine_map, row, col);
//     }
// }



int get_mine_court(char mine_map[ROWS][COLS], int x, int y)
{
    //字符'1' - 字符'0' = 整形数字1
    //字符'0' + 整形数字1 = 字符'1'
    //字符'0'-字符'0' = 整形数字0                                                       
    return (mine_map[x-1][y]+
    mine_map[x-1][y-1]+
    mine_map[x-1][y+1]+
    mine_map[x][y-1]+
    mine_map[x][y+1]+
    mine_map[x+1][y]+
    mine_map[x+1][y-1]+
    mine_map[x+1][y+1]-8*'0');         
}

void FindMine(char mine_map[ROWS][COLS], char show_map[ROWS][COLS],int row, int col)
{
    int x = 0;
    int y = 0;
    int win = 0; //记录排查出的雷的数量
    while (win < (row * col - EASY_COUNT))
    {
        printf("请输入排查雷的坐标:>");
        scanf("%d%d", &x, &y);
        //判断坐标是否合法
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if(show_map[x][y] != '*')
            {
                printf("该位置已排查，请重新输入！\n");
                continue;
            }
            //判断是否是雷
            if (mine_map[x][y] == '1')
            {
                printf("很遗憾，你被炸死了！\n");
                DisplayBoard(mine_map, row, col);
                break;
            }
            else
            {
                //计算周围雷的数量
                int count = get_mine_court(mine_map, x, y);             
                show_map[x][y] = count + '0';
                DisplayBoard(show_map, row, col);
                win++;
            }
        }
        else
        {
            printf("输入坐标非法，请重新输入！\n");
        }
    }
    if (win == (row * col - EASY_COUNT))
    {
        printf("恭喜你，排查完所有雷，你赢了！\n");
        DisplayBoard(mine_map, row, col);
    }
}

//上述为基础功能
//下面可以添加高级功能
//1. 扩展难度选择功能
//2. 扩展排雷功能，比如标记功能
//3.当排查x,y位置周围没有雷时，自动排查其周围位置