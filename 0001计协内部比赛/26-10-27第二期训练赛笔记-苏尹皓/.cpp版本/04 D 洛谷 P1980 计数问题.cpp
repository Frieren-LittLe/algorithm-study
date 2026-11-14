#include<iostream>
using namespace std;
int n;
int ans;
int t;
int main() {
	cin >> n;
	cin >> t;
	for (int i = 1;i <= n;i++) {
		int d = i;
		while (d > 0) {
			int x = d % 10;
			if (x == t) {
				ans++;
			}
			d = d / 10;
		}
	}
	cout << ans << endl;
	return 0;
}