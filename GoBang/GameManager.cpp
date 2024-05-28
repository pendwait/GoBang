//GameManager.cpp成员函数实现
#include "GameManager.h"
#include <iostream>

using namespace std;

void GameManager::select_mode()//进行模式的选择，确定m
{
	char t='a';
	cout << "输入0，进入人机对战；输入1，进入双人对战" << endl;
	cin >> t;
	if (t == '0') {
		m = 0;//人机对战模式
	}
	if (t == '1') {
		m = 1;//双人对战模式
	}
	else if(t!='0' && t!='1')
	{
		cout << "输入错误，请重新输入" << endl;
		GameManager::select_mode();//进行递归
	}
}