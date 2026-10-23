#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> add(vector<int>& a, vector<int>& b) {
	vector<int> c;
	int carry = 0;

	for (int i = 0;i < a.size() || i < b.size() || carry;i++) {
		if (i < a.size()) carry += a[i];
		if (i < b.size()) carry += b[i];
		c.push_back(carry % 10);
		carry /= 10;
	}
	return c;
}

int main() {
	int n;
	cin >> n;
	
	vector<int> f[3] = { {1},{1},{} };
	//f[1]等于1
	for (int i = 2; i <= n;i++) {
		f[i % 3] = add(f[(i - 1) % 3], f[(i - 2) % 3]);
	}
	vector<int>& ans = f[n % 3];

	for (int i = ans.size() - 1;i >= 0;i--) {
		cout << ans[i];
	}
	return 0;
}