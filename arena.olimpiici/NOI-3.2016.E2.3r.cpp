#include <iostream>
using namespace std;

int main()
{
    int N,K;
    cin>>N>>K;

    long long S=K+K+N-1;

    for(int i=1;i<=N-2;i++)
        S*=2;
    cout<<S<<endl;
    return 0;
}
