#include <bits/stdc++.h>
using namespace std;
using LL = long long;
inline char itoc(int a){return (char)(a+'0');}
inline int ctoi(char a){return (a-'0');}
int main()
{
    char a;
    string s="";
    cin >> a;
    while (a!='!')
    {
        s+=a;
        cin >> a;
    }
    // cout<<s<<endl;
    // reverse(s.begin(),s.end());
    string out(s.size(),' ');
    int p=0;
    for (int i = s.size()-1; i >=0 ;i--)
    {
        int ch=ctoi(s[i]);
        ch*=5;
        out[i]=itoc(ch%10+p);
        // cout<<out[i]<<endl;
        p=ch/10;
    }
    if (p)
    {
        cout <<p<< out << endl;
    }else
        cout << out << endl;
    
    return 0;
}