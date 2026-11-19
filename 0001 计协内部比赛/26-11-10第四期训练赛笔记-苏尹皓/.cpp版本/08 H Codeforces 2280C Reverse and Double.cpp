#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

bool check(int v, const vector<int>& a) {
	int n = a.size();
	vector<int> bad;
	for (int i = 0; i < n;i++) {
		if (abs(a[i] - a[i + 1] > v) {
			bad.push_back(i);
		}
	}
	if(bad.empty())return true;
	if(bad.size() > 2)return false;
	if (bad.size() == 2) {
		int l = bad[0]+1;
		int r = bad[1];
		if(abs(a[l - 1] - 2 * a[r]) > v)return false;
	}

	
}