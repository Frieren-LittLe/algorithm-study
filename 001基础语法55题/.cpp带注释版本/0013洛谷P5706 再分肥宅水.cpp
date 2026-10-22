#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	float a;
	int b;
	cin >> a >> b;
	cout << fixed << setprecision(3) << a / b << endl;
	cout << b * 2 << endl;
	return(0);


}