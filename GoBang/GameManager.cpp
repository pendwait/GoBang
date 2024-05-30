//GameManager.cpp成员函数实现
#include "GameManager.h"
#include "Player.h"
#include "Board.h"
#include "AiStrategy.h"
#include <iostream>

using namespace std;
extern Board Chess;

void GameManager::select_mode()//进行模式的选择，确定m
{
	char t = 'a';
	cout << "请选择对战模式：" << endl;
	cout << "输入0，进入双人对战;" << endl;
	cout << "输入1，进入人机对战；" << endl;
	cout << "输入2，退出游戏；" << endl;
	cin >> t;
	if (t == '0') {
		m = 0;//双人对战模式
	}
	if (t == '1') {
		m = 1;//人机对战模式
	}
	if(t=='2')
	{
		exit(0);
	}
	else if (t != '0' && t != '1')
	{
		cout << "输入错误，请重新输入" << endl;
		GameManager::select_mode();//进行递归
	}
}

void GameManager::play_game(int& m)//主循环
{
	if (m == 0) {
		Player player1;
		Player player2;
		while (true) {
			coordinate temp1= player1.playchess1();
			Chess.show();
			if (Chess.judgewinner1('0',temp1) || Chess.judgewinner2('0',temp1) || Chess.judgewinner3('0',temp1) ||Chess.judgewinner4('0',temp1))
			{
				cout << "玩家1胜！！！";
				break;
			}
			coordinate temp2 = player2.playchess2();
			Chess.show();
			if (Chess.judgewinner1('1', temp2) || Chess.judgewinner2('1', temp2) || Chess.judgewinner3('1', temp2) || Chess.judgewinner4('1', temp2))
			{
				cout << "玩家2胜！！！";
				break;
			}
		}
	}
	else if (m == 1) {
		Player player1;
		AiStrategy player3;
		while (true) {
			coordinate temp1 = player1.playchess1();
			Chess.show();
			if (Chess.judgewinner1('0', temp1) || Chess.judgewinner2('0', temp1) || Chess.judgewinner3('0', temp1) || Chess.judgewinner4('0', temp1))
			{
				cout << "玩家1胜！！！";
				break;
			}
			coordinate temp2 = player3.Get_key_Setchess();
			Chess.show();
			if (Chess.judgewinner1('2', temp2) || Chess.judgewinner2('2', temp2) || Chess.judgewinner3('2', temp2) || Chess.judgewinner4('2', temp2))
			{
				cout << "电脑胜！！！";
				break;
			}
		}
	}
}

