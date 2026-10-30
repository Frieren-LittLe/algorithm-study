#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string s;
    cin >> s;

    // 设cur遇到 1 则+1（向右走），遇到 0 则-1（向左走）
    // 如果发现cur回到了曾经来过的地方,说明这段时间里0和1一样多（前缀和思想）
    // 那么我们就考可以认为刚才走过的路程长度为一个平衡子串的长度

    // pos 数组用来记录：cur第一次到达某个位置，是在第几步
    // 因为往左走位置会变成负数，数组下标不能是负的，所以我们干脆把起点定在 n
    // 为保证这样最坏全往左走，底标为 0，不会报错,数组一共需要 2n + 1 页
    // 第0步的时候，在起点 n  （偏移量映射思想）
    vector<int> pos(2 * n + 1, -1);

    pos[n] = 0;

    int cur = 0; // 当前位置,于坐标轴往右走变大，往左走变小。
    int ans = 0; // 记录目前找到的最长的一串平衡字串

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') cur++; // 往右走
        else cur--;             // 往左走

        // 为了不报错，把当前位置加上起点 n，转成pos上的合法底标
        int idx = cur + n;

        // 若第一次遍历该坐标
        // 记在pos上：在第 (i + 1) 步第一次来这
        // 注意：以后再绕回这个地方，也绝对不改这行记录，因为我们要留着最早的记录，才能算出最长的距离

        // 若此底标曾遍历过
        // 平衡字串的长度 = 当前的步数 (i + 1) 减去 第一次来这的步数 pos[idx]
        // 若路程比之前找到的都要长，是的话就更新答案



        if (pos[idx] == -1) {
            pos[idx] = i + 1;
        }
        else {
            ans = max(ans, (i + 1) - pos[idx]);
        }
    }

    cout << ans << "\n";

    return 0;
}