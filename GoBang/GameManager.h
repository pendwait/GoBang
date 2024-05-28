#pragma once
using namespace std;
class GameManager
{
public:
	//属性
	int mode;//对战模式,0为人机对战，1为双人对战
	int& m = mode;
	//方法
	void select_mode();//进行模式的选择，确定m
	void judge_game_over();
};



//### 3. 游戏管理类（`GameManager`）
//
//* **属性 * *：
//- 当前棋盘对象。
//- 当前玩家对象（或两个，一个用于玩家1，一个用于玩家2）。
//- 游戏模式（例如，枚举：人机对战、双人对战）。
//
//* **方法 * *：
//- 开始新游戏。
//- 切换玩家。
//- 处理玩家落子。
//- 检查游戏结束条件。
//- 显示游戏结果。
//- 处理悔棋请求。
//