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

	//���������������ť
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
		"��ʼ��Ϸ",
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
		"��Ϸ����",
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
		"�˳���Ϸ",
		0,
	};


	while (1)
	{
		//����ť
		handleButton(button_start);
		handleButton(button_help);
		handleButton(button_quit);

		//���°�ť״̬
		updateButtonState(button_start);
		updateButtonState(button_help);
		updateButtonState(button_quit);

		//ִ�а�ť�ĵ���¼�
		switch (n)
		{
		case 1:
			closegraph();
			game();
		case 2:
			MessageBox(NULL, "Χ����һ��˫�˶��ĵĲ�����������Ϸ����Դ���й��������ڶ��ǡ�Χ�����������19�����ߺ�19�������ཻ���ɵķ��񣬹���361������㡣Χ��������Ǻڰ���ɫ��Բ��ʯ�ӣ��ֱ�����λ����ִ�ӣ����������̵Ŀհ׵������ӡ�Χ���Ŀ�������Լ�������Χס�Է������ӻ��߿հ����򣬴Ӷ�ռ�и������ء�Χ��Ļ����������£�����ÿ�������������ڵĿյ��������γ�һ������һ�����ӿ����ж������һ�����������Ӷ�����ӡ����һ�����ӻ���һ��������ͬɫ����û�����ˣ��ͻᱻ�Է����ߣ�Ҳ���ǳ��ӡ�����㣺���һ���յ������ӻᵼ���Լ�������û��������ô����յ���ǽ���㣬���������ӡ�������һ������������������������յ������ӿ���ͬʱ�Ե��Է������ӣ���ô����յ�Ͳ��ǽ���㣬���ǽ���ţ��������ӡ���٣����һ���յ������ӿ��ԳԵ��Է���һ�����ӣ����Է��ֿ���������յ������ӳԻ������γ�һ������ѭ�����������ô����յ���Ǵ�١���ٵ�ʱ�򣬹���涨��һ����ٺ���һ������������أ������������ط����ӣ�Ҳ���Ǹ�һ�֣�Ȼ�������ء���ٵĹ����У�˫�����Ի�����в��ֱ��һ���������߽��������", "�������", MB_SYSTEMMODAL);
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