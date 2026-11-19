#include <iostream>
using namespace std;

int main() {
	int length, n = 1;
	cin >> length;
	while (length > 1) {
	//while（条件）{循环体：条件为ture时反复执行}
		length = length / 2;n++;
	}
	cout << n << endl;
	return 0;
}