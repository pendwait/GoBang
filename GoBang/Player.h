#pragma once
#include <vector>
#include "coordinate.h"
using namespace std;
extern const int N;
class Player
{
public:
	//属性
	int type;//- 玩家类型（例如，枚举：人机、玩家1、玩家2）
	vector<int> color;

	//方法
	coordinate playchess1();
	coordinate playchess2();
	coordinate computerplayer();
};


//### 2. 玩家类（`Player`）
//
//* **属性 * *：
//- 玩家类型（例如，枚举：人机、玩家1、玩家2）。
//- 玩家颜色（对应`Board`中的表示）。
//* **方法 * *：
//- 获取下一步棋的位置（对于人机玩家，这将是AI计算的结果；对于真实玩家，可能是从输入获取的）。
//