#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
char mx = 'C', mn = 'A';
int A, B, C, M, o = 0;
inline bool update()
{
    int minA = min(min(A, B), C);
    int maxA = max(max(A, B), C);
    int razl = maxA - minA;
    razl /= 2;
    int a = 0, b = 0;
    if (maxA == C)
    {
        C -= razl;
        a = 3;
    }

    if (maxA == B)
    {
        B -= razl;
        a = 2;
    }
    if (maxA == A)
    {
        A -= razl;
        a = 1;
    }

    if (minA == C)
    {
        C += razl;
        b = 3;
    }
    if (minA == B)
    {
        B += razl;
        b = 2;
    }
    if (minA == A)
    {
        A += razl;
        b = 1;
    }
    M = abs(b - a) * razl;
    // cout << M << " razl:" << razl << endl;
    if (razl==0)
    {
        return 1;
    }

    o += M;
    return 0;
}
int main()
{
    cin >> A >> B >> C;
    for (; A != B || A != C;)
    {
        if (update())
            break;
    }

    cout << o << endl;
    return 0;
}