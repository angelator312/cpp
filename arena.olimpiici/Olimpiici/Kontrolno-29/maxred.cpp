#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
int n = 0, k = 0;
// inline string max(const string &str,
//                   const string &str2) // str.size()==str2.size()
// {
//   return str > str2 ? str : str2;
// }
// inline string delOld(const string &str,
//                      const int &strSize) // str.size()==strSize
// {
//   if (strSize == n - k)
//     return str;
//   string maxStr(strSize - 1, '0');
//   string str2 = "";
//   for (int i = 0; i < strSize; ++i) {
//     maxStr = max(maxStr, str2 + str.substr(i + 1));
//     str2 += str[i];
//   }
//   return delOld(maxStr, strSize - 1);
// }

inline void del(const string &str) {
  stack<char> strSt;
  for (int i = 0; i < n; ++i)
  {
    strSt
  }
  
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string s;
  cin>>n>>k;
  cin >> s;
  del(s.substr(0, n));
  del(s.substr(n, n));
  del(s.substr(2 * n));
  cout<<"\n";
  // cerr << endl;
  // cout << del(s.substr(n, n), n);
  // // cerr << endl;
  // cout << del(s.substr(2 * n, n), n);
}