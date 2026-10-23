#include<iostream>
#include<vector>
using namespace std;


int main() {
	int N, M, C;
	cin >> N >> M >> C;
	vector<vector<int>> mp(M, vector<int>(N));

	for (int y = 0;y < N;y++) {
		for (int x = 0;x < M;x++) {
			cin >> mp[x][y];
		}
	}

	vector<vector<long long>> sum(M, vector<long long>(N, 0));

	int maxX = 0;
	int maxY = 0;
	long long maxSum = -1e9;
	for (int y = 0;y < N;y++) {
		for (int x = 0;x < M;x++) {
			sum[x][y] = mp[x][y];
			if (x > 0) sum[x][y] += sum[x - 1][y];
			if (y > 0) sum[x][y] += sum[x][y - 1];
			if (x > 0 && y > 0) sum[x][y] -= sum[x - 1][y - 1];
		}
	}

	for (int y = 0;y <= N - C;y++) {
		for (int x = 0;x <= M - C;x++) {
			int x2 = x + C - 1;
			int y2 = y + C - 1;
			long long total = sum[x2][y2];
			if (x > 0)total -= sum[x - 1][y2];
			if (y > 0)total -= sum[x2][y - 1];
			if (x > 0 && y > 0)total += sum[x - 1][y - 1];
			if (total > maxSum) {
				maxSum = total;
				maxX = x;
				maxY = y;
			}
		}
	}
	cout << maxY + 1 << " " << maxX + 1 << endl;

	return 0;

}