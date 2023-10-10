#define _CRT_SECURE_NO_WARNINGS
#define BOARD_SIZE 15
#include <easyx.h>
#include <graphics.h>
#include <stdio.h>
#include <string.h>
#include <mmsystem.h>;
#pragma comment(lib,"winmm.lib") 
int flag = 0;
int token = 0;
int a = 0;
int musicb = 0;
int musica = 1;
char board[15][15];
int x, y, i, j, ret1;
void button1(int x, int y, int w, int z, const char* text);//按钮选项
void button2(int x, int y, int w, int z, const char* text);//按钮选项
void gamepage();//五子棋游戏页面
void menu();//开始页面
void quitpage();//退出游戏页面
void game1();//正常游戏页面
void game2();//道具模式页面
void playwaypage();//游玩方式详细
void optionpage();//设置页面详细
void gameinfo();//游戏玩法介绍……
void overpage();//结束页面
void clearchess();//复制棋盘
int check_win(int x, int y, char color);//输赢判断
void drawboard();//打印棋盘
void remove();//消除功能
void gamemaker();//制作者名单
void background();//背景装饰
void gameintroduce();//游玩介绍页面
void circlelabel(int x, int y, int r, const char* text);
void Rectangularlabel(int x, int y, int w, int h, const char* text);
void destroy();//销毁功能
void musictexiao1();//音效功能
void musictexiao2();
void musictexiao3();
int check_tri(int x, int y, char color);//三子连接判断
void musicplaybr(void);

