#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Song {
    int id;
    long long Thap;
};//建立一个结构体，将歌曲的编号与其总hap值联系起来

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);//加速函数

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<long long> sumhap(n + 1, 0);//用于存某首歌总hap值
    vector<int> Zhap(n + 1, 0);//用于存某首歌对Z的的hap值

    for (int i = 1;i <= a;i++) {
        for (int j = 1;j <= n;j++) {
            int h;
            cin >> h;
            sumhap[j] += h;//存放好某首歌的总hap
            if (i == b) Zhap[j] = h;//存放某首歌对Z的hap值
        }
    }

    int fav = 1;
    for (int j = 2;j <= n;j++) {
        if (Zhap[j] > Zhap[fav]) {
            fav = j;
        }
    }
    //通过擂台法比较出Z的fav
    vector<Song> songs(n);
    for (int j = 1;j <= n;j++) songs[j - 1] = { j, sumhap[j] };
    //将序号从1到n的歌曲及其hap值，依次存入底标从0到n-1的结构体组之中
    sort(songs.begin(), songs.end(), [](const Song& x, const Song& y) {
        return x.Thap > y.Thap;
        });
        //用lambda比较函数，对songs排序
            vector<int> list;
        for (int i = 0;i < m;i++)
            list.push_back(songs[i].id);
        //讲songs的id存入list中
        auto it = find(list.begin(), list.end(), fav);
        //记录fav的位置为it
        if (it != list.end()) {
            list.erase(it);
            list.insert(list.begin(), fav);
        }//若其不在末尾将其擦除并插入第一位
        else {
            list.pop_back();
            list.push_back(fav);
        }//若其在末尾将末尾原先的歌擦除并将其添入在末尾
        for (int i = 0;i < m;i++) {
            if (i)cout << ' ';//if（i）等价于if（i ！= 0）
            cout << list[i];
        }
        cout << '\n';
        return 0;
}