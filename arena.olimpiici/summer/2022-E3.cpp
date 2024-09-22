#include <iostream>
using namespace std;
using ul = long long;
int main()
{
    ul n, d, m1, m2, m3;
    cin >> n >> m1 >> m2 >> m3 >> d;
    m1--;
    m2--;
    m3--;
    bool t[n]{};
    int br = 3;
    t[m1] = 1;
    t[m2] = 1;
    t[m3] = 1;
    for (ul i = 1; i <= d; i++)
    {
        if (m1 + i < n)
        {
            if (!t[m1 + i])
            {
                br++;
                t[m1 + i] = 1;
            }
        }
        if (m1 - i >= 0)
            if (!t[m1 - i])
            {
                br++;
                t[m1 - i] = 1;
            }
        if (m2 + i < n)
            if (!t[m2 + i])
            {
                // cout<<m2+i<<endl;
                br++;
                t[m2 + i] = 1;
            }
        if (m2 - i >= 0)
            if (!t[m2 - i])
            {
                // cout<<m2-i<<endl;
                br++;
                t[m2 - i] = 1;
            }
        if (m3 + i < n)
            if (!t[m3 + i])
            {
                br++;
                t[m3 + i] = 1;
            }
        if (m3 - i >= 0)
            if (!t[m3 - i])
            {
                br++;
                t[m3 - i] = 1;
            }
    }
    // cout<<endl;
    cout <<  n-br << endl;
    return 0;
}
