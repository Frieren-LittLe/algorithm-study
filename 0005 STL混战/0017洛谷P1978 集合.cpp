#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
// 本题的贪心解法是:
// 把所有不是 k 的倍数的数都存进去
// 是 k 的倍数的数，从小到大一个一个看着去存
// 一旦发现当前数 a[i] 除以 k 后的那个数（a[i]/k）已经被存进集合里了，就跳过该数
// 否则存进去
int main() {
	int n, k;
	cin >> n >> k;

	long long a[100005];
	// a的数据范围为-2^63+1~2^63-1
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	sort(a, a + n);

	set<long long> s;
	for (int i = 0;i < n;i++) {
		if (a[i] % k != 0 || s.find(a[i] / k) == s.end()) {
			s.insert(a[i]);
		}
	}
	// 最终输出set的大小
	cout << s.size() << endl;
	return 0;
}