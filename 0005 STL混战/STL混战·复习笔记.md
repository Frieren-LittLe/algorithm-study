# STL 混战 · 复习笔记

17 题 · stack / queue / priority_queue / set / map / 排序杂题

## 一、栈 stack

后进先出（LIFO）。只在栈顶进出。

`stack<类型> st;`　操作：`push(x)` 压栈、`pop()` 弹栈、`top()` 看栈顶、`empty()` 判空、`size()` 元素个数。

| 题号 | 题目 | 要点 |
|---|---|---|
| 0001 | B3614 【模板】栈 | 四个操作直接实现；空栈 `pop` 输出 `Empty`，`query` 输出 `Anguei!` |
| 0005 | P1449 后缀表达式 | 数字累加成 `num`，遇 `.` 入栈，遇运算符弹两个 |
| 0012 | P1981 表达式求值 | 只有 `+` 和 `*`：`*` 立即与栈顶相乘，`+` 先入栈最后累加 |
| 0013 | CF821C Okabe and Boxes | 花一次代价可重排整栈，排好后等价于空栈 |

0005 的弹出顺序：

```cpp
long long b = st.top(); st.pop();   // 后出现的数
long long a = st.top(); st.pop();   // 先出现的数
if (c == '-') st.push(a - b);       // 减法、除法必须 a 在前
if (c == '/') st.push(a / b);
```

0012 边读边算乘法：

```cpp
while (cin >> op >> num) {
    num %= MOD;
    if (op == '+') st.push(num);
    if (op == '*') {
        int cur = st.top(); st.pop();
        st.push(cur * num % MOD);
    }
}
while (!st.empty()) ans = (ans + st.top()) % MOD, st.pop();
```

要记得：

- `unsigned long long` 不能存负数，输入负数按模 `2^64` 回绕成大正数，`cin` 不报错。
- 后缀表达式里后弹出的才是左操作数，`-` 和 `/` 反了就错。
- 0013 的「重排」是花一次代价把整栈排好，不是交换一次。排好后所有 `remove` 都能顺序弹出，代码里可直接清空。

## 二、队列 queue

先进先出（FIFO）。队尾进，队头出。`push` / `front` / `pop` / `empty` / `size`。

| 题号 | 题目 | 要点 |
|---|---|---|
| 0002 | B3616 【模板】队列 | 四个操作；空队列 `pop` / `front` 输出固定错误串 |
| 0011 | P1996 约瑟夫问题 | 前 `m-1` 个搬到队尾，第 `m` 个输出并弹出 |

约瑟夫用队列模拟环形：

```cpp
while (!q.empty()) {
    for (int i = 1; i < m; i++) { q.push(q.front()); q.pop(); }
    cout << q.front() << " ";
    q.pop();
}
```

要记得：

- `size` 是函数，写 `q.size()`。写成 `q.size` 取的是函数地址，输出 `1`，编译不报错。
- 队列取队头是 `front()`，没有 `top()`。
- 空队列 `pop` 是未定义行为，先判 `empty()`。

## 三、堆 priority_queue

随时取最值。取顶 `O(1)`，插入删除 `O(log n)`。内部不保证有序，不能遍历。

```cpp
priority_queue<int> pq;                                  // 大根堆
priority_queue<int, vector<int>, greater<int>> pq;       // 小根堆
```

三个模板参数是类型、底层容器、比较器，默认 `vector` + `less`。

| 题号 | 题目 | 要点 |
|---|---|---|
| 0003 | P3378 【模板】堆 | `push` / `top` / `pop` |
| 0006 | P1090 合并果子 | 每次取最小的两堆合并，和放回，累加 |

```cpp
while (pq.size() > 1) {
    int a = pq.top(); pq.pop();
    int b = pq.top(); pq.pop();
    sum += a + b;
    pq.push(a + b);
}
```

要记得：

- `greater<int>` 在 `<functional>`。
- 合并果子的累加值会超 `int`，用 `long long`。
- 堆顶是 `top()`，没有 `front()`。

## 四、set

自动去重、自动升序。`insert` / `count` / `find` / `erase` / `lower_bound`。

| 题号 | 题目 | 要点 |
|---|---|---|
| 0004 | P3370 字符串哈希 | 每个串转 `ull` 哈希塞进 `set`，`size()` 就是不同串数 |
| 0016 | P5250 木材仓库 | `lower_bound` 找第一个 `≥ len` 的，与 `prev` 比距离 |
| 0017 | P1978 集合 | 排序后扫，是 `k` 的倍数且 `a[i]/k` 已在集合里就跳过 |

