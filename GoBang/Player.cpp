#include "Player.h"
#include "Board.h"
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;
extern Board Chess;
coordinate Player::playchess1()  //���һ����
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
		if (Chess.board[x1][y1] == ' ') {
			Chess.board[x1][y1] = '0';//0��ʾ���1����
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
coordinate Player::playchess2()  //��Ҷ�����
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
		if (Chess.board[x2][y2] == ' ') {
			Chess.board[x2][y2] = '1';//1��ʾ���2����
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
coordinate Player::computerplayer()//��������
{
	coordinate temp;
	srand((unsigned)time(NULL));
	int x1 = 0, y1 = 0;
	while ((x1 = (rand() % (N - 1)) + 1) && (y1 = (rand() % (N - 1)) + 1))
	{
		if (Chess.board[x1][y1] == ' ') {
			Chess.board[x1][y1] = '2';//2��ʾai����
			break;
		}
		else continue;
	}
	temp.x = x1; temp.y = y1;
	return temp;
}