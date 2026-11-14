#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	int mx = 0;
	for (int i = 0;i < n;i++) {
		int a, b;
		cin >> a >> b;
		ans += a;
		mx = max(ans, mx);
		if (ans - b < 0) {
			ans = 0;
		}
		else {
			ans -= b;
		}

	}
	cout << mx << endl;
	return 0;
}