#include <iostream>
using namespace std;
int main()
{
    int M, N, P, Q, K;
    cin >> M >> N >> P >> Q >> K;
    int Kes = (M + N) - (P + Q);
    if (K == 1)
    {
        cout<< min(P,N)<<endl;
    }
    else if (K == 2)
    {
        cout<< Q-min(M,Q)<<endl;
    }
    else
    {
        cout<< M-min(N,Kes)<<endl;
    }
    return 0;
}