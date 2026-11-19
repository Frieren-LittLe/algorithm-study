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
    // 通过擂台法比较出Z的fav
    
    vector<Song> songs(n);
    for (int j = 1;j <= n;j++) songs[j - 1] = { j, sumhap[j] };
    // 将序号从1到n的歌曲及其hap值，依次存入底标从0到n-1的结构体组之中
    // j被存为id，sumhap[j]被存为Zhap
    sort(songs.begin(), songs.end(), [](const Song& x, const Song& y) {
        return x.Thap > y.Thap;
        });
        // 用lambda比较函数，对songs排序
        // sort的比较格式为(起始点，终止点，函数)
        // lambda的格式为[](参数列表){函数体}
        
        vector<int> list;
        for (int i = 0;i < m;i++)
            list.push_back(songs[i].id);
        // 讲songs的id存入list中
        // push_back是vector的成员函数，可以将数据追加在vector的末尾
        // 格式:数组名.push_back(所要填入的数)

        auto it = find(list.begin(), list.end(), fav);
        // 记录fav的位置为it

        if (it != list.end()) {
            list.erase(it);
            list.insert(list.begin(), fav);
        }
        // erase是vector的成员函数，可以将指定位置的数据从vector中删除，后面的数据自动向前填充
        // 格式:数组名.erase（所要删除的数据）
        
        // insert是vector的成员函数，可以将指定的数据填入指定的位置,原先位置上的数据和其后面的数据自动向后填充
        // 格式:数组名.isnert(所要填入的位置，所要填入的值)

        // 所以这段代码的意思为：若列表中有zyl最喜欢的歌，将其排在数组的第一位
        else {
            list.pop_back();
            list.push_back(fav);
        }
        // pop_back的作用和push_back相反，在英文中push可以理解为塞进去，pop可以理解为突然弹出
        // 所以pop_back的用处是:将vector数组中最后一个数据弹出
       
        // 所以这段代码的意思为:若列表中无zyl最喜欢的歌，将原本列表最后一位弹出，填上zyl最喜欢的歌
        for (int i = 0;i < m;i++) {
            if (i)cout << ' ';
            // if（i）等价于if（i ！= 0）
            cout << list[i];
        }
        cout << '\n';
        return 0;
}