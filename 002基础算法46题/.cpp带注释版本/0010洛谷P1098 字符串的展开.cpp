#include<iostream>
#include<cctype>
#include<string>
#include<algorithm>
using namespace std;

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
		}

		if (i > 0 && i < s.length() - 1) {
			char le = s[i - 1];
			char ri = s[i + 1];

			bool digit = isdigit(le) && isdigit(ri) && (le < ri);
			bool alpha = islower(le) && islower(ri) && (le < ri);

			if (digit || alpha) {
				string fill = "";
				for (char c = le+1;c < ri;c++) {
					char cur_c = c;
					if (alpha && p1 == 2) {
						cur_c = toupper(cur_c);
					}
					if (p1 == 3) {
						cur_c = '*';
					}
					for (int k = 0;k < p2;k++) {
						fill += cur_c;
					}
				}
				if (p3 == 2) {
					reverse(fill.begin(), fill.end());
				}
				result += fill;
				continue;
			}
		}
		result += s[i];
	}
	cout << result << endl;
	return 0;
}