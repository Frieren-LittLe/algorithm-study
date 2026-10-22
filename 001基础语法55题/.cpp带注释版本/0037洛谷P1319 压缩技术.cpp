#include<iostream>
using namespace std;
//这题也可以用二维数组写，以下分享的是一份不用二维数组的写法
int main() {
	int N;
	cin >> N;
	int cur = 0;
	//初始化一个整数数值用来表示当前输出的是0还是1，就叫它cur吧
	int cnt = 0;
	//设置初始化一个数值用来判断换行，就叫它cnt吧
	int x;
	//初始化数值x
	while (cin >> x) {
		//不断读取输入的数据，令其为x
		//注意，可以不断读取x的原理是新x会不断覆盖掉旧x，在这个while循环之后的x就只是最新输入进去的x
		for (int i = 0; i < x;i++) {
			cout << cur;
			//输出当前的cur值，一共输出cur个
			cnt++;
			if (cnt % N == 0) {
				//当cnt=N时，令其自动归零，然后输出endl换行
				cout << endl;
			}
		}
		cur = 1 - cur;
		//通过这个公式可以实现cur在0和1之间的相互转化
	}
	return 0;
}