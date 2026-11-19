#include<iostream>
using namespace std;
// 暴力枚举必然TLE，于是我们可以尝试利用数学公式减少运算量
int main() {
	// 思路一:
	// 一共有C_n^2种组合可能,总共写下的数字个数为2*C_n^2即为2*n(n-1)/2 = n(n-1)个
	// 因为n只尘灵的地位完全对等，这n(n - 1)个位置会平均分配给a_1,a_2 ... a_n这n个数
	// 每个数都出现了n-1次，于是令sum*(n-1)即可
	// 思路二:
	// 每个数据都要和除自身以外的数据配对一次，即n-1次;
	// 那么令sum*(n-1)即为答案
	int n;
	cin >> n;
	long long sum = 0;
	for (int i = 0;i < n;i++) {
		long long x;
		cin >> x;
		sum += x;
	}
	cout << sum * (n - 1) << endl;
	return 0;
}