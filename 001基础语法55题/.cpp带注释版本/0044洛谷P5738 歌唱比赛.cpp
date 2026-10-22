#include<iostream>
#include<iomanip>
#include<algorithm>
//这题我们复习一下:<algorithm> 提供了大量通用的、作用于容器（如字符串、数组、向量等）的算法函数
using namespace std;

struct S {
	int scores[25];//结构体内部也是可以建立数组的
	//这里我们建立一个数组来存所有评委的评分(尽管最多可能只有20个评委，但稍微开大一点的数组是好习惯,留点缓冲余量)
	int sum;
	double avg;

	double Domath(int m) {
		//在这句话中，double是返回值的参数类型，Domtah是函数名称，(小括号)内部的是需要引用参数以及该参数的类型
		//int m的意思就是，这个函数需要引入一个int类型的参数，构建函数运算时，暂且叫这个参数m
		sort(scores, scores + m);
		//sort源自于algorithm可以进行排序功能，sort有从小到大排序，从大到小排序，自定义排序三种用法
		//sort(起始地址,结果地址)是默认的小到大排序
		
		//在用sort排序一维数组时，起始地址和终止地址一般都是“数组名+整数参数”的写法
		//整数参数是多少，则表示其在数组中是第几位，其在数组中的底标就是该 整数参数
		//“数组名”和“数组名+1”是等价的，前者是后者的缩写
		//这道题中我们从数组开头排到m，可以直接sort(scores,scores+m)
		 
		//这只是在一维数组的排序写法，不要直接照搬别的情况
		sum = 0;
		for (int i = 1;i < m - 1;i++) {
			sum += scores[i];
		}
		//排序完之后，我们从底标为1的数开始，不断累加后面的数相加到m-2，底标为0和m-1的数不计入内，最小值和最大值自动被忽略了
		avg = (double)sum / (m - 2);
		//算出数据之和后除去数据的个数，就得到平均数了
		return avg;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	double max = 0.0;
	//有数组就用打擂台算法求出最大值。
	for (int i = 0;i < n;i++) {
		S stu;
		for (int j = 0;j < m;j++) {
			cin >> stu.scores[j];
		}
		double cur = stu.Domath(m);
		if (cur > max) {
			max = cur;
		}
	}
	cout << fixed << setprecision(2) << max << endl;
	return 0;
}