//GameManager.cpp��Ա����ʵ��
#include "GameManager.h"
#include <iostream>

using namespace std;

void GameManager::select_mode()//����ģʽ��ѡ��ȷ��m
{
	char t='a';
	cout << "����0�������˻���ս������1������˫�˶�ս" << endl;
	cin >> t;
	if (t == '0') {
		m = 0;//�˻���սģʽ
	}
	if (t == '1') {
		m = 1;//˫�˶�սģʽ
	}
	else if(t!='0' && t!='1')
	{
		cout << "�����������������" << endl;
		GameManager::select_mode();//���еݹ�
	}
}