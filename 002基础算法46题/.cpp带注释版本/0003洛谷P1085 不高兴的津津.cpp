#include<iostream>
#include<algorithm>
using namespace std;

struct S {
	int n;
	int m;
	int ans = 0;
	int tol() {
		return n + m;
	}
};



int main() {
	S ltm[7];
	bool pan = false;

	for (int i = 0;i < 7;i++) {
		cin >> ltm[i].n >> ltm[i].m;
	}

	for (int i = 0;i < 7;i++) {
		if (ltm[i].tol() > 8) {
			pan = true;
			break;
		}
	}

	int ans = 0;

	if (pan) {
		int max = ltm[0].tol();
		for (int i = 0;i < 7;i++) {
			if (ltm[i].tol() > max) {
				max = ltm[i].tol();
				ans = i+1;
			}
		}
	}
	cout << ans << endl;
}