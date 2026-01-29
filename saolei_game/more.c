#include "game.h"


void menu()
{
    printf("******************************\n") ;
    printf("****** 1. Start Game  *******\n") ;
    printf("****** 0. Exit Game   *******\n") ;
    printf("******************************\n") ;
}

void game()
{
    char mine_map[ROWS][COLS]={0}; //存放布置好的雷的信息
    char show_map[ROWS][COLS]={0}; //存放排查出雷的信息

    //初始化数组的内容为指定的内容
    //mine_map数组初始化为'0'
    InitBoard(mine_map, ROWS, COLS,'0');
    //show_map数组初始化为'*'
    InitBoard(show_map, ROWS, COLS,'*');

    //DisplayBoard(mine_map,ROW,COL);
    //设置雷
    SetMine(mine_map, ROW, COL);
    DisplayBoard(show_map,ROW,COL);

    //排查雷的过程
    FindMine(mine_map, show_map, ROW, COL);
}


int main()
{
    srand((unsigned int)time(NULL));
    int input = 0;
    do
    {
        menu();
        printf("Please select:> ") ;
        scanf("%d", &input);
        switch (input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("Exit Game\n") ;
                break;
                default:
                printf("选择错误，请重新输入\n") ;
                break;
        }
    } while (input);
    
    return 0;
}