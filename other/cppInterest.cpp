#include <bits/stdc++.h>
#if 1
#define p(a) cout<<a<<endl
#else
#define p(a)
#endif
using namespace std;
using LL=long long;
struct Data
{
    int d;
    int y;
    int m;
    void n(){}
    void out()
    {
        
        cout<<d<<" "<<m<<" "<<y<<endl;
    }
};

int main()
{
    Data d1;
    
    cin>>d1.d>>d1.m>>d1.y;
    // cout<<d1.d<<" "<<d1.m<<" "<<d1.y<<endl;
    d1.out();
    return 0;
}