#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[100];
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	//读取每个小鱼的可爱值，存入数组中
	for (int i = 0;i < n;i++) {
		int L = 0;
		//设可爱值不及当前小鱼的左边的小鱼的个数为L
		for (int j = 0;j < i;j++)
			//从0起读到i-1，i-1就是当前小鱼的底标
			if (a[j] < a[i]) {
				L++;
				//当小鱼j不及当前小鱼i可爱时，L增加
			}
		cout << L << " ";
	}
	return 0;
}