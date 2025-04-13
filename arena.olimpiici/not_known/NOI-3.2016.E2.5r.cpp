#include <iostream>
using namespace std;

int main()
{
    int N,K;
    cin>>N>>K;

    long long S=K+K+N-1;
    S=S<<(N-2);
    cout<<S<<endl;
    return 0;
}
