// 本题看起来很难，做起来也不简单
// 以下解法运用了【树状数组】+【离散化】两种核心思想
// 关于【树状数组】，推荐视频
// https://www.bilibili.com/video/BV1ce411u7qP/?spm_id_from=333.1387.favlist.content.click&vd_source=1eeddff83189d44268cf958b438bd062
// 如果在本题型笔记中讲解必然要耗费很多文字，所以本题我打算拆散开分别讲解
// 看以下内容时推荐先看【数状数组笔记.pdf】和【洛谷P1908 逆序对(离散化).pdf】
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> a;
vector<int> b;
vector<int> bit;

int lowbit(int x) {
    return x & -x;
    // 用 x & -x 可以取出二进制中最低位的 1
    // "&"是"按位与"运算符号，"按位与"就是两个数都变成二进制，然后一位一位地对：两个都是 1 才得 1，否则得 0

    // lowbit 通常指取一个整数二进制表示中最低位的 1 所对应的值
    // 即 x 二进制中最低位的 1 所对应的 2 的幂
    // 树状数组正是利用 lowbit，让每个下标自动归属到不同层级，形成一棵隐式的树 (注意这正是难以理解的部分之一)

    // 例如下标 1~8 的 lowbit 依次是：1, 2, 1, 4, 1, 2, 1, 8
    // 分层看：lowbit=1 的（1,3,5,7）在最底层，只管自己；
    //         lowbit=2 的（2,6）高一层，各管两个；
    //         lowbit=4 的（4）再高一层，管四个；
    //         lowbit=8 的（8）最高，管八个。

    // (不要求第一遍看能够看懂，推荐先点笔记开头的视频链接看视频方便直观理解)
}

void add(int i, int v) {
    while (i <= n) {
        bit[i] += v;
        i += lowbit(i);
    }
}
// 【树状数组·更新】add(i, v):
// 对下标 i 做单点更新，并沿 i += lowbit(i) 向上走，更新所有覆盖 i 的节点，使各节点维护的区间和增加 v

int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= lowbit(i);
    }
    return s;
}
// 【树状数组·查找】sum(i)：查询前缀和
// 注意：它并非直接求原数组的前 i 项和
// 而是求排名在 1~i 之间的数出现的总次数（即沿着 lowbit 路径往回跳，累加 bit 的值。

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);
    // resize 可以给可变数组扩容
    // 注意：可变数组并非能无限制地随意塞数据，底层空间是固定的
    // 装满了就必须先 resize 申请更大的内存，才能继续往里加
    
    // 对于vector数组用 push_back 不需要提前 resize。
    // 想用 v[5] = 100 直接下标赋值，必须先 resize(6)，否则越界
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    n = b.size();               
    bit.assign(n + 1, 0);

    long long ans = 0;
    for (int i = a.size() - 1; i >= 0; i--) {  
        int rank = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        ans += sum(rank - 1);
        add(rank, 1);
    }
    cout << ans;
    return 0;
}