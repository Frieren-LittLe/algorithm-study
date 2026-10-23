#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Song {
    int id;
    long long Thap;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<long long> sumhap(n + 1, 0);//用于存某首歌总hap值
    vector<int> Zhap(n + 1, 0);//用于存某首歌对Z的的hap值

    for (int i = 1;i <= a;i++) {
        for (int j = 1;j <= n;j++) {
            int h;
            cin >> h;
            sumhap[j] += h;
            if (i == b) Zhap[j] = h;
        }
    }
    
    int fav = 1;
    for (int j = 2;j <= n;j++) {
        if (Zhap[j] > Zhap[fav]) {
            fav = j;
        }
    }
    vector<Song> songs(n);
    for (int j = 1;j <= n;j++) songs[j - 1] = { j, sumhap[j] };

    sort(songs.begin(), songs.end(), [](const Song& x, const Song& y) {
        return x.Thap > y.Thap;
        });

    vector<int> list;
    for (int i = 0;i < m;i++)
        list.push_back(songs[i].id);

    auto it = find(list.begin(),list.end(), fav);

    if (it != list.end()) {
        list.erase(it);
        list.insert(list.begin(), fav);
    }
    else {
        list.pop_back();
        list.push_back(fav);
    }
    for (int i = 0;i < m;i++) {
        if (i)cout << ' ';
        cout << list[i];
    }
    cout << '\n';
    return 0;
}