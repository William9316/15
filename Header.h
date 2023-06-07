#ifndef Header_h
#define Header_h

class New2048
{
public:
	New2048()                       //建構函式，初始話資料
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				a[i][j] = 0;
		num = 0;
	}
	void make_frame();             //列印框架函式
	void display_num();            //列印數字函式
	void creat_num();              //隨機產生數函式
	void RightMove();              //右移函式
	void LeftMove();               //左移函式
	void UpMove();		           //上移函式
	void DownMove();	           //下移函式
	int cheak();                   //檢查遊戲是否結束函式
	void clean();                  //清理顯示出來的數字
	int score();
	~New2048() {}

private:
	int a[4][4];
	int num;
};
#endif