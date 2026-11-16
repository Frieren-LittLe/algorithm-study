#include<iostream>
using namespace std;

void solve() {
	int a1, a2, a3, a4, a5;
	cin >> a1 >> a2 >> a3 >> a4 >> a5;
	// 核心思路:逆向列方程
	// 设下标2，3，4分别被操作了x2，x3，x4次
	// 则当满足条件时,可以得到以下五个方程
	// 1. a1+x2 = 2
	// 2. a2-x2+x3 = 2
	// 3. a3+x2-x3+x4 = 2
	// 4. a4-x2+x3 = 2
	// 5. a5+x4 = 2

	// 根据 x2~x4和a1~a5 是否满足上述方程即可得到答案
	int x2 = 2 - a1;
	int x4 = 2 - a5;
	// 先求出x2和x4的值，将其代入方程2和4可得
	// x3 = 4 - a1 - a2 = 4 - a5 - a4
	int x3 = 4 - a1 - a2;
	// 最后还要令式子3成立，将x2，x3，x4带入式子3可得
	// a2 + a3 - a5 = 2和a4 + a3 - a1 = 2
	// 综上，我们需要判断x2~x4和a1~a5的点共有:
	// 1.操作次数必须大于0; x2,x3,x4 > 0;
	// 2.x3只有一个: 4 - a1 - a2 = x3 = 4- a5 - a4即a1+a2 = a4+a5 
	// 3.使3式子满足:a2 + a3 - a5 = 2 = a4 + a3 - a1，由于已知a1+a2=a4+a5,只需判断其中之一即可
	if (x2 >= 0 && x3 >= 0 && x4 >= 0 &&
		a1 + a2 == a4 + a5 &&
		a2 + a3 - a5 == 2) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}