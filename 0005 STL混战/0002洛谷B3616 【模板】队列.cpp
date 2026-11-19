#include<iostream>
#include<queue>
using namespace std;
// 队列，从队尾进来，队头出去，遵循一个最后进来的最后出去(Last In,Last Out)的特性
int main() {
    int n;
    cin >> n;
    queue<int> q;
    // 声明队列的格式和声明栈的格式一致,队列的大部分格式都和栈一致
    // queue<变量类型> 队列名
    while (n--) {
        int op, x;
        cin >> op;
        if (op == 1) {
            cin >> x;
            q.push(x);
            // "(队列名).push(要添加的元素)"可以将元素添加至队列尾部
            // 注意括号内只能填一个元素
        }
        else if (op == 2) {
            if (q.empty())cout << "ERR_CANNOT_POP" << endl;
            else q.pop();
            // "(队列名).pop()"表示将栈顶的元素弹出，空队列pop是未定义行为
        }
        else if (op == 3) {
            if (q.empty())cout << "ERR_CANNOT_QUERY" << endl;
            else cout << q.front() << endl;
            // "(队列名).front()"表示的是队首的元素
        }
        else if (op == 4) {
            cout << q.size << endl;
            // "(栈名).size()"表示的是当前队列的长度
        }
    }
    return 0;
}