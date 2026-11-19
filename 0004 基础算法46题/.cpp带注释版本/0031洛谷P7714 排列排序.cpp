#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6 + 10;
int a[N];

void solve() {
// void的含义为"空"，如果函数不放回任何值，就把返回类型写成void
// 注意：本题的p数组中含有1到n中的所有整数
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)cin >> a[i];
	int ans = 0;
	int maxi = 0, l = 1;
	// 设l为乱序部分的左端
	for (int i = 1;i <= n;i++) {
		maxi = max(maxi, a[i]);
		// 从左到右遍历，并用打擂台法判断当前出现的最大值
		if (maxi == i) {
			// 当最大值等于当前下标时，说明[l,i]是一个独立的乱序块
			// (此时，数组中第i位之前所有的数都小于i，则此时我们可以把区间[l,i]给排序,然后使i+1成为新的l)
			// 记录消耗的代价为i-l+1
			int len = i - l + 1;
			if (len > 1)ans += len;
			l = i + 1;
		}
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}
// 本题的双指针体现在l和i共同维护一个区间[l,i],i单调右移扩张,满足maxi==i时l跳到i+1,两个指针都只向右、不回退