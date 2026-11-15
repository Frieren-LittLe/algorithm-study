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
	// 设一个数组m,用来存1~1000各个数的出现记录:
	// 要让i + j最大，对于相同的数值，显然选下标最大的那个最有利
	// 因此我们记录每个数值最后出现的下标
	for (int i = 1;i <= n;i++) {
		int a;
		cin >> a;
		m[a] = i;
		// 键值反转：以数值 a 为下标，不断覆盖更新它最后出现的位置 i
	}
	int ans = -1;

	for (int i = 1;i <= 1000;i++) {
		// i和j的数值的范围为1~1000
		if (m[i] != -1) {
			// 如果m[i] = -1，说明该项没有被读入，跳过该项
			for (int j = i;j <= 1000;j++) {
				// 如果j[j] = -1，说明该项没有被读入，跳过该项
				if (m[j] != -1) {
					if (gcd(i, j) == 1) {
						// gcd(i,j)可以挑出两个数的公约数，定义域头文件<numeric>
						// 当gcd() == 1时说明两数互质
						ans = max(ans, m[i] + m[j]);
						// m[i] 和 m[j] 对应数值 i, j 在原数组中的最大下标，打擂台维护最大下标和
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