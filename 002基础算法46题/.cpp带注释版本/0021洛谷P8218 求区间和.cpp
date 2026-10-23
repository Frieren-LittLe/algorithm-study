#include<iostream>
using namespace std;

const int N = 1e5 + 5;
long long s[N];

int main() {
	int n, m;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		int x;
		cin >> x;
		s[i] = s[i - 1] + x;
	}
	cin >> m;
	for (int i = 1;i <= m;i++) {
		int l, r;
		cin >> l >> r;
		cout << s[r] - s[l - 1] << '\n';
	}
	return 0;
}