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

	//四个借口，用于获取包含x,y点四个方向的五元组情况，返回敌我棋的数量
	vector<int> Get_Nums1(int x, int y);
	vector<int> Get_Nums2(int x, int y);
	vector<int> Get_Nums3(int x, int y);
	vector<int> Get_Nums4(int x, int y);

	//一个五元组内，根据敌我棋的数量获取得分
	int x_Points(vector<int> nums);

	//传入该点的位置，获取该点的得分
	int GetPoints(int x, int y);

	//返回ai最佳点位置
	coordinate Get_key_Setchess();
};