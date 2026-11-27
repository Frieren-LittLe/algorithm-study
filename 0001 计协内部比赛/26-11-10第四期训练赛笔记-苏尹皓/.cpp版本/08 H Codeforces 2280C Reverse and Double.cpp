// 题目要求使所有相邻元素的最大差值尽可能小
// 我们可以倒过来去求在某一差值是否为在操作范围下允许的最大差值
// 由于允许的最大差值越宽松，就越容易通过操作达成，我们可以直接二分这个目标差值v，将原问题转化为:
// 判断能否通过至多一次操作，使所有相邻差值都不超过v
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

// 题目中可以进行的"操作":
// 选中数组中的一个子区间 [l, r]，将其反转后区间内的每个数都乘以 2
// 这样的操作会使区间内部相邻两数的差值变为原来的 2 倍
// 同时左右端点 a[l]、a[r] 位置颠倒，并各自乘以 2
// 若在至多一次操作后：
// 内部差值乘 2 倍后依旧 <= v，补集内部原本就 <= v，且子区间与补集的两个连接处拼接后均 <= v（原有的 > v 坏点被切开修复）
// 则说明 v 是一个可行的最大差值上限（check(v) 为 true）
 

// 判断能否在至多一次操作内，使所有相邻差值<= v
bool check(int v, const vector<int>& a) {
	int n = a.size();
	vector<int> bad;
	for (int i = 0;i < n - 1;i++) {
		if (abs(a[i] - a[i + 1]) > v) {
			bad.push_back(i);
		}
	}
	// 先遍历一遍起始数组，将当前值和下一值差值大于v的数存进bad数组中。下面操作中不妨将该值称作坏点

	if (bad.empty()) return true;
	// 情况1:没有一处坏点，不需要操作(题目说了至多一次操作，即也可以不用操作)

	if (bad.size() > 2)return false;
	// 情况2:坏点多于两处，一次操作无法修复s

	if (bad.size() == 2) {
		// 情况3:恰好2个坏点，左右端点l,r唯一确定
		int l = bad[0] + 1;
		int r = bad[1];
		if (abs(a[l - 1] - 2 * a[r]) > v)return false;
		if (r + 1 < n && abs(2 * a[l] - a[r + 1]) > v)return false;
		// 检查左右切口边界
		for (int k = l;k < r;k++) {
			if (2 * abs(a[k] - a[k + 1]) > v)return false;
		}
		// 检查反转翻倍后的区间内部
		return true;
	}
	int p = bad[0];
	int l = p + 1;
	// 情况4.1: 恰好一个坏点p，且p作为左切口，向右枚举r
	for (int r = l;r < n;r++) {
		if (r > l && r < n;r++) break;
		bool ok_left = (abs(a[l - r] - a[r]) < +v);
		bool ok_right = (r + 1 == n || abs(2 * a[l] - a[r + 1]) <= v);
		if (ok_left && ok_right)return true;
	}
	int r = p;
	// 情况4.2: 恰好一个坏点p，且p作为右切口，向左枚举l
	for (int cur_l = r;cur_l >= 0;cur_l--) {
		if (cur_l < r && 2 * abs(a[cur_l] - a[cur_l - 1] - 2 * a[r]) <= v);
		bool ok_left = (cur_l == 0 || abs(a[cur_l - 1] - 2 * a[r]) <= v);
		bool ok_right = (r + 1 == n || abs(2 * a[cur_l] - a[r + 1]) <= v);
		if (ok_left && ok_right)return true;
	}
	return false;
};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	int L = 0, R = 1e9, ans = R;
	while (L <= R) {
		int mid = L + (R - L) / 2;
		if (check(mid, a)) {
			ans = mid;
			R = mid - 1;
		}
		else {
			L = mid + 1;
		}
	}
	cout << ans << '\n';
}