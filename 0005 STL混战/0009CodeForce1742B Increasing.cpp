#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int cur = 0;
	// 先将所有数据由小到大排好序
	// 记录上一位数为cur，初始化cur = 0(数组a中所有数据皆大于0)
	// 然后不断遍历数据，发现了比cur大的数据就令其为新cur
	// 若发现和cur相等的数据，则代表该数组不可以排列成严格递增的一串数据，输出NO并返回
	// 遍历完毕仍未输出NO的话，则输出YES
	for (int i = 0;i < n;i++) {
		if (a[i] > cur)cur = a[i];
		else if (a[i] == cur) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}