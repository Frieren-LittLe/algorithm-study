#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double a, b, c, d;

double f(double x) {
	return ((a * x + b) * x + c) * x + d;
}

int main() {
	cin >> a >> b >> c >> d;

	cout << fixed << setprecision(2);

	for (int i = -100;i < 100;i++) {
		double l = i;
		double r = i + 1;
		double fl = f(l);
		double fr = f(r);
		if (fl == 0) {
			cout << l << " ";
		}
		else if (fl * fr < 0) {
			while (r - l > 1e-4) {
				double mid = (l + r) / 2;
				double fm = f(mid);
				if (fl * fm <= 0) {
					r = mid;
					fr = fm;
				}
				else {
					l = mid;
					fl = fm;
				}
			}
			cout << l << " ";
		}
		if (f(100) == 0) {
			cout << 100;
		}
	}
	return 0;
}