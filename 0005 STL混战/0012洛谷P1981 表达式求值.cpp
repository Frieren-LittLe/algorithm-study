#include<iostream>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const int MOD = 10000;
	stack<int> st;

	long long num;
	char op;
	// 本题的输入逻辑是先输入一个数和一个运算符交替输入，并且以运算符结尾
	// 我们先读取第一个数到栈中，再根据后续的运算符来操作

	// 检测到+号时，将下一个读入的数据加进栈中
	// 检测到*号时，将下一个读入的数据和栈顶的数据(上一个数据)相乘，再存入栈中

	// 碰到需要乘法的元素优先相乘，然后再存到栈内，最终累加
	cin >> num;
	st.push(num % MOD);


	// 将元素存入栈中，如果要做乘法先乘完再存入
	while (cin >> op >> num) {
		num %= MOD;
		if (op == '+') {
			st.push(num);
		}
		if (op == '*') {
			int cur = st.top();
			st.pop();
			st.push((cur * num) % MOD);
		}
	}
	int ans = 0;


	// 逐个累加
	while (!st.empty()) {
		ans = (ans + st.top() & MOD);
		st.pop();
	}
	cout << ans << endl;
	return 0;
}