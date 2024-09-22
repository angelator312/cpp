#include <bits/stdc++.h>
using namespace std;

int main()
{
    float x1, y1;
    float x2, y2;
    float x, y;
    float a, b;
    cin >> x1 >> y1;
    cin >> a >> b;
    cin >> x >> y;
    x2=x1+a;
    y2=y1+b;
    if (x > x1 && x < x2 && y > y1 && y <= y2)
    {
        cout << "1\n";
    }
    else if ((x >= x1 && x <= x2 )|| (y >= y1 && y <= y2))
        cout << "0\n";
    else 
        cout << "-1\n";
    // cout << P << " " << S << endl;
    return 0;
}
