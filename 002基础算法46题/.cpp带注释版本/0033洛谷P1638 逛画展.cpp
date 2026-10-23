#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6 + 10;
const int M = 2010;
int a[N];
int b[M];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	int l = 1, r = 0;
	int cnt = 0;
	int ans = N;
	int ansL = 1, ansR = n;
	while (r < n) {
		r++;
		if (b[a[r]] == 0)cnt++;
		b[a[r]]++;
		while (cnt == m) {
			if (r - l + 1 < ans) {
				ans = r - l + 1;
				ansL = l;
				ansR = r;
			}
			b[a[l]]--;
			if (b[a[l]] == 0)cnt--;
			l++;
		}
	}
	cout << ansL << " " << ansR << endl;
	return 0;
}