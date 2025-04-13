#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
int mx = 0, mn = 30, all = 0;
inline int read(int m[])
{
    for (int i = 0; i < 6; i++)
    {
        cin >> m[i];
        mx = max(mx, m[i]);
        mn = min(mn, m[i]);
        all += m[i];
    }
    if (mx == mn)
        return 6 * mn;
    else
        return all - (mn + mx);
}
int main()
{
    int m[6];
    cout << read(m) << endl;
    return 0;
}