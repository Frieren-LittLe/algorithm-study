#include<iostream>
#include<algorithm>
using namespace std;

//对每个位置i,算“以i结尾的最长严格上升子序列长度”+"以i开头的最长严格下降子序列长度“-1，遍历所有i取最大，再用n减去它
//每一边进行内外两层枚举，时间复杂度为O（n^2)
//计算量为 （ 100*（100-1）/2 ）* 2 + 100 = 10^4 < 10^8，不超时
const int N = 110;
int n, a[N], l[N], r[N];
// a[]记录初始站位
// l[]记录当前值左端的最长严格上升子序列长度
// r[]记录当前值右端的最长严格下降子序列长度

int main() {
	cin >> n;
	for (int i = 1;i <= n;i++)cin >> a[i];

	for (int i = 1; <= n;i++) {
		f[i] = 1;
		for (int j = 1;j < i;j++) {
			//
			if (a[j] < a[i])r[i] = max(r[i], r[i] + 1);
		}
	}

	for (int i = n;i >= 1;i--) {
		g[i] = 1;

	}
}