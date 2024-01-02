#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int main()
{
    int a1, a2, a3;
    int b1, b2, b3;
    int L;
    cin >> a1 >> a2 >> a3;
    cin >> b1 >> b2 >> b3 >> L;
    int k3 = L / a3 + min(1, L % a3), k2 = L / a2, k1 = L / a1;
    int br = 1000;
    bool brk = 0;
    for (int i = 0; i <= b1; i++)
    {
        for (int j = 0; j <= b2; j++)
        {
            for (int k = 0; k <= b3; k++)
            {
                if (i == 0 && j == 0 && k == 0)
                    continue;
                if (br == 1)
                {
                    brk = 1;
                    break;
                }

                int brL = i + j + k;
                int dL = i * a1 + j * a2 + k * a3;
                if (dL >= L)
                {
                    // if (i == 6)
                        // cout << "[" << i << "][" << j << "][" << k << "] brL:" << brL << endl;

                    if (brL < br)
                    {
                        br = brL;
                    }

                    // br = min(br, brL);
                }
            }
            if (brk)
            {
                break;
            }
        }
        if (brk)
        {
            break;
        }
    }
    if (br == 1000)
        br = 0;
    cout << br << endl;
    return 0;
}