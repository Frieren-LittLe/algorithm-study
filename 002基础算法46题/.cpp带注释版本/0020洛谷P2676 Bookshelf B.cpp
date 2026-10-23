#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int N, B;
	cin >> N >> B;
	vector<int> h(N);

	for (int i = 0;i < N;i++) {
		cin >> h[i];
	}

	sort(h.begin(), h.end(),greater<int>());

	long long tolH = 0;
	int cnt = 0;

	for (int i = 0;i < N;i++) {
		tolH += h[i];
		cnt++;
		if (tolH >= B) {
			break;
		}
	}
	cout << cnt << endl;
	return 0;
}