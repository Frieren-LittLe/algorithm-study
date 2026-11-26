#include<iostream>
#include<algorithm>
using namespace std;
// 本题的解题思路为:设四个数组存放分别四种颜色的上边界，下边界，左边界，右边界
// 将其高和宽比较，其更长的一条即为能框住所有该颜色格子的正方形

const int N = 1e5 + 5;
const int INF = 1e9;

int min_x[N], max_x[N], min_y[N], max_y[N];

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	fill(min_x, min_x + k + 1, INF);
	fill(min_y, min_y + k + 1, INF);
	// fill是一个定义于<algorithm>中的赋值函数，用来把一段连续区间内的所有元素统一赋值为指定的值
	// 格式为fill(起始地址，结束地址，填充的值);

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			int c;
			cin >> c;
			// 输入当前颜色，对当前颜色判断是否是该颜色新的上下及左右边界，是的话则更新
			min_x[c] = min(min_x[c], i);
			max_x[c] = max(max_x[c], i);
			min_y[c] = min(min_y[c], j);
			max_y[c] = max(max_y[c], j);
		}
	}

	for (int c = 1;c <= k;c++) {
		if (min_x[c] == INF) {
			// 如果发现该颜色最小值是一开始的设定值，直接输出0，去遍历下一个数
			cout << 0 << '\n';
			continue;
		}
		int h = max_x[c] - min_x[c] + 1;
		int w = max_y[c] - min_y[c] + 1;
		int d = max(h, w);
		cout << 1LL * d * d << '\n';
		// 1LL 可以将后续运算强制提升为long long类型，从而防止int计算过程中发生溢出
		// 等价于 (long long)d * d
	}
	return 0;
}