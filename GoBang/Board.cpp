#include "Board.h"
#include "coordinate.h"
#include <vector>
#include <windows.h>
#include <iostream>

using namespace std;
Board::Board() : board(15, vector<int>(15, -1))
{
	cout << "Board Chess创建成功" << endl;
	//构造函数初始化棋盘为-1，表示空；0表示玩家1黑子，1表示玩家2白子，2表示机器
}
void Board::color(int a)//改变颜色的函数
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
				cout << "●";
			}
			else if (board[i][j] == 1) {
				color(0x7f);
				cout << "●";
			}
		}
		cout << endl;
	}
}


bool Board::judgewinner1(char a, coordinate temp)//判断横排
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
bool Board::judgewinner2(char a, coordinate temp)//判断竖排
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
bool Board::judgewinner3(char a, coordinate temp)//判断主对角线
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
bool Board::judgewinner4(char a, coordinate temp)//判断负对角线
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
bool Board::judgeheqi()//判断和棋
{
	for (int i = 1; i < N; ++i)
		for (int j = 1; j < N; ++j)
			if (board[i][j] == ' ')return 1;
	return -1;
}