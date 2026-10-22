#include<iostream>
using namespace std;

struct S {
	int c, m, e;
	//设语文，数学，英语成绩分别为整数c,m,e
	int sum() {
		return c + m + e;
	}//设置一个返回结果为c+m+e的名为sum()的函数
};

int main() {
	int N;
	cin >> N;
	S a[1002];
	//和数组，字符组，字符串组类似，结构体也是可以建立组的
	for (int i = 0; i < N;i++) {
		cin >> a[i].c >> a[i].m >> a[i].e;
	}
	//读取N，将N个学生的各个变量存入结构体组
	int ans = 0;//先初始化旗鼓相当的学生的对数为0
	for (int i = 0;i < N;i++) {
		for (int j = i + 1;j < N;j++) {
			//先挑出第一个数据，从第一个数的后面的所有数据中依次拿第二个数进行比较，
			//比完后面所有的数后，将第一个数据更改为其后一位数据
			//这样可以避免重复计数
			if (abs(a[i].c - a[j].c) <= 5 && abs(a[i].m - a[j].m) <= 5 && abs(a[i].e - a[j].e) <= 5) {
				if (abs(a[i].sum() - a[j].sum()) <= 10) {
					//对语文，数学，英语成绩以及总分成绩依次进行判定
					//判定成功ans++
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}