#include<iostream>
#include<queue>
using namespace std;
// 本题我们可以利用队列后进后出的特性
// 通过把队首的前m-1个数转移到队列后面以完成约瑟夫游戏的首尾连贯性
int main() {
	int n, m;
	cin >> n >> m;
	queue<int> q;

	for (int i = 1;i <= n;i++) {
		q.push(i);
	}
	while (!q.empty()) {
		// 循环终止条件
		for (int i = 1;i < m;i++) {
			q.push(q.front());
			q.pop();
			// 对于每次出圈前的m-1个数，复制一份存进队尾，然后再将队首的本体弹出
		}
		// 对于每次循环的第m个数，将其输出，然后从队列中弹出
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}