#include<iostream> 
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;

struct P {
	double x;
	double y;
	double z;
};
// 设置一个结构体用于存放某一位置初始的x,y,z值
bool cmp(const P& p1, const P& p2) {
	return p1.z < p2.z;
}
// 对其高度进行排序
double dis(const P& p1, const P& p2) {
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
};
// 制作一个运算方程
int main() {
	int N;
	cin >> N;
	
	P p[114514];
	double ans = 0.0;
	
	for (int i = 0;i < N;i++) {
		cin >> p[i].x >> p[i].y >> p[i].z;
	}
	// 读入
	sort(p, p + N, cmp);
	// 排序
	for (int i = 0;i < N-1;i++) {
		ans += dis(p[i], p[i + 1]);
	}
	// 运算
	cout << fixed << setprecision(3) << ans << endl;
	// 输出结果
	return 0;
}