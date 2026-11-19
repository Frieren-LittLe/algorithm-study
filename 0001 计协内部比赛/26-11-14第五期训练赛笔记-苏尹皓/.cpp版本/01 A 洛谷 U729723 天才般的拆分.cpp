#include<iostream>
#include<string>
using namespace std;
// 把最左边的k位和最右边的k位字符串的长度最小化，即看作1(贪心策略)
// 只要两头的k个字符对称，中间不管剩下一团什么乱码(只要长度>= 1)，都可以整段打包塞进a_k+1里
// 因此我们只要比对最左右两边的前k位字符是否一一对应即可
void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	if (n - 2 * k < 1) {
		cout << "NO" << endl;
		return;
	}
	// 注意k+1的长度不能超过(n+1)/2，即保证两边的字符串不会交叉(否则会导致拼接的字符串长度超过原数组)
	for (int i = 0; i < k;i++) {
		char c1 = s[i];
		char c2 = s[n - 1 - i];
		if (c1 != c2) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	return;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}