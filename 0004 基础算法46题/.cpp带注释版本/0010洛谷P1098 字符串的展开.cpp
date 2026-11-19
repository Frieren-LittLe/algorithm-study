#include<iostream>
#include<cctype>
#include<string>
#include<algorithm>
using namespace std;
// 模拟题就是不靠数学公式抄近道
// 直接把题面规则一字不差地翻译成 C++ 的变量、循环和分支
// 在内存里把整个过程一步不落地硬跑出来

int main() {
	int p1, p2, p3;
	cin >> p1 >> p2 >> p3;

	string s;
	cin >> s;

	string result = "";

	for (int i = 0;i < s.length();i++) {
		if (s[i] != '-') {
			result += s[i];
			continue;
			// 如果未识别到'-'，照原样填入，并进行下一循环
			// 只有当
		}

		if (i > 0 && i < s.length() - 1) {
			char le = s[i - 1];
			char ri = s[i + 1];
			// 采集当前字符左边的字符及其右边的
			bool digit = isdigit(le) && isdigit(ri) && (le < ri);
			bool alpha = islower(le) && islower(ri) && (le < ri);
			// isdigit(字符变量)可以判断该字符变量是否为数字，是一类布尔函数
			// islower(字符变量)可以判断该字符变量是否为小写字母，也是一类布尔函数
			if (digit || alpha) {
				// 当判定生效之后
				string fill = ""; 
				// 规划将要填入的数据
				for (char c = le+1;c < ri;c++) {//将从c左端到c右端之间夹着的ASCII码依次拎出来
					char cur_c = c;//引入cur_c来保护c不被修改导致影响循环
					// 当前字符左端字符+1
					if (alpha && p1 == 2) { 
						cur_c = toupper(cur_c);
						// 如果'-'左右两边为字符，且p1 == 2，将其cur_c修改为大写c
					}
					if (p1 == 3) {
						cur_c = '*';
						// 如果p1 == 3,将cur_c修改为*
					}
					for (int k = 0;k < p2;k++) {
						fill += cur_c;
						//将cur_c输出p2遍
					}
				}
				if (p3 == 2) {
					reverse(fill.begin(), fill.end());
					// 若p3 == 2，将要填入的数据反转
				}
				result += fill;// 然后加进输出的字符串中
				continue;
			}
		}
		result += s[i];// 有些'-'并不满足条件，原样输出
	}
	cout << result << endl;
	return 0;
}