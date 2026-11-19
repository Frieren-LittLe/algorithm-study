#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
// 差分是前缀和的逆运算，专门用来高效处理区间修改问题
// 差分数组的每一项是原数组相邻两项的差

const int N = 5e6 + 5;
int a[N], d[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, p;
	cin >> n >> p;

	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		d[i] = a[i] - a[i - 1];
	}
	// 读入a[i]，并记录a[i]与上一项a[i-1]的差值d[i]
	// 通过改变两端点的d[i]，可以使区间内的a[i]发生改变
	
	// 试想某一区间(l,r)整体增假或缩小，其(l,r)内所有相邻元素之间的差值并未发生改变
	// 发生改变的，只有【r-1与l】 和【r 与r+】之间的差值发生改变1
	// 借此特性，可以方便我们高效完成多次区间加减操作

	for (int i = 0;i < p;i++) {
		int x, y, z;
		cin >> x >> y >> z;
		d[x] += z;
		d[y + 1] -= z;
		// 修改:将第x端+z，y+1端减z
	}
	int ans = INT_MAX;

	for (int i = 1;i <= n;i++) {
		a[i] = a[i - 1] + d[i];
		// 把从x端到y+1端内的a[i]重新算
		ans = min(ans, a[i]);
		// 同时比较出最小值
	}
	cout << ans << endl;
	return 0;

}