#include<iostream>
#include<map>
using namespace std;

void solve() {
    long long ans = 0;
    int n;
    cin >> n;
    map<int, int> cnt;
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