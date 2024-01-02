#include <iostream>
#include <cmath>
#include <math.h>
#if 0
#define Pd cout << __LINE__ << endl;
#else
#define Pd
#endif
#if 0
#define P(a) cout << a << endl;
#else
#define P(a)
#endif
using namespace std;

int main()
{
    int N, K, razl;
    cin >> N >> K;
    if (N == K)
    {
        cout << N - 1 << endl;
        return 0;
    }
    if (K==2)
    {
        cout<<1<<endl;
        return 0;
    }

    razl = N - K;
    int M = -1, ML = 1, DrL = -1, Dr = -1, b = K - 2;
    Pd;
    
    do
    {
        int a = razl - ML;
        Pd;
        P(a);
        P(b);
        if (a % b > 0)
        {
            Pd;
            ML+=a%b;
            a = razl - ML;
        }
        DrL = a / b;
        if (DrL==ML)
        {
            cout<<b+1<<endl;
            return 0;   
        }
        
        if (DrL > Dr)
        {
            Dr = DrL;
            M = ML;
        }
        Pd;
        // cout<<DrL<<endl;
        ML++;
    } while (DrL > 0);
    if (M > Dr)
    {
        cout << b << endl;
    }
    else if (Dr == M)
    {
        cout << b + 1 << endl;
    }
    else
        cout << 1 << endl;

    // cout<<Dr<<endl;
    return 0;
}