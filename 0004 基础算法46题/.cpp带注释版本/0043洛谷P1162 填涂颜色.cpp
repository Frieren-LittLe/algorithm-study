#include<iostream>
using namespace std;

int n;
int a[35][35];	//地图数组
bool b[35][35];	//vis数组
// 故意把数组开大一些，尽量使1周围都有一圈0包着，方便我们遍历dfs时不会被数组边缘的1挡住
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
// 解题思路:
// 本题可以看作三层:外层一层'0'，中间一层'1’,里面一层'0'
// 也许你会想用bfs把所有的内层0都联系起来标记，遍历数组并扫描标记过的0，再把它们全部改为'2'即可(其实也是能实现的)

// 以下的办法为将外层0都联系起来标记，遍历数组并扫描尚未被被记过的0，再把它们全部改为'2'
// 还能省去找内层0的步骤，
// 先用dfs数组将处于1形成的圈之外的'0'全部标记
void dfs(int x, int y) {
	if (x < 0 || x > n+1 || y < 0 || y > n + 1)return;  // 当越界时，bfs函数结束
	if (b[x][y] || a[x][y] == 1)return;					// 当b[x][y]为true(已被判定过)或者a[x][y]=1(碰壁)时，
	b[x][y] = true;	// 将该区域的b[x][y]标记为已访问过 
	for (int i = 0;i < 4;i++) {	// 向四周探点，查找数组中有没有其它在1形成的圈之外的0
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
				// 遍历地图数组，发现没有被标记的0就填入为2
				cout << '2' << " ";
			}
			else {
				cout << a[i][j] << " ";
				// 其它区域原模原样输出
			}
		}
		cout << endl;
	}
	return 0;
}