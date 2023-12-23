#pragma once
#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <cstdlib>
#include <conio.h>

int board[19][19];//定义棋盘数组，空格为0，黑棋为1，白棋为2
int storeboard[19][19];//检测时储存用的虚棋盘
int nearby_con[2][19][19];//储存过去两步的棋盘状态，用于处理打劫
int black_block[720][19][19];//黑棋分块
int store_black_block[720][19][19];
int bbn = 0;//黑棋分块数上限
int store_bbn;
int white_block[720][19][19];//白棋分块
int store_white_block[720][19][19];
int wbn = 0;//白棋分块数上限
int store_wbn;
int n;//储存按下的按钮序号
ExMessage msg;//储存鼠标信息

//求最小值的函数
int minimum(int a, int b, int c, int d)
{
	if (a <= b && a <= c && a <= d)
	{
		return a;
	}
	if (b <= a && b <= c && b <= d)
	{
		return b;
	}
	if (c <= a && c <= b && c <= d)
	{
		return c;
	}
	if (d <= a && d <= b && d <= c)
	{
		return d;
	}
}

//返回棋子状态
int con_single(int x, int y)
{
	if (x != 0 && y != 0 && x != 18 && y != 18)
	{
		if (board[x + 1][y] != board[x][y] && board[x][y + 1] != board[x][y] && board[x - 1][y] != board[x][y] && board[x][y - 1] != board[x][y])
		{
			if (board[x + 1][y] == 3 - board[x][y] && board[x][y + 1] == 3 - board[x][y] && board[x - 1][y] == 3 - board[x][y] && board[x][y - 1] == 3 - board[x][y])
			{
				return 3;//周围全为对方的棋子则返回3
			}
			return 0;//周围无己方棋子，但有空棋子则返回0
		}
		else
		{
			if (board[x + 1][y] != 0 && board[x][y + 1] != 0 && board[x - 1][y] != 0 && board[x][y - 1] != 0)
			{
				return 2;//周围有己方棋子且无空棋子则返回2
			}
			else
			{
				return 1;//周围有己方棋子且有空棋子则返回1
			}
		}
	}
	if (x == 0 && y != 0)
	{
		if (board[x + 1][y] != board[x][y] && board[x][y + 1] != board[x][y] && board[x][y - 1] != board[x][y])
		{
			if (board[x + 1][y] == 3 - board[x][y] && board[x][y + 1] == 3 - board[x][y] && board[x][y - 1] == 3 - board[x][y])
			{
				return 3;//周围全为对方的棋子则返回3
			}
			return 0;//周围无己方棋子，但有空棋子则返回0
		}
		else
		{
			if (board[x + 1][y] != 0 && board[x][y + 1] != 0 && board[x][y - 1] != 0)
			{
				return 2;//周围有己方棋子且无空棋子则返回2
			}
			else
			{
				return 1;//周围有己方棋子且有空棋子则返回1
			}
		}
	}
	if (x == 18 && y != 0)
	{
		if (board[x - 1][y] != board[x][y] && board[x][y + 1] != board[x][y] && board[x][y - 1] != board[x][y])
		{
			if (board[x - 1][y] == 3 - board[x][y] && board[x][y + 1] == 3 - board[x][y] && board[x][y - 1] == 3 - board[x][y])
			{
				return 3;//周围全为对方的棋子则返回3
			}
			return 0;//周围无己方棋子，但有空棋子则返回0
		}
		else
		{
			if (board[x - 1][y] != 0 && board[x][y + 1] != 0 && board[x][y - 1] != 0)
			{
				return 2;//周围有己方棋子且无空棋子则返回2
			}
			else
			{
				return 1;//周围有己方棋子且有空棋子则返回1
			}
		}
	}
	if (x != 0 && y == 0)
	{
		if (board[x + 1][y] != board[x][y] && board[x][y + 1] != board[x][y] && board[x - 1][y] != board[x][y])
		{
			if (board[x + 1][y] == 3 - board[x][y] && board[x][y + 1] == 3 - board[x][y] && board[x - 1][y] == 3 - board[x][y])
			{
				return 3;//周围全为对方的棋子则返回3
			}
			return 0;//周围无己方棋子，但有空棋子则返回0
		}
		else
		{
			if (board[x + 1][y] != 0 && board[x][y + 1] != 0 && board[x - 1][y] != 0)
			{
				return 2;//周围有己方棋子且无空棋子则返回2
			}
			else
			{
				return 1;//周围有己方棋子且有空棋子则返回1
			}
		}
	}
	if (x != 0 && y == 18)
	{
		if (board[x + 1][y] != board[x][y] && board[x][y - 1] != board[x][y] && board[x - 1][y] != board[x][y])
		{
			if (board[x + 1][y] == 3 - board[x][y] && board[x - 1][y] == 3 - board[x][y] && board[x][y - 1] == 3 - board[x][y])
			{
				return 3;//周围全为对方的棋子则返回3
			}
			return 0;//周围无己方棋子，但有空棋子则返回0
		}
		else
		{
			if (board[x + 1][y] != 0 && board[x][y - 1] != 0 && board[x - 1][y] != 0)
			{
				return 2;//周围有己方棋子且无空棋子则返回2
			}
			else
			{
				return 1;//周围有己方棋子且有空棋子则返回1
			}
		}
	}
	if (x == 0 && y == 0)
	{
		if (board[x + 1][y] != board[x][y] && board[x][y + 1] != board[x][y])
		{
			if (board[x + 1][y] == 3 - board[x][y] && board[x][y + 1] == 3 - board[x][y])
			{
				return 3;//周围全为对方的棋子则返回3
			}
			return 0;//周围无己方棋子，但有空棋子则返回0
		}
		else
		{
			if (board[x + 1][y] != 0 && board[x][y + 1] != 0)
			{
				return 2;//周围有己方棋子且无空棋子则返回2
			}
			else
			{
				return 1;//周围有己方棋子且有空棋子则返回1
			}
		}
	}
	if (x == 0 && y == 18)
	{
		if (board[x + 1][y] != board[x][y] && board[x][y - 1] != board[x][y])
		{
			if (board[x + 1][y] == 3 - board[x][y] && board[x][y - 1] == 3 - board[x][y])
			{
				return 3;//周围全为对方的棋子则返回3
			}
			return 0;//周围无己方棋子，但有空棋子则返回0
		}
		else
		{
			if (board[x + 1][y] != 0 && board[x][y - 1] != 0)
			{
				return 2;//周围有己方棋子且无空棋子则返回2
			}
			else
			{
				return 1;//周围有己方棋子且有空棋子则返回1
			}
		}
	}
	if (x == 18 && y == 0)
	{
		if (board[x - 1][y] != board[x][y] && board[x][y + 1] != board[x][y])
		{
			if (board[x - 1][y] == 3 - board[x][y] && board[x][y + 1] == 3 - board[x][y])
			{
				return 3;//周围全为对方的棋子则返回3
			}
			return 0;//周围无己方棋子，但有空棋子则返回0
		}
		else
		{
			if (board[x - 1][y] != 0 && board[x][y + 1] != 0)
			{
				return 2;//周围有己方棋子且无空棋子则返回2
			}
			else
			{
				return 1;//周围有己方棋子且有空棋子则返回1
			}
		}
	}
	if (x == 18 && y == 18)
	{
		if (board[x - 1][y] != board[x][y] && board[x][y - 1] != board[x][y])
		{
			if (board[x - 1][y] == 3 - board[x][y] && board[x][y - 1] == 3 - board[x][y])
			{
				return 3;//周围全为对方的棋子则返回3
			}
			return 0;//周围无己方棋子，但有空棋子则返回0
		}
		else
		{
			if (board[x - 1][y] != 0 && board[x][y - 1] != 0)
			{
				return 2;//周围有己方棋子且无空棋子则返回2
			}
			else
			{
				return 1;//周围有己方棋子且有空棋子则返回1
			}
		}
	}
}

