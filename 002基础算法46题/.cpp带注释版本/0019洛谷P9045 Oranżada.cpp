#include <iostream>
using namespace std;

long long a[500010];
bool used[500100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // 这题我们只需要把每次抓到的新品牌都交换到左边并计算交换量
    // 一旦抓够了k个新品牌就输出答案
    // 若是遍历完了也抓不到k个，输出-1

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    // 把橙汁品牌都存入数组a中
    long long ans = 0;
    // 累计最小交换代价
    int g = 0;
    // 已确定的不同品牌数量(即已填好的位置数)
    for (int i = 1; i <= n; i++) {
        if (!used[a[i]]) {
            ans += i - g - 1;
            // 遇到一个尚未使用的新品牌
            g++;
            // 把它从位置i交换到位置g+1的代价
            used[a[i]] = true;
            // 标记该品牌已使用
            if (g == k) {
                // 凑够k个不同品牌
                cout << ans;
                return 0;
                // 从左往右选，首次凑够即为最小代价
            }
        }
    }
    cout << -1;
    // 扫描完仍不足k个不同品牌，无解
    return 0;
}