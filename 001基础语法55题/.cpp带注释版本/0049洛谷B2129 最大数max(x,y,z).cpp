#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int Max(int a, int b, int c) {
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	return max;
}
//制作一个判断最大值的函数:打擂台法:让a做擂主，b，c依次上擂台比较，赢了旧擂主的数据做新擂主
//制作该函数主要是为了方便接下来引用最大值

double Domath(int a, int b, int c) {//再照着题意制作一套运算函数
	int up = Max(a, b, c);//注意该函数应用了我们之前制作的Max函数，方便了新函数的构建
	int down = Max(a + b, b, c) * Max(a, b, b + c);
	double m = (double)up / down;//先运算分子，再运算分母，最后令分子除以分母，简洁明了
	return m;
}


int main() {//主函数只需要读取数据并把数据导入我们之前的运算函数旧行了
	int a, b, c;
	cin >> a >> b >> c;
	double m = Domath(a, b, c);
	cout << fixed << setprecision(3) << m << endl;
	return 0;
}