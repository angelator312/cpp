#include<bits/stdc++.h>
using namespace std;
const int N=1e6+2;
using LL=long long;
bool eratosten[N];

inline int main2()
{
    for(int i=4;i<N;i+=2)
    {
        eratosten[i]=true;
    }
    for(int i=3;i<N;i+=2)
    {
        if(eratosten[i])continue;
        for(LL j=2*i;j<N;j+=i)
        {
            eratosten[j]=true;
        }
    }
    return 1;
}
inline int main3()
{
    for(int i=2;i<N;++i)
    {
        if(eratosten[i])continue;
        for(int j=2*i;j<N;j+=i)
        {
            eratosten[j]=true;
        }
    }
    return 1;
}
int main()
{
    const auto start{chrono::steady_clock::now()};
    //cerr<<1<<endl;
    for(int i=0; i<1000; ++i)
    {
        main2();
    }
    const auto finish{chrono::steady_clock::now()};
    const chrono::duration<double> elapsed_seconds{finish - start};
    cout<<elapsed_seconds.count()<<endl;
    const auto start2{chrono::steady_clock::now()};
    for(int i=0; i<1000; ++i)
    {
        main3();
    }
    const auto finish2{chrono::steady_clock::now()};
    const chrono::duration<double> elapsed_seconds2{finish2 - start2};
    cout<<elapsed_seconds2.count()<<endl;

}
