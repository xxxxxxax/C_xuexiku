#include <stdio.h>

void menu_text()
{
    printf("******************************\n");
    printf("**      1.开始游戏          **\n");
    printf("**      2.退出游戏          **\n");
    printf("******************************\n");
}
int main()
{
    int input=0;
    do
    {
        menu_text();
        printf("请选择菜单:\n");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                printf("游戏开始！\n");
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