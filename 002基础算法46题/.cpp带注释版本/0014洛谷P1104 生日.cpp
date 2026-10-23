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

  };

bool cmp(const Stu&stu1,const Stu&stu2){

   if(stu1.y!= stu2.y)return stu1.y<stu2.y;

   if(stu1.m!= stu2.m)return stu1.m<stu2.m;

   if(stu1.d!= stu2.d)return stu1.d<stu2.d;

   return stu1.id>stu2.id;

    };

int main(){

  int n;

  cin >> n;

  Stu stu[114];

  for(int i = 0;i < n;i++){

    cin>> stu[i].name >> stu[i].y >> stu[i].m >> stu[i].d;

    stu[i].id = i;

    }

  sort(stu,stu+n,cmp);

  for(int i = 0;i<n;i++){

    cout << stu[i].name <<endl;

}

return 0;

  }