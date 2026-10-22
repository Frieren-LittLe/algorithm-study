#include<iostream>
using namespace std;

int main() {
	int a[100];
	//设计一个数组用于存数
	int n = 0;
	//对存进去了多少个数进行计数
	int x;
	while (cin >> x) {
		//while (cin >> x) 就是持续不断地从输入中读取数据给 x，每次都用新值覆盖旧值，直到输入结束
		//这是使用while来不断读取输入数据的一种方式
		if (x == 0)break;
		//当输入0时，程序自动打断
		a[n] = x;//把x的当前值存入数组里面
		n++;
	}
	for (int i = n - 1;i >= 0;i--) {
		//用for循环来把数组的数从n-1到0递减式输出
		cout << a[i] << " ";
	}
	return 0;
}