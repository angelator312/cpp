#include <bits/stdc++.h>
using namespace std;
using LL = long long;
// inline char itoc(int a){return (char)(a+'0');}
// inline int ctoi(char a){return (a-'0');}
// bool startEq(char a,int b){return a==(char)(b+'a')||a==(char)(b+'A');}
int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <=n; i++)
    {
        
        cout<<string(n-i,' ');
        string a="";
        for (int j = i; j >1; j--)
        {
            a+=to_string(j);
        }
        
        cout<<a<<1;
        reverse(a.begin(),a.end());
        cout<<a<<endl;
        
    }
    for (int i = n-1; i >0; i--)
    {
        
        cout<<string(n-i,' ');
        string a="";
        for (int j = i; j >1; j--)
        {
            a+=to_string(j);
        }
        
        cout<<a<<1;
        reverse(a.begin(),a.end());
        cout<<a<<endl;
        
    }
    
    return 0;
}