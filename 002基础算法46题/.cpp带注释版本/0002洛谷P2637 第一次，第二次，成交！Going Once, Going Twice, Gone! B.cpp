#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int p[2048];

	for (int i = 0;i < m;i++) {
		cin >> p[i];
	}
	sort(p, p + m,greater<int>());
	
	int limit = min(n, m);
	int ans1 = 0;
	int ans2 = 0;

	for (int i = 0;i < limit;i++) {
		int sum = (i + 1) * p[i];
		if (sum >= ans2) {
			ans2 = sum;
			ans1 = p[i];
		}
	}
	cout << ans1 << " " << ans2 << endl;
}