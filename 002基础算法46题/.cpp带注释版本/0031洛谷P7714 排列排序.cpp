#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6 + 10;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)cin >> a[i];
	int ans = 0;
	int maxi = 0, l = 1;

	for (int i = 1;i <= n;i++) {
		maxi = max(maxi, a[i]);
		if (maxi == i) {
			int len = i - l + 1;
			if (len > 1)ans += len;
			l = i + 1;
		}
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}