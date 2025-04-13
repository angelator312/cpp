#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int a,b,ch[4];
  for (int i = 0; i < 4; i++)
  {
    cin>>a>>b;
    ch[i] = a*1001 + b;
  }
  sort(ch,ch+4);
  for (int i = 3; i >=0; i--)
  {
    cout<<ch[i]/1001<<" "<<ch[i]%1001<<endl;
  }
  
  return 0;
}
