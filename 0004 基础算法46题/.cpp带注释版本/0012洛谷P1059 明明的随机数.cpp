#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[101];
  for(int i=0;i<n;i++){
    cin >> a[i];
    }
  //将随机数存入a[n]中并对其进行排序
  sort(a,a+n);
  
  int m = unique(a,a+n)-a;
  // unique把相邻的重复元素中多余的移走，(通常被覆盖到后面），
  // 并返回去重后区间末尾的迭代器
  // 即指向第一个"多余"位置；m = unique(a, a + n) - a 即为不重复元素个数
  
  cout << m << endl;
  for(int i=0;i<m;i++){
    cout << a[i];
    if(i<m-1){
      cout << " ";
      }
    }
  return 0;
  
}