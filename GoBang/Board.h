#pragma once
#include <vector>
#include "coordinate.h"
using namespace std;
extern const int N;
class Board
{
public:
	Board* p;
	vector<vector<int>> board;	//错误的定义  vector<int,vector<int> board;
	//属性
	int now_player;// 当前玩家（0表示玩家1黑子，1表示玩家2白子，2表示机器）
	int status;// 游戏状态（例如，进行中、白胜、黑胜、平局）
	bool retract_flag;// 是否允许悔棋的标志。

	//方法
	Board();//构造函数原型声明
	bool check();// 检查棋盘上某位置是否可以落子
	bool judgewinner1(char a, coordinate temp);//判断横排
	bool judgewinner2(char a, coordinate temp);//判断竖排
	bool judgewinner3(char a, coordinate temp);//判断主对角线
	bool judgewinner4(char a, coordinate temp);//判断副对角线
	bool judgeheqi();
	void retract();//- 悔棋（如果允许）
	void show();//- 打印棋盘状态
	void color(int a);
};