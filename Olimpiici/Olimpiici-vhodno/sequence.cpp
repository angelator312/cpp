#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >>> n >> k;
    int a, posl = -1;
    int gM=-1,g=0;
    while (cin >> a)
    {
        if (a == posl)
        {
            if (a == 0)
            {
                posl = 0;
                gM=max(gM,g);
            }
            else
            {
                cout << "No\n";
            }
        }
    }
}