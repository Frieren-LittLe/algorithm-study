#include<iostream>
using namespace std;

const int N = 1e6 + 5;
int a[N];
// 这题如果用传统查找法，最坏情况下，运算量为10^6*10^5= 10^11，超时!

// 观察到这题初始数列满足"单调不减"的特征，可以考虑使用二分法
// 二分法:抽出数列中间的数mid，将该数据和我们要判断位置的另一个数据q进行比较
//		  若mid大于等于q，即mid及右边的数据全部大于等于q，则将判断区间的右端点缩至mid
//		  若mid小于q，即mid及左边的数据全部小于q，则将判断区间的左端点缩至mid+1
//		  缩小区间后，再计算新的mid，直到l= r时，循环停止
		  
// 枚举法需要从头遍历到尾，一次最多需要10^6次运算
// 二分法只取每层区间的中间一位判断，一次最多只需要log_2(10^6) 也就是约等于20次运算
// 只看"查找"步骤的话，时间复杂度从O(n)被压缩到O(log_n)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i= 1;i <= n;i++) {
		cin >> a[i];
	}

	for (int i = 0;i < m;i++) {
		int q;
		cin >> q; 

		int l = 1, r = n;
		while (l < r) {
			int mid = l + (r - l) / 2;
			// l+(r-l)/2是(r+l)/2的等价写法，这么写是为了防止爆内存
			if (a[mid] >= q)r = mid;
			else l = mid + 1;
		}
		if (a[l] == q)cout << l << ' ';
		else cout << -1 << ' ';
		// 如果最后得到的数据等于Q的话，输出最终的l，否则就是没找到，输出'-1'
	}
	return 0;
}