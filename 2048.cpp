#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include "Header.h"
using namespace std;

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);    //獲取控制代碼

int i = 0;

void gotoxy(HANDLE hOut, int x, int y)            //輸出位置的函式
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);
}
void New2048::make_frame()                       //列印框架
{
	gotoxy(hOut, 0, 0);
	cout << "         得分" << endl;
	cout << "口口口口口口口口口口口口口" << endl;
	cout << "口    口    口    口    口" << endl;
	cout << "口口口口口口口口口口口口口" << endl;
	cout << "口    口    口    口    口" << endl;
	cout << "口口口口口口口口口口口口口" << endl;
	cout << "口    口    口    口    口" << endl;
	cout << "口口口口口口口口口口口口口" << endl;
	cout << "口    口    口    口    口" << endl;
	cout << "口口口口口口口口口口口口口" << endl;
}
void New2048::clean()
{
	int k = 0, l = 0;
	for (int i = 2; i < 21, k < 4; i = i + 6)    //找到對應的框，輸入空格
	{
		l = 0;
		for (int j = 2; j < 9; j = j + 2)
		{
			gotoxy(hOut, i, j);
			printf("    ");
			l++;
		}
		k++;
	}
}
void New2048::display_num()                          //列印數字
{
	int k = 0, l = 0;
	for (int i = 2; i < 21, k < 4; i = i + 6)    //找到對應的框，輸入數字
	{
		l = 0;
		for (int j = 2; j < 9; j = j + 2)
		{
			gotoxy(hOut, i, j);          //找到各個位置並輸出數字
			a[l][k] == 0 ? printf(" ") : printf("%d", a[l][k]);
			l++;
		}
		k++;
	}
	gotoxy(hOut, 13, 0);
	cout << num * 10;
	i = num * 10;
	gotoxy(hOut, 0, 10);
}

int New2048::score() {
	return i;
}

