#include <iostream>
using namespace std;
int main() {
  int n, m;
  cin >> n >>m;
  if(n+m==2){
    cout<<1<<endl; 
    cout<<1<<endl;
    return 0;
  }
  if((n+m)%2==0){
    cout<<2<<endl;
    return 0;
  }
  cout<<1<<endl;
  if(n==2|| m==2){
    cout<<max(n,m)<<endl; 
  }else{
    cout<<n+m<<endl;
  }
  return 0;
}