#include<iostream>
using namespace std;
int a[1000007];
int main() {
    int n;
    int max = 0;
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }

    for (int i = 0;i < n - 1;i++) {
        int ans = 1;
        int j = i + 1;
        while ((a[j] > a[i]) && i < (n - 1)) {
            ans++;
            i = j;
            j = j + 1;
        }
        if (ans > max) {
            max = ans;
        }
    }
    cout << max << endl;
    return 0;
}