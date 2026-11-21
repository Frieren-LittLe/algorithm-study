#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
// 本题要求我们求ans表示最大的k-集合的大小
// 为了让选出的数最多，贪心地优先选最小的(即选第1，3，5......个)，就能保证每条长度为L的链都取到理论最大值[L/2]
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	long long k;
	cin >> n >> k;
	vector<long long> a(n);
	for (int i = 0; i < n;i++)




}