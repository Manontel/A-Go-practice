#pragma once
#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <cstdlib>
#include <conio.h>

int board[19][19];//�����������飬�ո�Ϊ0������Ϊ1������Ϊ2
int storeboard[19][19];//���ʱ�����õ�������
int nearby_con[2][19][19];//�����ȥ����������״̬�����ڴ�����
int black_block[720][19][19];//����ֿ�
int store_black_block[720][19][19];
int bbn = 0;//����ֿ�������
int store_bbn;
int white_block[720][19][19];//����ֿ�
int store_white_block[720][19][19];
int wbn = 0;//����ֿ�������
int store_wbn;
int n;//���水�µİ�ť���
ExMessage msg;//���������Ϣ

//����Сֵ�ĺ���
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

//��������״̬
int con_single(int x, int y)
{
	if (x != 0 && y != 0 && x != 18 && y != 18)
	{
		if (board[x + 1][y] != board[x][y] && board[x][y + 1] != board[x][y] && board[x - 1][y] != board[x][y] && board[x][y - 1] != board[x][y])
		{
			if (board[x + 1][y] == 3 - board[x][y] && board[x][y + 1] == 3 - board[x][y] && board[x - 1][y] == 3 - board[x][y] && board[x][y - 1] == 3 - board[x][y])
			{
				return 3;//��ΧȫΪ�Է��������򷵻�3
			}
			return 0;//��Χ�޼������ӣ����п������򷵻�0
		}
		else
		{
			if (board[x + 1][y] != 0 && board[x][y + 1] != 0 && board[x - 1][y] != 0 && board[x][y - 1] != 0)
			{
				return 2;//��Χ�м����������޿������򷵻�2
			}
			else
			{
				return 1;//��Χ�м����������п������򷵻�1
			}
		}
	}
	if (x == 0 && y != 0)
	{
		if (board[x + 1][y] != board[x][y] && board[x][y + 1] != board[x][y] && board[x][y - 1] != board[x][y])
		{
			if (board[x + 1][y] == 3 - board[x][y] && board[x][y + 1] == 3 - board[x][y] && board[x][y - 1] == 3 - board[x][y])
			{
				return 3;//��ΧȫΪ�Է��������򷵻�3
			}
			return 0;//��Χ�޼������ӣ����п������򷵻�0
		}
		else
		{
			if (board[x + 1][y] != 0 && board[x][y + 1] != 0 && board[x][y - 1] != 0)
			{
				return 2;//��Χ�м����������޿������򷵻�2
			}
			else
			{
				return 1;//��Χ�м����������п������򷵻�1
			}
		}
	}
	if (x == 18 && y != 0)
	{
		if (board[x - 1][y] != board[x][y] && board[x][y + 1] != board[x][y] && board[x][y - 1] != board[x][y])
		{
			if (board[x - 1][y] == 3 - board[x][y] && board[x][y + 1] == 3 - board[x][y] && board[x][y - 1] == 3 - board[x][y])
			{
				return 3;//��ΧȫΪ�Է��������򷵻�3
			}
			return 0;//��Χ�޼������ӣ����п������򷵻�0
		}
		else
		{
			if (board[x - 1][y] != 0 && board[x][y + 1] != 0 && board[x][y - 1] != 0)
			{
				return 2;//��Χ�м����������޿������򷵻�2
			}
			else
			{
				return 1;//��Χ�м����������п������򷵻�1
			}
		}
	}
	if (x != 0 && y == 0)
	{
		if (board[x + 1][y] != board[x][y] && board[x][y + 1] != board[x][y] && board[x - 1][y] != board[x][y])
		{
			if (board[x + 1][y] == 3 - board[x][y] && board[x][y + 1] == 3 - board[x][y] && board[x - 1][y] == 3 - board[x][y])
			{
				return 3;//��ΧȫΪ�Է��������򷵻�3
			}
			return 0;//��Χ�޼������ӣ����п������򷵻�0
		}
		else
		{
			if (board[x + 1][y] != 0 && board[x][y + 1] != 0 && board[x - 1][y] != 0)
			{
				return 2;//��Χ�м����������޿������򷵻�2
			}
			else
			{
				return 1;//��Χ�м����������п������򷵻�1
			}
		}
	}
	if (x != 0 && y == 18)
	{
		if (board[x + 1][y] != board[x][y] && board[x][y - 1] != board[x][y] && board[x - 1][y] != board[x][y])
		{
			if (board[x + 1][y] == 3 - board[x][y] && board[x - 1][y] == 3 - board[x][y] && board[x][y - 1] == 3 - board[x][y])
			{
				return 3;//��ΧȫΪ�Է��������򷵻�3
			}
			return 0;//��Χ�޼������ӣ����п������򷵻�0
		}
		else
		{
			if (board[x + 1][y] != 0 && board[x][y - 1] != 0 && board[x - 1][y] != 0)
			{
				return 2;//��Χ�м����������޿������򷵻�2
			}
			else
			{
				return 1;//��Χ�м����������п������򷵻�1
			}
		}
	}
	if (x == 0 && y == 0)
	{
		if (board[x + 1][y] != board[x][y] && board[x][y + 1] != board[x][y])
		{
			if (board[x + 1][y] == 3 - board[x][y] && board[x][y + 1] == 3 - board[x][y])
			{
				return 3;//��ΧȫΪ�Է��������򷵻�3
			}
			return 0;//��Χ�޼������ӣ����п������򷵻�0
		}
		else
		{
			if (board[x + 1][y] != 0 && board[x][y + 1] != 0)
			{
				return 2;//��Χ�м����������޿������򷵻�2
			}
			else
			{
				return 1;//��Χ�м����������п������򷵻�1
			}
		}
	}
	if (x == 0 && y == 18)
	{
		if (board[x + 1][y] != board[x][y] && board[x][y - 1] != board[x][y])
		{
			if (board[x + 1][y] == 3 - board[x][y] && board[x][y - 1] == 3 - board[x][y])
			{
				return 3;//��ΧȫΪ�Է��������򷵻�3
			}
			return 0;//��Χ�޼������ӣ����п������򷵻�0
		}
		else
		{
			if (board[x + 1][y] != 0 && board[x][y - 1] != 0)
			{
				return 2;//��Χ�м����������޿������򷵻�2
			}
			else
			{
				return 1;//��Χ�м����������п������򷵻�1
			}
		}
	}
	if (x == 18 && y == 0)
	{
		if (board[x - 1][y] != board[x][y] && board[x][y + 1] != board[x][y])
		{
			if (board[x - 1][y] == 3 - board[x][y] && board[x][y + 1] == 3 - board[x][y])
			{
				return 3;//��ΧȫΪ�Է��������򷵻�3
			}
			return 0;//��Χ�޼������ӣ����п������򷵻�0
		}
		else
		{
			if (board[x - 1][y] != 0 && board[x][y + 1] != 0)
			{
				return 2;//��Χ�м����������޿������򷵻�2
			}
			else
			{
				return 1;//��Χ�м����������п������򷵻�1
			}
		}
	}
	if (x == 18 && y == 18)
	{
		if (board[x - 1][y] != board[x][y] && board[x][y - 1] != board[x][y])
		{
			if (board[x - 1][y] == 3 - board[x][y] && board[x][y - 1] == 3 - board[x][y])
			{
				return 3;//��ΧȫΪ�Է��������򷵻�3
			}
			return 0;//��Χ�޼������ӣ����п������򷵻�0
		}
		else
		{
			if (board[x - 1][y] != 0 && board[x][y - 1] != 0)
			{
				return 2;//��Χ�м����������޿������򷵻�2
			}
			else
			{
				return 1;//��Χ�м����������п������򷵻�1
			}
		}
	}
}

