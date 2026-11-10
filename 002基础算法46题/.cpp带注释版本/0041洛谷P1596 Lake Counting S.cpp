#include<iostream>
using namespace std;
// 本题的核心思路是:
// 遍历整个地图，发现到 'W'就用dfs把这个'W'与其周边九格(即题中的与之相连通)的'W'全部都变为 '.'
int n, m;
char a[105][105];
// 设置一个范围涵盖左上，上，右上，左，右，左下，下，右下八个发现的dx,dy组合
int dx[] = { 1,1,1,0,0,-1,-1,-1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

void dfs(int x,int y) {
	a[x][y] = '.';
	for (int i = 0;i < 8;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == 'W') {
			dfs(nx, ny);
		}
	}
}
// 定制一个dfs函数
// 将当前格子改为','并向八个方向以nx，ny探测，一旦不越界且检测到'W'
// 则在第一个检测到的'W'分支中继续bfs，当当前分支到底时，for循环结束，自动退回上一分支
int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (a[i][j] == 'W') {
				ans++;
				dfs(i, j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
// DFS 对时间复杂度的优化体现在：它沿一条路径深入并在找到解时立即回溯终止，
// 配合剪枝跳过不可能产生解的分支，从而避免展开与目标无关的搜索空间