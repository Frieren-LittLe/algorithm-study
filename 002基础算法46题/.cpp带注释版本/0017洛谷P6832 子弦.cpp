#include<iostream>
#include<algorithm>
using namespace std;

int cnt[26];
// 字符串的最小长度为1，也就是说这题我们只要记26位字母中最常出现的就行了
// 贪心体现在：直接选当前出现次数最多的字母，不再权衡其他选择
int main() {
	string s;
	cin >> s;
	for (char c : s)cnt[c - 'a']++;
	// for(char 字符名: 字符串名)可以把字符串中的每个字符依次拆开来进行判定，
	// -'a'可以将a~z转换成0~26,方便计数
	int ans = 0;
	for (int i = 0;i < 26;i++)ans = max(cnt[i], ans);
	cout << ans;
	return 0;
}