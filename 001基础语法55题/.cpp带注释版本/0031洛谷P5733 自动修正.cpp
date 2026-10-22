#include<iostream>
#include<cctype>
//当题目要求我们对字符串操作时，不一定非要用string，有时候用char字符组会更方便一些
//<cctype> 是 C++ 的字符处理头文件，提供了判断和转换单个字符的函数
using namespace std;
int main() {
	char s[100];
	//建立一个最大能存100个字符的字符组
	cin >> s;
	for (int i = 0;s[i] != '\0';i++) {
		//'\0' 就是「什么都不是的字符」，用来标记字符串的结束位置
		s[i] = toupper(s[i]);
		//toupper源自于cctype，用于转大写，与之相反的有tolower；
	}
	cout << s << endl;
	return 0;
}