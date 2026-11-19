// 这题的算法实现的思路是;
// 我们知道序号在前的数一定要被序号在后的数淘汰
// 那么最后一次运算（此时已经淘汰掉除最后一位的所有数据）一定会令序号为n的数做为剩下的战士
// 所以本质上我们要令a[n]的值为最大
// 由于a[n-1]后面只有a[n]这一个数，所以a[n]-a[n-1]是必然发生的
// 如果使a[n-1]足够小，那么就减小了a[n]-a[n-1]对a[n]造成的负担
// 并且我们知道战士的评级可以为负数，若a[n-1]在运算完毕后得到的值为一个负数，那么不久可以使得a[n]的值变大吗？
// 由此可观，若我们让a[n-1]减去前面所有的值，就可以得到最终结果为a[n]-a[n-1]+a[1]+a[2]+a[3]+...+a[n-2]
// 即除a[n-1]以外所有数的总和减去a[n-1]的值

// 或许看完算法的实现逻辑有一种“感觉懂了但是没完全懂，且不知道自己哪里没懂”的感觉，不过广度上来了之后再回顾这道题就懂意思了
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);//下标从1开始，合法范围要到n+1
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // 累加前 n - 2 名战士的评级
    long long sum = 0;
    for (int i = 1; i <= n - 2; ++i) {
        sum += a[i];
    }

    // 最终最大评级 = a[n] - a[n-1] + 前 n-2 人的总和
    long long ans = a[n] - a[n - 1] + sum;
    cout << ans << "\n";//需要很多次换行时，勤加’\n'加快速度
}

int main() {
    // 优化输入输出流速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //加速代码，要经常加
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    //通过viod来让代码分层的方式  可以通过多打来练会
    return 0;
}

