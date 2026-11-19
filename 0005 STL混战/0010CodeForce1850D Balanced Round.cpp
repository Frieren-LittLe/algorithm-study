#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// 将数据从底标1开始存入，存到底标n
// 先用sort将整个数组排好序
// 设一个cnt = 0用来记录当前区间的连续值
// 再设一个mx = 0用来记录最大cnt值
// 当a_i - a_i-1 <= k时，cnt++
// 当a_i - a_i-1 >  k时，cnt和mx比较，当cnt > mx值时覆盖为新mx值，然后cnt回归成1
// 当遍历到底时mx再和cnt进行一次比较
// 这样求出来的mx就是最多保留的题，再减去就是最少删去的题
void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1, 0);
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int cnt = 0;
	int mx = 0;
	for (int i = 1;i <= n;i++) {
		if (a[i] - a[i - 1] <= k) {
			cnt++;
		}
		else {
			mx = max(mx, cnt);
			cnt = 1;
		}
	}
	mx = max(mx, cnt);
	cout << n - mx << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}