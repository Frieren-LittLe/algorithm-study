#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin >> q;
	map<string, int> mp;
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			string s;
			cin >> s;
			int sc;
			cin >> sc;
			mp[s] = sc;
			cout << "OK" << endl;
		}
		if (op == 2) {
			string s;
			cin >> s;
			if (mp.find(s) == mp.end()) {
				// .find(某一键)可以查找出某一键是否在map中存过
				// .find返回的是迭代器，不可以用int等容器来存,默认容器为auto
				// 当map容器没有存过所要查找的键时，返回同为迭代器的.end()，判断该键是否存在，比较.find()是否等于.end()即可
				cout << "Not found" << endl;
			}
			else {
				cout << mp[s] << endl;
			}
		}
		if (op == 3) {
			string s;
			cin >> s;
			if (mp.find(s) == mp.end()) {
				cout << "Not found" << endl;
			}
			else {
				mp.erase(s);
				// .erase(某一键)可以擦除掉map容器中的指定键和该键的对应值
				cout << "Deleted successfully" << endl;
			}
		}
		if (op == 4) {
			cout << mp.size() << endl;
		}
	}
	return 0;
}