#include<iostream>
#include<stack>
#include<string>
using namespace std;
// 栈：本义为竹木编成的棚栅，引申为货栈、客店等暂存实物之处
// 由“暂存实物”抽象为“暂存数据的空间”，即后进先出的数据结构栈
// (我们主要需要理解的含义)
// 再引申为层叠的技术组合——“技术栈”，全栈即覆盖整个技术层级空间
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		stack<unsigned long long > st;
		// unsigned表示无符号，即只能表示非负数（0 和正数），不能表示负数（x的数据规模为0~2^64）
		// 输入负数到 unsigned long long 会按模2^64回绕成一个大正数(如-1变成2^64-1),且cin不报错
		
		// 栈的声明格式为"stack<元素类型>变量名;"
		// 你可以把栈理解成弹匣，子弹一颗一颗压入弹匣中，卸弹时最先弹出的就是最后一颗压入的
		// 栈的特性为后进先出"（最后进去的元素，最先出来，Last In, First Out，简称LIFO）
		int n;
		cin >> n;
		while (n--) {
			string op;
			cin >> op;
			if (op == "push") {
				// 由于栈"后进先出"的特性
				// push作用于栈时，其作用是把元素压入到栈顶，格式为(栈名).push
				unsigned long long x;
				cin >> x;
				st.push(x);
			}
			else if (op == "pop") {
				if (st.empty())cout << "Empty" << endl;
				// "(栈名).empty()"是一个布尔函数，当该栈的元素数量为0时判断为true，否则为false
				// 注意.empty()的小括号内是不可以填东西的
				else st.pop();
				// "(栈名).pop()"表示将栈顶的元素弹出，空栈pop是未定义行为
			}
			else if (op == "query") {
				// query在的中文意思是"查询"
				if (st.empty())cout << "Anguei!" << endl;
				else cout << st.top() << endl;
				// "(栈名).pop()"表示的是栈顶的元素
			}
			else if (op == "size") {
				cout << st.size() << endl;
				// "(栈名).size()"表示的是当前栈的层数
			}
		}
	}
	return 0;
}