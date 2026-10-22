#include<iostream>
using namespace std;

long long  Domath(int n, int x) {//和上一题同理，本质上分段嵌套函数，不再仔细讲解
	if (n == 0) return 1;
	else if (n == 1) return 2 * x;
	else if (n > 1) {
		return 2 * x * Domath(n - 1, x) - 2 * (n - 1) * Domath(n - 2, x);
	}
}
int main() {
	int n, x;
	cin >> n >> x;
	cout << Domath(n, x) << endl;
	return 0;
}