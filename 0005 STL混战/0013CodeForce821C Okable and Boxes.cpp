#include<iostream>
#include<stack>
#include<string>
using namespace std;
// “告诉他达里需要重排箱子的最小次数”,这里的重排不是指一次交换位置，而是指一整套套排序步骤
// 也就是说只要花一次代价就可以重排整个栈，那我们触发重排时，将栈里的所有箱子按从大到小排得整整齐齐
// 让栈里现有的所有箱子在接下来的remove中全部按照顺序出现在栈顶，再也不需要为它们花任何调整次数
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	stack<int> st;
	int need = 1; // 当前remove的值
	int ans = 0;  // 需要重排的次数 

	for (int i = 0;i < 2 * n;i++) {
		string op;
		cin >> op;
		if (op == "add") {
			// 当读到"add"时，输入新数据，将新数据存入栈中
			int x;
			cin >> x;
			st.push(x);
		}
		else {
			// 当读到"remove"时
			// 若当前数据没有被清空，取栈顶元素判断是否和所需要remove的元素相同，若相同则将其弹出
			// 若当前数据没有被清空，且此时所需要移出的元素不在栈顶，ans++(执行一次重排操作，在物理建模层面从大往小排)
			// 随后，清空整个栈
			// 因为在物理建模层面此时整个栈的顺序都已经从大到小被排好了,这段栈内的元素在碰到remove时，不会再触发ans++
			// 那么，当栈empty时ans++，也就是说此时在代码层面，栈从大往小排好序的情况和空栈的情况等价，
			// 并且写.empty()消耗的运输量比写一段代码模拟重排节省的多
			// 于是我们干脆直接写st.empty()
			// 像这种"满足条件的已整理区省略"的思想，就是"状态压缩"及"抽象建模"思想
			if (!st.empty()) {
				if (st.top() == need) {
					st.pop();
				}
				else {
					ans++;
					while (!st.empty()) {
						st.pop();
					}
				}
			}
			need++;
		}
	}
	cout << ans << '\n';
	return 0;
}