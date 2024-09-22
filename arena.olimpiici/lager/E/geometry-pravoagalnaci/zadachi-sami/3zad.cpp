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
    int x, y,br=0;
    do
    {
        cin>>x>>y;
        if (x > x1 && x < x2 && y > y1 && y < y2)
        {
            br++;
        }
    } while (x + y > 0);
    cout<<br<<endl;
    // cout << P << " " << S << endl;
    return 0;
}
