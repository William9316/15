#ifndef Header_h
#define Header_h

class New2048
{
public:
	New2048()                       //�غc�禡�A��l�ܸ��
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				a[i][j] = 0;
		num = 0;
	}
	void make_frame();             //�C�L�ج[�禡
	void display_num();            //�C�L�Ʀr�禡
	void creat_num();              //�H�����ͼƨ禡
	void RightMove();              //�k���禡
	void LeftMove();               //�����禡
	void UpMove();		           //�W���禡
	void DownMove();	           //�U���禡
	int cheak();                   //�ˬd�C���O�_�����禡
	void clean();                  //�M�z��ܥX�Ӫ��Ʀr
	int score();
	~New2048() {}

private:
	int a[4][4];
	int num;
};
#endif