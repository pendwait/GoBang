#pragma once
#include <vector>
#include "coordinate.h"
using namespace std;
extern const int N;
class Player
{
public:
	//����
	int type;//- ������ͣ����磬ö�٣��˻������1�����2��
	vector<int> color;

	//����
	coordinate playchess1();
	coordinate playchess2();
	coordinate computerplayer();
};


//### 2. ����ࣨ`Player`��
//
//* **���� * *��
//- ������ͣ����磬ö�٣��˻������1�����2����
//- �����ɫ����Ӧ`Board`�еı�ʾ����
//* **���� * *��
//- ��ȡ��һ�����λ�ã������˻���ң��⽫��AI����Ľ����������ʵ��ң������Ǵ������ȡ�ģ���
//