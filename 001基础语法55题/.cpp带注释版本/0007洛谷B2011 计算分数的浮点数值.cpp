#include <iostream>
#include <iomanip>
//iomanip的全称是输入输出操纵器，作用：控制cout和cin的格式化输出

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	double ans = (double)a / b;
//double是双浮点小数的意思，单浮点的小数是float，double的范围更大，float更省内存，一般情况不用float
//（double）a的意思是让a以double的格式进行运算，小数是不可以直接通过整数运算得到的，例如5/2 =2
//小数是一定要带小数点的，例如5.0 / 2.0 = 2.5
	cout << fixed << setprecision(9);
//setprecison来自iomaip，意思是输出小数到多少位，不加fixed时只会输出到有效数字
//fixed来自iomanip，作用是固定小数点位置，注意fixed，会一直生效直到你输入cout.unsetf(ios::fixed)取消
	cout << ans << endl;

	return 0;
}