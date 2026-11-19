#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> h;
// 设立一个布尔函数，在该函数中计算锯片高度为H时裁下来的木头总长
// 达标则返回true，不达标则返回false
bool check(long long H) {
	long long sum = 0;
	for (int i = 0;i < N;i++) {
		if (h[i] > H) {
			sum += h[i] - H;
		}
		if (sum >= M) {
			return true; // 提前返回：防 sum 溢出并提速
		}
	}
	return false;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	h.resize(N);

	long long max_h = 0;

	for (int i = 0;i < N;i++) {
		cin >> h[i];
		if (h[i] > max_h) {
			max_h = h[i];
		}
		// 不断读入数据，并且用打擂台法筛出最大值
		// (其实本题的右端点也可以不用筛，直接填一个很大的数也行)
	}

	// 利用二分法在答案取值空间里逼近最优值(所以并不需要对大树进行排序)
	// 循环结束时，ans 记录的是满足 check 的最大高度
	// （即所有 check(mid) == true 的 mid 中的最大值）
	long long L = 0;
	long long R = max_h;
	long long ans = 0;

	while (L <= R) {
		long long mid = L + (R - L) / 2;
		if (check(mid)) {
			ans = mid;
			L = mid + 1;// 满足，往大找
		}
		else {
			R = mid - 1;// 不满足，往小找
		}
	}
	cout << ans << endl;
	return 0;
}