#include<iostream>
#include<vector>
using namespace std;
// 莽夫解法必然TLE
// 求解本题需要我们将前缀和思维从一维上升到二维
int main() {
	int N, M, C;
	cin >> N >> M >> C;
	vector<vector<int>> mp(M, vector<int>(N));
	
	for (int y = 0;y < N;y++) {
		for (int x = 0;x < M;x++) {
			cin >> mp[x][y];
		}
	}

	vector<vector<long long>> sum(M, vector<long long>(N, 0));
	// 为了防止和会很大，开long long
	int maxX = 0;
	int maxY = 0;
	long long maxSum = -1e9;
	// 设一个极小的值做初始max，让它很容易被取代
	for (int y = 0;y < N;y++) {
		for (int x = 0;x < M;x++) {
			sum[x][y] = mp[x][y];
			// sum[x][y]值：从(0,0)到(x,y)内所有数值的总和
			if (x > 0) sum[x][y] += sum[x - 1][y];
			if (y > 0) sum[x][y] += sum[x][y - 1];
			if (x > 0 && y > 0) sum[x][y] -= sum[x - 1][y - 1];
			// 从左上角向右下角累加前缀和
			// 规则：先令当前sum值为当前地块值
			//		 若该数不在最左端:当前sum值+=其上方一格的sum值
			//       若该数不在最上端:当前sum值+=其左方一格的sum值
			//		 若该数不在最左端也不在最上端:当前sum值-=其左上方的sum值(为了去重)
			//		 注意:这里的三个if产生的效果是要叠加的！！！
			//
			// 可以看[二维前缀和.pdf]形象理解
		}
	}

	for (int y = 0;y <= N - C;y++) {
		for (int x = 0;x <= M - C;x++) {
			int x2 = x + C - 1;
			int y2 = y + C - 1;
			long long total = sum[x2][y2];
			if (x > 0)total -= sum[x - 1][y2];
			if (y > 0)total -= sum[x2][y - 1];
			if (x > 0 && y > 0)total += sum[x - 1][y - 1];
			if (total > maxSum) {
				maxSum = total;
				maxX = x;
				maxY = y;
			}
			// total值:(x,y)到(x2,y2)内所有点的总和
			// maxX，total最大时的x值
			// maxY，total最大时的y值
			// 
			// 规则：初始化(x,y)的tolal为(x2,y2)处的sum值
			//		若 x>0，减去左侧多出的部分 sum[x-1][y2]
			//		若 y>0，减去上方多出的部分 sum[x2][y-1]
			//		若 x>0 且 y>0，左上角被减了两次，加回一次 sum[x-1][y-1]
		}
	}
	cout << maxY + 1 << " " << maxX + 1 << endl;

	return 0;

}