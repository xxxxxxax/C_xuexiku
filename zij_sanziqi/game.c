#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"

void InteBorrad(char borrad[ROW][COL],int row,int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		int j = 0;
		for (j = 0;j < col;j++)
		{
			borrad[i][j] = ' ';
		}
	}
}

#pragma region 打印棋盘函数（固定3X3版）
//void DisBorrad(char borrad[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0;i < row;i++)
//	{
//		printf(" %c | %c | %c \n", borrad[i][0], borrad[i][1], borrad[i][2]);
//		if (i < row - 1)
//		{
//			printf("---|---|---\n");
//		}
//	}
//}
#pragma endregion  // 折叠结束标记

void DisBorrad(char borrad[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		int j = 0;
		for (j = 0;j < col;j++)
		{
			printf(" %c ",borrad[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0;j < col;j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}

			}
			printf("\n");
		}
	}
}



void PlayerMore(char borrad[ROW][COL], int row, int col)
{
	printf("玩家下棋！\n");
	int a = 0;
	int b = 0;
	printf("请输入你要下棋的坐标(行 列):>");
	scanf("%d %d", &a,&b);

	if (a >= 1 && a <= 3 && b >= 1 && b <= 3)
	{
		if (borrad[a - 1][b - 1] == ' ')
		{
			borrad[a - 1][b - 1] = '*';
		}
		else 
		{
			printf("该位置已被占用，请重新输入！\n");
			PlayerMore(borrad, ROW, COL);
		}
	}
	else
	{
		printf("输入坐标非法，请重新输入！\n");
		PlayerMore(borrad, ROW, COL);
	}
}

void ComputerMore(char borrad[ROW][COL], int row, int col)
{
	printf("电脑下棋！\n");
	int x = 0;
	int y = 0;

	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (borrad[x][y] == ' ')
		{
			borrad[x][y] = '#';
			break;
		}
	}
}



#pragma region //玩家、电脑落子函数(ai版)
//// 玩家落子函数（修复bug+优化体验）
//void PlayerMore(char borrad[ROW][COL], int row, int col)
//{
//	printf("玩家下棋！\n");
//	int a, b;
//	while (1)  // 用循环替代递归，避免栈溢出
//	{
//		printf("请输入你要下棋的坐标(行 列):>");
//		// 校验输入是否为有效数字
//		if (scanf("%d %d", &a, &b) != 2)//scanf("%d %d", &a, &b) != 2的意思是：只要没有成功读取 2 个整数，就判定为输入格式错误，需要提示用户重新输入。
//		{
//			// 清空输入缓冲区的非法字符
//			while (getchar() != '\n');
//			printf("输入格式错误！请输入两个数字（如：1 2）\n");
//			continue;
//		}
//
//		// 校验坐标范围（修复b的判断条件）
//		if (a >= 1 && a <= row && b >= 1 && b <= col)
//		{
//			// 转换为数组下标（玩家输入1-based，数组是0-based）
//			int x = a - 1;
//			int y = b - 1;
//			// 校验位置是否为空
//			if (borrad[x][y] == ' ')
//			{
//				borrad[x][y] = '*';
//				break;  // 落子成功，退出循环
//			}
//			else
//			{
//				printf("该位置已被占用，请重新输入！\n");
//			}
//		}
//		else
//		{
//			printf("输入坐标非法！请输入1-%d行、1-%d列的数字\n", row, col);
//		}
//	}
//}
//
//// 电脑落子函数（修复死循环+随机落子）
//void ComputerMore(char borrad[ROW][COL], int row, int col)
//{
//	printf("电脑下棋！\n");
//	// 设置随机数种子（只需初始化一次，建议放在main函数中）
//	static int seed_init = 0;
//	if (seed_init==0)
//	{
//		srand((unsigned int)time(NULL));//// 设置随机数种子（用当前时间作为种子）
//		seed_init = 1;//将seed_init设为1，标记“种子已初始化”
//	}
//
//	// 随机生成合法坐标，直到找到空位置
//	while (1)
//	{
//		// 生成0~row-1、0~col-1的随机下标
//		int x = rand() % row;
//		int y = rand() % col;
//		// 检查位置是否为空
//		if (borrad[x][y] == ' ')
//		{
//			borrad[x][y] = '#';
//			printf("电脑下在了：%d行 %d列\n", x + 1, y + 1);  // 提示电脑落子位置
//			break;
//		}
//	}
//}
#pragma endregion  // 折叠结束标记
// 三子棋胜负判断函数
// 形参board[ROW][COL]：棋盘数组  row/col：棋盘行列数（三子棋固定3）
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	// 1. 判断行：每一行的三个元素是否相同且不是空格
	for (i = 0; i < row; i++)
	{
		// 一行的三个元素：board[i][0]、board[i][1]、board[i][2]
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0]; // 返回获胜的棋子（X/O）
		}
	}

	// 2. 判断列：每一列的三个元素是否相同且不是空格
	// 注意：重置循环变量j=0，i也重新在循环内定义/重置
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j]; // 返回获胜的棋子（X/O）
		}
	}

	// 3. 判断两条对角线：元素相同且不是空格
	// 对角线1：左上→右下 (0,0) (1,1) (2,2)
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[1][1];
	}
	// 对角线2：右上→左下 (0,2) (1,1) (2,0) 【补充漏掉的对角线】
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[1][1];
	}

	// 4. 判断是否平局：棋盘无空格（遍历所有位置，没有' '则平局）
	int count = 0; // 统计非空格的数量
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] != ' ')
			{
				count++;
			}
		}
	}
	// 三子棋总共有row*col=9个位置，全满则平局
	if (count == row * col)
	{
		return 'Q'; // Q = Quit，平局结束
	}

	// 5. 既无人赢，棋盘也没满，继续游戏
	return 'C'; // C = Continue，继续
}