void refreshColor();//皮肤颜色选择
int main()
{
	int musicb = 0;
	musicplaybr();
	menu();
}//主函数
void button1(int x, int y, int w, int h, const char* text) {
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	setfillcolor(RGB(190, 170, 200));
	fillroundrect(x, y, x + w, y + h, 10, 10);
	settextstyle(30, 0, "楷体");
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);

}
void button2(int x, int y, int w, int h, const char* text)
{
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	setfillcolor(RGB(140, 180, 120));
	fillroundrect(x, y, x + w, y + h, 10, 10);
	settextstyle(30, 0, "楷体");
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}
void gamepage()
{
	initgraph(1000, 800);//初始化绘图窗口
	setbkcolor(YELLOW);//绘图背景色
	cleardevice();//使用当前背景色清空上一个绘图
	setlinecolor(BLACK);//设置当前设备画线颜色
	for (int i = 50; i <= 750; i += 50)//画棋盘
	{
		line(i + 100, 50, i + 100, 750);
		line(150, i, 850, i);
	}
	if (token == 0)
	{
		game1();

	}
	if (token == 1)
	{
		game2();
	}
}
void game1()//正常模式
{
	for (i = 1; i <= 15; i++)
	{
		for (j = 1; j <= 15; j++)
		{
			board[i][j] = 'a';
		}
	}
	button1(870, 200, 130, 50, "清空棋盘");
	button1(870, 400, 130, 50, "返回页面");
	ExMessage m;
	int x, y, ret1;
	int a = 0;
	while (1)
	{
		m = getmessage(EX_MOUSE | EX_KEY);
		if (m.x <= 1000 && m.y <= 270 && m.x >= 850 && m.y >= 180 && m.message == WM_LBUTTONDOWN)
		{

			cleardevice();
			for (i = 1; i <= 15; i++)
			{
				for (j = 1; j <= 15; j++)
				{
					board[i][j] = 'a';
				}
			}
			for (int i = 50; i <= 750; i += 50)//画棋盘
			{
				line(i + 100, 50, i + 100, 750);
				line(150, i, 850, i);
			}

			button1(870, 200, 130, 50, "清空棋盘");
			button1(870, 400, 130, 50, "返回页面");

		}
		if (m.x <= 1000 && m.y <= 470 && m.x >= 850 && m.y >= 380 && m.message == WM_LBUTTONDOWN)
		{

			break;
		}
		if (m.x <= 875 && m.y <= 775 && m.x >= 130 && m.y >= 25)
		{
			x = m.x % 50;
			y = m.y % 50;
			if (x >= 25)
				m.x = m.x - x + 50;
			else
				m.x = m.x - x;
			if (y >= 25)
				m.y = m.y - y + 50;
			else
				m.y = m.y - y;
			i = m.x / 50 - 2;
			j = m.y / 50;
			if (m.message == WM_LBUTTONDOWN)
			{
				if (a % 2 == 0 && board[i][j] != 'B' && board[i][j] != 'W')
				{
					setfillcolor(BLACK);

					a++;
					board[i][j] = 'B';
					fillcircle(m.x, m.y, 20);
					ret1 = check_win(i, j, 'B');
					if (musica == 1)
						musictexiao1();

				}
				else if (a % 2 != 0 && board[i][j] != 'B' && board[i][j] != 'W')
				{
					setfillcolor(WHITE);
					a++;
					board[i][j] = 'W';
					fillcircle(m.x, m.y, 20);
					ret1 = check_win(i, j, 'W');
					if (musica == 1)
						musictexiao2();

				}
				if (ret1 == 1)
				{
					Sleep(100);
					flag = 5;

					break;
				}

			}

		}

	}

}
void quitpage()
{
	closegraph();
	exit(0);
}
void playwaypage()//游玩方式页面
{

	setbkcolor(RGB(180, 180, 180));
	cleardevice();
	background();
	setfillcolor(BLACK);
	settextcolor(BLACK);
	settextstyle(40, 0, "楷体");
	button2(163, 250, 270, 40, "正常模式");
	button2(163, 500, 270, 40, "道具模式");
	if (token == 1)
		rectangle(163, 250, 433, 290);
	ExMessage m;
	while (1)
	{
		if (peekmessage(&m, EX_MOUSE))
		{
			if (m.x >= 163 && m.x <= 433 && m.y >= 250 && m.y <= 290)
			{
				if (m.message == WM_LBUTTONDOWN)
				{
					token = 0;
					break;//正常
				}
			}
			if (m.x >= 163 && m.x <= 433 && m.y >= 500 && m.y <= 540)
			{
				if (m.message == WM_LBUTTONDOWN)
				{
					token = 1;

					break;//道具
				}
			}
			switch (m.message)
			{
			case WM_MOUSEMOVE:
				printf("%d %d\n", m.x, m.y);
				if (flag == 0 && m.x >= 153 && m.x <= 453 && m.y >= 500 && m.y <= 500 + 40)//背景

				{
					setlinecolor(BLACK);
					setlinestyle(PS_SOLID, 3);
					rectangle(163, 500, 433, 540);
				}

				else if (flag == 0 && m.x >= 163 && m.x <= 433 && m.y >= 250 && m.y <= 250 + 40)//音效设置
				{
					setlinecolor(BLACK);
					setlinestyle(PS_SOLID, 3);
					rectangle(163, 250, 433, 290);
				}
				else
				{
					if (flag == 0) //未触发为……框，其余为……框
					{
						setlinecolor(WHITE);
						setlinestyle(PS_SOLID, 3);
						rectangle(163, 500, 433, 540);
						rectangle(163, 250, 433, 290);

					}
				}

				break;
			}
		}
	}
}
void optionpage()//设置页面（背景，音效，地图选择，关于我们）
{
	flag = 0;
	setbkcolor(RGB(180, 180, 180));
	cleardevice();
	setfillcolor(BLACK);
	settextcolor(BLACK);
	settextstyle(60, 0, "宋体");
	outtextxy(230, 60, "设置");
	setlinecolor(RED);
	button2(163, 200, 270, 40, "音效：");
	button2(163, 350, 270, 40, "背景音乐：");
	button2(163, 500, 270, 40, "地图选择");
	button2(163, 650, 270, 40, "关于我们");
	outtextxy(45, 40, "返回");
	ExMessage m;
	//接受鼠标消息
	int c = 0, d = 0;
	while (true)
	{
		if (peekmessage(&m, EX_MOUSE)) {
			if (flag == 0 && m.x >= 30 && m.x <= 130 && m.y >= 20 && m.y <= 90 && m.message == WM_LBUTTONDOWN)
			{
				printf("测试成功");
				break;
			}
			switch (m.message)
			{
			case WM_MOUSEMOVE:
				printf("%d %d\n", m.x, m.y);
				if (flag == 0 && m.x >= 153 && m.x <= 453 && m.y >= 500 && m.y <= 500 + 40)//背景

				{
					setlinecolor(BLACK);
					setlinestyle(PS_SOLID, 3);
					rectangle(163, 500, 433, 540);
				}

				else if (flag == 0 && m.x >= 163 && m.x <= 433 && m.y >= 200 && m.y <= 200 + 40)//音效设置
				{
					setlinecolor(BLACK);
					setlinestyle(PS_SOLID, 3);
					rectangle(163, 200, 433, 240);
				}

				else if (flag == 0 && m.x >= 163 && m.x <= 430 && m.y >= 350 && m.y <= 350 + 40)//地图选择
				{
					setlinecolor(BLACK);
					setlinestyle(PS_SOLID, 3);
					rectangle(163, 350, 433, 390);
				}
				else if (flag == 0 && m.x >= 163 && m.x <= 433 && m.y >= 650 && m.y <= 690)//关于我们
				{
					setlinecolor(BLACK);
					setlinestyle(PS_SOLID, 3);
					rectangle(163, 650, 433, 690);
				}
				else if (flag == 0 && m.x >= 30 && m.x <= 130 && m.y >= 20 && m.y <= 90)
				{
					setlinecolor(BLACK);
					setlinestyle(PS_SOLID, 3);
					rectangle(40, 30, 110, 75);
				}
				else
				{
					if (flag == 0) //未触发为……框，其余为……框
					{
						setlinecolor(WHITE);
						setlinestyle(PS_SOLID, 3);
						rectangle(163, 500, 433, 540);
						rectangle(163, 200, 433, 240);
						rectangle(163, 350, 433, 390);
						rectangle(163, 650, 433, 690);
						rectangle(40, 30, 110, 75);
					}
				}

				break;
			case WM_LBUTTONDOWN:
				if (flag == 0 && m.x >= 153 && m.x <= 433 && m.y >= 500 && m.y <= 500 + 40)
				{


				}

				else  if (flag == 0 && m.x >= 163 && m.x <= 433 && m.y >= 200 && m.y <= 200 + 40)
				{
					if (d % 2 == 0)
					{
						button2(163, 200, 270, 40, "音效：关");
						d++;
						musica = 0;
						continue;
					}
					if (d % 2 != 0)
					{
						button2(163, 200, 270, 40, "音效：开");
						d++;
						musica = 1;
						continue;

					}

				}

				else if (m.x >= 160 && m.x <= 430 && m.y >= 350 && m.y <= 350 + 40)
				{

					if (c % 2 == 0)
					{
						button2(163, 350, 270, 40, "背景音乐：关");
						c++;
						mciSendString("stop aaa", NULL, 0, NULL);
						continue;
					}
					if (c % 2 != 0)
					{
						button2(163, 350, 270, 40, "背景音乐：开");
						c++;
						mciSendString("play aaa", 0, 0, 0);//继续播放
						continue;

					}


				}
				else if (flag == 0 && m.x >= 163 && m.x <= 433 && m.y >= 650 && m.y <= 650 + 40)
				{
					flag = 1;
					gamemaker();
				}

				break;
			}
		}
	}
}
void gameinfo()
{
	setbkcolor(RGB(180, 180, 180));
	cleardevice();
	setfillcolor(BLACK);
	button2(190, 600, 200, 60, "返回页面");
	settextcolor(BLACK);
	settextstyle(40, 0, "楷体");
	outtextxy(200, 5, "游玩介绍");
	gameintroduce();
	ExMessage m;
	while (1)//各种功能的实现
	{
		if (peekmessage(&m, EX_MOUSE))
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				if (m.x >= 190 && m.x <= 390 && m.y >= 600 && m.y <= 660)
				{
					flag = 0;
					break;
				}
			}
		}
	}
}
void menu()
{
start_game:;//仅针对game1
	initgraph(600, 800);
start:;
	int  flag = 0;//初始值
	//mciSendString("open ./bk.mp3 ", 0, 0, 0);
	//mciSendString("play ./bk.mp3 repeat ", 0, 0, 0);
	if (flag == 0)
	{
	
		setbkcolor(RGB(200, 140, 20));
		cleardevice();
		background();
		button1(163, 500, 270, 40, "开始游戏");
		button1(163, 200, 270, 40, "设置页面");
		button1(163, 350, 270, 40, "游玩说明");
		button1(163, 650, 270, 40, "退出游戏");
		settextstyle(50, 0, "楷体");
		settextcolor(RGB(200, 240, 150));
		outtextxy(173, 50, "千宁五子棋");
	}
option:;
	if (flag == 1)//1为设置页面
	{
		setbkcolor(RGB(120, 160, 40));
		cleardevice();
		optionpage();
		goto start;
	}
playway:;
	if (flag == 2)//2为游玩说明页面
	{
		setbkcolor(RGB(10, 150, 100));
		cleardevice();
		gameinfo();
		goto start;
	}
game:;
	if (flag == 3)//3为游戏页面
	{
		playwaypage();//游戏选择
		gamepage();
		flag = 5;
		goto over;//返回初始页面
	}
quit:;
	if (flag == 4)//4为退出游戏页面
	{
		quitpage();
		goto start;//返回初始页面
	}
over:;
	if (flag == 5)
	{
		musictexiao3();
		overpage();
		flag = 0;
		goto start_game;
	}
	Sleep(200);
	ExMessage m;
	//接受鼠标消息
	while (true)
	{
		if (peekmessage(&m, EX_MOUSE)) {
			switch (m.message)
			{
			case WM_MOUSEMOVE:
				//开始游戏
				printf("%d %d\n", m.x, m.y);
				if (flag == 0 && m.x >= 153 && m.x <= 453 && m.y >= 500 && m.y <= 500 + 40)//开始游戏按钮框
				{
					setlinecolor(WHITE);
					setlinestyle(PS_SOLID, 3);
					rectangle(163, 500, 433, 540);
				}
				//设置
				else if (flag == 0 && m.x >= 163 && m.x <= 433 && m.y >= 200 && m.y <= 200 + 40)//设置页面按钮框
				{
					setlinecolor(WHITE);
					setlinestyle(PS_SOLID, 3);
					rectangle(163, 200, 433, 240);
				}
				//游玩方式
				else if (flag == 0 && m.x >= 163 && m.x <= 430 && m.y >= 350 && m.y <= 350 + 40)//游玩方式框
				{
					setlinecolor(WHITE);
					setlinestyle(PS_SOLID, 3);
					rectangle(163, 350, 433, 390);
				}
				else if (flag == 0 && m.x >= 163 && m.x <= 433 && m.y >= 650 && m.y <= 690)//退出游戏页面
				{
					setlinecolor(WHITE);
					setlinestyle(PS_SOLID, 3);
					rectangle(163, 650, 433, 690);
				}
				else
				{
					if (flag == 0) //未触发为……框，其余为……框
					{
						setlinecolor(BLACK);
						setlinestyle(PS_SOLID, 3);
						rectangle(163, 500, 433, 540);
						rectangle(163, 200, 433, 240);
						rectangle(163, 350, 433, 390);
						rectangle(163, 650, 433, 690);
					}
				}

				break;
			case WM_LBUTTONDOWN://开始游戏页面进入
				if (flag == 0 && m.x >= 153 && m.x <= 433 && m.y >= 500 && m.y <= 500 + 40)
				{
					Sleep(300);
					//mciSendString("close ./bk.mp3", 0, 0, 0);
					flag = 3;
					goto game;
				}
				//设置页面进入
				else  if (flag == 0 && m.x >= 163 && m.x <= 433 && m.y >= 200 && m.y <= 200 + 40)
				{
					printf("进入设置页面");
					flag = 1;
					goto option;//跳转到设置页面
				}
				//游玩方式页面进入
				else if (m.x >= 160 && m.x <= 430 && m.y >= 350 && m.y <= 350 + 40)
				{
					//游玩方式函数实现
					flag = 2;
					goto playway;//跳转规则介绍
				}
				else if (flag == 0 && m.x >= 163 && m.x <= 433 && m.y >= 650 && m.y <= 650 + 40)//退出游戏页面
				{
					flag = 4;
					goto quit;
				}

				break;
			}
		}
	}
	getchar();
	closegraph();
}
void overpage()
{
	initgraph(300, 400);
	setbkcolor(WHITE);
	cleardevice();
	button1(75, 120, 150, 50, "再来一局");
	button1(75, 220, 150, 50, "退出游戏");
	ExMessage m;
	while (1)
	{
		if (peekmessage(&m, EX_MOUSE))
		{
			if (m.x <= 220 && m.x >= 75 && m.y <= 170 && m.y >= 120)
			{
				if (m.message == WM_LBUTTONDOWN)
				{
					break;//正常
				}
			}
			if (m.x <= 225 && m.x >= 75 && m.y <= 270 && m.y >= 220)
			{
				if (m.message == WM_LBUTTONDOWN) {
					closegraph(); // 关闭绘图窗口
					exit(0);    //强制退出
				}
			}
		}
	}

}
void clearchess()//复制棋盘
{


	for (int i = 1; i <= 15; i++)
	{
		for (int j = 1; j <= 15; j++)
		{
			if (board[i][j] == 'B')
			{
				setfillcolor(BLACK);
				fillcircle((i) * 50, j * 50, 20);
			}
			if (board[i][j] == 'W')
			{
				setfillcolor(WHITE);
				fillcircle((i) * 50, j * 50, 20);
			}
		}


	}

}
int check_win(int x, int y, char color)//五子棋判断
{
	// 检查横向是否有五个连续的棋子
	int count = 0;

	for (int i = x; i >= 0; i--) {
		if (board[i][y] != color)
		{
			break;
		}
		count++;
	}
	for (int i = x + 1; i < BOARD_SIZE; i++) {
		if (board[i][j] != color) {
			break;
		}
		count++;
	}
	if (count >= 5) {
		return 1;
	}

	// 检查竖向是否有五个连续的棋子
	count = 0;
	for (int j = y; j >= 0; j--) {
		if (board[x][j] != color) {
			break;
		}
		count++;
	}
	for (int j = y + 1; j < BOARD_SIZE; j++) {
		if (board[x][j] != color) {
			break;
		}
		count++;
	}
	if (count >= 5) {
		return 1;
	}

	// 检查左上 - 右下斜向是否有五个连续的棋子
	count = 0;
	for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j] != color) {
			break;
		}
		count++;
	}
	for (int i = x + 1, j = y + 1; i < BOARD_SIZE && j < BOARD_SIZE; i++, j++) {
		if (board[i][j] != color) {
			break;
		}
		count++;
	}
	if (count >= 5) {
		return 1;
	}

	// 检查左下 - 右上斜向是否有五个连续的棋子
	count = 0;
	for (int i = x, j = y; i < BOARD_SIZE && j >= 0; i++, j--) {
		if (board[i][j] != color) {
			break;
		}
		count++;
	}
	for (int i = x - 1, j = y + 1; i >= 0 && j < BOARD_SIZE; i--, j++)
	{
		if (board[i][j] != color)
		{
			break;
		}
		count++;
	}
	if (count >= 5) {
		return 1;
	}
}
int check_tri(int x, int y, char color)//五子棋判断
{
	// 检查横向是否有五个连续的棋子
	int count = 0;

	for (int i = x; i >= 0; i--) {
		if (board[i][y] != color) {
			break;
		}
		count++;
	}
	for (int i = x + 1; i < BOARD_SIZE; i++) {
		if (board[i][j] != color) {
			break;
		}
		count++;
	}
	if (count >= 3) {
		return 2;
	}

	// 检查竖向是否有五个连续的棋子
	count = 0;
	for (int j = y; j >= 0; j--) {
		if (board[x][j] != color) {
			break;
		}
		count++;
	}
	for (int j = y + 1; j < BOARD_SIZE; j++) {
		if (board[x][j] != color) {
			break;
		}
		count++;
	}
	if (count >= 3) {
		return 2;
	}

	// 检查左上 - 右下斜向是否有五个连续的棋子
	count = 0;
	for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j] != color) {
			break;
		}
		count++;
	}
	for (int i = x + 1, j = y + 1; i < BOARD_SIZE && j < BOARD_SIZE; i++, j++) {
		if (board[i][j] != color) {
			break;
		}
		count++;
	}
	if (count >= 3) {
		return 2;
	}

	// 检查左下 - 右上斜向是否有五个连续的棋子
	count = 0;
	for (int i = x, j = y; i < BOARD_SIZE && j >= 0; i++, j--) {
		if (board[i][j] != color) {
			break;
		}
		count++;
	}
	for (int i = x - 1, j = y + 1; i >= 0 && j < BOARD_SIZE; i--, j++)
	{
		if (board[i][j] != color)
		{
			break;
		}
		count++;
	}
	if (count >= 3) {
		return 2;
	}
}

