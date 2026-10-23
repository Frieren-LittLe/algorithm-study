#include<iostream>
using namespace std;

int n, m;
char a[105][105];
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