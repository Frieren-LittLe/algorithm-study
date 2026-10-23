#include<iostream>
#include<algorithm>
using namespace std;

int cnt[26];

int main() {
	string s;
	cin >> s;
	for (char c : s)cnt[c - 'a']++;

	int ans = 0;
	for (int i = 0;i < 26;i++)ans = max(cnt[i], ans);
	cout << ans;
	return 0;
}