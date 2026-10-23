#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    vector<int> a(m), b(n);
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(a.begin(), a.end());

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(a.begin(), a.end(), b[i]) - a.begin();

        int min_d;
        if (pos == m) {
            min_d = b[i] - a[m - 1];
        }
        else if (pos == 0) {
            min_d = a[0] - b[i];
        }
        else {
            min_d = min(b[i] - a[pos - 1], a[pos] - b[i]);
        }
        ans += min_d;
    }
    cout << ans << endl;
    return 0;
}