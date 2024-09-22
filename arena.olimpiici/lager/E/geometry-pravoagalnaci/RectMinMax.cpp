#include <bits/stdc++.h>
using namespace std;

int main()
{
    float h, a;
    float P = 0, S = 1e7;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        float x1, y1;
        float x2, y2;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        float a = fabs(y1 - y2);
        float b = fabs(x1 - x2);
        S = min(S, a * b);
        P = max(P, 2 * (a + b));
    }

    cout << P << " " << S << endl;
    return 0;
}
