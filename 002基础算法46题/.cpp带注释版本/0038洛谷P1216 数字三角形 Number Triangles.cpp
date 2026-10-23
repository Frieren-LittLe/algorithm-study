#include<iostream>
#include<algorithm>
using namespace std;

int a[1005][1005];

int main() {
	int r;
	cin >> r;

	for (int i = 0;i < r;i++) {
		for (int j = 0;j <= i;j++) {
			cin >> a[i][j];
		}
	}

	for (int i = r - 2;i >= 0;i--) {
		for (int j = 0;j <= i;j++)
			a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);
	}
	cout << a[0][0] << endl;
	return 0;
}