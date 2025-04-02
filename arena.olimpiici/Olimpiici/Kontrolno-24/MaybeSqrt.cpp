#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#define endl "\n"
using namespace std;
using LL=unsigned long long;
using pI=pair<int,int>;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n;
    cin>>n;
    LL a=sqrt(n);
    if(a*a==n)
    {
        cout<<a<<endl;
    }else cout<<0<<endl;
    return 0;
}
/*
1
5
4 3 3 4 4
*/
