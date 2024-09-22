#include <iostream>
using namespace std;

int main()
{
    int N,K,N2;
    cin>>N>>K;
    long long ch[N];
    N2=N;
    for(int i=0; i<=N2; i++)
    {
        ch[i]=K+i;
    }
    while(N2!=0)
    {
        for(int i=0; i<N2-1; i++)
        {
            ch[i]=ch[i+1]+ch[i];
        }
        N2--;

    }
    cout<<ch[0]<<endl;
    return 0;
}
