#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a1, b1;
    int a, b;
    int x, y;
    cin >> a1 >> b1;
    cin >> a >> b;
    int a2 = a1 + a, b2 = b1 + b;
    int n, br = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (x > a1 && x < a2 && y > b1 && y < b2)
            ;
        else if (x >= a1 && x <= a2 && y >= b1 && y <= b2)
            br++;
    }
    cout << br << endl;
    return 0;
}
