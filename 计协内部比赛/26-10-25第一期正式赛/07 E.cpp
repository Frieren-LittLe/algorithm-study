#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 这一题我们要输入很多数据，所以要记得写加速代码
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> A(n), B(n), C(n);//类似于int a[],b[],c[];是同时声明三个数组的标准写法
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];
    for (int i = 0; i < n; ++i) cin >> C[i];

    // 我们知道当我们要对比这三个层级的大小时，必须要先枚举一个层级开始对比
    // 而枚举哪个层级更好呢？
    // 答案是中间的那一个，如果从最上端或者是最下端开始的话，时间复杂度为O(n)*O(n)*O(n)=O(n^3)
    // 如果从中间开始的话，时间复杂度为O(n)*(O(n)+*O(n))= O(2n^2)
    // 但是这题n的最大值为10^5，如果我们定好了中间开始穷举的话，计算量依旧为2*10^10,>10^8，超时了

    // 所以我们需要继续对算法进行优化
    // 由于这题有一个数据对一连串数字比大小的情况存在，我们考虑使用二分;
    // 对 A 和 C 进行升序排序,然后用二分，n等于100000，对10^5进行二分，就是log2（10^5）向上取整，等于17
    // 总计算量为（17+17）*10^5 < 4*10^6< 10^8,可以运行

    sort(A.begin(), A.end());
    sort(C.begin(), C.end());

    long long ans = 0;

    // 枚举中间部分 B[j]
    for (int j = 0; j < n; ++j) {
        // lower_bound 找到第一个 >= B[j] 的元素迭代器，减去 begin() 得到严格小于 B[j] 的个数
        long long cnt_A = lower_bound(A.begin(), A.end(), B[j]) - A.begin();

        // upper_bound 找到第一个 > B[j] 的元素迭代器，用 end() 减去它得到严格大于 B[j] 的个数
        long long cnt_C = C.end() - upper_bound(C.begin(), C.end(), B[j]);

        ans += cnt_A * cnt_C;
    }

    cout << ans << "\n";

    return 0;
}