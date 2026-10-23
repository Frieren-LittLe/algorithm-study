#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct  bao{
	int m;
	int v;
	double vBm() const{
		return (double)v / m;
	}
};

bool cmp(const bao& b1, const bao& b2) {
	return b1.vBm() > b2.vBm();
}



int main() {
	int N, T;
	cin >> N >> T;
	vector<bao> Bao(N);

	for (int i = 0;i < N;i++) {
		cin >> Bao[i].m >> Bao[i].v;
	}
	sort(Bao.begin(), Bao.end(), cmp);

	double ans = 0;
	for (int i = 0;i < N;i++) {
		if (T >= Bao[i].m) {
			ans += Bao[i].v;
			T -= Bao[i].m;
		}
		else {
			ans += (double)T / Bao[i].m * Bao[i].v;
			break;
		}
	}
	printf("%.2f\n", ans);
	return 0;
}