#include <iostream>
#include <iomanip>
#include <cmath>
//cmath的主要作用：提供丰富的数学函数
using namespace std;

int main() {
	int r;
	cin >> r;
	double V = (4.0 / 3.0) * 3.14 * pow(r, 3);
//pow源于头文件<cmath>   前面的r表示底数，后面的3表示幂数
//tips：幂数是可以为负数的，例如：pow(r, -3) 就是"半径的立方的倒数"
	cout << fixed << setprecision(5);
	cout << V << endl;
	return(0);
}