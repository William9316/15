#include <iostream>
#include <conio.h>
#include "Header.h"
#include "DisplayTimer.h"
using namespace std;

int main()
{
	while (1)
	{
		char ch;

		DisplayTimer timer;
		timer.start();
		system("cls");                        //清屏
		New2048 s;
		s.make_frame();                       //列印框架
		s.creat_num();
		s.creat_num();                        //產生兩個隨機數
		s.display_num();                      //顯示數字
		while (1)
		{
			ch = _getch();
			if (ch == 'a' || ch == 's' || ch == 'd' || ch == 'w' || ch == ' ' ||
				ch == 'A' || ch == 'S' || ch == 'D' || ch == 'W')
				break;
		}
	p:		switch (ch)
	{
	case 's':
	case 'S':
	{
		while (s.cheak())
		{
			s.DownMove();             //下移
			s.clean();                //清理
			s.display_num();          //顯示數字
			while (1)
			{
				ch = _getch();
				if (ch == 'a' || ch == 's' || ch == 'd' || ch == 'w' || ch == ' ' ||
					ch == 'A' || ch == 'S' || ch == 'D' || ch == 'W')
					break;
			}
			goto p;
		}
	}break;
	case 'd':
	case 'D':
	{
		while (s.cheak())
		{
			s.RightMove();                //右移
			s.clean();                    //清理
			s.display_num();              //顯示數字
			while (1)
			{
				ch = _getch();
				if (ch == 'a' || ch == 's' || ch == 'd' || ch == 'w' || ch == ' ' ||
					ch == 'A' || ch == 'S' || ch == 'D' || ch == 'W')
					break;
			}
			goto p;
		}
	}break;
	case 'a':
	case 'A':
	{
		while (s.cheak())
		{
			s.LeftMove();              //左移
			s.clean();                 //清理
			s.display_num();           //顯示數字
			while (1)
			{
				ch = _getch();
				if (ch == 'a' || ch == 's' || ch == 'd' || ch == 'w' || ch == ' ' ||
					ch == 'A' || ch == 'S' || ch == 'D' || ch == 'W')
					break;
			}
			goto p;
		}
	}break;
	case 'w':
	case 'W':
	{
		while (s.cheak())
		{
			s.UpMove();               //上移
			s.clean();                //清理
			s.display_num();          //顯示數字
			while (1)
			{
				ch = _getch();
				if (ch == 'a' || ch == 's' || ch == 'd' || ch == 'w' || ch == ' ' ||
					ch == 'A' || ch == 'S' || ch == 'D' || ch == 'W')
					break;
			}
			goto p;
		}
	}break;
	default:
		break;
	}                            //退出switch，遊戲結束
	system("cls");               //清屏
	timer.stop();
	cout << "                         Failed" << endl;
	cout << "                        Score:" << New2048().score() << endl;
	cout << "                       Time:" << timer.elapsedSeconds() << endl;
	cout << "               PLAY AGAIN ? YES(Y) : NO(N)" << endl;
	while (1)
	{
		ch = _getch();
		if (ch == 'y' || ch == 'n' || ch == 'Y' || ch == 'N')
			break;
	}
	if (ch == 'y' || ch == 'Y')          //Y繼續
		{
		timer.reset();
		continue;
		}
	else                                 //否則退出
		break;
	}
	return 0;
}