#include<iostream>
#include<vector>
using namespace std;
// 本题严格意义来讲不能算贪心
// 硬要说的话，本题贪心思维体现在左右端点各自贴紧首末水瓶，能不多扩就绝不多扩——局部不浪费即全局最短
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	bool has = false;
	// 注意:本题中有可能一瓶水都没有,于是我们声明一个布尔函数has判断无水的情况
	for (int i = 0;i < n;i++) {
		cin >> a[i];
		if (a[i] == 1)has = true;
		// 一旦填入的数中有1(有水)，则布尔函数has生效
	}

	if (!has) {
		// 当布尔函数未生效时(无水)，直接输出'0'
		cout << 0;
	}
	else {
		// 当布尔函数生效时
		// 左边设立一个指针l找左边第一个有水的地方
		// 右边设立一个指针r找右边第一个有水的地方
		// 区间[l,r]即为要喝的水，瓶数为r - l +1 
		int l = 0;
		while (a[l] != 1)l++;

		int r = n - 1;
		while (a[r] != 1)r--;

		cout << r - l + 1;
	}
	return 0;
}