void remove()
{
	int b = 1;
	ExMessage m;
	while (1)
	{
		m = getmessage(EX_MOUSE | EX_KEY);
		if (m.x <= 875 && m.y <= 775 && m.x >= 130 && m.y >= 25)
		{
			x = m.x % 50;
			y = m.y % 50;
			if (x >= 25)
				m.x = m.x - x + 50;
			else
				m.x = m.x - x;
			if (y >= 25)
				m.y = m.y - y + 50;
			else
				m.y = m.y - y;
			i = m.x / 50;
			j = m.y / 50;
			if (m.message == WM_RBUTTONDOWN)
			{

				setlinecolor(GREEN);
				setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 10);
				board[i][j] = 'N';
				circle(m.x, m.y, 20);
				b++;
				setlinestyle(PS_SOLID, 0);
				if (b == 4)
				{
					Sleep(100);
					cleardevice();
					drawboard();
					clearchess();
					break;
				}
			}

		}
	}

}
void drawboard()
{
	button1(370, 5, 270, 40, "道具模式");
	button1(0, 0, 125, 30, "玩家1");
	button1(875, 0, 125, 30, "玩家2");
	Rectangularlabel(0, 200, 130, 50, "道具点数：");
	Rectangularlabel(870, 200, 130, 50, "道具点数：");
	button1(370, 755, 270, 40, "返回页面");
	circlelabel(25, 400, 25, "消除");
	circlelabel(975, 400, 25, "消除");
	circlelabel(25, 600, 25, "销毁");
	circlelabel(975, 600, 25, "销毁");
	for (int i = 50; i <= 750; i += 50)//画棋盘
	{
		line(i + 100, 50, i + 100, 750);
		line(150, i, 850, i);
	}
}
void gamemaker()
{
	cleardevice();
	setbkcolor(LIGHTGRAY);
	cleardevice();
	settextcolor(LIGHTCYAN);
	button2(190, 600, 200, 60, "返回页面");
	settextstyle(40, 0, "楷体");
	outtextxy(173, 10, "制作人名单");
	outtextxy(93, 150 + 30, "组长：故里");
	outtextxy(93, 190 + 30, "副组长：K0x1e  投投");
	outtextxy(93, 230 + 30, "技术官：摸鱼帝");
	outtextxy(93, 270 + 30, "产品经理：没有脑袋  烟囱");
	outtextxy(93, 310 + 30, "监督官： 咸鱼之王");
	outtextxy(93, 350 + 30, "信息官： 小宁  苏德洲");
	ExMessage m;
	while (1)//各种功能的实现
	{
		if (peekmessage(&m, EX_MOUSE))
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				if (m.x >= 190 && m.x <= 390 && m.y >= 600 && m.y <= 660)
				{

					cleardevice();
					flag = 0;
					optionpage();
					break;
				}
			}
		}
	}
}
void background()
{
	setlinecolor(BLACK);
	rectangle(0, 55, 125, 680);
	rectangle(470, 55, 600, 680);
	settextstyle(30, 0, "楷体");
	settextcolor(BLACK);
	outtextxy(0, 0 + 60, "先手要攻");
	outtextxy(480, 0 + 60, "后手要守");
	outtextxy(0, 30 + 60, "以攻为守");
	outtextxy(480, 30 + 60, "以守待攻");
	outtextxy(0, 60 + 60, "攻守转换");
	outtextxy(480, 60 + 60, "慎思变化");
	outtextxy(0, 90 + 60, "先行争夺");
	outtextxy(480, 90 + 60, "地破天惊");
	outtextxy(0, 120 + 60, "守取外势");
	outtextxy(480, 120 + 60, "攻聚内力");
	outtextxy(0, 150 + 60, "八卦易守");
	outtextxy(480, 150 + 60, "成角易攻");
	outtextxy(0, 180 + 60, "阻断分隔");
	outtextxy(480, 180 + 60, "稳如泰山");
	outtextxy(0, 210 + 60, "不思争先");
	outtextxy(480, 210 + 60, "胜如登天");
	outtextxy(0, 240 + 60, "初盘争二");
	outtextxy(480, 240 + 60, "终局抢三");
	outtextxy(0, 270 + 60, "留三不冲");
	outtextxy(480, 270 + 60, "变化万千");
	outtextxy(0, 300 + 60, "多个先手");
	outtextxy(480, 300 + 60, "细算次先");
	outtextxy(0, 330 + 60, "五子要点");
	outtextxy(480, 330 + 60, "次序在前");
	outtextxy(0, 360 + 60, "斜线为阴");
	outtextxy(480, 360 + 60, "直线为阳");
	outtextxy(0, 390 + 60, "阴阳结合");
	outtextxy(480, 390 + 60, "防不胜防");
	outtextxy(0, 420 + 60, "连三连四");
	outtextxy(480, 420 + 60, "易见为明");
	outtextxy(0, 450 + 60, "跳三跳四");
	outtextxy(480, 450 + 60, "暗剑深藏");
	outtextxy(0, 480 + 60, "己落一子");
	outtextxy(480, 480 + 60, "敌增一兵");
	outtextxy(0, 510 + 60, "攻其要点");
	outtextxy(480, 510 + 60, "守其必争");
	outtextxy(0, 540 + 60, "势已形成");
	outtextxy(480, 540 + 60, "败即降临");
	outtextxy(0, 570 + 60, "五子精华");
	outtextxy(480, 570 + 60, "一子输赢");



}
void gameintroduce()
{
	settextcolor(BLACK);
	settextstyle(20, 0, "宋体");
	outtextxy(0, 100, "五子棋来历：五子棋起源于中国上古时代的传统黑白棋种之一。");
	outtextxy(0, 120, "主要流行于华人和汉字文化圈，是世界上最古老的棋通常双方分别使用黑白两色的棋子");
	outtextxy(0, 140, "下在棋盘直线与横线的交叉点上先形成5子连线者获胜");
	outtextxy(0, 160, "五子棋玩法：");
	outtextxy(0, 180, "经典玩法：");
	outtextxy(0, 220, "自已的五颗棋子连成一条线，可以横着、竖着、斜着；");
	outtextxy(0, 240, "连成的棋子中间不能有对方的棋子，就可以获胜。");

	outtextxy(0, 260 + 30, "娱乐模式：");
	outtextxy(0, 280 + 30, "加点：每当对手四子连珠时，我方技能点 + 1");

	outtextxy(0, 300 + 30, "道具1销毁：（需4点）");
	outtextxy(0, 320 + 50, "选用道具销毁，接下来一着棋由原本颜色的棋子变为道具棋，");
	outtextxy(0, 340 + 50, "落子处点位被销毁，黑白双方均无法落子");
	outtextxy(0, 360 + 50, "道具2消除：（需3点）");
	outtextxy(0, 380 + 80, "选用道具消除，接下来一着棋由原本颜色的棋子变为消除棋。");
	outtextxy(0, 400 + 80, "落子处，随机三子排列的形状的黑白棋均被擦去。");


}
void game2()//道具模式
{

	for (i = 1; i <= 15; i++)
	{
		for (j = 1; j <= 15; j++)
		{
			board[i][j] = 'a';
		}
	}

	button1(370, 5, 270, 40, "道具模式");
	button1(0, 0, 125, 30, "玩家1");
	button1(875, 0, 125, 30, "玩家2");
	Rectangularlabel(0, 200, 130, 50, "道具点数：");
	Rectangularlabel(870, 200, 130, 50, "道具点数：");
	circlelabel(25, 400, 25, "消除");
	circlelabel(975, 400, 25, "消除");
	circlelabel(25, 600, 25, "销毁");
	circlelabel(975, 600, 25, "销毁");
	button1(370, 755, 270, 40, "返回页面");
	ExMessage m;
	int x, y, ret2 = 0;
	int a = 0, c = 1, d = 1;
	int ret1 = 0;
	int ret3 = 0;

	while (1)
	{
		m = getmessage(EX_MOUSE | EX_KEY);
		if (m.x <= 640 && m.y <= 800 && m.x >= 350 && m.y >= 735 && m.message == WM_LBUTTONDOWN)
		{

			break;
		}
		if (m.x <= 875 && m.y <= 775 && m.x >= 130 && m.y >= 25)
		{
			x = m.x % 50;
			y = m.y % 50;
			if (x >= 25)
				m.x = m.x - x + 50;
			else
				m.x = m.x - x;
			if (y >= 25)
				m.y = m.y - y + 50;
			else
				m.y = m.y - y;
			i = m.x / 50;
			j = m.y / 50;
			if (m.message == WM_LBUTTONDOWN)
			{
				if (a % 2 == 0 && board[i][j] != 'B' && board[i][j] != 'W' && board[i][j] != 'X')
				{
					setfillcolor(BLACK);
					board[i][j] = 'B';
					a++;
					fillcircle(m.x, m.y, 20);
					if (musica == 1)
						musictexiao1();
					ret1 = check_win(i, j, 'B');
					ret2 = check_tri(i, j, 'B');

				}
				else if (a % 2 != 0 && board[i][j] != 'B' && board[i][j] != 'W' && board[i][j] != 'X')
				{
					setfillcolor(WHITE);
					board[i][j] = 'W';
					a++;
					fillcircle(m.x, m.y, 20);
					if (musica == 1)
						musictexiao2();
					ret1 = check_win(i, j, 'W');
					ret3 = check_tri(i, j, 'W');

				}
				if (ret1 == 1)
				{
					Sleep(100);
					flag = 5;
					break;
				}
			}


		}

		if (m.x <= 70 && m.x >= 0 && m.y <= 470 && m.y >= 380 && m.message == WM_LBUTTONDOWN)//道具1的设置（左）
		{

			remove();
		}
		else if (m.x <= 1000 && m.x >= 930 && m.y <= 470 && m.y >= 380 && m.message == WM_LBUTTONDOWN)//道具1的设置（右）
		{
			remove();
		}
		else if (m.x <= 70 && m.x >= 0 && m.y <= 670 && m.y >= 580 && m.message == WM_LBUTTONDOWN)//道具2的功能（左）
		{
			destroy();
		}
		else if (m.x <= 1000 && m.x >= 930 && m.y <= 670 && m.y >= 580 && m.message == WM_LBUTTONDOWN)//道具2的设置（右）
		{
			destroy();
		}
	}
}
void circlelabel(int x, int y, int r, const char* text)
{
	LOGFONT fontstyle;
	gettextstyle(&fontstyle);//获取当前字体样式LOGFONT
	fontstyle.lfQuality = ANTIALIASED_QUALITY;//字体输出质量：抗锯齿
	settextstyle(&fontstyle);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 1);
	setfillcolor(RGB(255, 178, 50));
	settextstyle(20, 0, "楷体");

	fillcircle(x, y, r);
	int tx = x - r;
	int ty = y - r / 2;
	outtextxy(tx, ty, text);
}
void Rectangularlabel(int x, int y, int w, int h, const char* text)
{
	LOGFONT fontstyle;
	gettextstyle(&fontstyle);//获取当前字体样式LOGFONT

	fontstyle.lfQuality = ANTIALIASED_QUALITY;//字体输出质量：抗锯齿
	settextstyle(&fontstyle);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 5);
	settextstyle(20, 0, "楷体");
	setfillcolor(RGB(135, 206, 235));

	RECT rect;
	rect.left = x;//左上角的x
	rect.top = y;//左上角的y
	rect.right = x + w;//右下角的x
	rect.bottom = y + h;//右下角的y
	fillrectangle(rect.left = x, rect.top = y, rect.right = x + w, rect.bottom = y + h);
	drawtext(text, &rect, DT_SINGLELINE | DT_VCENTER);
}
void destroy()
{
	int b = 1;
	ExMessage m;
	while (1)
	{
		m = getmessage(EX_MOUSE | EX_KEY);
		if (m.x <= 875 && m.y <= 775 && m.x >= 130 && m.y >= 25)
		{
			x = m.x % 50;
			y = m.y % 50;
			if (x >= 25)
				m.x = m.x - x + 50;
			else
				m.x = m.x - x;
			if (y >= 25)
				m.y = m.y - y + 50;
			else
				m.y = m.y - y;
			i = m.x / 50;
			j = m.y / 50;
			if (m.message == WM_RBUTTONDOWN)
			{

				setlinecolor(RED);
				setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 10);
				board[i][j] = 'X';
				circle(m.x, m.y, 20);
				printf("%d  %d    %c\n", i, j, board[i][j]);
				printf("%d\n", b);
				b++;
				setlinestyle(PS_SOLID, 0);
				if (b == 2)
				{
					Sleep(100);
					cleardevice();
					drawboard();
					clearchess();
					break;
				}
			}

		}
	}

}
void musictexiao1()
{
	//放在落子函数里面。每放一次函数就触发一次音效
	//关闭函数就是触发关闭键
	mciSendString("open wuhun3.mp3 alias bbb type mpegvideo", NULL, 0, NULL);
	mciSendString("play bbb ", NULL, 0, NULL);
	Sleep(3500);
	mciSendString("close bbb ", NULL, 0, NULL);

}

