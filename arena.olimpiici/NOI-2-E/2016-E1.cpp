#include <bits/stdc++.h>
#define f if(!(a>=0&&b>=0&&c>=0))break;else bombIz++;
using namespace std;
using LL=long long;
int main()
{
    LL a,b,c,bombIz=0;
    cin>>a>>b>>c;
    // cout<<bombIz<<endl;
    bombIz=min(min(a,c),b/2);
    a-=bombIz;
    b-=bombIz*2;
    c-=bombIz;
    bombIz*=4;
    while (1)
    {
    a--;
    f;
    b--;
    f;
    c--;
    f;
    b--;
    f; 
    }

    cout<<bombIz<<endl;
    return 0;
}