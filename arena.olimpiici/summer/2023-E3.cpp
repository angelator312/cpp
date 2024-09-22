#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int P = 3e3;
const int K = 3e4; // max chislo

int main()
{
    int x = 0, y = 0, n, br = 1;
    cin >> n;
    bool xB = 0;
    int prodXL = 0, prodXM = 0;
    int prodYL = 0, prodYM = 0;
    for (int i = 0; i < n; i++)
    {
        short a;
        cin >> a;
        if (a == 1)
        {
            if (prodYL > 0)
            {
                prodYM = max(prodYL, prodYM);
                prodYL = 0;
            }
            if (y > x && xB == 0)
            {
                prodXL = 1;
            }
            else
            {

                if (prodXL > 0 && xB == 1)
                {
                    prodXL++;
                    // cout << i << endl;
                }
                else
                    prodXM = max(prodXL, prodXM);
            }
            x++;
            // cout << x<<":"<<y << endl;
            xB = 1;
        }
        else
        {
            if (prodXL > 0)
            {
                prodXM = max(prodXL, prodXM);
                prodXL = 0;
            }

            if (y < x && xB == 1)
            {
                prodYL = 1;
                // cout << i<<endl;
            }
            else if (prodYL > 0 && xB == 0)
            {
                prodYL++;
            }
            else
                prodYM = max(prodYL, prodYM);

            y++;
            xB = 0;
        }
        if (x == y)
            br++;
    }

    prodXM = max(prodXL, prodXM);
    prodYM = max(prodYL, prodYM);

    cout << x << " " << y << endl;
    cout << br << endl;
    cout << max(prodXM, prodYM) << endl;
    return 0;
}