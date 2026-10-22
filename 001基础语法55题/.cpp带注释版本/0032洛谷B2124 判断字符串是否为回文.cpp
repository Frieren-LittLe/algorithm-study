#include<iostream>
#include<cstring>
//<cstring> 是 C++ 中用于处理 C 风格字符串（字符数组）的头文件，提供了大量字符串操作函数
using namespace std;

int main() {
	char s[100];
	cin >> s;
	int len = strlen(s);
	//strlen源自于头文件cstring，作用是获取字符串长度（不含 '\0'）
	int left = 0;
	int right = len - 1;
	//虽然这个字符组到时会装进len个数，但是由于组类型的都是底标从0起开始计数的，最右端的底标写个len-1
	bool isPalindrome = true;
	//bool的固定赋值用法，先默认存在isPalindrome，且为true
	//ture和false的本质是1和0，用1和0替代true和false，程序逻辑不变
	//赋值的数本质上只能有0和非0，令其等于2，3，4，也和1一样被视为true
	while (left < right) {
		if (s[left] != s[right]) {
			isPalindrome = false;
			break;
		}
		left++;
		right--;
	}
	if (isPalindrome) {
		//if (isPalindrome) 的默认判断就是if(isPalindrome = true)
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	return 0;
}