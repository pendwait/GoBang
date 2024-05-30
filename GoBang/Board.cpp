#include "Board.h"
#include "coordinate.h"
#include <vector>
#include <windows.h>
#include <iostream>
#include<windows.h>


using namespace std;
Board::Board() : board(15, vector<int>(15, -1))
{
	//cout << "Board Chess�����ɹ�" << endl;
	//���캯����ʼ������Ϊ-1����ʾ�գ�0��ʾ���1���ӣ�1��ʾ���2���ӣ�2��ʾ����

}
void Board::color(int a)//�ı���ɫ�ĺ���
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

void Board::show()
{
	extern Board Chess;
	system("cls");
	system("color 70");
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (Chess.board[i][j] == '0')
			{
				color(0x70);
				cout << "��";
			}
			else if (Chess.board[i][j] == '1' || Chess.board[i][j] == '2')
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
		color(0x70);
		cout << i;
		cout << endl;
		//color(0x70);
	}
	//color(0x76);
	color(0x70);
	cout << "0123456789ABCDE"<<endl;
	color(0x70);
}


bool Board::judgewinner1(char a, coordinate temp)//�жϺ���
{
	extern Board Chess;
	coordinate begin, end;
	begin.x = end.x = temp.x;
	if (temp.y <= 5)begin.y = 0;
	else begin.y = temp.y - 4;
	if (temp.y >= N - 5)end.y = N - 1;
	else end.y = temp.y + 4;
	for (int i = begin.x, j = begin.y; j <= end.y - 4; ++j)
	{
		if (Chess.board[i][j] == a
			&& Chess.board[i][j] == Chess.board[i][j + 1]
			&& Chess.board[i][j + 1] == Chess.board[i][j + 2]
			&& Chess.board[i][j + 2] == Chess.board[i][j + 3]
			&& Chess.board[i][j + 3] == Chess.board[i][j + 4])
			return 1;
	}
	return 0;
}
bool Board::judgewinner2(char a, coordinate temp)//�ж�����
{
	extern Board Chess;
	coordinate begin, end;
	begin.y = end.y = temp.y;
	if (temp.x <= 5)begin.x = 0;
	else begin.x = temp.x - 4;
	if (temp.x >= N - 5)end.x = N - 1;
	else end.x = temp.x + 4;
	for (int i = begin.x, j = begin.y; i <= end.x - 4; ++i)
	{
		if (Chess.board[i][j] == a
			&& Chess.board[i][j] == Chess.board[i + 1][j]
			&& Chess.board[i + 1][j] == Chess.board[i + 2][j]
			&& Chess.board[i + 2][j] == Chess.board[i + 3][j]
			&& Chess.board[i + 3][j] == Chess.board[i + 4][j])
			return 1;
	}
	return 0;
}
bool Board::judgewinner3(char a, coordinate temp)//�ж����Խ���
{
	extern Board Chess;
	coordinate begin, end;
	if (temp.x <= 5)begin.x = 0;
	else begin.x = temp.x - 4;
	if (temp.y <= 5)begin.y = 0;
	else begin.y = temp.y - 4;
	if (temp.x >= N - 5)end.x = N - 1;
	else end.x = temp.x + 4;
	if (temp.y >= N - 5)end.y = N - 1;
	else end.y = temp.y + 4;
	for (int i = begin.x, j = begin.y; i <= end.x - 4 && j <= end.y - 4; ++i, ++j)
	{
		if (Chess.board[i][j] == a && Chess.board[i][j] == Chess.board[i + 1][j + 1]
			&& Chess.board[i + 1][j + 1] == Chess.board[i + 2][j + 2]
			&& Chess.board[i + 2][j + 2] == Chess.board[i + 3][j + 3]
			&& Chess.board[i + 3][j + 3] == Chess.board[i + 4][j + 4])
			return 1;
	}
	return 0;
}
bool Board::judgewinner4(char a, coordinate temp)//�жϸ��Խ���
{
	extern Board Chess;
	coordinate begin, end;
	if (temp.x <= 5)begin.x = 0;
	else begin.x = temp.x - 4;
	if (temp.y >= N - 5)begin.y = N - 1;
	else begin.y = temp.y + 4;
	if (temp.x >= N - 5)end.x = N - 1;
	else end.x = temp.x + 4;
	if (temp.y <= 5)end.y = 0;
	else end.y = temp.y - 4;
	for (int i = begin.x, j = begin.y; i <= end.x - 4 && j >= end.y - 4; ++i, --j)
	{
		if (Chess.board[i][j] == a
			&& Chess.board[i][j] == Chess.board[i + 1][j - 1]
			&& Chess.board[i + 1][j - 1] == Chess.board[i + 2][j - 2]
			&& Chess.board[i + 2][j - 2] == Chess.board[i + 3][j - 3]
			&& Chess.board[i + 3][j - 3] == Chess.board[i + 4][j - 4])
			return 1;
	}
	return 0;
}
bool Board::judgeheqi()//�жϺ���
{
	extern Board Chess;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (Chess.board[i][j] == -1)return 1;
	return -1;
}