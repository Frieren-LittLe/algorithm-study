#include<iostream>
using namespace std;
// 由完全平方公式可知 (a + b + c)^2 = a^2 + b^2 + c^ 2 + 2ab + 2ac + 2bc
// 设我们所求的"答案(ab + ac + bc)"为q，则q = [|r1 + r2 + r3|^2 - r1^2 - r2^2 - r3^2] / 2;
// 由于r1，r2,r3为定值，要让q最小，只需让|a + b + c|最小
// 若r3 <= r1 + r2，三个向量可以首尾相接形成闭合三角形，使得|a + b + c| = 0
// 此时q为- (r1^2 + r2^2 + r3^2)/2
// 若r3 > r1 + r2，最小合向量长度为:|a + b + c| = r3 - r1 - r2
// 此时q为 r1*r2 - r1*r3 - r2*r3
// 由于r1，r2，r3均为整数，除以2后小数部分只可能为.0或.5，且计算过程中可能会产生double存不下的数据，因此我们开long long
int main() {
	long long r1, r2, r3;
	cin >> r1 >> r2 >> r3;
	if (r1 + r2 >= r3) {
		long long sum = r1 * r1 + r2 * r2 + r3 * r3;
		cout << -(sum / 2) << (sum & 1 ? ".5\n" : ".0\n");
		// "& 1"与"% 2 == 1"等价，但是前者只要判断两个数二进制格式中最小的一位，速度相对而言更快(但其实快不了多少)
	}
	else {
		long long q = r1 * r2 - r1 * r3 - r3 * r2;
		cout << q << ".0\n";
	}
	return 0;
}