#include<iostream>
#include<string>
#include<vector>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	string s;
	cin >> s;
	// 题目允许不同的数字变成相同的字符，只禁止同一个数字变成不同的字符
	// 只需要检查:相同数字的位置，字符是否一定相同
	// 由于a的最大数目为50，直接两个for循环滚过去即可
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (a[i] == a[j] && s[i] != s[j]) {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}