#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	double p = (a + b + c) / 2;
	double d = sqrt(p * (p - a) * (p - b) * (p - c));
//sqrt（x）在数学上等价于x的算数平方根，源于<cmath>
	cout << fixed << setprecision(1);
	cout << d << endl;
	return(0);
}