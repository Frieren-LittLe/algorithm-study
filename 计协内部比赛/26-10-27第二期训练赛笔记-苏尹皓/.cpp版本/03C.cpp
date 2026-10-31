#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	int x, y, z;
	double sum = 0.0;
	cin >> x;
	if (x <= 150) {
		sum += x * 0.4463;
	}
	if (x > 150 && x <= 400) {
		sum += 150 * 0.4463;
		y = x - 150;
		sum += y * 0.4663;
	}
	if (x >= 400) {
		sum += 150 * 0.4463;
		sum += 250 * 0.4663;
		z = x - 400;
		sum += z * 0.5663;
	}
	cout << fixed << setprecision(1) << sum << endl;
	return 0;
}