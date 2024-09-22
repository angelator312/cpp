#include <bits/stdc++.h>
using namespace std;
using LL = long long;
// inline char itoc(int a){return (char)(a+'0');}
// inline int ctoi(char a){return (a-'0');}
bool startEq(char a,int b){return a==(char)(b+'a')||a==(char)(b+'A');}
int main()
{
    int n,m,daL=0;
    cin>>n>>m;
    char a[83];
    for (int i = 0;cin.good(); i++)
    {
        cin.getline(a,82);
        if (a[0]<'A' || a[0]>'z')
        {
            continue;
        }
        
        bool da=startEq(a[0],n-1);
        // cout<<a[0]<<a[1]<<endl;
        if(da && m>0 && daL==0)daL=i;
        else m-=1;
    }
    if (daL)
    {
        cout << "win " <<daL<< endl;
    }else
        cout <<"lose" << endl;
    

    return 0;
}