void New2048::creat_num()                     //隨機產生座標位置和該位置的數 2 或 4
{
	int i, j, num;
	srand((unsigned)time(NULL));             //隨機數產生初始化，不然產生的數一直相同        
	i = (rand() % (4)) + 0;
	j = (rand() % (4)) + 0;
	while (a[i][j])                           //該位置上的數不是0，重新產生
	{
		i = (rand() % (4)) + 0;
		j = (rand() % (4)) + 0;
	}
	num = (rand() % (4)) + 1;                //產生的是1或3就自增
	if (num == 1)
		++num;
	if (num == 3)
		--num;
	a[i][j] = num;
}
int New2048::cheak()
{
	int i, j, flag = 0, tag = 0;
	for (i = 0; i < 4; i++)                  //檢查是否還有位置，有，tag = 1。
	{
		for (j = 0; j < 4; j++)
		{
			if (a[i][j] == 0)
			{
				tag = 1;
				break;
			}
		}
		if (tag == 1)
			break;
	}
	if (tag)                               //有，返回1。
		return 1;
	for (i = 0; i < 4; i++)                //檢查左右的相鄰是否有相等，是，flag = 1，退出迴圈
	{
		for (j = 0; j < 3; j++)
		{
			if (a[i][j] == a[i][j + 1])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	for (j = 0; j < 4; j++)                //檢查上下的相鄰是否有想等，是，flag = 1，退出迴圈
	{
		for (i = 0; i < 3; i++)
		{
			if (a[i][j] == a[i + 1][j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	if (tag == 0 && flag == 0)            //flag = 0 和 tag = 0，遊戲結束。
		return 0;
	else                                  //否則，繼續遊戲
		return 1;
}
void New2048::DownMove()                  //下移的情況
{
	int k, tag = 0;
	for (int i = 0; i < 4; i++)           //從每一列開始
	{
		int b[4] = { 0 };				 //定義一個臨時陣列來儲存相加之後的情況
		k = 3;
		for (int j = 3; j > 0; j--)
		{
			if (a[j][i] != 0)
			{
				int flag = 0;
				for (int l = j - 1; l >= 0; l--)    //找是否有相同的數
				{
					if (a[l][i] != 0)
					{
						flag = 1;
						if (a[l][i] == a[j][i])
						{
							b[k--] = 2 * a[j][i];
							num++;
							a[l][i] = a[j][i] = 0;
							break;
						}
						else
						{
							b[k--] = a[j][i];
							break;
						}
					}
				}
				if (flag == 0)
					b[k--] = a[j][i];
			}
		}
		b[k] = a[0][i];                 //最後一個沒有檢查，賦值過去，不管是否為0，都無所謂的
		for (int j = 0; j < 4; j++)     //檢查是否有移動
		{
			if (a[j][i] != b[j])
			{
				tag = 1;
				break;
			}
		}
		for (int j = 0; j < 4; j++)    //將結果覆蓋回去
			a[j][i] = b[j];
	}
	if (tag)                          //存在移動，產生新的數
		creat_num();
}
void New2048::LeftMove()                 //同上
{
	int k, tag = 0;
	for (int i = 0; i < 4; i++)
	{
		int b[4] = { 0 };
		k = 0;
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] != 0)
			{
				int flag = 0;
				for (int l = j + 1; l < 4; l++)
				{
					if (a[i][l] != 0)
					{
						flag = 1;
						if (a[i][l] == a[i][j])
						{
							b[k++] = 2 * a[i][j];
							num++;
							a[i][j] = a[i][l] = 0;
							break;
						}
						else
						{
							b[k++] = a[i][j];
							break;
						}
					}
				}
				if (flag == 0)
					b[k++] = a[i][j];
			}
		}
		b[k] = a[i][3];
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] != b[j])
			{
				tag = 1;
				break;
			}
		}
		for (int j = 0; j < 4; j++)
			a[i][j] = b[j];
	}
	if (tag)
		creat_num();
}
void New2048::RightMove()              //同上
{
	int k, tag = 0;
	for (int i = 0; i < 4; i++)
	{
		int b[4] = { 0 };
		k = 3;
		for (int j = 3; j > 0; j--)
		{
			if (a[i][j] != 0)
			{
				int flag = 0;
				for (int l = j - 1; l >= 0; l--)
				{
					if (a[i][l] != 0)
					{
						flag = 1;
						if (a[i][l] == a[i][j])
						{
							b[k--] = 2 * a[i][j];
							num++;
							a[i][j] = a[i][l] = 0;
							break;
						}
						else
						{
							b[k--] = a[i][j];
							break;
						}
					}
				}
				if (flag == 0)
					b[k--] = a[i][j];
			}
		}
		b[k] = a[i][0];
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] != b[j])
			{
				tag = 1;
				break;
			}
		}
		for (int j = 0; j < 4; j++)
			a[i][j] = b[j];
	}
	if (tag)
		creat_num();
}
void New2048::UpMove()
{
	int k, tag = 0;
	for (int i = 0; i < 4; i++)
	{
		int b[4] = { 0 };                 //定義一個臨時陣列來儲存相加之後的情況
		k = 0;
		for (int j = 0; j < 3; j++)
		{
			if (a[j][i] != 0)
			{
				int flag = 0;
				for (int l = j + 1; l < 4; l++)    //找是否有相同的數
				{
					if (a[l][i] != 0)
					{
						flag = 1;
						if (a[l][i] == a[j][i])
						{
							b[k++] = 2 * a[j][i];
							num++;
							a[l][i] = a[j][i] = 0;
							break;
						}
						else
						{
							b[k++] = a[j][i];
							break;
						}
					}
				}
				if (flag == 0)
					b[k++] = a[j][i];
			}
		}
		b[k] = a[3][i];
		for (int j = 0; j < 4; j++)
		{
			if (a[j][i] != b[j])
			{
				tag = 1;
				break;
			}
		}
		for (int j = 0; j < 4; j++)      //將結果覆蓋回去
			a[j][i] = b[j];
	}
	if (tag)
		creat_num();
}