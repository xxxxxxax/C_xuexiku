#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"


void temp()
{
	printf("**************************\n");
	printf("*******1.play 0. exit*****\n");
	printf("**************************\n");

}

void game()
{
	printf("开始游戏！\n");
	char borrad[ROW][COL] = { 0 };
	char ret = 0;
	 InteBorrad(borrad, ROW, COL);
	 DisBorrad(borrad, ROW, COL);

	 while (1)
	 {
		 PlayerMore(borrad, ROW, COL);
		 DisBorrad(borrad, ROW, COL);// 新增：打印玩家落子后的最新棋盘

		 ret = IsWin(borrad, ROW, COL);
		 if (ret!='C')
		 {
			 break;
		 }
		 //DisBorrad(borrad, ROW, COL);


		 ComputerMore(borrad, ROW, COL);
		 DisBorrad(borrad, ROW, COL);
		 ret = IsWin(borrad, ROW, COL);
		 if (ret != 'C')
		 {
			 break;
		 }
	 }
	 
	 if (ret == '*')
	 {
		 printf("玩家胜利！\n");
		 fflush(stdout); // 强制刷新，确保立即显示
	 }
	 if (ret == '#')
	 {
		 printf("电脑胜利！\n");
	 }
	 if (ret == 'Q')
	 {
		 printf("平局！\n");
	 }

}
int main()
{
	srand((unsigned int)time(NULL));//设置随机数的生成起点
	int turnt = 0;
	do
	{
		temp();
		printf("请输入>:");
		scanf("%d", &turnt);
		switch (turnt)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏退出\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}


	} while (turnt);

	return 0;
}