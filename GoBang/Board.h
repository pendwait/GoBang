#pragma once
#include <vector>
#include "coordinate.h"
using namespace std;
extern const int N;
class Board
{
public:
	Board* p;
	vector<vector<int>> board;	//����Ķ���  vector<int,vector<int> board;
	//����
	int now_player;// ��ǰ��ң�0��ʾ���1���ӣ�1��ʾ���2���ӣ�2��ʾ������
	int status;// ��Ϸ״̬�����磬�����С���ʤ����ʤ��ƽ�֣�
	bool retract_flag;// �Ƿ��������ı�־��

	//����
	Board();//���캯��ԭ������
	bool check();// ���������ĳλ���Ƿ��������
	bool judgewinner1(char a, coordinate temp);//�жϺ���
	bool judgewinner2(char a, coordinate temp);//�ж�����
	bool judgewinner3(char a, coordinate temp);//�ж����Խ���
	bool judgewinner4(char a, coordinate temp);//�жϸ��Խ���
	bool judgeheqi();
	void retract();//- ���壨�������
	void show();//- ��ӡ����״̬
	void color(int a);
};