#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	// 先将所有数据用数组a存起来
	// 再用sort把a排序好
	sort(a.begin(), a.end());
	int cnt = 0;
	// 用cnt记录上一个数第一次出现的下标
	// 不断遍历a数组，每次发现一个新数据就将新数据的下标减去上一数据的下标，得到上一数据的数目
	// 此时输出cnt固定的数据及其数目
	// 然后将下一个数用cnt重新固定
	for (int i = 1;i < n;i++) {
		if (a[i] > a[cnt]) {
			cout << a[cnt] << " " << i - cnt << endl;
			cnt = i;
		}
	}
	cout << a[cnt] << " " << n - cnt << endl;

	return 0;
}