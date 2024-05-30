#pragma once
#include <vector>
#include <iostream>
#include "coordinate.h"
#include "Board.h"

using namespace std;

extern Board Chess;
class AiStrategy
{
public:
	bool is_Ok(int x, int y) { return x >= 0 && y >= 0 && x < 15 && y < 15; };

	//�ĸ���ڣ����ڻ�ȡ����x,y���ĸ��������Ԫ����������ص����������
	vector<int> Get_Nums1(int x, int y);
	vector<int> Get_Nums2(int x, int y);
	vector<int> Get_Nums3(int x, int y);
	vector<int> Get_Nums4(int x, int y);

	//һ����Ԫ���ڣ����ݵ������������ȡ�÷�
	int x_Points(vector<int> nums);

	//����õ��λ�ã���ȡ�õ�ĵ÷�
	int GetPoints(int x, int y);

	//����ai��ѵ�λ��
	coordinate Get_key_Setchess();
};