//将填入的棋子分块
void block(int x, int y)
{
	if (con_single(x, y) == 0 || con_single(x, y) == 3)//创建新分块
	{
		if (board[x][y] == 1)
		{
			bbn++;
			black_block[bbn - 1][x][y] = 1;
		}
		if (board[x][y] == 2)
		{
			wbn++;
			white_block[wbn - 1][x][y] = 2;
		}
	}
	if (con_single(x, y) == 1 || con_single(x, y) == 2)//归入已有分块
	{
		int surround[4] = { -1,-1,-1,-1 };//0代表(x+1，y)，1代表(x，y+1)，2代表(x-1，y)，3代表(x，y-1)
		if (board[x][y] == 1)//黑棋的情况
		{
			int i, m, n, p;
			for (i = 0; i < bbn; i++)
			{
				if (black_block[i][x + 1][y] == 1)
				{
					surround[0] = i;
				}
			}
			for (i = 0; i < bbn; i++)
			{
				if (black_block[i][x][y + 1] == 1)
				{
					surround[1] = i;
				}
			}
			for (i = 0; i < bbn; i++)
			{
				if (black_block[i][x - 1][y] == 1)
				{
					surround[2] = i;
				}
			}
			for (i = 0; i < bbn; i++)
			{
				if (black_block[i][x][y - 1] == 1)
				{
					surround[3] = i;
				}
			}
			int temp[4] = { 720,720,720,720 };
			for (i = 0; i < 4; i++)
			{
				if (surround[i] > -1)
				{
					temp[i] = surround[i];
				}
			}
			int re = minimum(temp[0], temp[1], temp[2], temp[3]);//最终分块编号
			int h = 0;
			for (i = 0; i < 4; i++)
			{
				if (surround[i] == -1)
				{
					continue;
				}
				h++;
				for (m = 0; m < 19; m++)
				{
					for (n = 0; n < 19; n++)
					{
						black_block[re][m][n] = black_block[surround[i]][m][n];//整合进最终分块
						if (surround[i] != re)
						{
							black_block[surround[i]][m][n] = 0;
						}
					}
				}
			}
			black_block[re][x][y] = 1;
		}
		if (board[x][y] == 2)//白棋的情况
		{
			int i, m, n, p;
			for (i = 0; i < wbn; i++)
			{
				if (white_block[i][x + 1][y] == 2)
				{
					surround[0] = i;
				}
			}
			for (i = 0; i < wbn; i++)
			{
				if (white_block[i][x][y + 1] == 2)
				{
					surround[1] = i;
				}
			}
			for (i = 0; i < wbn; i++)
			{
				if (white_block[i][x - 1][y] == 2)
				{
					surround[2] = i;
				}
			}
			for (i = 0; i < wbn; i++)
			{
				if (white_block[i][x][y - 1] == 2)
				{
					surround[3] = i;
				}
			}
			int temp[4] = { 720,720,720,720 };
			for (i = 0; i < 4; i++)
			{
				if (surround[i] > -1)
				{
					temp[i] = surround[i];
				}
			}
			int re = minimum(temp[0], temp[1], temp[2], temp[3]);//最终分块编号
			int h = 0;
			for (i = 0; i < 4; i++)
			{
				if (surround[i] == -1)
				{
					continue;
				}
				h++;
				for (m = 0; m < 19; m++)
				{
					for (n = 0; n < 19; n++)
					{
						white_block[re][m][n] = white_block[surround[i]][m][n];//整合进最终分块
						if (surround[i] != re)
						{
							white_block[surround[i]][m][n] = 0;
						}
					}
				}
				white_block[re][x][y] = 2;
			}
		}
	}
}

