#include<iostream>
using namespace std;
int main() {
	int n;
	char s[51];
	cin >> n;
	cin >> s;
	for (int i = 0;s[i] != 0;i++) {
		s[i] = (s[i] - 'a' + n) % 26 + 'a';
		// `s[i] - 'a'`：把字母映射成 0~25 的序号
		// `+ n`：加上偏移量
		// `% 26`：保证循环（超过 z 就回到 a）
		// `+ 'a'`：把序号转回字母
	}
	//字符就是数字，ASCII 码就是它们的“身份证号”。这串代码就是用身份证号做加法、取模，再翻译回字母
	cout << s << endl;
	return 0;
}