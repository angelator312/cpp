#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include<cmath>
#define endl "\n"
using namespace std;
using LL=long long;
using pI=pair<int,int>;

unsigned int n, m,x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    unsigned int bit_position=7,mask=1<<bit_position;
    for(int k=0; k<t; ++k)
    {
        cin >>x>> n >> m;
        unsigned int nm=x,mx=x;
        int lg=log2(x);
        if(n+m>8*lg)
        {
            cout<<"0 0\n";
            continue;
        }
        int n2=n,m2=m;
        int sm=n+m;
        for(int i=0;i<sm;++i)
        {
            //if(n>0&&(mx & mask) >> bit_position==0)
            if(n>0&&mx%2==0)
            {
                mx>>=1;
                --n;
            }else if(m>0)
            {
                ++mx;
                mx>>=1;
                --m;
            }
            else if(n>0)
            {
                mx>>=1;
                --n;
            }
        }
        n=n2;
        m=m2;
        for(int i=0;i<sm;++i)
        {
            //if(m>0&&(nm & mask) >> bit_position==0)
            if(m>0&&nm%2==0)
            {
                nm=(nm+1)/2;
                --m;
            }else if(n>0)
            {
                nm>>=1;
                --n;
            }
            else
            {
                nm=(nm+1)/2;
                --m;
            }
        }
        cout<<nm<<" "<<mx<<endl;
    }
    return 0;
}

/*

1
15 1 1
/=4 4

1
19 1 2
/=3 3

1
255 2 1
/=32 32
*/
