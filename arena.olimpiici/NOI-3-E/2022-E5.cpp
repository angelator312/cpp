#include <iostream>
using namespace std;
using LL = long long;
const int N = 5e6;
LL dotuk[N];
int main()
{
    LL n, w;
    cin >> n >> w;
    LL minL = N + 2, localL = 0;
    for (LL i = 0; i < n; i++)
    {
        LL e;
        cin >> e;
        if (e > w)
        {
            cout << 1 << endl;
            return 0;
        }
        if (i == 0)
            dotuk[i] = e;
        else
        {
            dotuk[i] = dotuk[i - 1] + e;
            // cout<<dotuk[i]<<endl;
            if (dotuk[i] > w)
            {
                minL = min(minL, i + 1);
                int dot = dotuk[i] - dotuk[0];
                int dr = 1;
                localL = i + 1;
                while (dot > w)
                {
                    localL--;
                    // cout<<dot<<" length:"<<localL<<endl;
                    minL = min(minL, localL);
                    dot = dotuk[i] - dotuk[dr];
                    dr++;
                }
            }
        }
    }
    if (dotuk[n - 1] <= w || minL == N + 2)
    {
        cout << 0 << endl;
    }
    else
        cout << minL << endl;
    return 0;
}