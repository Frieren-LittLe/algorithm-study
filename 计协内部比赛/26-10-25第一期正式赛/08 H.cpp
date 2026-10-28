#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 与其计算“最少需要从两端移除多少个元素”
// 不如反过来求“和正好等于s的最长连续子数组”
void solve() {
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total_sum += a[i];
    }

    // 如果全部元素加起来都不够 s，绝对不可能达成
    if (total_sum < s) {
        cout << -1 << "\n";
        return;//retrun用于跳出分函数
    }

    // 如果总和刚好等于 s，说明一个元素都不用删
    if (total_sum == s) {
        cout << 0 << "\n";
        return;
    }
    // 凡是涉及"寻找满足特定条件的连续子数组（或区间）"的问题
    // 通常都可以优先考虑使用"滑动窗口（同向双指针）"算法



    int L = 0;
    int current_sum = 0;
    int max_len = -1;

    // 开始滑动窗口
    for (int R = 0; R < n; R++) {
        current_sum += a[R]; // 窗口右侧吞入新元素

        // 当窗口内的和超过 s 时，左侧吐出元素，直到和恢复合法
        while (current_sum > s && L <= R) {
            current_sum -= a[L];
            L++;
        }

        // 如果和正好等于 s，看看能不能刷新最长记录
        if (current_sum == s) {
            max_len = max(max_len, R - L + 1);
        }
    }

    // 最小操作数 = 总长度 - 留下来的最长连续子数组长度
    cout << n - max_len << "\n";
}

int main() {
    // 优化标准输入输出速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}