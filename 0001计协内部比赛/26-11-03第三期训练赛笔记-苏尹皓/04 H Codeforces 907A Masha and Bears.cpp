#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int v1, v2, v3, vm;
	cin >> v1 >> v2 >> v3 >> vm;

	// 本题的主要锚点肯定是vm，我们对vm进行分析
	// 发现当vm >= v2时，会出现：
	// 1.玛莎喜欢中型车 或 2.玛莎不喜欢小型车 的两种情况,导致不合法

	// 确立好vm右边界之后，发现vm和v3等价，都喜欢小型车
	// 为使两者都有同一辆小型车，他们满足 v3m /2 <= Car <= v3m 
	// 拆开来得到v3/2 <= vm和 vm/2 <= v3
	// 那么反过来，当vm < v3/2或vm/2 > v3时不合法
	// 2vm < v3 , 2v3 < vm ，也就是vm和v3之间大的一个数为小的一个数的两倍时不合法
	if (vm >= v2 || max(vm, v3) > 2 * min(vm, v3)) {
		cout << "-1" << endl;
	}
	// 那么排除了不合法的情况，可以考虑输出哪些数据了
	// 我们输出一个2v1(恰好满足熊爸喜欢)
	// 再输出一个2v2(恰好满足熊妈)
	// 再输出一个max(v3,vm）(恰好满足小熊和玛莎喜欢)
	else {
		cout << 2 * v1 << endl;
		cout << 2 * v2 << endl;
		cout << max(vm, v3) << endl;
	}
	return 0;
}