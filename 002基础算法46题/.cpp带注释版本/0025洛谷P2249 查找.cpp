#include<iostream>
using namespace std;

const int N = 1e6 + 5;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i= 1;i <= n;i++) {
		cin >> a[i];
	}

	for (int i = 0;i < m;i++) {
		int q;
		cin >> q;

		int l = 1, r = n;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (a[mid] >= q)r = mid;
			else l = mid + 1;
		}
		if (a[l] == q)cout << l << ' ';
		else cout << -1 << ' ';
	}
	return 0;
}