#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

const int N = 5e6 + 5;
int a[N], d[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, p;
	cin >> n >> p;

	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		d[i] = a[i] - a[i - 1];
	}
	for (int i = 0;i < p;i++) {
		int x, y, z;
		cin >> x >> y >> z;
		d[x] += z;
		d[y + 1] -= z;
	}
	int ans = INT_MAX;

	for (int i = 1;i <= n;i++) {
		a[i] = a[i - 1] + d[i];
		ans = min(ans, a[i]);
	}
	cout << ans << endl;
	return 0;

}