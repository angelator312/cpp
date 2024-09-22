#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int A = 6;
char b[A];
inline bool getbit(int bit)
{
    return (b[bit / 8] & (1 << bit % 8)) ? 1 : 0;
}
inline void setbit(int bit, bool v)
{
    if (v)
    {
        b[bit / 8] = b[bit / 8] | (1 << bit % 8);
    }
    else
    {
        b[bit / 8] = b[bit / 8] & (~(1 << bit % 8));
    }
}

void popylni()
{
    // popylvame koreni kvadrati
    setbit(1, 1);

    int nech = 3;
    for (int i = 4; i <= 1369; i += nech)
    {
        setbit(i, 1);
        // cout<<i<<endl;
        nech += 2;
    }
}

bool prov(LL a)
{
    int sum = 0;

    while (a > 0)
    {
        int e = a % 10;
        sum += e * e;
        a /= 10;
    }
    return getbit(sum);
}

int main()
{
    LL b;
    cin >> b;
    if (b < 11)
    {
        cout << b << endl;
        return 0;
    }
    LL br = 10, start = 20;

    if (b >= 100)
    {
        br = 23;
        start = 101;
    }
    if (b >= 1000)
    {
        br = 76;
        start = 1001;
    }
    if (b >= 1000000)
    {
        br = 35179;
        start = 1000001;
    }
    if (b >= 10000000)
    {
        br = 368817;
        start = 10000001;
    }
    if (b >= 100000000)
    {
        br = 3642463;
        start = 100000001;
    }
    if (b >= 1000000000)
    {
        br = 34746544;
        start = 1000000001;
    }
    if (b >= 10000000000)
    {
        br = 319925194;
        start = 10000000001;
    }

    popylni();

    for (LL i = start; i <= b; i++)
        if (prov(i))
            br++;

    cout << br << endl;
    return 0;
}