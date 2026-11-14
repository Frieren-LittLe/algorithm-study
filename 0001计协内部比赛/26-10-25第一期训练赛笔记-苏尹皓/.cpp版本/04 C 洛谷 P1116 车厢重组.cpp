#include<iostream>
#include<algorithm>
using namespace std;

int n;
int ans = 0;

struct train {
	int x; // 车厢号
	int p; // 原位置
};

train a[1005];

bool cmp(const train& a, const train& b) {
	return a.x < b.x; 
	//根据车厢号由小到大重排车厢
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x;//输入车厢号
		a[i].p = i; //记录下原位置
	}

	sort(a + 1, a + n + 1, cmp); 

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			//按车厢号拍好之后，我们依次看看每个数据后面都有哪些数据
			if (a[i].p > a[j].p) {
				//如果判定前一位数的原位置大于后一位数的原位置，交换的次数+1
				
				//那么实际上是怎么排的？
				///依次把序号小的排好，在排好的过程中每个车厢都只会和前面的比自己序号大的车厢排一次，这也是为什么 只 + 1
				ans++;

			}
		}
	}

	cout << ans << endl;
	return 0;
}