#include<iostream>
using namespace std;

int main() {
	int m;
	cin >> m;

	int l = 1, r = 1;
	int sum = 0;

	while (l <= m / 2) {
		if (sum < m) {
			sum += r;
			r++;
		}
		else if (sum > m) {
			sum -= l;
			l++;
		}
		else {
			cout << l << " " << r - 1 << endl;
			sum -= l;
			l++;
		}
	}
	return 0;
}