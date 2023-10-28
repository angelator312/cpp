//100 t.
#include <iostream>
using namespace std;
int main()
{
    long long a, b, c, max = 0, t = 0;
    cin >> a >> b >> c;
    max = a * b + c;
    t = a * b - c;
    if (t > max)
    {
        max = t;
    }
    t = a + b * c;
    if (t > max)
    {
        max = t;
    }
    t = a - b * c;
    if (t > max)
    {
        max = t;
    }
    t = a + b - c;
    if (t > max)
    {
        max = t;
    }
    t = a - b + c;
    if (t > max)
    {
        max = t;
    }
    // razm a-b b-a
    t = b + a * c;
    if (t > max)
    {
        max = t;
    }
    t = b - a * c;
    if (t > max)
    {
        max = t;
    }
    t = b + a - c;
    if (t > max)
    {
        max = t;
    }
    t = b - a + c;
    if (t > max)

    {
        max = t;
    }
    // razm a-c c-a
    t = b * c - a;
    if (t > max)
    {
        max = t;
    }
    t = c - a * b;
    if (t > max)
    {
        max = t;
    }
    t = c - b + a;
    if (t > max)
    {
        max = t;
    }
    // razm b-c c-b
    t = a * c - b;
    if (t > max)
    {
        max = t;
    }
    t = a + c - b;
    if (t > max)
    {
        max = t;
    }
    
    cout<<max<<endl;
    return 0;
}