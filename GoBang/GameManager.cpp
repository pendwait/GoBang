//GameManager.cpp��Ա����ʵ��
#include "GameManager.h"
#include "Player.h"
#include "Board.h"
#include "AiStrategy.h"
#include <iostream>

using namespace std;
extern Board Chess;

void GameManager::select_mode()//����ģʽ��ѡ��ȷ��m
{
	char t = 'a';
	cout << "��ѡ���սģʽ��" << endl;
	cout << "����0������˫�˶�ս;" << endl;
	cout << "����1�������˻���ս��" << endl;
	cout << "����2���˳���Ϸ��" << endl;
	cin >> t;
	if (t == '0') {
		m = 0;//˫�˶�սģʽ
	}
	if (t == '1') {
		m = 1;//�˻���սģʽ
	}
	if(t=='2')
	{
		exit(0);
	}
	else if (t != '0' && t != '1')
	{
		cout << "�����������������" << endl;
		GameManager::select_mode();//���еݹ�
	}
}

void GameManager::play_game(int& m)//��ѭ��
{
	if (m == 0) {
		Player player1;
		Player player2;
		while (true) {
			coordinate temp1= player1.playchess1();
			Chess.show();
			if (Chess.judgewinner1('0',temp1) || Chess.judgewinner2('0',temp1) || Chess.judgewinner3('0',temp1) ||Chess.judgewinner4('0',temp1))
			{
				cout << "���1ʤ������";
				break;
			}
			coordinate temp2 = player2.playchess2();
			Chess.show();
			if (Chess.judgewinner1('1', temp2) || Chess.judgewinner2('1', temp2) || Chess.judgewinner3('1', temp2) || Chess.judgewinner4('1', temp2))
			{
				cout << "���2ʤ������";
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
				cout << "���1ʤ������";
				break;
			}
			coordinate temp2 = player3.Get_key_Setchess();
			Chess.show();
			if (Chess.judgewinner1('2', temp2) || Chess.judgewinner2('2', temp2) || Chess.judgewinner3('2', temp2) || Chess.judgewinner4('2', temp2))
			{
				cout << "����ʤ������";
				break;
			}
		}
	}
}

