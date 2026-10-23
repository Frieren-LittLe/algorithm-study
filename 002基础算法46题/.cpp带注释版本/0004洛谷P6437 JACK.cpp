#include<iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int a[101];
	int b[1145140] = { 0 };
	int cnt = 0;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	for (int i = 0;i < n;i++) {
		for (int j = i + 1;j < n;j++) {
			for (int t = j + 1;t < n;t++) {
				int sum = a[i] + a[j] + a[t];
				if (sum <= m) {
					b[cnt] = sum;
					cnt++;
				}
			}
		}
	}
	int max = b[0];
	for (int i = 0;i < cnt;i++) {
		if (b[i] > max) {
			max = b[i];
		}
	}
	cout << max << endl;
	return 0;
}