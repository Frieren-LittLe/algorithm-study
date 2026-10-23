#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> segs(n);
	for (int i = 0;i < n;i++) {
		cin >> segs[i].first >> segs[i].second;
	}

	sort(segs.begin(), segs.end());

	long long ans = 0;
	int start = segs[0].first, end = segs[0].second;

	for (int i = 1;i < n;i++) {
		int l = segs[i].first, r = segs[i].second;
		if (l >= end) {
			ans += end - start;
			start = l;
			end = r;
		}
		else {
			end = max(end, r);
		}
	}
	ans += end - start;
	cout << ans << endl;
	return 0;
}