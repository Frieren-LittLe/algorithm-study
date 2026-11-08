#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
// 真用暴力枚举的话得枚举到猴年马月
// 本题需要我们将"模拟"和"二分"思想联动运用
double a, b, c, d;

double f(double x) {
	return ((a * x + b) * x + c) * x + d;
	// 将a*x^3+b*x^2+cx+dy用秦九韶算法把多项式改写成嵌套的乘加形式
	// 定制一个函数f(x)，其返回值表示x代入某一元三次方程时的解
	
	// 由于该题提供的一元三次方程一定有三个实数根，并且每个根之间的距离一定大于1
	// 且根的范围限制在-100到100
	// 用零点定理(介质定理)依次检查[-100,100]内每个长度为1的区间[k,k+1]的两端点函数值符号
	// 若f(l)*f(r) > 0 说明该区间无端点，遍历下一区间
	// 若f(l)*f(r) < 0 说明该区间存在端点，并利用二分法拆到小数点后第四位的精度
	// 此时得到的“精确到小数点后两位的”的值会更精确，防止因误差而求措
	// 初始区间长度为 1，精确到小数点后第 5 位，计算量n满足1/(2^n) < 10^(-5)，解得n= 17次
	// 那么“查找”步骤中总消耗的运算量为197+17*3约为250次
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
	}
	if (f(100) == 0) {
		cout << 100;
	}
	return 0;
}