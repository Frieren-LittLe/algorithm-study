#include<iostream>
using namespace std;

const int mod = 100003;
int dp[1005][1005];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int x, y;
		cin >> x >> y;
		dp[x][y] = -1;
	}

	if (dp[1][1] == -1) {
		cout << 0 << endl;
		return 0;
	}
	dp[1][1] = 1;

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (i == 1 && j == 1) continue;
			if(dp[i][j] == -1) {
				dp[i][j] = 0;
			}
			else {
				int fromUp = (i > 1 && dp[i - 1][j] != -1) ? dp[i - 1][j] : 0;
				int fromLeft = (j > 1 && dp[i][j - 1] != -1) ? dp[i][j - 1] : 0;
				dp[i][j] = (fromUp + fromLeft) % mod;
			}
		}
	}
	cout << dp[n][n] << endl;
	return 0;
}