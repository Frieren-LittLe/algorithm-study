#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t; // 读取测试用例数量

    while (t--) {
        int n, r, b;
        cin >> n >> r >> b;

        // b 个 'B' 会把字符串分成 b + 1 段
        int q = r / (b + 1);   // 每一段最少要放几个 'R'
        int rem = r % (b + 1); // 还剩下几个多余的 'R'

        // 循环处理这 b + 1 段
        for (int i = 0; i < b + 1; i++) {
            // 1. 先确定当前这一段要打印几个 'R'
            int count = q;
            if (i < rem) {
                count = count + 1; // 前 rem 段，每段多分 1 个剩下的 'R'
            }

            // 2. 用最基础的循环逐个打印 'R'
            for (int j = 0; j < count; j++) {
                cout << 'R';
            }

            // 3. 在每段后面打印一个 'B' 作隔板（最后一段后面不用打印）
            if (i < b) {
                cout << 'B';
            }
        }

        // 每个测试用例结束后换行
        cout << endl;
    }

    return 0;
}