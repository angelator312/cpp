#include<iostream>
#include <algorithm>
using namespace std;
using LL =long long;
const int N = 1e7+2;
bool eratosten[N];
void eratostenFill()
{
  eratosten[0] = 1;
  eratosten[1] = 1;
  for (int j = 2 * 2; j <= N; j += 2) {
    eratosten[j] = 1;
  }
  for (int i = 3; i < N; i+=2) {
        if(eratosten[i])continue;
        for (int j = i*2; j <= N; j+=i)
        {
            eratosten[j]=1;
        }
    }
}
int main(){
    eratostenFill();
    int n;
    cin >> n;
    for (int i = 2; i < n; ++i)
    {
        if(!eratosten[i])cout << i << " ";
    }
    cout<<endl;
    return 0;
}