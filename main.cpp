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
void button1(int x, int y, int w, int z, const char* text);//��ťѡ��
void button2(int x, int y, int w, int z, const char* text);//��ťѡ��
void gamepage();//��������Ϸҳ��
void menu();//��ʼҳ��
void quitpage();//�˳���Ϸҳ��
void game1();//������Ϸҳ��
void game2();//����ģʽҳ��
void playwaypage();//���淽ʽ��ϸ
void optionpage();//����ҳ����ϸ
void gameinfo();//��Ϸ�淨���ܡ���
void overpage();//����ҳ��
void clearchess();//��������
int check_win(int x, int y, char color);//��Ӯ�ж�
void drawboard();//��ӡ����
void remove();//��������
void gamemaker();//����������
void background();//����װ��
void gameintroduce();//�������ҳ��
void circlelabel(int x, int y, int r, const char* text);
void Rectangularlabel(int x, int y, int w, int h, const char* text);
void destroy();//���ٹ���
void musictexiao1();//��Ч����
void musictexiao2();
void musictexiao3();
int check_tri(int x, int y, char color);//���������ж�
void musicplaybr(void);

void refreshColor();//Ƥ����ɫѡ��
int main()
{
	int musicb = 0;
	musicplaybr();
	menu();
}//������
void button1(int x, int y, int w, int h, const char* text) {
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	setfillcolor(RGB(190, 170, 200));
	fillroundrect(x, y, x + w, y + h, 10, 10);
	settextstyle(30, 0, "����");
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
	settextstyle(30, 0, "����");
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}
void gamepage()
{
	initgraph(1000, 800);//��ʼ����ͼ����
	setbkcolor(YELLOW);//��ͼ����ɫ
	cleardevice();//ʹ�õ�ǰ����ɫ�����һ����ͼ
	setlinecolor(BLACK);//���õ�ǰ�豸������ɫ
	for (int i = 50; i <= 750; i += 50)//������
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
void game1()//����ģʽ
{
	for (i = 1; i <= 15; i++)
	{
		for (j = 1; j <= 15; j++)
		{
			board[i][j] = 'a';
		}
	}
	button1(870, 200, 130, 50, "�������");
	button1(870, 400, 130, 50, "����ҳ��");
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
			for (int i = 50; i <= 750; i += 50)//������
			{
				line(i + 100, 50, i + 100, 750);
				line(150, i, 850, i);
			}

			button1(870, 200, 130, 50, "�������");
			button1(870, 400, 130, 50, "����ҳ��");

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
void playwaypage()//���淽ʽҳ��
{

	setbkcolor(RGB(180, 180, 180));
	cleardevice();
	background();
	setfillcolor(BLACK);
	settextcolor(BLACK);
	settextstyle(40, 0, "����");
	button2(163, 250, 270, 40, "����ģʽ");
	button2(163, 500, 270, 40, "����ģʽ");
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
					break;//����
				}
			}
			if (m.x >= 163 && m.x <= 433 && m.y >= 500 && m.y <= 540)
			{
				if (m.message == WM_LBUTTONDOWN)
				{
					token = 1;

					break;//����
				}
			}
			switch (m.message)
			{
			case WM_MOUSEMOVE:
				printf("%d %d\n", m.x, m.y);
				if (flag == 0 && m.x >= 153 && m.x <= 453 && m.y >= 500 && m.y <= 500 + 40)//����

				{
					setlinecolor(BLACK);
					setlinestyle(PS_SOLID, 3);
					rectangle(163, 500, 433, 540);
				}

				else if (flag == 0 && m.x >= 163 && m.x <= 433 && m.y >= 250 && m.y <= 250 + 40)//��Ч����
				{
					setlinecolor(BLACK);
					setlinestyle(PS_SOLID, 3);
					rectangle(163, 250, 433, 290);
				}
				else
				{
					if (flag == 0) //δ����Ϊ����������Ϊ������
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
void optionpage()//����ҳ�棨��������Ч����ͼѡ�񣬹������ǣ�
{
	flag = 0;
	setbkcolor(RGB(180, 180, 180));
	cleardevice();
	setfillcolor(BLACK);
	settextcolor(BLACK);
	settextstyle(60, 0, "����");
	outtextxy(230, 60, "����");
	setlinecolor(RED);
	button2(163, 200, 270, 40, "��Ч��");
	button2(163, 350, 270, 40, "�������֣�");
	button2(163, 500, 270, 40, "��ͼѡ��");
	button2(163, 650, 270, 40, "��������");
	outtextxy(45, 40, "����");
	ExMessage m;
	//���������Ϣ
	int c = 0, d = 0;
	while (true)
	{
		if (peekmessage(&m, EX_MOUSE)) {
			if (flag == 0 && m.x >= 30 && m.x <= 130 && m.y >= 20 && m.y <= 90 && m.message == WM_LBUTTONDOWN)
			{
				printf("���Գɹ�");
				break;
			}
			switch (m.message)
			{
			case WM_MOUSEMOVE:
				printf("%d %d\n", m.x, m.y);
				if (flag == 0 && m.x >= 153 && m.x <= 453 && m.y >= 500 && m.y <= 500 + 40)//����

				{
					setlinecolor(BLACK);
					setlinestyle(PS_SOLID, 3);
					rectangle(163, 500, 433, 540);
				}

				else if (flag == 0 && m.x >= 163 && m.x <= 433 && m.y >= 200 && m.y <= 200 + 40)//��Ч����
				{
					setlinecolor(BLACK);
					setlinestyle(PS_SOLID, 3);
					rectangle(163, 200, 433, 240);
				}

				else if (flag == 0 && m.x >= 163 && m.x <= 430 && m.y >= 350 && m.y <= 350 + 40)//��ͼѡ��
				{
					setlinecolor(BLACK);
					setlinestyle(PS_SOLID, 3);
					rectangle(163, 350, 433, 390);
				}
				else if (flag == 0 && m.x >= 163 && m.x <= 433 && m.y >= 650 && m.y <= 690)//��������
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
					if (flag == 0) //δ����Ϊ����������Ϊ������
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
						button2(163, 200, 270, 40, "��Ч����");
						d++;
						musica = 0;
						continue;
					}
					if (d % 2 != 0)
					{
						button2(163, 200, 270, 40, "��Ч����");
						d++;
						musica = 1;
						continue;

					}

				}

				else if (m.x >= 160 && m.x <= 430 && m.y >= 350 && m.y <= 350 + 40)
				{

					if (c % 2 == 0)
					{
						button2(163, 350, 270, 40, "�������֣���");
						c++;
						mciSendString("stop aaa", NULL, 0, NULL);
						continue;
					}
					if (c % 2 != 0)
					{
						button2(163, 350, 270, 40, "�������֣���");
						c++;
						mciSendString("play aaa", 0, 0, 0);//��������
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
	button2(190, 600, 200, 60, "����ҳ��");
	settextcolor(BLACK);
	settextstyle(40, 0, "����");
	outtextxy(200, 5, "�������");
	gameintroduce();
	ExMessage m;
	while (1)//���ֹ��ܵ�ʵ��
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
start_game:;//�����game1
	initgraph(600, 800);
start:;
	int  flag = 0;//��ʼֵ
	//mciSendString("open ./bk.mp3 ", 0, 0, 0);
	//mciSendString("play ./bk.mp3 repeat ", 0, 0, 0);
	if (flag == 0)
	{
	
		setbkcolor(RGB(200, 140, 20));
		cleardevice();
		background();
		button1(163, 500, 270, 40, "��ʼ��Ϸ");
		button1(163, 200, 270, 40, "����ҳ��");
		button1(163, 350, 270, 40, "����˵��");
		button1(163, 650, 270, 40, "�˳���Ϸ");
		settextstyle(50, 0, "����");
		settextcolor(RGB(200, 240, 150));
		outtextxy(173, 50, "ǧ��������");
	}
option:;
	if (flag == 1)//1Ϊ����ҳ��
	{
		setbkcolor(RGB(120, 160, 40));
		cleardevice();
		optionpage();
		goto start;
	}
playway:;
	if (flag == 2)//2Ϊ����˵��ҳ��
	{
		setbkcolor(RGB(10, 150, 100));
		cleardevice();
		gameinfo();
		goto start;
	}
game:;
	if (flag == 3)//3Ϊ��Ϸҳ��
	{
		playwaypage();//��Ϸѡ��
		gamepage();
		flag = 5;
		goto over;//���س�ʼҳ��
	}
quit:;
	if (flag == 4)//4Ϊ�˳���Ϸҳ��
	{
		quitpage();
		goto start;//���س�ʼҳ��
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
	//���������Ϣ
	while (true)
	{
		if (peekmessage(&m, EX_MOUSE)) {
			switch (m.message)
			{
			case WM_MOUSEMOVE:
				//��ʼ��Ϸ
				printf("%d %d\n", m.x, m.y);
				if (flag == 0 && m.x >= 153 && m.x <= 453 && m.y >= 500 && m.y <= 500 + 40)//��ʼ��Ϸ��ť��
				{
					setlinecolor(WHITE);
					setlinestyle(PS_SOLID, 3);
					rectangle(163, 500, 433, 540);
				}
				//����
				else if (flag == 0 && m.x >= 163 && m.x <= 433 && m.y >= 200 && m.y <= 200 + 40)//����ҳ�水ť��
				{
					setlinecolor(WHITE);
					setlinestyle(PS_SOLID, 3);
					rectangle(163, 200, 433, 240);
				}
				//���淽ʽ
				else if (flag == 0 && m.x >= 163 && m.x <= 430 && m.y >= 350 && m.y <= 350 + 40)//���淽ʽ��
				{
					setlinecolor(WHITE);
					setlinestyle(PS_SOLID, 3);
					rectangle(163, 350, 433, 390);
				}
				else if (flag == 0 && m.x >= 163 && m.x <= 433 && m.y >= 650 && m.y <= 690)//�˳���Ϸҳ��
				{
					setlinecolor(WHITE);
					setlinestyle(PS_SOLID, 3);
					rectangle(163, 650, 433, 690);
				}
				else
				{
					if (flag == 0) //δ����Ϊ����������Ϊ������
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
			case WM_LBUTTONDOWN://��ʼ��Ϸҳ�����
				if (flag == 0 && m.x >= 153 && m.x <= 433 && m.y >= 500 && m.y <= 500 + 40)
				{
					Sleep(300);
					//mciSendString("close ./bk.mp3", 0, 0, 0);
					flag = 3;
					goto game;
				}
				//����ҳ�����
				else  if (flag == 0 && m.x >= 163 && m.x <= 433 && m.y >= 200 && m.y <= 200 + 40)
				{
					printf("��������ҳ��");
					flag = 1;
					goto option;//��ת������ҳ��
				}
				//���淽ʽҳ�����
				else if (m.x >= 160 && m.x <= 430 && m.y >= 350 && m.y <= 350 + 40)
				{
					//���淽ʽ����ʵ��
					flag = 2;
					goto playway;//��ת�������
				}
				else if (flag == 0 && m.x >= 163 && m.x <= 433 && m.y >= 650 && m.y <= 650 + 40)//�˳���Ϸҳ��
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
	button1(75, 120, 150, 50, "����һ��");
	button1(75, 220, 150, 50, "�˳���Ϸ");
	ExMessage m;
	while (1)
	{
		if (peekmessage(&m, EX_MOUSE))
		{
			if (m.x <= 220 && m.x >= 75 && m.y <= 170 && m.y >= 120)
			{
				if (m.message == WM_LBUTTONDOWN)
				{
					break;//����
				}
			}
			if (m.x <= 225 && m.x >= 75 && m.y <= 270 && m.y >= 220)
			{
				if (m.message == WM_LBUTTONDOWN) {
					closegraph(); // �رջ�ͼ����
					exit(0);    //ǿ���˳�
				}
			}
		}
	}

}
void clearchess()//��������
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
int check_win(int x, int y, char color)//�������ж�
{
	// �������Ƿ����������������
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

	// ��������Ƿ����������������
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

	// ������� - ����б���Ƿ����������������
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

	// ������� - ����б���Ƿ����������������
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
int check_tri(int x, int y, char color)//�������ж�
{
	// �������Ƿ����������������
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

	// ��������Ƿ����������������
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

	// ������� - ����б���Ƿ����������������
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

	// ������� - ����б���Ƿ����������������
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
	button1(370, 5, 270, 40, "����ģʽ");
	button1(0, 0, 125, 30, "���1");
	button1(875, 0, 125, 30, "���2");
	Rectangularlabel(0, 200, 130, 50, "���ߵ�����");
	Rectangularlabel(870, 200, 130, 50, "���ߵ�����");
	button1(370, 755, 270, 40, "����ҳ��");
	circlelabel(25, 400, 25, "����");
	circlelabel(975, 400, 25, "����");
	circlelabel(25, 600, 25, "����");
	circlelabel(975, 600, 25, "����");
	for (int i = 50; i <= 750; i += 50)//������
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
	button2(190, 600, 200, 60, "����ҳ��");
	settextstyle(40, 0, "����");
	outtextxy(173, 10, "����������");
	outtextxy(93, 150 + 30, "�鳤������");
	outtextxy(93, 190 + 30, "���鳤��K0x1e  ͶͶ");
	outtextxy(93, 230 + 30, "�����٣������");
	outtextxy(93, 270 + 30, "��Ʒ����û���Դ�  �̴�");
	outtextxy(93, 310 + 30, "�ල�٣� ����֮��");
	outtextxy(93, 350 + 30, "��Ϣ�٣� С��  �յ���");
	ExMessage m;
	while (1)//���ֹ��ܵ�ʵ��
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
	settextstyle(30, 0, "����");
	settextcolor(BLACK);
	outtextxy(0, 0 + 60, "����Ҫ��");
	outtextxy(480, 0 + 60, "����Ҫ��");
	outtextxy(0, 30 + 60, "�Թ�Ϊ��");
	outtextxy(480, 30 + 60, "���ش���");
	outtextxy(0, 60 + 60, "����ת��");
	outtextxy(480, 60 + 60, "��˼�仯");
	outtextxy(0, 90 + 60, "��������");
	outtextxy(480, 90 + 60, "�����쾪");
	outtextxy(0, 120 + 60, "��ȡ����");
	outtextxy(480, 120 + 60, "��������");
	outtextxy(0, 150 + 60, "��������");
	outtextxy(480, 150 + 60, "�ɽ��׹�");
	outtextxy(0, 180 + 60, "��Ϸָ�");
	outtextxy(480, 180 + 60, "����̩ɽ");
	outtextxy(0, 210 + 60, "��˼����");
	outtextxy(480, 210 + 60, "ʤ�����");
	outtextxy(0, 240 + 60, "��������");
	outtextxy(480, 240 + 60, "�վ�����");
	outtextxy(0, 270 + 60, "��������");
	outtextxy(480, 270 + 60, "�仯��ǧ");
	outtextxy(0, 300 + 60, "�������");
	outtextxy(480, 300 + 60, "ϸ�����");
	outtextxy(0, 330 + 60, "����Ҫ��");
	outtextxy(480, 330 + 60, "������ǰ");
	outtextxy(0, 360 + 60, "б��Ϊ��");
	outtextxy(480, 360 + 60, "ֱ��Ϊ��");
	outtextxy(0, 390 + 60, "�������");
	outtextxy(480, 390 + 60, "����ʤ��");
	outtextxy(0, 420 + 60, "��������");
	outtextxy(480, 420 + 60, "�׼�Ϊ��");
	outtextxy(0, 450 + 60, "��������");
	outtextxy(480, 450 + 60, "�������");
	outtextxy(0, 480 + 60, "����һ��");
	outtextxy(480, 480 + 60, "����һ��");
	outtextxy(0, 510 + 60, "����Ҫ��");
	outtextxy(480, 510 + 60, "�������");
	outtextxy(0, 540 + 60, "�����γ�");
	outtextxy(480, 540 + 60, "�ܼ�����");
	outtextxy(0, 570 + 60, "���Ӿ���");
	outtextxy(480, 570 + 60, "һ����Ӯ");



}
void gameintroduce()
{
	settextcolor(BLACK);
	settextstyle(20, 0, "����");
	outtextxy(0, 100, "��������������������Դ���й��Ϲ�ʱ���Ĵ�ͳ�ڰ�����֮һ��");
	outtextxy(0, 120, "��Ҫ�����ڻ��˺ͺ����Ļ�Ȧ��������������ϵ���ͨ��˫���ֱ�ʹ�úڰ���ɫ������");
	outtextxy(0, 140, "��������ֱ������ߵĽ���������γ�5�������߻�ʤ");
	outtextxy(0, 160, "�������淨��");
	outtextxy(0, 180, "�����淨��");
	outtextxy(0, 220, "���ѵ������������һ���ߣ����Ժ��š����š�б�ţ�");
	outtextxy(0, 240, "���ɵ������м䲻���жԷ������ӣ��Ϳ��Ի�ʤ��");

	outtextxy(0, 260 + 30, "����ģʽ��");
	outtextxy(0, 280 + 30, "�ӵ㣺ÿ��������������ʱ���ҷ����ܵ� + 1");

	outtextxy(0, 300 + 30, "����1���٣�����4�㣩");
	outtextxy(0, 320 + 50, "ѡ�õ������٣�������һ������ԭ����ɫ�����ӱ�Ϊ�����壬");
	outtextxy(0, 340 + 50, "���Ӵ���λ�����٣��ڰ�˫�����޷�����");
	outtextxy(0, 360 + 50, "����2����������3�㣩");
	outtextxy(0, 380 + 80, "ѡ�õ���������������һ������ԭ����ɫ�����ӱ�Ϊ�����塣");
	outtextxy(0, 400 + 80, "���Ӵ�������������е���״�ĺڰ��������ȥ��");


}
void game2()//����ģʽ
{

	for (i = 1; i <= 15; i++)
	{
		for (j = 1; j <= 15; j++)
		{
			board[i][j] = 'a';
		}
	}

	button1(370, 5, 270, 40, "����ģʽ");
	button1(0, 0, 125, 30, "���1");
	button1(875, 0, 125, 30, "���2");
	Rectangularlabel(0, 200, 130, 50, "���ߵ�����");
	Rectangularlabel(870, 200, 130, 50, "���ߵ�����");
	circlelabel(25, 400, 25, "����");
	circlelabel(975, 400, 25, "����");
	circlelabel(25, 600, 25, "����");
	circlelabel(975, 600, 25, "����");
	button1(370, 755, 270, 40, "����ҳ��");
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

		if (m.x <= 70 && m.x >= 0 && m.y <= 470 && m.y >= 380 && m.message == WM_LBUTTONDOWN)//����1�����ã���
		{

			remove();
		}
		else if (m.x <= 1000 && m.x >= 930 && m.y <= 470 && m.y >= 380 && m.message == WM_LBUTTONDOWN)//����1�����ã��ң�
		{
			remove();
		}
		else if (m.x <= 70 && m.x >= 0 && m.y <= 670 && m.y >= 580 && m.message == WM_LBUTTONDOWN)//����2�Ĺ��ܣ���
		{
			destroy();
		}
		else if (m.x <= 1000 && m.x >= 930 && m.y <= 670 && m.y >= 580 && m.message == WM_LBUTTONDOWN)//����2�����ã��ң�
		{
			destroy();
		}
	}
}
void circlelabel(int x, int y, int r, const char* text)
{
	LOGFONT fontstyle;
	gettextstyle(&fontstyle);//��ȡ��ǰ������ʽLOGFONT
	fontstyle.lfQuality = ANTIALIASED_QUALITY;//������������������
	settextstyle(&fontstyle);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 1);
	setfillcolor(RGB(255, 178, 50));
	settextstyle(20, 0, "����");

	fillcircle(x, y, r);
	int tx = x - r;
	int ty = y - r / 2;
	outtextxy(tx, ty, text);
}
void Rectangularlabel(int x, int y, int w, int h, const char* text)
{
	LOGFONT fontstyle;
	gettextstyle(&fontstyle);//��ȡ��ǰ������ʽLOGFONT

	fontstyle.lfQuality = ANTIALIASED_QUALITY;//������������������
	settextstyle(&fontstyle);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 5);
	settextstyle(20, 0, "����");
	setfillcolor(RGB(135, 206, 235));

	RECT rect;
	rect.left = x;//���Ͻǵ�x
	rect.top = y;//���Ͻǵ�y
	rect.right = x + w;//���½ǵ�x
	rect.bottom = y + h;//���½ǵ�y
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
	//�������Ӻ������档ÿ��һ�κ����ʹ���һ����Ч
	//�رպ������Ǵ����رռ�
	mciSendString("open wuhun3.mp3 alias bbb type mpegvideo", NULL, 0, NULL);
	mciSendString("play bbb ", NULL, 0, NULL);
	Sleep(3500);
	mciSendString("close bbb ", NULL, 0, NULL);

}

void musictexiao2()
{
	//�������Ӻ������档ÿ��һ�κ����ʹ���һ����Ч
	//�رպ������Ǵ����رռ�
	mciSendString("open wuhun2.mp3 alias ccc type mpegvideo", NULL, 0, NULL);
	mciSendString("play ccc ", NULL, 0, NULL);
	Sleep(3500);
	mciSendString("close ccc ", NULL, 0, NULL);

}
void musictexiao3()
{
	//�������Ӻ������档ÿ��һ�κ����ʹ���һ����Ч
	//�رպ������Ǵ����رռ�
	mciSendString("open ji.mp3 alias bbb type mpegvideo", NULL, 0, NULL);
	mciSendString("play bbb ", NULL, 0, NULL);
	Sleep(15000);
	mciSendString("close bbb ", NULL, 0, NULL);

}
/*�ҵ��뷨�ǰ������������������Ǹ���Ч����ҳ���Ǹ��������档
���������ȽϷ��㣬Ҳ����ȥ�漰�������Ӻ�������ȥ��ӣ��������ĸ��ʸ���*/
void musicplaybr(void)
{
	//����ǰ�涨��musicb
	if (musicb == 0)
	{
		mciSendString("open a.wav alias aaa type mpegvideo", NULL, 0, NULL);
		mciSendString("play aaa repeat", NULL, 0, NULL);
		//�������Զ�����
	}
	if (musicb == 1)/*������Ч���ڵĿ�������*/
	{
		mciSendString("stop aaa", NULL, 0, NULL);//��ͣ����
		//�����musicb=1��������ͣ����
	}
	if (musicb == 2 /*��ǰ��Ҫע���ȡ���Ĵ��룩*/)
	{
		mciSendString("resume aaa", 0, 0, 0);//��������
		//�����musicb=2���ͼ�������
	}
	//_getch();

}
