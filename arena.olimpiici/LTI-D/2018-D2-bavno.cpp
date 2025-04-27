#include <iostream>
#include <cmath>
#include <map>
using namespace std;
using LL = long long;
using pB = pair<bool, int>;

inline pB divisors(LL num2)
{
    int e = 0, br = 0, total;
    while (num2 % 2 == 0)
    {
        ++e;
        num2 /= 2;
    }
    if (e > 0)
        ++br;
    total = e + 1;
    for (int i = 3; (LL)i * i <= num2; i += 2)
    {
        e = 0;
        while (num2 % i == 0)
        {
            e++;
            num2 /= i;
        }
        if (e > 0)
        {
            total = e + 1;
            ++br;
        }
    }
    if (num2 > 1)
    {
        ++br;
        total = 1;
    }

    // cout<<"n "<<num<<" "<<total<<" n";
    return {br == 1, total};
}
inline bool isProsto(const LL &num)
{
    if (num % 2 == 0)
        return false;
    int i = 3;
    while (i * i <= num)
    {
        if (num % i == 0)
            return false;
        i += 2;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL a, b;
    cin >> a;
    cin >> b;
    int br = 0;
    int i = sqrt(a);
    if (i * i < a)
        ++i;
    if (i == 1)
        ++i;
    // LL plus = 2 * i + 1, kvadr = i * i;
    for (; i * i <= b; ++i)
    {
        pB c = divisors(i);
        // if (i == 16)
        //     cerr << 16 << ":" << c.second << endl;
        if (c.first && isProsto((c.second - 1) * 2 + 1))
        {
            ++br;
            // cerr << i << "\n";
        }
    }

    cout << br << endl;
    return 0;
}