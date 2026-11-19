#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 离散化是算法竞赛和数据处理中非常常用的一种思想
// 核心:把“值很大但个数不多”的数据，映射成“值很小且连续”的编号，从而用数组等结构高效处理
// 基本步骤:排序-去重-映射

// 以下使用 离散化+差分 思维来解(本题也可以使用排序+贪心合并的解法)
// 本题的起火点和熄火点的数值差异极大，不宜用下标表示起火点和熄火点
// 离散化可以使原先的起火点和熄火点的表示方式由大数组的“下标”转为小数组的“数值”
// 差分可以记录边界变化，用于解决"区间重叠覆盖",
// 且可以将O(N)的区间修改(将[l,r)区域全部标记，降维成O(1)的端点标记(只给l，r打标记)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<long long>L(n), R(n);
	// 设一个L数组和R数组，分别收集船头和船尾，注意a,b之间的数值巨大，要开long long
	vector<long long>vals;
	// 用收集所有船头和船尾的真实坐标后填入vals数组排序，初始时乱序

	for (int i = 0;i < n;i++) {
		cin >> L[i] >> R[i];
		vals.push_back(L[i]);
		vals.push_back(R[i]);
	}
	// 排序：让所有坐标从小到大排好
	// vals数组的作用只是提供浓缩后的坐标系字典，所以可以杂糅排序
	sort(vals.begin(), vals.end());
	// 去重：把重复的坐标挤到末尾，并用 erase 删掉废数据
	vals.erase(unique(vals.begin(), vals.end()), vals.end());

	int m = vals.size();
	// .size()可以求得vals数组的元素数量
	vector<int> diff(m, 0);
	// 差分数组
	for (int i = 0;i < n;i++) {
		// 映射：用二分查找 lower_bound，把原本极大的真实坐标，映射成 vals 里的微小数组下标 (0, 1, 2...)
		int u = lower_bound(vals.begin(), vals.end(),L[i]) - vals.begin();
		int v = lower_bound(vals.begin(), vals.end(), R[i]) - vals.begin();
		
		// 差分操作：从下标 u 开始，覆盖厚度 +1；到下标 v 结束，厚度 -1
		diff[u] += 1;
		diff[v] -= 1;
		// diff每碰到一个起火点就+1，每碰到一个熄火点就-1
		// 用cur对diff从0到m遍历，当cur处于0时代表此处无火，当cur > 0时代表此处有火
	}

	long long sum = 0;
	int cur = 0; 
	// 反映当前区域被多少艘船(几层火)覆盖
	// 遍历每一个离散化后由vals分隔的相邻小区间
	for (int i = 0;i < m - 1;i++) {
		// 前缀和累加，算出第i个小区间到底有没有被火烧到
		cur += diff[i];
		// 只要覆该层数大于零，就代表该区域有火，将该区域的长度读入sum
		if (cur > 0) {
			sum += (vals[i + 1] - vals[i]);
			// 因为vals是从小到大排过序的，所以不用担心有重叠区间
		}
	}

	cout << sum << "\n";
	return 0;
}