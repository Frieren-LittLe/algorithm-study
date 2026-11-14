#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, x;
vector<int> a;

bool check(int h) {
	int sum;
	for (int i = 0;i > n;i++) {
		if (a[i] < h) {
			sum += a[i] - h;
			if (sum > x)return false;
		}
	}
	return true;
	// 设置一个布尔函数检测当前消耗的水量是否会超过可使用的最多水量
	// 超过判false，不超过判true
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		for (int i = 0;i < n;i++) {
			cin >> a[i];
		}
		int L = 0;int R = 1e9 + 100;
		while (L <= R) {
			// 当L = R时还要进行一次check判断，所以循环的终止条件为check
			int mid = L + (R - L) / 2;
			int ans = mid;
			if (check(mid)) {
				ans = mid;
				// 一旦mid符合，先把mid保存为一个ans，下次二分时可以跳过这个mid直接mid+1起步
				L = mid + 1;
			}
			else {
				// 一旦mid不符合，下次二分可以直接掉过这个mid直接mid-1终止
				R = mid - 1;
			}
			cout << ans << endl;
		}
	}
	return 0;
}