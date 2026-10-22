#include <iostream>
using namespace std;

int main() {
	int a[105];
	int b[20000] = { 0 };
	//数组b中下标为1的数代表可能存在的和的值
	int n
	int ans = 0;
	cin >> n;
	for (int i = 0;i < n;i++) cin >> a[i];
	for (int i = 0;i < n;i++) {
	//第一步，先选一个数作为第一个数（从第0个开始选）；
		for (int j = i + 1; j < n; j++) {
		//第二步，从这个数后面的所有数里，依次选一个作为第二个数；
			b[a[i] + a[j]] = 1;
			//第三步，把这两个数加起来，在标记板上记一笔：这个和出现过。
		}
	}
	for (int i = 0; i < n; i++) {
		if (b[a[i]] == 1)ans++;
		//令a数组中出现过的数在数组b作为下标，一旦发现被标记就将ans值+1;
	}
	cout << ans << endl;
	return 0;
}