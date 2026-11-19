#include<iostream>
#include<algorithm>
#include<map>
#include<climits>
using namespace std;
// P3029和P1638本质上是同一类题，都是「最短包含所有品种的连续区间」问题
// 核心都是排序 + 滑动窗口
// 区别在于:P1638 的“区间长度”是下标差，P3029 的“区间长度”是坐标差
// P1638 中，画展是按顺序排列的，位置就是下标，所以直接滑窗即可
// P3029 中，牛的位置是乱序的，必须先按位置排序，才能保证「连续区间」对应「坐标上连续的一段」，然后滑窗

// 所以这题是一道"排序"+"双指针”类型的模板题
struct Cow {
	int pos;
	int id;
};

bool cmp(const Cow& a, const Cow& b) {
	return a.pos < b.pos;
}
// 制作一个cmp函数，把牛从小到大排序
Cow a[50005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	map<int, int> total; // 用于统计总品种

	// map是一种容器类型，定义在头文件 <map> 中,<int,int>表示:键是 int，值也是 int
	// 当我们用用 [] 访问且键不存在时，map才创建某个键
	// 键相当于下标，但是与常规数组下标的区别在于它可以不连续，且可以不为整数形式
	// 例如map<char,int>把后面的值映射到某一个字符上面
	// 键 = 品种编号，值 = 该品种在窗口内出现的次数
	// 所以题中的map相当于一个一维数组，但是由于未出现的下标不会创建键，会更省内存

	for (int i = 0;i < n;i++) {
		cin >> a[i].pos >> a[i].id;
		total[a[i].id] = 1;
	}

	int kind = total.size(); //不同品种的总数

	// .size()定义在头文件 <map> 中，可以记录map里面键值对的个数，也就是不同键的个数

	sort(a, a + n, cmp);

	map<int, int>cnt;
	// cnt 用于统计当前滑动窗口内，每个品种出现的次数
	int l = 0;
	int covered = 0;	// 记录当前窗口内已经覆盖了多少种不同的品种
	int ans = INT_MAX;	// 答案，初始化为一个很大的值

	for (int r = 0;r < n;r++) {
		cnt[a[r].id]++;

		if (cnt[a[r].id] == 1) {
			covered++;
		}
		// 从左向右遍历，记录各品种奶牛出现的次数
		// 一旦发现当前数组cnt中这个奶牛第一次被标记，则记录当前窗口中已有的不同品种奶牛数目+1
		while (covered == kind) {
			int cost = a[r].pos - a[l].pos;
			// P1638 数的是“格子数”，P3029 算的是“距离”int cost = a[r].pos - a[l].pos不用+1
			if (cost < ans) {
				ans = cost;
			}
			cnt[a[l].id]--;
			if (cnt[a[l].id] == 0) {
				covered--;
			}
			l++;
		}
	// 老套路，通过 "--右端点不断增加 --直至符合题目要求 --替换为更优输出结果 --左端点增加继续遍历
	// --左，右端均到顶，输出最终的结果"的【滑动窗口打擂台】的模板得到最终答案
	}
	cout << ans << endl;
	return 0;
}

// 本题单的本章中的五题都是同向双指针，P7714的形式为快慢双指针，其它四题为滑动窗口