void musictexiao2()
{
	//放在落子函数里面。每放一次函数就触发一次音效
	//关闭函数就是触发关闭键
	mciSendString("open wuhun2.mp3 alias ccc type mpegvideo", NULL, 0, NULL);
	mciSendString("play ccc ", NULL, 0, NULL);
	Sleep(3500);
	mciSendString("close ccc ", NULL, 0, NULL);

}
void musictexiao3()
{
	//放在落子函数里面。每放一次函数就触发一次音效
	//关闭函数就是触发关闭键
	mciSendString("open ji.mp3 alias bbb type mpegvideo", NULL, 0, NULL);
	mciSendString("play bbb ", NULL, 0, NULL);
	Sleep(15000);
	mciSendString("close bbb ", NULL, 0, NULL);

}
/*我的想法是吧这两个函数都放在那个音效开关页面那个函数里面。
这样操作比较方便，也不会去涉及又在落子函数里面去添加，代码出错的概率更低*/
void musicplaybr(void)
{
	//在最前面定义musicb
	if (musicb == 0)
	{
		mciSendString("open a.wav alias aaa type mpegvideo", NULL, 0, NULL);
		mciSendString("play aaa repeat", NULL, 0, NULL);
		//音乐是自动启动
	}
	if (musicb == 1)/*填入音效框内的开关坐标*/
	{
		mciSendString("stop aaa", NULL, 0, NULL);//暂停部分
		//如果是musicb=1，就是暂停函数
	}
	if (musicb == 2 /*（前面要注入读取鼠标的代码）*/)
	{
		mciSendString("resume aaa", 0, 0, 0);//继续播放
		//如果是musicb=2，就继续播放
	}
	//_getch();

}
