#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> h;
bool check(int H) {
	long long sum = 0;
	for (int i = 0;i < N;i++) {
		if (h[i] > H) {
			sum += h[i] - H;
		}
		if (sum >= M) {
			return true;
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
	}
	int L = 0;
	int R = max_h;
	int ans = 0;

	while (L <= R) {
		int mid = L + (R - L) / 2;
		if (check(mid)) {
			ans = mid;
			L = mid + 1;
		}
		else {
			R = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}