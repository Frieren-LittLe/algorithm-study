#include<iostream>
using namespace std;

int n, m, t, sx, sy, fx, fy;
int ans;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool ld[10][10];

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
	}
	ld[sx][sy] = true;
	dfs(sx,sy);
	cout << ans << endl;
	return 0;
}