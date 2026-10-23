#include<iostream>
#include<iomanip>
using namespace std;

int n;
int ans[10];
bool used[10];

void dfs(int step) {
	if (step == n + 1) {
		for (int i = 1; i <= n;i++) {
			cout << setw(5) << ans[i];
		}
		cout << endl;
		return;
	}
	for (int i = 1;i <= n;i++) {
		if (!used[i]) {
			used[i] = true;
			ans[step] = i;
			dfs(step + 1);
			used[i] = false;
			//递归：一个函数直接或间接地调用自己
		}
	}
}

int main() {
	cin >> n;
	dfs(1);
	return 0;
}