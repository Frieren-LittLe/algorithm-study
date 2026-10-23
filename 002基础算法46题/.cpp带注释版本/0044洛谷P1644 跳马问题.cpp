#include<iostream>
using namespace std;

int n, m, ans;

int dx[] = { 1,2,2,1 };
int dy[] = { 2,1,-1,-2 };

void dfs(int x, int y) {
	if (x == m && y == n) {
		ans++;
		return;
	}
	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx <= m && ny >= 0 && ny <= n) {
			dfs(nx, ny);
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(0, 0);
	cout << ans << endl;
	return 0;
}