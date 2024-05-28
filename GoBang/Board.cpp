#include "Board.h"
#include "coordinate.h"
#include <vector>
#include <windows.h>
#include <iostream>

using namespace std;
Board::Board() : board(15, vector<int>(15, -1))
{
	cout << "Board Chess�����ɹ�" << endl;
	//���캯����ʼ������Ϊ-1����ʾ�գ�0��ʾ���1���ӣ�1��ʾ���2���ӣ�2��ʾ����
}
void Board::color(int a)//�ı���ɫ�ĺ���
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

void Board::show()
{
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == -1) {
				cout << " ";
			}
			else if (board[i][j] == 0) {
				color(0x70);
				cout << "��";
			}
			else if (board[i][j] == 1) {
				color(0x7f);
				cout << "��";
			}
		}
		cout << endl;
	}
}


bool Board::judgewinner1(char a, coordinate temp)//�жϺ���
{
	coordinate begin, end;
	begin.x = end.x = temp.x;
	if (temp.y <= 5)begin.y = 1;
	else begin.y = temp.y - 4;
	if (temp.y >= N - 5)end.y = N - 1;
	else end.y = temp.y + 4;
	for (int i = begin.x, j = begin.y; j <= end.y - 4; ++j)
	{
		if (board[i][j] == a
			&& board[i][j] == board[i][j + 1]
			&& board[i][j + 1] == board[i][j + 2]
			&& board[i][j + 2] == board[i][j + 3]
			&& board[i][j + 3] == board[i][j + 4])
			return 1;
	}
	return 0;
}
bool Board::judgewinner2(char a, coordinate temp)//�ж�����
{
	coordinate begin, end;
	begin.y = end.y = temp.y;
	if (temp.x <= 5)begin.x = 1;
	else begin.x = temp.x - 4;
	if (temp.x >= N - 5)end.x = N - 1;
	else end.x = temp.x + 4;
	for (int i = begin.x, j = begin.y; i <= end.x - 4; ++i)
	{
		if (board[i][j] == a
			&& board[i][j] == board[i + 1][j]
			&& board[i + 1][j] == board[i + 2][j]
			&& board[i + 2][j] == board[i + 3][j]
			&& board[i + 3][j] == board[i + 4][j])
			return 1;
	}
	return 0;
}
bool Board::judgewinner3(char a, coordinate temp)//�ж����Խ���
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
		if (board[i][j] == a && board[i][j] == board[i + 1][j + 1]
			&& board[i + 1][j + 1] == board[i + 2][j + 2]
			&& board[i + 2][j + 2] == board[i + 3][j + 3]
			&& board[i + 3][j + 3] == board[i + 4][j + 4])
			return 1;
	}
	return 0;
}
bool Board::judgewinner4(char a, coordinate temp)//�жϸ��Խ���
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
		if (board[i][j] == a
			&& board[i][j] == board[i + 1][j - 1]
			&& board[i + 1][j - 1] == board[i + 2][j - 2]
			&& board[i + 2][j - 2] == board[i + 3][j - 3]
			&& board[i + 3][j - 3] == board[i + 4][j - 4])
			return 1;
	}
	return 0;
}
bool Board::judgeheqi()//�жϺ���
{
	for (int i = 1; i < N; ++i)
		for (int j = 1; j < N; ++j)
			if (board[i][j] == ' ')return 1;
	return -1;
}