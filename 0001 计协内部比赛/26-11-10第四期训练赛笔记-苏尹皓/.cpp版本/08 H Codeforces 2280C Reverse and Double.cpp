#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 判断能否在至多一次操作内，使所有相邻差值 <= v
bool check(int v, const vector<int>& a) {
    int n = a.size();
    vector<int> bad;
    for (int i = 0; i < n - 1; ++i) {
        if (abs(a[i] - a[i + 1]) > v) {
            bad.push_back(i);
        }
    }

    // 情况 1：没有坏缝隙，无需操作
    if (bad.empty()) return true;
    // 情况 2：超过 2 个坏缝隙，一次操作最多切两刀，无法全部修复
    if (bad.size() > 2) return false;

    // 情况 3：恰好 2 个坏缝隙，操作区间 [l, r] 唯一确定
    if (bad.size() == 2) {
        int l = bad[0] + 1;
        int r = bad[1];
        // 检查左右两个新接缝
        if (abs(a[l - 1] - 2 * a[r]) > v) return false;
        if (r + 1 < n && abs(2 * a[l] - a[r + 1]) > v) return false;
        // 检查翻转并翻倍后的区间内部
        for (int k = l; k < r; ++k) {
            if (2 * abs(a[k] - a[k + 1]) > v) return false;
        }
        return true;
    }

    // 情况 4：恰好 1 个坏缝隙 p
    int p = bad[0];

    // 子情况 4.1：p 作为左切口 (固定 l = p + 1)，向右枚举 r
    int l = p + 1;
    for (int r = l; r < n; ++r) {
        if (r > l && 2 * abs(a[r - 1] - a[r]) > v) break;
        bool ok_left = (abs(a[l - 1] - 2 * a[r]) <= v);
        bool ok_right = (r + 1 == n || abs(2 * a[l] - a[r + 1]) <= v);
        if (ok_left && ok_right) return true;
    }

    // 子情况 4.2：p 作为右切口 (固定 r = p)，向左枚举 l
    int r = p;
    for (int cur_l = r; cur_l >= 0; --cur_l) {
        if (cur_l < r && 2 * abs(a[cur_l] - a[cur_l + 1]) > v) break;
        bool ok_left = (cur_l == 0 || abs(a[cur_l - 1] - 2 * a[r]) <= v);
        bool ok_right = (r + 1 == n || abs(2 * a[cur_l] - a[r + 1]) <= v);
        if (ok_left && ok_right) return true;
    }

    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 计算初始最大相邻差值作为二分上界
    int max_diff = 0;
    for (int i = 0; i < n - 1; ++i) {
        max_diff = max(max_diff, abs(a[i] - a[i + 1]));
    }

    // 二分最小 gap 值，用 ans 记录可行解
    int L = 0, R = max_diff, ans = max_diff;
    while (L <= R) {
        int mid = L + (R - L) / 2;
        if (check(mid, a)) {
            ans = mid;
            R = mid - 1;
        }
        else {
            L = mid + 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}