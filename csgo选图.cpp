#include<stdio.h>
#include<time.h>
#include<string.h>
#include<easyx.h>
#include<assert.h>
#include <Mmsystem.h>		
#pragma comment (lib, "Winmm.lib")
//����ɳ��2
//��Į�Գ�
//С��X
//����
//Զ���ż�
//��Ŭ��˹x
//����Σ��
//�г�ͣ��վx
typedef struct Button
{
	int x;
	int y;
	int w;
	int h;
	COLORREF color;
	char* next;
}*LP,Button;
LP creatButton(int x,int y,int w,int h,const char *str)
{
	LP button;
	button = (LP)malloc(sizeof(Button));
	assert(button);
	button->x = x;
	button->y = y;
	button->w = w;
	button->h = h;
	button->color = RGB(204, 213, 240);
	int length = strlen(str) + 1;
	button->next = (char*)malloc(sizeof(char) * length);
	strcpy(button->next, str);
	return button;
}
void drawbutton(LP button)
{
	setfillcolor(button->color);
	fillrectangle(button->x, button->y,button->x +button->w, button->y+button->h);
	settextstyle(25, 0, "����");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	int texttw = textwidth(button->next);
	int textwh = textheight(button->next);
	int xx = button->x + (button->w - texttw) / 2;
	int yy = button->y + (button->h - textwh) / 2;
	outtextxy(xx, yy, button->next);


	
}
void inputlight()
{
	IMAGE img;
	loadimage(&img,"��ͼ.jpg",1200,720);
	putimage(0,0,&img);
}
void findquesstino()
{
	srand(time(0));

}
void picture()
{
	int inbutton(LP button, ExMessage m)
		;
	IMAGE a, b, c, d, e, f, g, h;
	loadimage(&a, "ɳ��.png", 100, 100);
	putimage(100, 100, &a);
	settextcolor(RED);
	outtextxy(120, 220, "����ɳ��");
	loadimage(&b, "����Σ��.jpg", 100, 100);
	putimage(300, 100, &b);
	outtextxy(320, 220, "����Σ��");
	loadimage(&c, "�Գ�.jpg", 100, 100);
	putimage(100, 300, &c);
	outtextxy(120, 420, "��Į�Գ�");
	loadimage(&d, "�ż�.jpg", 100, 100);
	putimage(300, 300, &d);
	outtextxy(320, 420, "Զ���ż�");
	loadimage(&e, "����.jpg", 100, 100);
	putimage(720, 100, &e);
	outtextxy(740, 220, "��������");
	loadimage(&f, "��Ŭ��˹.jpg", 100, 100);
	putimage(720, 300, &f);
	outtextxy(740, 420, "��Ŭ��˹");
	loadimage(&g, "�г�.jpg", 100, 100);
	putimage(920, 300, &g);
	outtextxy(950, 420, "�г�");
	loadimage(&h, "С��.jpg", 100, 100);
	putimage(920, 100, &h);
	outtextxy(950, 220, "С��");
	LP bg=creatButton(450,250,200,100,"ѡ����Ϸ");
	LP find = creatButton(450, 350, 200, 100, "�鿴���");
	LP beginmusic=creatButton(120,560, 180, 160,"��ʼ����");
	LP pauseemusic = creatButton(880, 560, 180, 160, "��ͣ����");
	/*drawbutton(bg);*/

	mciSendString("open ./ҹ�յļž�.mp3 alias bk", 0, 0, 0);
	mciSendString("play bk repeat", 0, 0, 0);	
	
	BeginBatchDraw();

	while (1)
	{
		ExMessage m;
		peekmessage(&m, EX_MOUSE);
		drawbutton(bg); drawbutton(beginmusic); drawbutton(pauseemusic);
		drawbutton(find);
		if (inbutton(bg, m) && m.message == WM_LBUTTONDOWN)
		{
			inputlight();
		}
		if (inbutton(beginmusic, m) && m.message == WM_LBUTTONDOWN)
		{
			mciSendString(_T("stop bk"), NULL, 0, NULL);
			mciSendString(_T("close bk"), NULL, 0, NULL);
			mciSendString("open ./ҹ�յļž�.mp3 alias bk", 0, 0, 0);
			mciSendString("play bk repeat", 0, 0, 0);
		}
		if (inbutton(pauseemusic, m) && m.message == WM_LBUTTONDOWN)
		{
			mciSendString(_T("stop bk"), NULL, 0, NULL);
	mciSendString(_T("close bk"), NULL, 0, NULL);
		}
		if (inbutton(find, m) && m.message == WM_LBUTTONDOWN)
		{
			
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
	

}
int inbutton(LP button, ExMessage m)
{
	if (m.x > button->x && m.x <= button->x + button->w && m.y > button->y && m.y <= button->y + button->h)
	{
		button->color = RGB(280, 244, 255);
		return 1;
	}
	else
	{
		/*printf("dawd");*/
		button->color = RGB(204, 213, 240);
		return 0;
	}

}
int main()
{
	initgraph(1200,720);
	picture();
	getchar();
	closegraph();
}