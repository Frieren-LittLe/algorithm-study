#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

//观察题目可以发现，题中的规律为从最里层的√（1+x），依次向外叠加上2,3...n，每层都套一个根号
//最内层为1+x，第k层嵌套为√（k+上一层结果）
double Domath(double x, int n) {//那么很明显，我们可以制作一个嵌套函数来进行运算
	double f = sqrt(1 + x);//先制作最底层的√（1+x）令这一层结果为f
	for (int i = 2;i <= n;i++) {
		f = sqrt(i + f);// 每一层再把该层数加到上一层f上，再整体套根号得到新的f
	}
	return f;//执行到第n层，得到最终结果
}

int main() {
	double x;
	int n;
	cin >> x >> n;
	double f = Domath(x, n);
	//然后再读取x和n来运算就行了
	cout << fixed << setprecision(2) << f << endl;
	return 0;
}