#include <iostream>
using namespace std;

long long a[500010];
bool used[500100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    long long ans = 0;
    int g = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[a[i]]) {
            ans += i - g - 1;
            g++;
            used[a[i]] = true;
            if (g == k) {
                cout << ans;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}