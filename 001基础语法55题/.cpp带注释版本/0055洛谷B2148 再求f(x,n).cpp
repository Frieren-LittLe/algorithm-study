#include<iostream>
#include<iomanip>
using namespace std;

double f(double x, int n) {
	if (n == 1) {
		return x / (1 + x);//先写好最内层的运算，即最右下角的x/1+x
	}
	return x / (n + f(x, n - 1));//再写外层的运算
	//这道题我并没有用for循环构建外层运算，但是使用嵌套的方式也可以得到循环运算
}

int main() {
	double x;
	int n;
	cin >> x >> n;
	cout << fixed << setprecision(2) << f(x, n) << endl;
	return 0;
}