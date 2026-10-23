#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6 + 10;

int n, k;
int a[N];
int max_len = 0;

bool check(int x) {
	int sum = 0;
	for (int i = 0;i < n;i++) {
		sum += a[i] / x;
		if (sum >= k) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0;i < n;i++) {
		cin >> a[i];
		if (a[i] > max_len) {
			max_len = a[i];
		}
	}

	int l = 1;
	int r = max_len;
	int ans = 0;

	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans << endl;

	return 0;
}