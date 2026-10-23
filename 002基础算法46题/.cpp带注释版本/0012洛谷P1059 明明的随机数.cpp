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
  sort(a,a+n);
  int m = unique(a,a+n)-a;
  cout << m << endl;
  for(int i=0;i<m;i++){
    cout << a[i];
    if(i<m-1){
      cout << " ";
      }
    }
  return 0;
  
}