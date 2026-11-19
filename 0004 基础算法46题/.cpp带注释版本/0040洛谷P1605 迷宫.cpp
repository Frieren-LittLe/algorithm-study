#include<iostream>
using namespace std;
// 本题四个方向可走导致状态成环、无拓扑序，且“不重复经过”的约束依赖整条路径历史，无法用二维 DP 表压缩——故无递推解法
// 拓扑序 = 把一堆事情排成一个先后顺序，保证"每件事在做之前，它依赖的事都已经做完了
 

// 经过对上题的锻炼，已经对dfs+递归有基础的了解
// 本题就是将dfs从一维转化为二维的方式

// 本题有"向四个方向移动"的步骤
// 在【基础语法】第38题【蛇形方阵】中我们已经学过:
// 用dx[i]，dy[i]两个值的搭配来模拟方向
// 用nx，ny来判断是否越界
// 套用在这题即可
int n, m, t, sx, sy, fx, fy;
int ans;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool ld[10][10];
// 建立一个二维布尔数组，用来标记某一格区域当前的状态
// true代表已经被走过或者是存在障碍物，不可往这走，false代表尚未被走过

// dfs的原理和上一题一致，不再做详细讲解
void dfs(int x, int y) {
	if (x == fx && y == fy){
		ans++;
		return;
	}
	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
		if (ld [nx] [ny]) continue;
		ld[nx][ny] = true;
		dfs(nx, ny);
		ld[nx][ny] = false;
	}
}

int main() {
	cin >> n >> m >> t;
	cin >> sx >> sy >> fx >> fy;

	for (int i = 0;i < t;i++) {
		int x, y;
		cin >> x >> y;
		ld[x][y] = true;
		// 输入障碍物坐标，
	}
	ld[sx][sy] = true;
	dfs(sx,sy);
	// 从起点处开始dfs 
	cout << ans << endl;
	return 0;
}