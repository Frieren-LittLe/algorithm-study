#include<iostream>
using namespace std;
// 本题既有dfs写法，也有bfs写法，还有递推写法
// DFS：状态空间小、只需枚举 4 个固定方向且"只向右跳"保证无环，天然适合递归回溯统计路径条数
// BFS：本质是逐层扩展求方案数，每层按列推进不重不漏，队列层序天然对应"从左到右"的推进顺序
// 递推：马只向右跳意味着 (x,y) 的方案数只依赖左侧列的状态，满足无后效性，可按列（或按 x 递增）直接 DP 累加

// 不过DFS写法的思维负担最小，以下为DFS写法


int n, m, ans;
// 马向右跳的 4 个方向：右上竖日、右上横日、右下横日、右下竖日
int dx[] = { 1,2,2,1 };
int dy[] = { 2,1,-1,-2 };

void dfs(int x, int y) {
	if (x == m && y == n) {
		ans++;
		return;
		// 当棋子抵达终点时，答案计数+1，退出当前层dfs
	}
	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx <= m && ny >= 0 && ny <= n) {
			dfs(nx, ny);
			// 抵达某点后从该点扫描右方四处落点，并位移到下一落点执行dfs
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(0, 0);
	// 从起点(0,0)开始执行dfs
	cout << ans << endl;
	return 0;
}