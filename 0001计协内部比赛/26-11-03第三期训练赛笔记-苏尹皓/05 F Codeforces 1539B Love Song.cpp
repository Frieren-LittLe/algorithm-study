#include<iostream>
#include<vector>
#include<string>
using namespace std;
// 这题如果用传统做法，使用内外两层循环
// q最大为10^5,n最大为10^5,两层循环的话就是10^10,超过了10^8的安全阈值，TLE！

// 仔细观察，此题有大量对连续子数组/子串的查询
// 适合用前缀和算法将时间复杂度从O(n^2)压缩到O(n)，避免TLE

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> s(n + 1, 0);
    for (int i = 1;i <= n;i++) {
        char c;
        cin >> c;
        int fill = c - 'a' + 1;
        s[i] = s[i - 1] + fill;// 当前前缀和=上一前缀和+填充值
    }
    for (int i = 0;i < q;i++) {
        int l, r;
        cin >> l >> r;
        int ans = s[r] - s[l - 1];// 右端减去左端的前一位，就可以得到该区间的值
        cout << ans << endl;
    }
    return 0;
}