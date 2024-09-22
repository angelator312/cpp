#include <bits/stdc++.h>
using namespace std;

int main()
{
    float x1, y1;
    float x2, y2;
    float a, b;
    float a1, b1;
    float a2, b2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    a = fabs(a1 - x2);
    b = fabs(b1 - y2);
    int x, y,br=0;
    do
    {
        cin>>x>>y;
        if (x >= a1 && x <= x2 && y >= b1 && y <= y2)
        {
            br++;
        }
    } while (x + y > 0);
    cout<<br<<endl;
    cout << a * b << endl;
    // cout << P << " " << S << endl;
    return 0;
}
