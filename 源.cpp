//���һ������á�x����ʶ,��Ҷ���'o'��ʶ
#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
using namespace::std;

#define N 20
char chessboardflag = ' ';  //���̱�־
void color(int a)//�ı���ɫ�ĺ���
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

class coordinate            //������
{
public:
	int x;
	int y;
};
class fivechess
{
public:
	void initchessboard()//��ʼ������
	{
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				chessboard[i][j] = chessboardflag;
		printchessboard();
	}
	void printchessboard()//��ӡ����
	{
		system("cls");
		system("color 70");
		cout << "  1 2 3 4 5 6 7 8 9 10111213141516171819" << endl;
		for (int i = 1; i < N; ++i) {
			for (int j = 0; j < N; ++j)
			{
				if (j == 0) {
					if (i <= 9)cout << i << " ";
					else cout << i;
				}
				else
				{
					if (chessboard[i][j] == 'x')
					{
						color(0x70);
						cout << "��";
					}
					else if (chessboard[i][j] == 'o')
					{
						color(0x7f);
						cout << "��";
					}
					else
					{
						color(0x76);
						cout << "��";
					}
				}
			}
			cout << endl;
			color(0x70);
		}
	}
	coordinate playchess1()  //���һ����
	{
		cout << "�����һ��������:" << endl;
		int x1, y1;
		while (cin >> x1 >> y1)
		{
			if (x1 > N - 1 || y1 > N - 1 || x1 < 0 || y1 < 0)
			{
				cout << "���볬�磬���������" << endl;
				continue;
			}
			if (chessboard[x1][y1] == ' ') {
				chessboard[x1][y1] = 'x';
				break;
			}
			else
			{
				cout << "�������,����������";
			}
		}
		coordinate temp;
		temp.x = x1;
		temp.y = y1;
		return temp;
	}
	coordinate playchess2()  //��Ҷ�����
	{
		cout << "�����2��������:" << endl;
		int x2, y2;
		while (cin >> x2 >> y2)
		{
			if (x2 > N - 1 || y2 > N - 1 || x2 < 0 || y2 < 0)
			{
				cout << "���볬�磬���������" << endl;
				continue;
			}
			if (chessboard[x2][y2] == ' ') {
				chessboard[x2][y2] = 'o';
				break;
			}
			else
			{
				cout << "�������,����������";
			}
		}
		coordinate temp;
		temp.x = x2;
		temp.y = y2;
		return temp;
	}
	coordinate computerplayer()//��������
	{
		coordinate temp;
		srand((unsigned)time(NULL));
		int x1 = 0, y1 = 0;
		while ((x1 = (rand() % (N - 1)) + 1) && (y1 = (rand() % (N - 1)) + 1))
		{
			if (chessboard[x1][y1] == ' ') {
				chessboard[x1][y1] = 'x';
				break;
			}
			else continue;
		}
		temp.x = x1; temp.y = y1;
		return temp;
	}
	int judgewiner1(char a, coordinate temp)//�жϺ���
	{
		coordinate begin, end;
		begin.x = end.x = temp.x;
		if (temp.y <= 5)begin.y = 1;
		else begin.y = temp.y - 4;
		if (temp.y >= N - 5)end.y = N - 1;
		else end.y = temp.y + 4;
		for (int i = begin.x, j = begin.y; j <= end.y - 4; ++j)
		{
			if (chessboard[i][j] == a
				&& chessboard[i][j] == chessboard[i][j + 1]
				&& chessboard[i][j + 1] == chessboard[i][j + 2]
				&& chessboard[i][j + 2] == chessboard[i][j + 3]
				&& chessboard[i][j + 3] == chessboard[i][j + 4])
				return 1;
		}
		return 0;
	}
	int judgewiner2(char a, coordinate temp)//�ж�����
	{
		coordinate begin, end;
		begin.y = end.y = temp.y;
		if (temp.x <= 5)begin.x = 1;
		else begin.x = temp.x - 4;
		if (temp.x >= N - 5)end.x = N - 1;
		else end.x = temp.x + 4;
		for (int i = begin.x, j = begin.y; i <= end.x - 4; ++i)
		{
			if (chessboard[i][j] == a
				&& chessboard[i][j] == chessboard[i + 1][j]
				&& chessboard[i + 1][j] == chessboard[i + 2][j]
				&& chessboard[i + 2][j] == chessboard[i + 3][j]
				&& chessboard[i + 3][j] == chessboard[i + 4][j])
				return 1;
		}
		return 0;
	}
	int judgewiner3(char a, coordinate temp)//�ж����Խ���
	{
		coordinate begin, end;
		if (temp.x <= 5)begin.x = 1;
		else begin.x = temp.x - 4;
		if (temp.y <= 5)begin.y = 1;
		else begin.y = temp.y - 4;
		if (temp.x >= N - 5)end.x = N - 1;
		else end.x = temp.x + 4;
		if (temp.y >= N - 5)end.y = N - 1;
		else end.y = temp.y + 4;
		for (int i = begin.x, j = begin.y; i <= end.x - 4 && j <= end.y - 4; ++i, ++j)
		{
			if (chessboard[i][j] == a && chessboard[i][j] == chessboard[i + 1][j + 1]
				&& chessboard[i + 1][j + 1] == chessboard[i + 2][j + 2]
				&& chessboard[i + 2][j + 2] == chessboard[i + 3][j + 3]
				&& chessboard[i + 3][j + 3] == chessboard[i + 4][j + 4])
				return 1;
		}
		return 0;
	}
	int judgewiner4(char a, coordinate temp)//�жϸ��Խ���
	{
		coordinate begin, end;
		if (temp.x <= 5)begin.x = 1;
		else begin.x = temp.x - 4;
		if (temp.y >= N - 5)begin.y = N - 1;
		else begin.y = temp.y + 4;
		if (temp.x >= N - 5)end.x = N - 1;
		else end.x = temp.x + 4;
		if (temp.y <= 5)end.y = 1;
		else end.y = temp.y - 4;
		for (int i = begin.x, j = begin.y; i <= end.x - 4 && j >= end.y - 4; ++i, --j)
		{
			if (chessboard[i][j] == a
				&& chessboard[i][j] == chessboard[i + 1][j - 1]
				&& chessboard[i + 1][j - 1] == chessboard[i + 2][j - 2]
				&& chessboard[i + 2][j - 2] == chessboard[i + 3][j - 3]
				&& chessboard[i + 3][j - 3] == chessboard[i + 4][j - 4])
				return 1;
		}
		return 0;
	}
	int judgeheqi()//�жϺ���
	{
		for (int i = 1; i < N; ++i)
			for (int j = 1; j < N; ++j)
				if (chessboard[i][j] == ' ')return 1;
		return -1;
	}
	void play()
	{
		initchessboard();//��ʼ������
		double t;
		cout << "��ѡ��ģʽ���˻�ģʽ����1������ģʽ����2��" << endl;
		cin >> t;
		while (t == 1)
		{
			int m = judgeheqi();
			if (m == -1)
			{
				cout << "����!!!" << endl;
				break;
			}
			coordinate temp1 = computerplayer();//��������
			printchessboard();//��ӡ����
			if (judgewiner1('x', temp1) || judgewiner2('x', temp1) || judgewiner3('x', temp1) || judgewiner4('x', temp1))
			{
				cout << "����ʤ������";
				break;
			}
			coordinate temp2 = playchess2();//���2����
			printchessboard();//��ӡ����
			if (judgewiner1('o', temp2) || judgewiner2('o', temp2) || judgewiner3('o', temp2) || judgewiner4('o', temp2))
			{
				cout << "���2ʤ!!!";
				break;
			}
		}
		while (t == 2)
		{
			int m = judgeheqi();
			if (m == -1)
			{
				cout << "����!!!" << endl;
				break;
			}
			coordinate temp1 = playchess1();//��������
			printchessboard();//��ӡ����
			if (judgewiner1('x', temp1) || judgewiner2('x', temp1) || judgewiner3('x', temp1) || judgewiner4('x', temp1))
			{
				cout << "���1ʤ������";
				break;
			}
			coordinate temp2 = playchess2();//���2����
			printchessboard();//��ӡ����
			if (judgewiner1('o', temp2) || judgewiner2('o', temp2) || judgewiner3('o', temp2) || judgewiner4('o', temp2))
			{
				cout << "���2ʤ!!!";
				break;
			}
		}
		if (t != 1 && t != 2)
		{
			play();
		}
	}
private:
	char chessboard[N][N];  //����
};
int main()
{
	fivechess one;
	one.play();
	return 0;
}




