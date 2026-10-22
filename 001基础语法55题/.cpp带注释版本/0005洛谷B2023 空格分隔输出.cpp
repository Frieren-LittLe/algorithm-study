#include <iostream>
#include <iomanip>
//iomanip的全称是输入输出操纵器，作用：控制cout和cin的格式化输出
using namespace std;

int main() {
	char a; //字符型（底层存 ASCII 码整数，本质也是整型）
	int b;  //整型（存整数）
	float c;//单精度浮点型（存小数，精度约 6-7 位）
	double d;//双精度浮点型（存小数，精度约 15-16 位）
	//在 C++ 中声明变量时，都要声明其数据类型（type）
	//在C＋＋中不同数据类型所需求的内存空间是不同的，区分数据类型是为了更好分配计算机内存，减少代码占用的性能
	//电脑中的内存指的是Dram，人们口中常见的"内存"指的是SSD，一时半会讲不清，不懂请去自行搜索科普视频
	cin >> a >> b >> c >> d;

	cout << fixed << setprecision(6);
	//setprecison来自iomaip，意思是输出小数到多少位，不加fixed时只会输出到有效数字
	//fixed来自iomanip，作用是固定小数点位置，注意fixed，会一直生效直到你输入cout.unsetf(ios::fixed)取消
	cout << a << " " << b << " " << c << " " << d << endl;
	//与C不同，C++输出空格的方式是cout << "文本内容";时，双引号内部加上空格就行了
	return 0;
}