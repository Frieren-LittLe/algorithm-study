#include<iostream>
using namespace std;
int main() {
	int n;
	int m;
	cin >> n >> m;
	char aaa[114][514] = { 'y'};
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			char s;
			cin >> s;
			aaa[i][j] = s;
		}
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (aaa[i][j] == '?') {
				int ans = 0;
				for (int a = i - 1;a <= i + 1;a++) {
					for (int b = j - 1;b <= j + 1;b++) {
						if (aaa[a][b] == '*') {
							ans++;
						}
					}
				}
				aaa[i][j] = ans+'0';
			}
		}
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			cout << aaa[i][j];
		}
		cout << endl;
	}
	return 0;
}