//对某一分块进行检查，若有气则返回1，无气则返回0
int check_black(int i)
{
	int m, n;
	for (m = 0; m < 19; m++)
	{
		for (n = 0; n < 19; n++)
		{
			if (black_block[i][m][n] == 1)
			{
				if (con_single(m, n) == 0 || con_single(m, n) == 1)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

//对某一分块进行检查，若有气则返回1，无气则返回0
int check_white(int i)
{
	int m, n;
	for (m = 0; m < 19; m++)
	{
		for (n = 0; n < 19; n++)
		{
			if (white_block[i][m][n] == 2)
			{
				if (con_single(m, n) == 0 || con_single(m, n) == 1)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

//处理黑棋死活
void do_black()
{
	int i, m, n, p;
	for (i = 0; i < bbn; i++)//分块处理
	{
		if (check_black(i) == 0)
		{
			for (m = 0; m < 19; m++)
			{
				for (n = 0; n < 19; n++)
				{
					if (black_block[i][m][n] == 1)
					{
						board[m][n] = 0;
						black_block[i][m][n] = 0;
					}
				}
			}
		}
	}
}

//处理白棋死活
void do_white()
{
	int i, m, n, p;
	for (i = 0; i < wbn; i++)//分块处理
	{
		if (check_white(i) == 0)
		{
			for (m = 0; m < 19; m++)
			{
				for (n = 0; n < 19; n++)
				{
					if (white_block[i][m][n] == 2)
					{
						board[m][n] = 0;
						white_block[i][m][n] = 2;
					}
				}
			}
		}

	}
}

//检查打劫，无打劫情况返回1，有打劫情况返回0
int rob_check()
{
	int m, n;
	for (m = 0; m < 19; m++)
	{
		for (n = 0; n < 19; n++)
		{
			if (board[m][n] != nearby_con[1][m][n])
			{
				return 1;
			}
		}
	}
	return 0;
}

//绘制棋盘
void draw_board()
{
	setbkcolor(YELLOW);
	setlinecolor(BLACK);
	cleardevice();
	for (int i = 50; i <= 770; i += 40)
	{
		line(i, 50, i, 770);
		line(50, i, 770, i);
	}
}

//绘制棋子
void draw_piece()
{
	for (int m = 0; m < 19; m++)
	{
		for (int n = 0; n < 19; n++)
		{
			if (board[m][n] == 1)
			{
				setfillcolor(BLACK);
				fillcircle(50 + n * 40, 50 + m * 40, 20);
			}
			if (board[m][n] == 2)
			{
				setfillcolor(WHITE);
				fillcircle(50 + n * 40, 50 + m * 40, 20);
			}
		}
	}
}

//在输入中将x坐标定位为棋子坐标
int x_piece(int a)
{
	return (a - 30) / 40;
}

//在输入中将y坐标定位为棋子坐标
int y_piece(int a)
{
	return (a - 30) / 40;
}

//执行游戏内容
void game()
{
	int x, y, l, m, n, f, msg_x, msg_y;
	nearby_con[1][0][0] = -1;//避免初始情况被认定为违反打劫的规则
	int r = 0;
	ExMessage msg;
	initgraph(820, 820);
	srand(time(0));
	while (true)
	{
		//黑棋行棋
		draw_board();
		draw_piece();
		while (true)
		{
			f = 1;
			while (f)
			{
				msg = getmessage(EX_MOUSE);
				switch (msg.message)
				{
				case WM_LBUTTONDOWN:
					x = y_piece(msg.y);
					y = x_piece(msg.x);
					msg_x = msg.x;
					msg_y = msg.y;
					f = 0;
				}
			}
			//备份状态，以便在触发打劫禁入点后恢复
			for (m = 0; m < 19; m++)
			{
				for (n = 0; n < 19; n++)
				{
					storeboard[m][n] = board[m][n];
				}
			}
			for (l = 0; l < 720; l++)
			{
				for (m = 0; m < 19; m++)
				{
					for (n = 0; n < 19; n++)
					{
						store_black_block[l][m][n] = black_block[l][m][n];
					}
				}
			}
			for (l = 0; l < 720; l++)
			{
				for (m = 0; m < 19; m++)
				{
					for (n = 0; n < 19; n++)
					{
						store_white_block[l][m][n] = white_block[l][m][n];
					}
				}
			}
			store_bbn = bbn;
			store_wbn = wbn;
			if (board[x][y] != 0 || msg_x < 50 || msg_x > 770 || msg_y < 50 || msg_y > 770)
			{
				continue;
			}
			board[x][y] = 1;
			block(x, y);
			do_white();
			if (con_single(x, y) == 3)
			{
				board[x][y] = 0;
				continue;
			}
			if (con_single(x, y) != 3)
			{
				if (rob_check() == 1)
				{
					r = rand() % 100;
					if (r < 10)
					{
						draw_board();
						draw_piece();
						MessageBox(NULL, "您可以再次落子！", "恭喜您！", MB_SYSTEMMODAL);
						continue;
					}
					break;
				}
				else
				{
					//恢复状态
					for (m = 0; m < 19; m++)
					{
						for (n = 0; n < 19; n++)
						{
							board[m][n] = storeboard[m][n];
						}
					}
					for (l = 0; l < 720; l++)
					{
						for (m = 0; m < 19; m++)
						{
							for (n = 0; n < 19; n++)
							{
								black_block[l][m][n] = store_black_block[l][m][n];
							}
						}
					}
					for (l = 0; l < 720; l++)
					{
						for (m = 0; m < 19; m++)
						{
							for (n = 0; n < 19; n++)
							{
								white_block[l][m][n] = store_white_block[l][m][n];
							}
						}
					}
					bbn = store_bbn;
					wbn = store_wbn;
				}
			}
		}
		//记录最近两步的状态
		for (m = 0; m < 19; m++)
		{
			for (n = 0; n < 19; n++)
			{
				nearby_con[1][m][n] = nearby_con[0][m][n];
			}
		}
		for (m = 0; m < 19; m++)
		{
			for (n = 0; n < 19; n++)
			{
				nearby_con[0][m][n] = board[m][n];
			}
		}
		//白棋行棋
		draw_board();
		draw_piece();
		while (true)
		{
			f = 1;
			while (f)
			{
				msg = getmessage(EX_MOUSE);
				switch (msg.message)
				{
				case WM_LBUTTONDOWN:
					x = y_piece(msg.y);
					y = x_piece(msg.x);
					msg_x = msg.x;
					msg_y = msg.y;
					f = 0;
				}
			}
			//备份状态，以便在触发打劫禁入点后恢复
			for (m = 0; m < 19; m++)
			{
				for (n = 0; n < 19; n++)
				{
					storeboard[m][n] = board[m][n];
				}
			}
			for (l = 0; l < 720; l++)
			{
				for (m = 0; m < 19; m++)
				{
					for (n = 0; n < 19; n++)
					{
						store_black_block[l][m][n] = black_block[l][m][n];
					}
				}
			}
			for (l = 0; l < 720; l++)
			{
				for (m = 0; m < 19; m++)
				{
					for (n = 0; n < 19; n++)
					{
						store_white_block[l][m][n] = white_block[l][m][n];
					}
				}
			}
			store_bbn = bbn;
			store_wbn = wbn;
			if (board[x][y] != 0 || msg_x < 50 || msg_x > 770 || msg_y < 50 || msg_y > 770)
			{
				continue;
			}
			board[x][y] = 2;
			block(x, y);
			do_black();
			if (con_single(x, y) == 3)
			{
				board[x][y] = 0;
				continue;
			}
			if (con_single(x, y) != 3)
			{
				if (rob_check() == 1)
				{
					r = rand() % 100;
					if (r < 10)
					{
						draw_board();
						draw_piece();
						MessageBox(NULL, "您可以再次落子！", "恭喜您！", MB_SYSTEMMODAL);
						continue;
					}
					break;
				}
				else
				{
					//恢复状态
					for (m = 0; m < 19; m++)
					{
						for (n = 0; n < 19; n++)
						{
							board[m][n] = storeboard[m][n];
						}
					}
					for (l = 0; l < 720; l++)
					{
						for (m = 0; m < 19; m++)
						{
							for (n = 0; n < 19; n++)
							{
								black_block[l][m][n] = store_black_block[l][m][n];
							}
						}
					}
					for (l = 0; l < 720; l++)
					{
						for (m = 0; m < 19; m++)
						{
							for (n = 0; n < 19; n++)
							{
								white_block[l][m][n] = store_white_block[l][m][n];
							}
						}
					}
					bbn = store_bbn;
					wbn = store_wbn;
				}
			}
		}
		//记录最近两步的状态
		for (m = 0; m < 19; m++)
		{
			for (n = 0; n < 19; n++)
			{
				nearby_con[1][m][n] = nearby_con[0][m][n];
			}
		}
		for (m = 0; m < 19; m++)
		{
			for (n = 0; n < 19; n++)
			{
				nearby_con[0][m][n] = board[m][n];
			}
		}
	}
}

// 定义一个结构体，表示按钮的属性
struct Button
{
	int n;// 按钮的序号
	int x; // 按钮的横坐标
	int y; // 按钮的纵坐标
	int width; // 按钮的宽度
	int height; // 按钮的高度
	COLORREF color; // 按钮的颜色
	COLORREF hoverColor; // 按钮的鼠标悬停颜色
	COLORREF textColor; // 按钮的文本颜色
	const char* text; // 按钮的文本
	int state; // 按钮的状态
};

// 定义一个函数，用来处理按钮
void handleButton(Button& button)
{
	// 根据按钮的状态，选择不同的颜色
	if (button.state == 0)
	{
		setfillcolor(button.color); // 设置填充颜色
	}
	else if (button.state == 1)
	{
		setfillcolor(button.hoverColor); // 设置填充颜色
	}

	// 绘制一个矩形，作为按钮的背景
	solidrectangle(button.x, button.y, button.x + button.width, button.y + button.height);

	// 设置文本的颜色和对齐方式
	settextcolor(button.textColor); // 设置文本颜色
	settextstyle(40, 0, _T("黑体")); // 设置文本样式
	setbkmode(TRANSPARENT); // 设置文本背景为透明

	// 绘制文本，作为按钮的内容
	outtextxy(button.x + button.width / 9, button.y + button.height / 3.2, button.text);
}

// 定义一个函数，用来检测鼠标是否在按钮上
bool isMouseOnButton(Button& button)
{
	// 获取鼠标的坐标
	int mouseX = msg.x;
	int mouseY = msg.y;

	// 判断鼠标的坐标是否在按钮的范围内
	if (mouseX >= button.x && mouseX <= button.x + button.width &&
		mouseY >= button.y && mouseY <= button.y + button.height)
	{
		return true; // 鼠标在按钮上
	}
	else
	{
		return false; // 鼠标不在按钮上
	}
}

// 定义一个函数，用来更新按钮的状态
void updateButtonState(Button& button)
{

	// 获取鼠标的按键状态
	msg = getmessage(EX_MOUSE);

	// 如果鼠标在按钮上
	if (isMouseOnButton(button))
	{

		// 如果鼠标左键按下
		switch (msg.message)
		{
		case WM_LBUTTONDOWN:
			button.state = 2; // 设置按钮的状态为点击
			n = button.n;// 储存按钮序号
			break;
		case WM_LBUTTONUP:
			button.state = 1; // 设置按钮的状态为悬停
			break;
		default:
			button.state = 1; // 设置按钮的状态为悬停
			break;
		}
	}

	// 如果鼠标不在按钮上
	else
	{
		button.state = 0; // 设置按钮的状态为正常
	}
}