找最接近的值：

```cpp
auto it = s.lower_bound(len);
if (it == s.begin())    cout << *it;
else if (it == s.end()) cout << *prev(it);
else {
    auto pre = prev(it);
    if (len - *pre <= *it - len) cout << *pre;   // 一样近取小的
    else                         cout << *it;
}
```

要记得：

- `lower_bound` 返回迭代器，取值加 `*`；前一个用 `prev(it)`，在 `<iterator>`。
- `count(x)` 返回 0 或 1，可直接当 `bool`。
- `set` 的元素不能原地修改，要 `erase` 后 `insert`。

## 五、map

键值对，按 key 有序，查找 `O(log n)`。

| 题号 | 题目 | 要点 |
|---|---|---|
| 0014 | P1918 保龄球 | 键值反转：瓶子数当 key，位置当 value |
| 0015 | P5266 学籍管理 | `mp[s] = 分` / `find` / `erase` / `size` |

```cpp
map<int, int> mp;
for (int i = 1; i <= n; i++) { int x; cin >> x; mp[x] = i; }
cout << mp[m] << '\n';
```

要记得：

- `mp[x]` 访问不存在的键会建一个默认值 0；判存在用 `mp.find(x) != mp.end()`。
- 键值反转要求 key 不重复。
- key 到 `1e9` 数组开不下。0014 的 n 是 `1e5`，开数组约 3.8G，用 `map` 约 390KB。

## 六、vector + sort

| 题号 | 题目 | 要点 |
|---|---|---|
| 0007 | CF1744A Number Replacement | `n ≤ 50`，双重循环检查同一数字对应的字母是否唯一 |
| 0008 | P1097 统计数字 | 排序后数连续段，最后一段在循环外输出 |
| 0009 | CF1742B Increasing | 排序后有相邻相等则输出 `NO` |
| 0010 | CF1850D Balanced Round | 排序后找最长相邻差 `≤ k` 的段，答案 `n - 最长` |

0008 数段：

```cpp
sort(a.begin(), a.end());
int cnt = 0;                                   // 当前段起点
for (int i = 1; i < n; i++)
    if (a[i] > a[cnt]) {
        cout << a[cnt] << " " << i - cnt << endl;
        cnt = i;
    }
cout << a[cnt] << " " << n - cnt << endl;      // 最后一段
```

要记得：

- 降序：`sort(a, a + n, greater<int>())`。
- 0008 最后一段在循环外，别漏。
- 0010 从下标 1 存、`a[0] = 0` 当哨兵，`a[1] - a[0]` 自然成立，不用特判。

## 七、通用坑

- `size()` 带括号。`q.size` 静默输出 `1`。
- 栈 `top()`，队列 `front()`。
- `pop()` 前判 `empty()`。
- 返回迭代器的函数（`find` / `lower_bound`）要解引用 `*` 才能取值。
- 累加、乘积、坐标差用 `long long`。
- `sort` 左闭右开：`sort(a, a + n)`。

## 八、速查表

| # | 题目 | 容器 | 一句话 |
|---|---|---|---|
| 01 | B3614 【模板】栈 | stack | push/pop/top/size，空栈特判 |
| 02 | B3616 【模板】队列 | queue | 队尾进队头出，`size()` 带括号 |
| 03 | P3378 【模板】堆 | priority_queue | 小根堆三参数 |
| 04 | P3370 字符串哈希 | set | 串转哈希，set 去重计数 |
| 05 | P1449 后缀表达式 | stack | 遇 `.` 入栈，运算符弹两个 |
| 06 | P1090 合并果子 | priority_queue | 每次合并最小两堆 |
| 07 | CF1744A Number Replacement | vector | 双重循环查同数字字母唯一 |
| 08 | P1097 统计数字 | vector + sort | 排序后数连续段 |
| 09 | CF1742B Increasing | vector + sort | 排序后有相邻相等即 NO |
| 10 | CF1850D Balanced Round | vector + sort | 最长相邻差 ≤k 的段 |
| 11 | P1996 约瑟夫问题 | queue | 前 m-1 个搬队尾 |
| 12 | P1981 表达式求值 | stack | `*` 先算，`+` 后加 |
| 13 | CF821C Okabe and Boxes | stack | 重排后等价空栈 |
| 14 | P1918 保龄球 | map | 键值反转 |
| 15 | P5266 学籍管理 | map | 增删改查 |
| 16 | P5250 木材仓库 | set | lower_bound 找最近 |
| 17 | P1978 集合 | set | 排序后按 a[i]/k 去重 |
