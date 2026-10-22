#include<iostream>
using namespace std;

bool Leap(int year) {
	if (year % 400 == 0) return true;
	if (year % 100 == 0) return false;
	if (year % 4 == 0) return true;
	//因为每个if里面都有一个return判断成功就直接返回结果，不再看其余的if
	return false;
}
//制作一个判断闰年的布尔函数
int main() {
	int x, y;
	cin >> x >> y;

	int cnt = 0;
	int a[3000];
	//存一个用于装闰年年份的数组
	for (int i = x;i <= y; i++) {
		if (Leap(i)) {
			a[cnt] = i;
			cnt++;
		}//将每个年份依次拿出来进行闰年判断，判断成功存入a[]中
	}
	cout << cnt << endl;

	for (int i = 0; i < cnt; i++) {
		cout << a[i] << " ";
	}//再将a[]中的数据依次输出
	cout << endl;
	return 0;
}