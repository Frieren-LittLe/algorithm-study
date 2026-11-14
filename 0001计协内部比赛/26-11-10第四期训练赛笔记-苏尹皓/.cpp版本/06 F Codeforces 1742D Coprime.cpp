#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
// 虽然这题数组长度上限为10 ^ 5, 但是数值的区间为[1, 1000]
// 所以我们只要遍历区间内数值并且判断数值有没有出现过就是了
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> m(1001, -1);
	for (int i = 1;i <= n;i++) {
		int a;
		cin >> a;
		m[a] = i;
	}
	int ans = -1;

	for (int i = 1;i <= 1000;i++) {
		if (m[i] != -1) {
			for (int j = i;j <= 1000;j++) {
				if (m[j] != -1) {
					if (gcd(i, j) == 1) {
						ans = max(ans, m[i] + m[j]);
					}
				}
			}
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}