#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	// 强行运算必然会爆内存
	// 为实现高精度加法，我们要从加法的底层逻辑进行模拟运算
	
	int c = 0;
	// 用来判断进位
	string ans = "";

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	// 首先，将两个数字倒转过来，从个位数开始一步一步向上运算
	int len = max(s1.length(), s2.length());

	for (int i = 0;i < len;i++) {
		int fi1 = (i < s1.length()) ? (s1[i] - '0') : 0; // C++的三目运算符
		int fi2 = (i < s2.length()) ? (s2[i] - '0') : 0; // (条件)?(满足条件如何):不满足条件如何
		// 把当前位数拆出来
		
		int sum = fi1 + fi2 + c;
		// 计算其总和，并对10求模，取整，
		// 把余数作为合并后当前数，商作为进位
		ans += (sum % 10) + '0';
		c = sum / 10;
	}

	if (c > 0) {
		// 如果求到最后发现依然有进位，那就+1；
		ans += '1';
	}

	reverse(ans.begin(), ans.end());

	cout << ans << endl;
	return 0;
}
// 本题的时间复杂度为O(n)，其中 n = max(|s1|,|s2|}
// 本题的计算量约为 （读入）1000+（交换）1500+500*10 = 8500