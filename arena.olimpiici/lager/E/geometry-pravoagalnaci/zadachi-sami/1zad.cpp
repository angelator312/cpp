#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x1 = -1, y1 = -1;
    int x2 = 1, y2 = 1;
    int a1 = -2, b1 = -2;
    int a2 = 2, b2 = 2;
    int x, y;
    cin >> x >> y;
    if (x >= a1 && x <= a2 && y >= b1 && y <= b2)
        if (!(x >= x1 && x <= x2 && y >= y1 && y <= y2))
            cout << "Yes" << endl;
        else
            cout << "No\n";
    else
        cout << "No\n";

    // cout << P << " " << S << endl;
    return 0;
}
