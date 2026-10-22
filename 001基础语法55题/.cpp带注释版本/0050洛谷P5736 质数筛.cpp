#include<iostream>
using namespace std;

bool Prime(int n) {
	if (n < 2) return false;
	for (int i = 2;i * i <= n;i++) {
		if (n % i == 0) return false;
	}
	return true;
}
//在0048笔记中，有关于 制作判断质数的布尔函数 的方法


int main() {
	int n;
	cin >> n;
	//读取数值总数
	for (int i = 0;i < n;i++) {//制作一个循环，从0读到n-1，一共读取n遍
		int a;
		cin >> a;//将读取的数组依次进行质数判断，判断成功将其输出并附上空格
		if (Prime(a)) {
			cout << a << " ";
		}
	}
	return 0;
}