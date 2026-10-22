#include <iostream>
using namespace std;

int main() {
	int year, month;
	cin >> year >> month;
	switch (month) {
//switch 专门用于「整数等于哪个就执行哪个」的场景，本质是多选一的等值判断器
//switch不源自于任何头文件
//当括号内的整数等于case时，就会执行操作
//tips：switch支持整数，字符，枚举，不支持字符串和浮点数
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		cout << "31" << endl;
		break;
//break的作用是执行完cout后，立刻跳出switch,不加的话会接着去读cout << "30" << endl,导致输入大月时，不但会输出31，还会输出30
	case 4:case 6:case 9: case 11:
		cout << "30" << endl;
	}
	if (month == 2) {
		if (year % 400 == 0) {
			cout << "29" << endl;
		}
		else if (year % 100 == 0) {
			cout << "28" << endl;
		}
		else if (year % 4 == 0) {
			cout << "29" << endl;
		}
		else {
			cout << "28" << endl;
		}
//if或前面的else if成立时，后面的串联的else if 和else就自动不成立了
	}
	return(0);
}