#include<iostream>
#include<vector>

using namespace std;

struct Pixel {
	int rgb[3] = { 0,0,0 };
};

bool isEqual(const Pixel& p1, const Pixel& p2) {//省去拷贝，加快数度
	return p1.rgb[0] == p2.rgb[0] &&
		p1.rgb[1] == p2.rgb[1] &&
		p1.rgb[2] == p2.rgb[2];
	// 若一个彩色像素和另一个彩色像素中三种颜色的值（这个值可以理解成亮度）相同
	// 则判定该两色像素相同
	// 只要该图像中所有相对称的彩色色素相同，则输出"Yes"，否则输出"No"
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, q;
	cin >> n >> m >> q;

	vector<vector<Pixel>> img(n + 1, vector<Pixel>(m + 1));
	// a[][]中，左边的[]装着左边的vector，右边的[]装着右边的vector
	long long diff_count = 0;//用diff计数，若其为0，则判断为轴对称

	for (int k = 0;k < q;k++) {
		int i, j, t, c;
		cin >> i >> j >> t >> c;
		t--;

		int m_j = m - j + 1;
		// m-j+1为与j相对称的数
		if (j != m_j) {// 若该数不位于轴对称的对称轴上
			if (!isEqual(img[i][j], img[i][m_j])) {
				diff_count--;
				// 若两数初始值不相等，diff --保护，修改完发现不相等再diff++
			}
		}

		img[i][j].rgb[t] = (img[i][j].rgb[t] + c) % 256;
		// 开始进行更改
		if (j != m_j) {
			if (!isEqual(img[i][j], img[i][m_j])) {
				diff_count++;
				// 若两数原本相等 diff不变，修改后还是不相等，diff++，此时计入了一个不相等的数据
				// 若两数原本不相等 diff--，修改后还是不相等，diff++，但是因为之前的操作中已经算了这个不相等的数了,此时diff不会为0
				// 若两数原本不相等 diff--，修改后相等，之前计入的数据就消掉一个
			}
		}
		cout << (diff_count == 0 ? "Yes\n" : "No\n");
	}
	return 0;

}