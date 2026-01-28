#include "game.h"
void menu_text()
{
    printf("******************************\n");
    printf("**      1.开始游戏          **\n");
    printf("**      2.退出游戏          **\n");
    printf("******************************\n");
}

void game_sanziqi()
{
    char ret = 0;
    printf("三子棋游戏开始！\n");
    char board[ROW][COL] = { 0 };
    //初始化棋盘
    InitBoard(board,ROW,COL);
    DisplayBoard(board,ROW,COL);

   while (1)
   {
     //玩家下棋
    PlayerMore(board,ROW,COL);
    //判断玩家是否胜利
    ret=IsWin(board,ROW,COL);
    if (ret!='C')   
    {
        break;
    }
    
    DisplayBoard(board,ROW,COL);

    //电脑下棋
    ComputerMore(board,ROW,COL);
    //判断电脑是否胜利
    ret=IsWin(board,ROW,COL);
    if (ret!='C')   
    {
        break;
    }
    DisplayBoard(board,ROW,COL);

    if(ret=='*')
        {
            printf("玩家胜利！\n");
        }
        else if(ret=='#')
        {
            printf("电脑胜利！\n");
        }
        else (ret=='Q')
        {
            printf("平局！\n");
        }
    DisplayBoard(board,ROW,COL);

   }
   
}
int main()
{
    srand((unsigned int)time(NULL));//设置随机数的生成起点

    int input=0;
    do
    {
        menu_text();
        printf("请选择菜单:\n");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                game_sanziqi();
                break;
            case 2:
                printf("退出游戏！\n");
                break;
            default:
                printf("选择错误，请重新选择！\n");
                break;
        }
    } while (input);

    
    return 0;
}