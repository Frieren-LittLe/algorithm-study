#include<iostream>
using namespace std;

void solve() {
	string s;
	cin >> s;
	string a;
	for (int i = 0;i < s.length() - 1;i += 2)
		a += s[i];
	// 字符串变量名[i]，是表示字符串中某一位置对应的字符的合法方式
	// （但不知为什么今天打的时候报错了）
	a += s[s.length() - 1];
	cout << a << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}