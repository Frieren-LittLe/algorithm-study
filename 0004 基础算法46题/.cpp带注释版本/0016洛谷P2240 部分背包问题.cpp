#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 所谓贪心，就是只顾眼前最优、不顾长远后果的短视选择
// 当通过不断地短视运算恰好能满足最优解时，就可以使用贪心算法

struct  bao {
    int m;
    int v;
    double vBm() const {
        // C++中，若一个成员函数只读取，不修改对象成员，建议在参数列表后加const
        return (double)v / m;
    }
};

bool cmp(const bao& b1, const bao& b2) {
    return b1.vBm() > b2.vBm();
    // 制作一个cmp函数，比较其重价比来排序
}

int main() {
    int N, T;
    cin >> N >> T;
    vector<bao> Bao(N);

    for (int i = 0;i < N;i++) {
        cin >> Bao[i].m >> Bao[i].v;
    }
    // 输入

    sort(Bao.begin(), Bao.end(), cmp);
    // 排序

    double ans = 0;
    for (int i = 0;i < N;i++) {
        // 重价比高的优先装入，
        if (T >= Bao[i].m) {
            ans += Bao[i].v;
            T -= Bao[i].m;
            // 当背包剩余承重大于等于当前金币重量时
            // 剩余承重 -= 当前金币重量；总价值 += 当前金币总价
        }
        else {
            ans += (double)T / Bao[i].m * Bao[i].v;
            break;
            // 当背包剩余承重小于当前金币重量时
            // 计算并添加当前能装下一部分T/m *v金币，然后退出函数
        }
    }

    printf("%.2f\n", ans);
    // 使用C语言输出，方便且效率快

    return 0;
}