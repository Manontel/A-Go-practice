#include <iostream>
#include <cstdlib>
#include <graphics.h>
#include <Windows.h>
#include "head.h"

int main()
{
	initgraph(1200, 800);
	setbkcolor(BLACK);
	cleardevice();

	//定义所需的三个按钮
	Button button_start =
	{
		1,
		500,
		150,
		200,
		100,
		YELLOW,
		CYAN,
		BLACK,
		"开始游戏",
		0,
	};
	Button button_help =
	{
		2,
		500,
		350,
		200,
		100,
		YELLOW,
		CYAN,
		BLACK,
		"游戏帮助",
		0,
	};
	Button button_quit =
	{
		3,
		500,
		550,
		200,
		100,
		YELLOW,
		CYAN,
		BLACK,
		"退出游戏",
		0,
	};


	while (1)
	{
		//处理按钮
		handleButton(button_start);
		handleButton(button_help);
		handleButton(button_quit);

		//更新按钮状态
		updateButtonState(button_start);
		updateButtonState(button_help);
		updateButtonState(button_quit);

		//执行按钮的点击事件
		switch (n)
		{
		case 1:
			closegraph();
			game();
		case 2:
			MessageBox(NULL, "围棋是一种双人对弈的策略性棋类游戏，起源于中国，流行于东亚。围棋的棋盘是由19条横线和19条竖线相交而成的方格，共有361个交叉点。围棋的棋子是黑白两色的圆形石子，分别由两位棋手执子，轮流在棋盘的空白点上落子。围棋的目标是用自己的棋子围住对方的棋子或者空白区域，从而占有更多的领地。围棋的基本规则如下：气：每个棋子与其相邻的空点相连，形成一个气。一个棋子可以有多个气，一个气可以连接多个棋子。如果一个棋子或者一组相连的同色棋子没有气了，就会被对方提走，也就是吃子。禁入点：如果一个空点上落子会导致自己的棋子没有气，那么这个空点就是禁入点，不允许落子。但是有一种特殊情况，就是如果在这个空点上落子可以同时吃掉对方的棋子，那么这个空点就不是禁入点，而是解禁着，可以落子。打劫：如果一个空点上落子可以吃掉对方的一个棋子，而对方又可以在这个空点上落子吃回来，形成一种无限循环的情况，那么这个空点就是打劫。打劫的时候，规则规定，一方提劫后，另一方不能马上提回，必须在其他地方落子，也就是隔一手，然后才能提回。打劫的过程中，双方可以互相威胁，直到一方放弃或者解决劫争。", "规则介绍", MB_SYSTEMMODAL);
			n = 0;
			break;
		case 3:
			closegraph();
			return 0;
		default:
			break;
		}
	}
	return 0;
}