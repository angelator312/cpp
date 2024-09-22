#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a1, b1;
    int a2, b2;
    int x, y;
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    cin >> x >> y;
    if (x > 0 - a1 && x < a1 && y > 0 - b1 && y < b1)
        if (x > 0 - a2 && x < a2 && y > 0 - b2 && y < b2)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    else if (x > 0 - a2 && x < a2 && y > 0 - b2 && y < b2)
        cout << 1 << endl;
    else
        cout << -1 << endl;

    return 0;
}
