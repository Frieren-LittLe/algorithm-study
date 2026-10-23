#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5e5 + 10;
int n, k;
int a[N];
int pre[N];
int suf[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);

	int j = 1;
	for (int i = 1; i <= n;i++) {
		while (a[i] - a[j] > k) {
			j++;
		}
		pre[i] = max(pre[i - 1], i - j + 1);
	}

	j = n;
	for (int i = n;i >= 1;i--) {
		while (a[j] - a[i] > k) {
			j--;
		}
		suf[i] = max(suf[i + 1], j - i + 1);
	}

	int ans = 0;
	for (int i = 1;i < n;i++) {
		ans = max(ans, pre[i] + suf[i + 1]);
	}
	cout << ans << endl;
	return 0;
}