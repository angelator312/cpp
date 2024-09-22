#include <bits/stdc++.h>
using namespace std;

int main()
{
    float x1, y1;
    float x2, y2;
    int n, x, y,br=0;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin>>n;
    if(y1>y2)
    {
        swap(y1,y2);
    }
    if(x1>x2)
    {
        swap(x1,x2);
    }
    // cout<<x1<<" "<<y1<<endl;
    // cout<<x2<<" "<<y2<<endl;
    do
    {
        cin>>x>>y;
        if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
        {
            br++;
        }
        n--;
    } while (n > 0);
    cout<<br<<endl;
    // cout << P << " " << S << endl;
    return 0;
}
