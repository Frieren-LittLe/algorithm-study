#include <iostream>
#include <string>
#include <set>
using namespace std;
// 哈希英文hash，意为"混乱"
// 哈希值就是我们把原来的数据通过某些确定的运算打散、混合后，得到的一个固定长度的新数值
// 所谓字符串哈希就是把字符串变成有数值表示的哈希值
typedef unsigned long long ull;
const ull base = 131; // 常用底数
// 底数是什么意思:
// 字符串哈希把字符串看成是一个P进制数，这里的P就是底数

// 以下为一种常用的字符串哈希方式 || 一下的计算中也用到了该方式
// 将每个字符的ASCII码，按照从右往左的顺序（最右侧为底数^0）
// 依次乘以底数的n次方并累加求和，最后对 2^64 取模（利用自然溢出）

// 为什么131是常用底数
// 1.大于字符集最大值（ASCII 最大约 122），避免进位混同
// 2.是质数，哈希分布更均匀、冲突少
// 3.经实战验证冲突率低，配合自然溢出/大模数几乎不撞
// 4.数值小、乘法快，计算高效

// 定制一个字符串哈希函数:
ull get_hash(const string& s) {
    ull res = 0;    // res,result的缩写
    for (char c : s) {
        res = res * base + c; 
        // 此处用到秦九韶算法，res = res*base + c 层层展开即为：
        // (((c1*base + c2)*base + c3)*base + c4) ... 
        // 等价于：c1*base^(n-1) + c2*base^(n-2) + ... + cn*base^0
        // 每一步只“乘一次底数再加新字符”，将求高次幂转化为 O(n) 的滚动累加

        // unsined long long 本身拥有自然取模的功能，超过2^64的数据会自然%2^64变成能够存入内存中的数据
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    set<ull> st;
    // set(中文:集合)源于头文件<set>，是 C++ STL（标准模板库）中一个非常经典且常用的容器
    // set 是一个“自动去重”且“自动排序(默认升序)”的集合
    // 基础格式为"set<变量类型>集合名" 
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        st.insert(get_hash(s));
        // insert的中文含义为"插入，放下"
        // "集合名.insert(所要插入的值)”可以将某一数据插入集合中
    }
    cout << st.size() << endl;
    // 大多数容器的 容器名.size() 都可以表示该容器存入的元素数量
    return 0;
}