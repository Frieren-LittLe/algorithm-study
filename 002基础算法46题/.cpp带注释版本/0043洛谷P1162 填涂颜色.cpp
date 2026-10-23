#include<iostream>
using namespace std;

int n;
int a[35][35];
bool b[35][35];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int x, int y) {
	if (x < 0 || x > n+1 || y < 0 || y > n + 1)return;
	if (b[x][y] || a[x][y] == 1)return;
	b[x][y] = true;
	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		dfs(nx, ny);
	}
}

int main() {
	cin >> n;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cin >> a[i][j];
		}
	}
	dfs(0, 0);
	
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (a[i][j] == 0 && !b[i][j]) {
				cout << '2' << " ";
			}
			else {
				cout << a[i][j] << " ";
			}
		}
		cout << endl;
	}
	return 0;
}