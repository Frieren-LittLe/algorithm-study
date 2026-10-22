#include<iostream>
using namespace std;

struct S {
	int ID;
	int score1;
	int score2;

	int sum1() {
		//建立一个名为sum1的函数，返回一个整数数值
		//可以近似理解为 int sum1() = score1 + score2;
		return score1 + score2;
		//当函数执行到return时，立即结束，后面的代码不再执行，并且把 return 后面的值作为结果返回
	}
	//为什么不能直接int sum1()= score1 + score2？
	//结构体内部不能写 = 去执行运算，但可以写 return 表达式；return 语句是函数体的一部分，所以合法
	int sum2() {
		return score1 * 7 + score2 * 3;
	}
};
//结构体的内部也是可以建立函数的，这样做是为了省去声明结构体名称方便函数的构建
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n;i++) {
		S stu;//每次循环都创建一个新的 stu（局部变量）
		//注意：在循环内创建的参数，循环结束后就自动消失
		cin >> stu.ID >> stu.score1 >> stu.score2;

		if (stu.sum1() > 140 && stu.sum2() >= 800) {
			cout << "Excellent" << endl;
		}
		else {
			cout << "Not excellent" << endl;
		}
	}
	return 0;
}