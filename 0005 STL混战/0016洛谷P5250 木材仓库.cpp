#include<iostream>
#include<set>
#include<iterator>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m;
	cin >> m;

	set<int> t;

	while (m--) {
		int op, len;
		cin >> op >> len;

		if (op == 1) {
			if (s.count(len)) {
				// "集合名.count(查找值)"在效果上可以当作布尔函数来用
				// 其返回的是查找的特定值出现的次数
				// 该次数非0时的任何值皆为true，为0值时才为false
				cout << "Already Exist\n";
			}
			else {
				s.insert(len);
			}
		}
		else {
			if (s.empty()) {
				cout << "Empty\n";
			}
			auto it = s.lower_bound(len);
			if (it == s.begin()) {
				// 没有比len更短的，只能取it
				cout << *it << '\n';
				// *it等价于该迭代器定位到的下标所存的值
				s.erase(pre);
			}
			else if (it == s.end()) {
				auto pre = prev(it);
				// prev的作用是返回指定迭代器的前一个位置的迭代器
				// 所以本句意思为设pre为it的前一位迭代器
				if (len - *pre <= *it - len) {
					cout << *pre << '\n';
				}
			}
		}
	}
	return 0;
}