#include<iostream>
// “扫雷”是一道非常经典的“二维网络模拟”题
// 这题的“模拟”体现在：完全照搬扫雷的游戏规则
// 用代码一步步遍历每个格子的周围 8 个方向来统计地雷数量，并将结果填入网格中

using namespace std;
int main() {
	int n;
	int m;
	cin >> n >> m;
	char aaa[103][103] = { '0'};
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			char s;
			cin >> s;
			aaa[i][j] = s;
		}
	}
	for (int i = 1;i <= n;i++) {
		// 从1开始，越过边缘数组，防止越界
		
		for (int j = 1;j <= m;j++) {
			if (aaa[i][j] == '?') {
				int ans = 0;
				for (int a = i - 1;a <= i + 1;a++) {
					for (int b = j - 1;b <= j + 1;b++) {
						if (aaa[a][b] == '*') {
							ans++;
						}
					}
				}
				aaa[i][j] = ans+'0'; 
				// aaa本身是一个字符数组，我们前面求得的ans却是一个整数形
				// 所以为了让我们的答案输出ASCII码形式的数字，令ans+='0'使其转换为字符型
			
			}
		}
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			cout << aaa[i][j];
		}
		cout << endl;
	}
	return 0;
}
// 时间复杂度约为O(n^2),总计数算量约为100*100+100*100+100 = 20100