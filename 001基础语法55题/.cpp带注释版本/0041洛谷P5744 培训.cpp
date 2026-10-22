#include<iostream>
#include<string>
using namespace std;
//当多个不同类型的变量共同描述“同一个对象”时，可以使用结构体
struct S {
	//struct是结构体的制造工具，struct S{变量}的意思就是制造一个结构体类型S
	string name;
	int age;
	int score;
	//struct 内部只能定义变量类型
	//struct里面的变量不会被自动赋值为0，也不可以在结构体内部被赋值
};

S t(S s) {
	//~S t~的意思为：制定一个函数t，这个函数执行完后返回一个S类型的结构体
    //~(S s)~大S的意思为：执行t函数时，引入一个S类型的结构体进行操作，在该函数中暂且命名该结构体为s
	s.age = s.age + 1;
	//在使用结构体中的变量时，一定要声明结构体，需要使用~ 结构体名称.变量名词 ~的格式，如题中的s.age
	s.score = s.score * 1.2;
	if (s.score > 600) {
		s.score = 600;
	}
	return s;
}
//构建函数可以使用“返回值类型 函数名(引入参数）{}”的格式,有些函数不用加入引入参数，但依然需要小括号
int main() {
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		S s0;//初始化一个叫做s0的结构体变量
		cin >> s0.name >> s0.age >> s0.score;//不断读入s0中的各个数据
		S s1 = t(s0);//使用构建的函数进行运算时，要用函数名(引入参数)的格式
		cout << s1.name << " " << s1.age << " " << s1.score << endl;//经过运算后，依次输出s1中的各个数据
	}
	//其实这题可以不需要令s1=t(s0),直接用t(s0).name也是合法的操作。t(s0) 返回一个 S 结构体，可以直接用 . 访问其成员
	return 0;
}