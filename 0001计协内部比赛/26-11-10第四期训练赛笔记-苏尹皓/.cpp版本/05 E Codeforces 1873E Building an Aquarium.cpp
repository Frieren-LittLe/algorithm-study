#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
long long x;
vector<int> a;

bool C(long long h) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < h) {
            sum += (h - a[i]);
            if (sum > x) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        a.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long L = 0, R = 2e9 + 100;
        long long ans = 0;

        while (L <= R) {
            long long mid = L + (R - L) / 2;
            if (C(mid)) {
                ans = mid;
                L = mid + 1;
            }
            else {
                R = mid - 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}