#include<iostream>
#include<vector>

using namespace std;
//看不懂题面捏，跟着题目的要求一遍一遍模拟
int main() {
	int N;
	cin >> N;

	vector<vector<int>> a(N, vector<int>(N, 0));
	// vector<vector<形式>> 数组名(数组数目，内部数组<形式>(数组数目，初始值))
	// 通过此方式可以建立一个可变的二维数组
	int x = 0;
	int y = N / 2;
	a[x][y] = 1;
	// 首先将1写在第一行的中间
	for (int k = 2;k <= N * N;k++) {
		// 依次将2到n*n的数填入二维可变数组中
		if (x == 0 && y != N - 1) {
			x = N - 1;
			y = y + 1;
			// 若(K-1)在第一行但不在最后一列，则将K填在最后一行，(K-1)所在列的右一行
		}
		
		else if (x != 0 && y == N - 1) {
			x = x-1;
			y = 0;
			// 若(K-1)在最后一列但不在第一行，则将K填在第一列，(K-1)所在行的上一行
		}
		
		else if (x == 0 && y == N - 1) {
			x = x + 1;
			// 若(K-1)在第一行最后一列，则将K填在(K-1)的正下方
		}
		
		else {
			int rux = x - 1;
			int ruy = y + 1;
			if (a[rux][ruy] == 0) {
				x = rux;
				y = ruy;
			}
			else {
				x = x + 1;
			}
			// 若(K-1)既不在第一行，也不在最后一列，如果(K-1)的右上方还未填数，则将K填在(K-1)的右上方，
			// 否则将K填在(K-1)的正下方
		}
		a[x][y] = k;
	}
	
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cout << a[i][j];
			if (j != N - 1) {
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}