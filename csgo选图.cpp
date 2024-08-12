#include<stdio.h>
#include<time.h>
#include<string.h>
#include<easyx.h>
#include<assert.h>
#include <Mmsystem.h>		
#pragma comment (lib, "Winmm.lib")
//炙热沙城2
//荒漠迷城
//小镇X
//大厦
//远古遗迹
//阿努比斯x
//核子危机
//列车停放站x
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
	settextstyle(25, 0, "宋体");
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
	loadimage(&img,"地图.jpg",1200,720);
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
	loadimage(&a, "沙城.png", 100, 100);
	putimage(100, 100, &a);
	settextcolor(RED);
	outtextxy(120, 220, "炙热沙城");
	loadimage(&b, "核子危机.jpg", 100, 100);
	putimage(300, 100, &b);
	outtextxy(320, 220, "核子危机");
	loadimage(&c, "迷城.jpg", 100, 100);
	putimage(100, 300, &c);
	outtextxy(120, 420, "荒漠迷城");
	loadimage(&d, "遗迹.jpg", 100, 100);
	putimage(300, 300, &d);
	outtextxy(320, 420, "远古遗迹");
	loadimage(&e, "大厦.jpg", 100, 100);
	putimage(720, 100, &e);
	outtextxy(740, 220, "殒命大厦");
	loadimage(&f, "阿努比斯.jpg", 100, 100);
	putimage(720, 300, &f);
	outtextxy(740, 420, "阿努比斯");
	loadimage(&g, "列车.jpg", 100, 100);
	putimage(920, 300, &g);
	outtextxy(950, 420, "列车");
	loadimage(&h, "小镇.jpg", 100, 100);
	putimage(920, 100, &h);
	outtextxy(950, 220, "小镇");
	LP bg=creatButton(450,250,200,100,"选择游戏");
	LP find = creatButton(450, 350, 200, 100, "查看结果");
	LP beginmusic=creatButton(120,560, 180, 160,"开始音乐");
	LP pauseemusic = creatButton(880, 560, 180, 160, "暂停音乐");
	/*drawbutton(bg);*/

	mciSendString("open ./夜空的寂静.mp3 alias bk", 0, 0, 0);
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
			mciSendString("open ./夜空的寂静.mp3 alias bk", 0, 0, 0);
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