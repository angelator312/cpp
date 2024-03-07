#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define razm(ch)        \
    if (ch == 'A')      \
        swap(a, b);     \
    else if (ch == 'B') \
        swap(b, c);     \
    else                \
        swap(a, c);

// inline char itoc(int a){return (char)(a+'0');}
// inline int ctoi(char a){return (a-'0');}
// bool startEq(char a,int b){return a==(char)(b+'a')||a==(char)(b+'A');}
int main()
{
    int a=1,b=2,c=3;
    char k;
    cin>>k;
    while (k!='.')
    {
        razm(k);
        cin>>k;
    }
    cout<<a<<endl;
    return 0;
}