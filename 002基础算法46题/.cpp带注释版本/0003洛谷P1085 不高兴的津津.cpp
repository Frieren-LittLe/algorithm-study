#include<iostream>
using namespace std;

struct S {
	int n;
	int m;
	int tol() {
		return n + m;
	}//用tol()表示n+m的值
};



int main() {
	S ltm[7];
	bool pan = false;

	for (int i = 0;i < 7;i++) {
		cin >> ltm[i].n >> ltm[i].m;
	}

	for (int i = 0;i < 7;i++) {
		if (ltm[i].tol() > 8) {
			pan = true;
			break;
		}
	}
	//制作一个布尔函数，判断这7天内是否有一天不高兴，一旦有判断为true
	int ans = 0;

	if (pan) {//当该日存在不高兴的天数时
		int max = ltm[0].tol();
		for (int i = 0;i < 7;i++) {
			if (ltm[i].tol() > max) {
				max = ltm[i].tol();
				ans = i + 1;
				//从周一到周日开始遍历，一旦发现该日的tol值大于已有的ans，令其为新的ans
			}
		}
	}
	cout << ans << endl;
}
// 【运算量与复杂度】
// 1. 实际运算量：固定遍历 7 天，总操作仅约几十步（远小于 1 秒 10^8 次上限，耗时 < 0.001ms 瞬间跑完）
// 2. 时间复杂度：O(1)（常数阶）
// 3. 判定依据：循环次数死死固定为 7，完全不随任何外部输入规模 N 改变，故统记为 O(1)