//����������ӷֿ�
void block(int x, int y)
{
	if (con_single(x, y) == 0 || con_single(x, y) == 3)//�����·ֿ�
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
	if (con_single(x, y) == 1 || con_single(x, y) == 2)//�������зֿ�
	{
		int surround[4] = { -1,-1,-1,-1 };//0����(x+1��y)��1����(x��y+1)��2����(x-1��y)��3����(x��y-1)
		if (board[x][y] == 1)//��������
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
			int re = minimum(temp[0], temp[1], temp[2], temp[3]);//���շֿ���
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
						black_block[re][m][n] = black_block[surround[i]][m][n];//���Ͻ����շֿ�
						if (surround[i] != re)
						{
							black_block[surround[i]][m][n] = 0;
						}
					}
				}
			}
			black_block[re][x][y] = 1;
		}
		if (board[x][y] == 2)//��������
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
			int re = minimum(temp[0], temp[1], temp[2], temp[3]);//���շֿ���
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
						white_block[re][m][n] = white_block[surround[i]][m][n];//���Ͻ����շֿ�
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

//��ĳһ�ֿ���м�飬�������򷵻�1�������򷵻�0
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

//��ĳһ�ֿ���м�飬�������򷵻�1�������򷵻�0
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

//�����������
void do_black()
{
	int i, m, n, p;
	for (i = 0; i < bbn; i++)//�ֿ鴦��
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

//�����������
void do_white()
{
	int i, m, n, p;
	for (i = 0; i < wbn; i++)//�ֿ鴦��
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

//����٣��޴���������1���д���������0
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

//��������
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

//��������
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

//�������н�x���궨λΪ��������
int x_piece(int a)
{
	return (a - 30) / 40;
}

//�������н�y���궨λΪ��������
int y_piece(int a)
{
	return (a - 30) / 40;
}

//ִ����Ϸ����
void game()
{
	int x, y, l, m, n, f, msg_x, msg_y;
	nearby_con[1][0][0] = -1;//�����ʼ������϶�ΪΥ����ٵĹ���
	int r = 0;
	ExMessage msg;
	initgraph(820, 820);
	srand(time(0));
	while (true)
	{
		//��������
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
			//����״̬���Ա��ڴ�����ٽ�����ָ�
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
						MessageBox(NULL, "�������ٴ����ӣ�", "��ϲ����", MB_SYSTEMMODAL);
						continue;
					}
					break;
				}
				else
				{
					//�ָ�״̬
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
		//��¼���������״̬
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
		//��������
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
			//����״̬���Ա��ڴ�����ٽ�����ָ�
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
						MessageBox(NULL, "�������ٴ����ӣ�", "��ϲ����", MB_SYSTEMMODAL);
						continue;
					}
					break;
				}
				else
				{
					//�ָ�״̬
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
		//��¼���������״̬
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

// ����һ���ṹ�壬��ʾ��ť������
struct Button
{
	int n;// ��ť�����
	int x; // ��ť�ĺ�����
	int y; // ��ť��������
	int width; // ��ť�Ŀ��
	int height; // ��ť�ĸ߶�
	COLORREF color; // ��ť����ɫ
	COLORREF hoverColor; // ��ť�������ͣ��ɫ
	COLORREF textColor; // ��ť���ı���ɫ
	const char* text; // ��ť���ı�
	int state; // ��ť��״̬
};

// ����һ����������������ť
void handleButton(Button& button)
{
	// ���ݰ�ť��״̬��ѡ��ͬ����ɫ
	if (button.state == 0)
	{
		setfillcolor(button.color); // ���������ɫ
	}
	else if (button.state == 1)
	{
		setfillcolor(button.hoverColor); // ���������ɫ
	}

	// ����һ�����Σ���Ϊ��ť�ı���
	solidrectangle(button.x, button.y, button.x + button.width, button.y + button.height);

	// �����ı�����ɫ�Ͷ��뷽ʽ
	settextcolor(button.textColor); // �����ı���ɫ
	settextstyle(40, 0, _T("����")); // �����ı���ʽ
	setbkmode(TRANSPARENT); // �����ı�����Ϊ͸��

	// �����ı�����Ϊ��ť������
	outtextxy(button.x + button.width / 9, button.y + button.height / 3.2, button.text);
}

// ����һ�������������������Ƿ��ڰ�ť��
bool isMouseOnButton(Button& button)
{
	// ��ȡ��������
	int mouseX = msg.x;
	int mouseY = msg.y;

	// �ж����������Ƿ��ڰ�ť�ķ�Χ��
	if (mouseX >= button.x && mouseX <= button.x + button.width &&
		mouseY >= button.y && mouseY <= button.y + button.height)
	{
		return true; // ����ڰ�ť��
	}
	else
	{
		return false; // ��겻�ڰ�ť��
	}
}

// ����һ���������������°�ť��״̬
void updateButtonState(Button& button)
{

	// ��ȡ���İ���״̬
	msg = getmessage(EX_MOUSE);

	// �������ڰ�ť��
	if (isMouseOnButton(button))
	{

		// �������������
		switch (msg.message)
		{
		case WM_LBUTTONDOWN:
			button.state = 2; // ���ð�ť��״̬Ϊ���
			n = button.n;// ���水ť���
			break;
		case WM_LBUTTONUP:
			button.state = 1; // ���ð�ť��״̬Ϊ��ͣ
			break;
		default:
			button.state = 1; // ���ð�ť��״̬Ϊ��ͣ
			break;
		}
	}

	// �����겻�ڰ�ť��
	else
	{
		button.state = 0; // ���ð�ť��״̬Ϊ����
	}
}
