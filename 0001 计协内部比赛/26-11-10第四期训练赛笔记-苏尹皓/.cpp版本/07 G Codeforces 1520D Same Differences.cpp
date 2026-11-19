#include<iostream>
#include<map>
using namespace std;
// a_j - a_i = j - i
// 变形得到a_j - j = a_i - i;
// 设id等于a_i - i;
// 则id相同的数据互为索引对
// 输入数据的同时预处理id值，每个新数据带来的新索引对的数目为和它同id的数(除去这个数本身)

void solve() {
    long long ans = 0;
    int n;
    cin >> n;
    map<int, int> cnt;
    // 由于id值是分散的，零落的，用map来存以便节省内存
    for (int i = 1;i <= n;i++) {
        int a;
        cin >> a;
        int id = a - i;
        ans += cnt[id];
        cnt[id]++;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}