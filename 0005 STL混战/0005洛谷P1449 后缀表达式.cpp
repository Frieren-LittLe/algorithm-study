#include<stack>
#include<iostream>
#include<string>
using namespace std;
// 本题题面完美符合了栈"后进先出"的特性(作用的永远是最近出现的前两个操作数)
int main() {
	stack<int> st;
	string s;
	cin >> s;
	int num = 0;
	for (char c : s) {
		if (c == '@') {
			break;
		}
		// 设置一个num用来存字符串中包含的数据
		// 令c-'0'可以将字符型1~9转换成整型1~9
		// num = num*10 + (c - '0') 可以让上一位的num进位
		else if (c >= '0' && c <= '9') {
			num += num * 10 + (c - '0');
		}


		else if (c == '.') {
			st.push(num);
			num = 0;
		}
		else {
			long long b = st.top();
			st.pop();
			long long a = st.top();
			st.pop();
			// 注意先后顺序，后弹出的是位于字符串前面的a，先弹出的是位于字符串后面的b
			if (c == '+')st.push(a + b);
			if (c == '-')st.push(a - b);
			if (c == '*')st.push(a * b);
			if (c == '/')st.push(a / b);
		}
	}
	cout << st.top();
	return 0;
}