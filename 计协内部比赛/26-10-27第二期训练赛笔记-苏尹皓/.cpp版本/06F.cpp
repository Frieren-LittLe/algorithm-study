#include<iostream>
#include<string>
using namespace std;
string s;
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		int x = s.length() - 1;
		if (x < 10) {
			cout << s << endl;
		}
		else {
			char a = s[0];
			char b = s[x - 1];
			cout << s[0] << x - 1 << s[x] << endl;
		}
	}
	return 0;
}