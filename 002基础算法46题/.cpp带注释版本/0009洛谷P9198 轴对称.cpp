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
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, q;
	cin >> n >> m >> q;

	vector<vector<Pixel>> img(n + 1, vector<Pixel>(m + 1));

	long long diff_count = 0;

	for (int k = 0;k < q;k++) {
		int i, j, t, c;
		cin >> i >> j >> t >> c;
		t--;

		int m_j = m - j + 1;

		if (j != m_j) {
			if (!isEqual(img[i][j], img[i][m_j])) {
				diff_count--;
			}
		}

		img[i][j].rgb[t] = (img[i][j].rgb[t] + c) % 256;

		if (j != m_j) {
			if (!isEqual(img[i][j], img[i][m_j])) {
				diff_count++;
			}
		}
		cout << (diff_count == 0 ? "Yes\n" : "No\n");
	}
	return 0;

}