#include<iostream>
using namespace std;
int main() {
	long long n, k;
	cin >> n >> k;
	long long a[2048];
	int ans = 0;

	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}

	for (int i = 0;i < n;i++) {
		for (int j = i+1;j < n;j++) {
			if (a[i] * a[j] <= k) {
				ans++;
			}
		}
	}
	cout << ans << endl;
}
// 时间复杂度为O(n^2)，最大计算量约为100*(99/2)*2 = 9900