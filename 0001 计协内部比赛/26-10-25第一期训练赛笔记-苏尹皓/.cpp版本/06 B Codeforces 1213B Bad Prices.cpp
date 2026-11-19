#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		int a[1000860];
		cin >> n;
		for (int i = 0;i < n;i++) {
			cin >> a[i];
		}

		int bd = 0;
		// 用于记录badday
		int min = a[n - 1];
		// 当我们从前往后推时，不难发现我们推到的当前值是很难判断是否为bd的
		// 但是当我们从后往前推，就很容易判断当前值是否为bd
		// 假设最后一天是我们见过的最小值
		// 接下来，从倒数第二天开始，设立一个min值，依次往前推，
		// 可以发现我们不但能判定当前值是否为bd，还能在判定的同时，不断地更新min值，来帮助我们继续往前推
		for (int i = n - 2;i >= 0;i--) {
			if (a[i] > min) {
				bd++;//若当日值大于从后往前见过最小值，则判定当日为bd
			}
			else {
				min = a[i];//否则令其为新的min值
			}
		}
		cout << bd << endl;
	}
	return 0;
}