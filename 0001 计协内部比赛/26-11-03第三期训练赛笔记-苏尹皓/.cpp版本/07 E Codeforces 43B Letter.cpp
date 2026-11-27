#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    // getline保留空格，只以换行符终止，并丢弃换行符
    int S1[26] = { 0 };
    int S2[26] = { 0 };
    int S3[26] = { 0 };
    int S4[26] = { 0 };

    // 想要判断上句能不能拼成下句
    // 只需判断上句的大小写字符的个数是否比下句多就行了
    // 注意题意，大小写字符要分开判断
    for (char c : s1) {
        if (c >= 'a' && c <= 'z') S1[c - 'a']++;
        if (c >= 'A' && c <= 'Z') S3[c - 'A']++;
        // 为了方便大小写字符存入字符串数组中，要把读入的字符转化成ASCII码中的编号
        // 小写字符-'a'，大写字符-'b'即可快速得到
        // A的编号是65，Z的编号是90
        // a的编号是97，z的编号是122
        // 所以大小写不能太简单地放在一个大小52的数组里
    }

    for (char c : s2) {
        if (c >= 'a' && c <= 'z') S2[c - 'a']++;
        if (c >= 'A' && c <= 'Z') S4[c - 'A']++;
    }

    int ans = 1;
    for (int i = 0; i < 26; i++) {
        if (S1[i] < S2[i]) {
            ans = 0;
            break;
        }
        if (S3[i] < S4[i]) {
            ans = 0;
            break;
        }
    }
    if (ans == 1) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}