#include<iostream>
#include<queue>
using namespace std;
// 越早合并的果子，在后续的合并中会被反复当成新堆的一部分再次相加
// 为使相加总和最小，先合并的果子尽量为最小的两堆
// 可以利用优先队列的特性来解决
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		pq.push(x);
	}
	int sum = 0;
	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		// 用小根堆筛出最小的两个值，将其相加，记录消耗的体力并将结果存回队列中
		int c = a + b;
		sum += c;
		pq.push(c);
	}
	cout << sum << endl;
	return 0;
}