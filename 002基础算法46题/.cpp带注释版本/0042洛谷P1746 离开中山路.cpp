#include<iostream>
#include<cstring>
#include<queue>
#include<utility>

using namespace std;

typedef pair<int, int> PII;

int n;
int x1, y1, x2, y2;
char m[1005][1005];
int d[1005][1005];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int bfs() {
	memset(d, -1, sizeof d);
	queue<PII> q;

	q.push({ x1,y1 });
	d[x1][y1] = 0;

	while (!q.empty()) {
		auto t = q.front();
		q.pop();

		int x = t.first;
		int y = t.second;

		if (x == x2 && y == y2)return d[x][y];

		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
				if (d[nx][ny] == -1 && m[nx][ny] == '0') {
					d[nx][ny] = d[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for(int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++) {
			cin >> m[i][j];
		}
	cin >> x1 >> y1 >> x2 >> y2;
	cout << bfs() << endl;
	return 0;
}