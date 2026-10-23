#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	int c = 0;
	string ans = "";

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	int len = max(s1.length(), s2.length());

	for (int i = 0;i < len;i++) {
		int fi1 = (i < s1.length()) ? (s1[i] - '0') : 0;
		int fi2 = (i < s2.length()) ? (s2[i] - '0') : 0;

		int sum = fi1 + fi2 + c;

		ans += (sum % 10) + '0';
		c = sum / 10;
	}

	if (c > 0) {
		ans += '1';
	}

	reverse(ans.begin(), ans.end());

	cout << ans << endl;
	return 0;
}