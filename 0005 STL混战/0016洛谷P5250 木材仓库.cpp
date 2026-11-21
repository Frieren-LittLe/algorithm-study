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
	// set是自动排序+去重的容器，可以直接对其使用lower_bound和upper_bound
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
				continue;
			}
			auto it = s.lower_bound(len);
			if (it == s.begin()) {
				// 没有比len更短的，只能取第一位
				cout << *it << '\n';
				// *it等价于该迭代器定位到的下标所存的值
				s.erase(pre);
			}
			else if (it == s.end()) {
				auto pre = prev(it);
				// 没有比len更长的，取最后一位
				
				// prev作用是返回指定迭代器的前一个位置的迭代器，定义在<iterator>头文件之中
				// 所以本句意思为设pre为it的前一位迭代器
				cout << *pre << '\n';
				s.erase(pre);
				}
				else {
				auto pre = prev(it);
				// 左右邻居都存在，比较距离
				if (len -* pre <= *it - len) {
					// 此时*it大于len，*pre小于len，判断其差值哪个更小
					// 相等时取短的pre
					cout << *pre << '\n';
					}
				else{
					cout << *it << '\n';
					s.erase(it);
				}
			}
		}
	}
	return 0;
}