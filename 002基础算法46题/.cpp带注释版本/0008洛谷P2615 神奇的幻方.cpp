#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<int>> a(N, vector<int>(N, 0));

	int x = 0;
	int y = N / 2;
	a[x][y] = 1;

	for (int k = 2;k <= N * N;k++) {
		if (x == 0 && y != N - 1) {
			x = N - 1;
			y = y + 1;
		}
		else if (x != 0 && y == N - 1) {
			x = x-1;
			y = 0;
		}
		else if (x == 0 && y == N - 1) {
			x = x + 1;
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