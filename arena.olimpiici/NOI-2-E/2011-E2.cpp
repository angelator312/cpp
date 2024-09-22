#include <bits/stdc++.h>
using namespace std;
using LL = long long;
// inline char itoc(int a){return (char)(a+'0');}
// inline int ctoi(char a){return (a-'0');}
string kap(LL a,int n)
{
    string aS=to_string(a);
    int nL=aS.size();
    if (nL-n==0)
    {
        return "0";
    }
    return aS.substr(0,nL-n);
}
string rikar(LL a,int n)
{
    string aS=to_string(a);
    return aS.substr(aS.size()-n,n);
}
int main()
{
    int n,br=0;
    string a;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        LL aL2 = stoi(a);
        LL aL =aL2;
        aL *= aL;
        // cout<<aL<<endl;
        string kapa = kap(aL,a.size());
        string ra = rikar(aL,a.size());
        // cout<<kapa<<" "<<ra<<endl;
        br += ((stoi(kapa) + stoi(ra)) == aL2);
    }

    cout << br << endl;

    return 0;
}