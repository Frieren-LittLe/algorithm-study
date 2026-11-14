#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int s;
int n;

struct Dg {
    int x;//难度
    int y;//奖励
};

bool cmp(Dg dg1, Dg dg2) {
    return dg1.x < dg2.x;
}


int main() {
    cin >> s >> n;
    Dg dg[1005];
    for (int i = 0;i < n;i++) {
        cin >> dg[i].x >> dg[i].y;
    }
    sort(dg, dg + n, cmp);

    for (int i = 0;i < n;i++) {
        if (dg[i].x >= s) {
            cout << "NO" << endl;
            return 0;
        }
        else {
            s += dg[i].y;
        }
    }
    cout << "YES" << endl;
    return 0;
}