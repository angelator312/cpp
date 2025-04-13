#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
using LL = long long;
int main()
{
    LL a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == b && c == d)
    {
        cout << "YES" << endl
             << a * c << endl;
    }
    else if (a == c && b == d)
    {
        cout << "YES" << endl
             << a * b << endl;
    }
    else if (a == d && b == c)
    {
        cout << "YES" << endl
             << a * b << endl;
    }
    else
    {
        cout<<"NO\n"<<a+b+c+d<<endl;
    }
    return 0;
}