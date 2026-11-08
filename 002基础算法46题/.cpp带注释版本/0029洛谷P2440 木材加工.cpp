#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6 + 10;

int n, k;
int a[N];
int max_len = 0;

bool check(int x) {
	int sum = 0;
	for (int i = 0;i < n;i++) {
		sum += a[i] / x;
		if (sum >= k) return true;
	}
	return false;
}
// 和上题类似，设立一个布尔函数，在该函数中这些计算原木能切成长度为l时的小段木头的数量
// 达标(大于等于k)则返回true，不达标则返回false

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0;i < n;i++) {
		cin >> a[i];
		if (a[i] > max_len) {
			max_len = a[i];
		}
	}

	int l = 1;
	int r = max_len;
	int ans = 0;
	// 利用二分法在答案取值空间里逼近最优值，也是不用排序的
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;// 满足，往大找
		}
		else {
			r = mid - 1;// 不满足，往小找
		}
	}
	cout << ans << endl;

	return 0;
}
// "二分答案"和"二分查找"之间的区别：
// 二分查找：在有序数组中，通过比较中间元素与目标值，每次排除一半区间来定位元素
// 在答案的取值范围内，利用 check(mid) 的单调性，每次排除一半取值来逼近最优答案（不要求数组有序）