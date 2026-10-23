#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	bool has = false;

	for (int i = 0;i < n;i++) {
		cin >> a[i];
		if (a[i] == 1)has = true;
	}

	if (!has) {
		cout << 0;
	}
	else {
		int l = 0;
		while (a[l] != 1)l++;

		int r = n - 1;
		while (a[r] != 1)r--;

		cout << r - l + 1;
	}
	return 0;
}