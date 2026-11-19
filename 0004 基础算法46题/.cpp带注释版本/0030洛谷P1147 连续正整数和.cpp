#include<iostream>
using namespace std;

int main() {
	int m;
	cin >> m;

	int l = 1, r = 1;
	int sum = 0;
	// 设一个左端点和右端点，先初始化这两个数据为1
	// 当区间[l,r]的所有整数的总和小于所求的M时，右端点增加一格
	// 当区间[l,r]的所有整数的总和大于所求的M时，左端点增加一格
	// 当区间[l,r]的所有整数的总和等于所求的M时，输出此时的l和r
	// 若此时并未输出完所有的结果，将左端点增加一格，继续判断

	while (l <= m / 2) {
		// 每个l都有一个对应的r
		// 并且l的取值范围不可能大于m/2
		// 所以为使输出完所有可能的结果，持续循环的条件设为l <= m/2
		if (sum < m) {
			sum += r;
			r++;
		}
		else if (sum > m) {
			sum -= l;
			l++;
		}
		else {
			cout << l << " " << r - 1 << endl;
			// 输出r-1是为了抵消上一次if(sum < m)时末尾的r++
			sum -= l;
			l++;
		}
	}
	return 0;
}