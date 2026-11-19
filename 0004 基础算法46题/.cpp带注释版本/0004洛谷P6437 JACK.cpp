#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int a[101];
	vector<int> b(0);
	int cnt = 0;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	for (int i = 0;i < n;i++) {
		for (int j = i + 1;j < n;j++) {
			for (int t = j + 1;t < n;t++) {
				int sum = a[i] + a[j] + a[t];
				// 遍历三层循环，将可能的三数之和全部算出来，若其小于m，存入数组b中
				// 当n很大时，第一层为n，第二层约为n/2，第三层约为n/3
				if (sum <= m) {
					b.push_back(sum);
					// 可变数组.push_back(所要加进去的单值) 
					// 可以将一个值加入一个可变数组当前尚未被填入的最末端
					cnt++;
				}
			}
		}
	}
	int max = b[0];
	for (int i = 0;i < cnt;i++) {
		if (b[i] > max) {
			max = b[i];
			// 再在b[]用打擂台法筛出最大值
		}
	}
	// 时间复杂度为O(n^3)，最大总计算量约为 100*50*33+100+100 = 175000
	cout << max << endl;
	return 0;
}