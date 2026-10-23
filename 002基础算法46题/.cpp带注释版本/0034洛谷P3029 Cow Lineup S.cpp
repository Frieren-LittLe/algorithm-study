#include<iostream>
#include<algorithm>
#include<map>
#include<climits>
using namespace std;

struct Cow {
	int pos;
	int id;
};

bool cmp(const Cow& a, const Cow& b) {
	return a.pos < b.pos;
}

Cow a[50005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	map<int, int> total;
	
	for (int i = 0;i < n;i++) {
		cin >> a[i].pos >> a[i].id;
		total[a[i].id] = 1;
	}

	int kind = total.size();

	sort(a, a + n, cmp);

	map<int, int>cnt;

	int l = 0;
	int covered = 0;
	int ans = INT_MAX;

	for (int r = 0;r < n;r++) {
		cnt[a[r].id]++;

		if (cnt[a[r].id] == 1) {
			covered++;
		}

		while (covered == kind) {
			int cost = a[r].pos - a[l].pos;
			if (cost < ans) {
				ans = cost;
			}
			cnt[a[l].id]--;
			if (cnt[a[l].id] == 0) {
				covered--;
			}
			l++;
		}
	}
	cout << ans << endl;
	return 0;
}