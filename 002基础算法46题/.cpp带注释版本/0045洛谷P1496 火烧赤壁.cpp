#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 离散化是算法竞赛和数据处理中非常常用的一种思想，
// 核心：把“值很大但个数不多”的数据，映射成“值很小且连续”的编号，从而用数组等结构高效处理
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<long long, long long>> f(n);
	for (int i = 0;i < n;i++) {
		cin >> f[i].first >> f[i].second;
	}
	sort(f.begin(), f.end());
	// sort原生就完美支持对 pair<int, int> 进行排序
	// 系统会优先比较两个 pair 的 first 值。谁的 first 小，谁就排在前面
	// 如果两个 pair 的 first 完全相等，系统才会去比较它们的 second 值。此时谁的 second 小，谁排在前面
}