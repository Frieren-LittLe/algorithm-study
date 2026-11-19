// 想像用石头铺成一座金字塔，若想使其结构稳定，底面铺得的面积最大，越往上铺的石块越少，到顶上只有一块石头
// 堆，就是跟金字塔类似的上端元素少，下端元素多的一个多元素组成结构
// 最小元素在堆顶的叫小根堆，最大元素在堆顶的叫大根堆
#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	// 定义小根堆（最小的元素在堆顶）
	priority_queue<int, vector<int>, greater<int>>pq;
	// priority_queue优先队列，源于头文件<queue>,是一个“随时能取出当前最大（或最小）元素”的容器
	// 它让你不断插入元素，同时始终能以 O(1) 拿到当前最值、O(log n) 插入和删除最值，但内部不保证完全有序、也不能遍历
	// priority_queue 的“取最值”原理是堆

	// "priority_queue<参数类型(常见为数字型)> 优先队列名"是priority_queue的默认使用格式，默认为大根堆
	// 其完整模板格式为:priority_queue<数据类型, 底层容器, 比较器> 变量名;
	// 日常使用priority_queue时，底层容器几乎默认都是<vector>
	// greater<int> 是定义在 <functional> 头文件里的函数对象（仿函数），用来表示“大于”比较规则(大的排在下面)
	// 有些编译器里面的iostream可能间接引入了 <functional> 里的东西所以不引入<functional>时，greater<int> 有时也能编译通过
	while (n--) {
		int op;
		cin >> op;
		if (op == 1) {
			int x;
			cin >> x;
			pq.push(x);
		}
		else if (op == 2) {
			cout << pq.top() << endl;
			// 输出顶端的最小值
		}
		else if (op == 3) {
			pq.pop();
			// 弹出顶端的最小值
		}
	}
	return 0;
}