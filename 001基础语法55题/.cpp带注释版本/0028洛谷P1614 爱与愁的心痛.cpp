#include<iostream>
#include<climits>
// 提供 INT_MAX（int 类型的最大值）
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int a[3000];
	int b[3000];
	int min_b = INT_MAX;
	//INT_MAX的意思就是一个无限大的值
	//这题也可以设置min = b[0]
	for (int i = 0; i < n;i++) {
		cin >> a[i];
		//先把数据全部输入进a数组中
	}
	for (int i = 0;i <= n - m;i++) {
		//总共n个数，连续m个数据组成一组，一共有n-m+1组，现在从0到n-m就数起恰好是n-m+1个数了，不会超限
		b[i] = 0;
		//令b[i]为连续m个数的总和
		//设置b[i]的初始量为0，没有初始量无法计数 
		for (int j = 0; j < m;j++) {
			b[i] += a[i + j];
			//把a[i]到a[i+m-1]的数全部加入b[i]中，得出b[i]的值
		}
		if (b[i] < min_b) {
			min_b = b[i];
			//老样子通过跟当前已读的数中的最小值比较来得出最终最小值
		}
	}
	cout << min_b << endl;
	return 0;
}