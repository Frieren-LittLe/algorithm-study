#include<iostream>
using namespace std;
// 我们把一个偶数n和n之前的所有正整数拆成奇数组和偶数组时
// 1，3，5，7 ......n-1；
// 2，4，6，8 ......n；
// 令偶数组减去所有奇数组，可以得到之间的差值为:n/2
// 那么，既然偶数组比奇数组大，不妨将n以内的所有偶数依次输出
// 再将除n-1以外的奇数依次数组，最后再填一个大小满足n-1 + n/2 = 1.5n -1的奇数来
// 设n = 2k，3k-1需要是一个奇数，则k需要是一个偶数，则k%2 == 0
// 所以n % 4 == 0时有解
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n % 4 == 0) {
			cout << "YES" << endl;
			for (int j = 2;j <= n;j += 2) {
				cout << j << " ";
			}
			for (int j = 1;j < n - 2;j += 2) {
				cout << j << " ";
			}
			cout << n + n / 2 - 1 << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
// 这是一道 构造题（Construction Problem）
// 题目不要求你求最大值、最小值或计数，而是要求你按照给定条件"造"出一个满足要求的方案并输出