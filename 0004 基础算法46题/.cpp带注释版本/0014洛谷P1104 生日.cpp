#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Stu{

  string name;
  int y;
  int m;
  int d;
  int id;
  // 设置一个结构体将每位同学的数据存下
  };

bool cmp(const Stu&stu1,const Stu&stu2){
   if(stu1.y!= stu2.y)return stu1.y<stu2.y;
   if(stu1.m!= stu2.m)return stu1.m<stu2.m;
   if(stu1.d!= stu2.d)return stu1.d<stu2.d;
   return stu1.id>stu2.id;
   // 制作一个cmp比较函数，
   // 1.若年份不相等，返回年份小的排前面(年份，月份，日期越小的年龄越大）
   // 2.若月份不相等，返回月份小的排前面
   // 3.若日期不相等，返回日期小的排前面
    };

int main(){
  int n;
  cin >> n;
  Stu stu[114];

  for(int i = 0;i < n;i++){
    cin>> stu[i].name >> stu[i].y >> stu[i].m >> stu[i].d;
    stu[i].id = i;
    }
  // 读入
  sort(stu,stu+n,cmp);
  // 排序
  for(int i = 0;i<n;i++){
    cout << stu[i].name <<endl;
}
  // 输出
return 0;
  }