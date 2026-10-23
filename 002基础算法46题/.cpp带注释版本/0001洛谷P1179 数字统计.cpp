#include<iostream>
using namespace std;
int main() {
	int L, R;
	cin >> L >> R;
	int ans = 0;
	for (int i = L;i <= R;i++) {
		int t = i;
		while (t > 0) {
			if (t % 10 == 2) {
				ans++;
			}
			t = t / 10;
		}
	}
	cout << ans << endl;
	return 0;
}