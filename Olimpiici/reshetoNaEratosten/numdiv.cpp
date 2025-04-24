//#include
#include <iostream>
#include <vector>
//#using
using namespace std;
using LL = long long;
using pI = pair<int, int>;
//#constant variables
const int A = 1e5 + 2;
const int N = 3e6+1;
const int T = 1e5 + 2;
//#arrays
  //##arrays-vectors
    //###vector-int
    vector<int> vPrefix;
  //##arrays-int
  int eratosten[N];//vseki ima s 1 delitel po-malko 
//#variables
int n, t;
int poslEr=0;//poslednoto v vPrefix (nai-goliamoto chislo)
//#functions

void eratostenFill() 
{
  eratosten[0]=0;
  eratosten[1]=0;
  for (int i = 2; i < N; ++i)
  {
    for (int j = i; j < N; j+=i)
    {
      ++eratosten[j];
    }
    if(eratosten[i]>poslEr)
    {
      vPrefix.push_back(i);
      poslEr=eratosten[i];
    }
    
  }
  
}
void init() { eratostenFill(); }
//#main function
int main() {
  init();
  cin >> n;
  if(n==1)
  {
    cout<<1<<endl;
    cout<<1<<endl;
    return 0;
  }
  for (int i = 0; i < vPrefix.size(); i++) {
    if(vPrefix[i]>n)
    {
      cout<<vPrefix[i-1]<<endl;
      cout<<eratosten[vPrefix[i-1]]+1<<endl;
      return 0;
    }
  }

  cout << vPrefix.back() << endl;
  cout << eratosten[vPrefix.back()] + 1 << endl;
}
//#Примери
/*
8
2 4 5 4 4 2 7 4
3
1 8 4
*/
