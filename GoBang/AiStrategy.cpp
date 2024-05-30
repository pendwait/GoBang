#include "AiStrategy.h"
#include "Board.h"
#include "GameManager.h"

using namespace std;

//分数有当前点的分数，一个玩家总的分数

//获取该点的得分
int AiStrategy::GetPoints(int x, int y)
{
	int points = 0;
	int x1 = x, y1 = y, x2 = x, y2 = y, x3 = x, y3 = y, x4 = x, y4 = y;
	for (int i = 0; i < 5; i++) {
		if (is_Ok(x1, y1)) {
			points += x_Points(Get_Nums1(x1, y1));
			y1++;
		}
		if (is_Ok(x2, y2)) {
			points += x_Points(Get_Nums2(x2, y2));
			x2++;
		}
		if (is_Ok(x3, y3)) {
			points += x_Points(Get_Nums3(x3, y3));
			x3--, y3++;
		}
		if (is_Ok(x4, y4)) {
			points += x_Points(Get_Nums4(x4, y4));
			x4++, y4++;
		}
	}
	return points;
}


//一个五元组内，根据敌我棋的数量获取得分
int AiStrategy::x_Points(vector<int> nums)
{
	if (nums.empty())	return 0;
	int g, b;
	g = nums[0], b = nums[1];/*g是我方，b是电脑*/
	if (g == 0 && b == 0)		return 10;
	else if (g == 1 && b == 0)	return 35;
	else if (g == 2 && b == 0)	return 1500;
	else if (g == 3 && b == 0)	return 18000;
	else if (g == 4 && b == 0)	return 1000000;
	else if (g == 0 && b == 1)	return 15;
	else if (g == 0 && b == 2)	return 400;
	else if (g == 0 && b == 3)	return 6000;
	else if (g == 0 && b == 4)	return 150000;
	else if (g != 0 && b != 0)	return 0;
	return 0;
}
//四个借口，用于获取包含x,y点四个方向的五元组情况，返回敌我棋的数量
//0表示玩家1黑子,1表示玩家2白子，2表示ai白子
//k和t是什么呢？
vector<int> AiStrategy::Get_Nums1(int x, int y)
{
	int k = 0, t = 0, cnt = 5;
	while (cnt-- && is_Ok(x, y)) {
		if (Chess.board[x][y] == '0') k++;
		if (Chess.board[x][y] == '2') t++;
		y--;
	}
	if (cnt >= 0)	return {};
	return vector<int>({ k, t });
}

vector<int> AiStrategy::Get_Nums2(int x, int y)
{
	int k = 0, t = 0, cnt = 5;
	while (cnt-- && is_Ok(x, y)) {
		if (Chess.board[x][y] == '0') k++;
		if (Chess.board[x][y] == '2') t++;
		x--;
	}
	if (cnt >= 0)	return {};
	return vector<int>({ k, t });
}

vector<int> AiStrategy::Get_Nums3(int x, int y)
{
	int k = 0, t = 0, cnt = 5;
	while (cnt-- && is_Ok(x, y)) {
		if (Chess.board[x][y] == '0') k++;
		if (Chess.board[x][y] == '2') t++;
		x++, y--;
	}
	if (cnt >= 0)	return {};
	return vector<int>({ k,t });
}

vector<int> AiStrategy::Get_Nums4(int x, int y) {
	int k = 0, t = 0, cnt = 5;
	while (cnt-- && is_Ok(x, y)) {
		if (Chess.board[x][y] == '0') k++;
		if (Chess.board[x][y] == '2') t++;
		x--, y--;
	}
	if (cnt >= 0)	return {};
	return vector<int>({ k,t });
}



// 返回ai最佳点位置  
coordinate AiStrategy::Get_key_Setchess() {
	coordinate temp;
	int points, maxpoints = -1, maxx = 0, maxy = 0;
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			if (Chess.board[i][j] == '0'|| Chess.board[i][j]=='2') {
				continue;
			}
			points = GetPoints(i, j);
			if (points > maxpoints) {
				maxpoints = points;
				maxx = i;
				maxy = j;
			}
		}
	}
	temp.x = maxx;
	temp.y = maxy;
	Chess.board[maxx][maxy] = '2';
	return temp; 
}
//coordinate temp;
//srand((unsigned)time(NULL));
//int x1 = 0, y1 = 0;
//while ((x1 = (rand() % (N - 1)) + 1) && (y1 = (rand() % (N - 1)) + 1))
//{
//	if (Chess.board[x1][y1] == -1) {
//		Chess.board[x1][y1] = '1';//2表示ai白子
//		break;
//	}
//	else continue;
//}
//temp.x = x1; temp.y = y1;
//return temp;
// 
// 
// 
// 
// 
//coordinate AiStrategy::Get_key_Setchess()
//{
//	int points, maxpoints = -1, maxx = 0, maxy = 0;
//	int book = 0, cnt = 324 - 2 * mychs.steps;
//	vector<vector<int>> visit(map);
//	/*记录当前需要遍历的次数*/
//	while (book != cnt) {
//		int i, j;
//		/*使得电脑下棋尽可能随机化*/
//		srand((unsigned)time(0));
//		do {
//			i = rand() % 18;
//			j = rand() % 18;
//		} while (visit[i][j] != -1);
//		visit[i][j] = 0;
//		points = GetPoints(i, j);
//		/*获取最大的分点*/
//		if (points > maxpoints) {
//			maxpoints = points;
//			maxx = i;
//			maxy = j;
//		}
//		book++;
//	}
//	return;
//}