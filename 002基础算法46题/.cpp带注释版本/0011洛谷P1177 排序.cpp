#include<iostream>
#include<algorithm>
using namespace std;

//一个简单的排序题，使我们对排序有一个基础的了解


int main(){
  int n;
  cin >> n;
  int a[114514];
  for(int i=0;i<n;i++){
    cin >> a[i];}
  sort(a,a+n);
  for(int i=0;i<n;i++){
    cout << a[i];
    if(i < n-1){
      cout << " ";}
    }
  return 0;
  }