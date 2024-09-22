#include <bits/stdc++.h>
using namespace std;

int main()
{
    float x1, y1;
    float x2, y2;
    float x, y;
    cin >> x >> y;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    if (x > x1 && x < x2 && y > y1 && y <= y2)
    {
        cout << "Yes\n";
    }
    else
        cout << "No\n";
    // cout << P << " " << S << endl;
    return 0;
}
