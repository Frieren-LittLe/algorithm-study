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
}

void add(int i, int v) {
    while (i <= n) {
        bit[i] += v;
        i += lowbit(i);
    }
}

int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= lowbit(i);
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);
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