#include<iostream>
using namespace std;
// 设b为x倍的a，c为y倍的b即y*x倍的a
// 则a(1+x+xy) = n;
// 其中a，n，x，y必为整数
// 设n/a为q，则q必为整数，且q - 1 = x (1 + y)
// 因为n已知，所以q的情况数等于a的情况数
// 则求a，b，c的方案数，等价与求a，x，y+1的方案数
// 解本题可以枚举所有可能的a，再在当前a情况下对应的q-1情况下枚举出所有可能的x和y+1的组合的方案数
int calc(int q) {
	// 统计q-1的合法因数对个数
	const int m = q - 1;
	int res = 0;

	for (int f = 1;f * f <= m;f++) {
		// 枚举所有可能的因数值
		// 枚举到√(q-1)即可:
		// 因为因数总是成队出现且分别位于根号m两侧，只需枚举到根号m就能顺带推行胡另一半更大的因数
		// 从而将时间复杂度从O(m)优化到O(√m)
		if (m % f != 0)continue;
		// 整除非整数直接跳过
		int g = m / f;
		// 整除得到的整数为y+1的值，设为g
		if (f > 1 && g > 2)res++;
		// x的范围大于1，y+1的范围大于2
		// 此时设x为f，y+1为g
		if (f != g && g > 1 && f > 2)res++;
		// x和y+1位置互换！再加一遍组合的方案数
	}
	return res;
}

int main() {
	int n;
	cin >> n;

	int ans = 0;
	for (int a = 1;a * a <= n;a++) {
		if (n % a != 0)continue;
		ans += calc(a);
		if (a * a != n)ans += calc(n / a);
	}
	cout << ans << '\n';
	return 0;
}