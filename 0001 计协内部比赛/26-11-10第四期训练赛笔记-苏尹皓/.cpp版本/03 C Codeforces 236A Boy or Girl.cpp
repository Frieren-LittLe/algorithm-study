#include<iostream>
#include<string>
int cc[26];
using namespace std;
// 记录26个字出现的个数
// 判断该数量是否为偶数
int main() {
    string s;
    cin >> s;
    int n = 0;
    for (char c : s) {
        if (cc[c - 'a'] == 0) {
            n++;
            cc[c - 'a']++;
        }
    }
    if (n % 2 == 0) {
        cout << "CHAT WITH HER!" << endl;
    }
    else {
        cout << "IGNORE HIM!" << endl;
    }
    return 0;

}