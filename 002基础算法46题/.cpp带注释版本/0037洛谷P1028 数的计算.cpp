#include<iostream>
using namespace std;
 
int f[1005];

int main() {
	int n;
	cin >> n;
	f[1] = 1;
	for (int i = 2;i <= n;i++) {
		f[i] = f[i - 1];
		//奇数i和它前面的偶数i-1，在构造数列时能添加的数是一样的
		if (i % 2 == 0) {
			f[i] += f[i / 2];
			//偶数 i 比它前面的奇数 i-1 多了一个可选的第二位数 i/2，而这一类方案的数量正好是 f(i/2)
		}
	}
	cout << f[n];
	return 0;
}