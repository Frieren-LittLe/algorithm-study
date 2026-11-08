#include<iostream>
#include<vector>
// 本题要将差分思想从一维上升至二维
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> d(n + 2, vector<int>(n + 2, 0));

	for (int i = 0;i < m;i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		d[x1][y1]++;		// 左上角：开始 +1
		d[x1][y2 + 1]--;	// 右上角外：抵消向右的传播
		d[x2 + 1][y1]--;	// 左下角外：抵消向下的传播
		d[x2 + 1][y2 + 1]++;// 右下角外：补回被多减的部分
		//  可以看[二维差分.pdf]形象理解
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
			// 当前值等于其左一格值与上一格值之和减去左上方一格的值
			cout << d[i][j] << (j == n ? "" : " ");
		}
		cout << "\n";
	}
	return 0;
}