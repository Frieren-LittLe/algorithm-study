#include<iostream>
using namespace std;
// 其实样例也不是非要遵守，例如这题看样例就看不出解题的方式
// 特别是对这种构造题

// 套路：固定 c = 1,1为a，b的最大公约数
// 则只需使a与b互质即可，所以目标：把 n-1 拆成两个互质的数

void solve() {
	int n;
	cin >> n;

	if (n % 2 == 0) {
		cout << n / 2 - 1 << " " << n / 2  << " " << 1;
		// 若n为偶数，由于相邻的两个数互为质数，将n-1拆为n/2-1和n/2 
	}
	else {
		int m = (n - 1) / 2;
		// 若n为奇数，先把n-1的剩余部分拆成均等的两半看还能不能拆
		// 如果还能拆成均等的两半(m为偶数)，就将一边+1，另一边-1
		// 如果无法拆成均等的两半(m为奇数)，就将一边+2，另一边-2

		if (m % 2 == 0) {
			cout << m + 1 << " " << m - 1 << " " << 1 << endl;
		}
		else {
			cout << m + 2 << " " << m - 2 << " " << 1 << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}