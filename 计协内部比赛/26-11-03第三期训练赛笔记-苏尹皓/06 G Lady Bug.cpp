#include<iostream>
#include<string>
using namespace std;
// 把字符串a的奇数位的数字和字符串b的偶数位数字看作一个集合A
// 字符串a的偶数位的数字和字符串b的奇数位数字看作另一个集合B
// 那么A，B的长度均为n
// 由于我们要将a中的1都移入b中，来保证a中全部为0
// 则集合A中最多可以有的'1'的个数就是b的偶数位的数目，即n/2   (整除)
// 集合B中最多可以有的'1'的个数就是b的奇数位数目，即(n+1)/2   (整除)

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;

		int cnt1 = 0;int cnt2 = 0;
		// 我们设置一个cnt1和cnt2对集合A与集合B中'1’的个数进行计数
		for (int i = 0;i < n;i++) {
			if (i % 2 == 0) {
				// 通过-'0’可以将字符转换为数字，直接将1和0的数值加起来，其总和就是1的个数
				cnt1 += (a[i] - '0');
				cnt2 += (b[i] - '0');
			}
			else {
				cnt1 += (b[i] - '0');
				cnt2 += (a[i] - '0');
			}
		}
		

		if (cnt1 <= n / 2 && cnt2 <= (n + 1) / 2)
			cout << "YES\n";
		else {
			cout << "NO\n";
		}
	}
	return 0;
}