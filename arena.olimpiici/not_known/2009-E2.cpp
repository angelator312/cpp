#include <algorithm>
#include <iostream>

using namespace std;
using LL = long long;
int podmen(string &s)
{
    string s2="";
    int n = s.size(),out=0;
    for (int i = 0; i < n; i++)
    {
        if(i%2==0)
        {
            s2+=s[i];
            // cout<<s2<<endl;
        }
        if ((s[i]-'0')%2)
        {
            out++;
        }
        
    }
    // cout << s2 << endl;
    // cout <<"out: "<< out << endl;
    s=s2;
    return out;
}

int main() {
  string s,out,rev;
  cin>>s;
  out=s;
  int n=podmen(out);
  int o = stoi(out);
  rev=out;
  reverse(rev.begin(),rev.end());
  o -= stoi(rev);
  o =abs(o);
  cout<<n<<o<<endl;
  return 0;
}
