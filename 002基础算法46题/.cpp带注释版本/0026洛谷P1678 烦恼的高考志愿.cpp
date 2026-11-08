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
    // 设立一个录取线数组a
    for (int i = 0; i < n; i++) cin >> b[i];
    // 再设立一个分数数组b
    sort(a.begin(), a.end());

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        // lower_bound源于头文件<algorithm>
        // 它可以快速利用二分法得到【升序对】中第一个大于等于某一值的【迭代器】
        // 【迭代器】并非【下标】
        // a.begin()就是表示a数组开头的迭代器
        // lower_bound得到的迭代器减去.begin()就可以得到数列中有【多少个】数据严格小于所求值
        // 同时该【多少个】也为数组中第一个大于等于所求值的数据的【下标】

        // 可以看【lower_bound和upper_bound的用法.pdf】加深理解

        // 所以这句话的本质为:遍历学生估分数组 b，
        // 并把当前学生的估分 b[i] 放在学校录取线数组 a 中查找出第一个大于等于 b[i] 的录取线位置 pos
        int min_d;
        if (pos == m) {
            // 当pos == m，即 lower_bound 返回了 a.end()
            // 说明学校录取线数组 a 中所有录取线都严格小于当前学生估分 b[i]
            // 此时最接近 b[i] 的只能是 a 中的最大值 a[m - 1]
            // 不满意度等于该学生估分减去当前最大录取线
            min_d = b[i] - a[m - 1];
        }
        else if (pos == 0) {
            min_d = a[0] - b[i];
            // 当pos == 0
            // 说明学校录取线数组 a 中第一个元素 a[0] 就已经大于等于 b[i]
            // 也就是发现录取线数组中所有的录取线都大于等于当前学生估分 b[i]
            // 此时最接近 b[i] 的只能是 a 中的最小值 a[0]
        }
        else {
            min_d = min(b[i] - a[pos - 1], a[pos] - b[i]);
            // pos 在中间：b[i] 夹在 a[pos-1] 和 a[pos] 之间
            // 最接近的录取线只可能是 a[pos-1] 或 a[pos]，取两者差值较小者
        }
        ans += min_d;
    }
    cout << ans << endl;
    return 0;
}