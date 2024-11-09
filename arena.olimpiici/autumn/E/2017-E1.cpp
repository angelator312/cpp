// TEST_ZIP: https://arena.olimpiici.com/api/public/problems/1853/zip?download=true
#include <iostream>
#define endl "\n"
#if 1
#define P(a) cout << a << endl
#else
#define P(a)
#endif
using namespace std;
int main()
{
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    string max = "";
    string t;
    max = a + b + c + d;
    t = a + b + d + c;
    if (max < t)
    {
        max = t;
    }
    t = a + d + b + c;
    if (max < t)
    {
        max = t;
    }
    t = a + d + c + b;
    if (max < t)
    {
        max = t;
    }
    t = a + c + d + b;
    // 5
    if (max < t)
    {
        max = t;
    }
    t = a + c + b + d;
    if (max < t)
    {
        max = t;
    }
    t = b + a + c + d;
    if (max < t)
    {
        max = t;
    }
    t = b + a + d + c;
    if (max < t)
    {
        max = t;
    }
    t = b + c + a + d;
    if (max < t)
    {
        max = t;
    }
    t = b + c + d + a;
    // 10
    if (max < t)

    {
        max = t;
    }
    t = b + d + a + c;
    if (max < t)
    {
        max = t;
    }
    t = b + d + c + a;
    if (max < t)
    {
        max = t;
    }
    t = c + a + b + d;
    if (max < t)
    {
        max = t;
    }
    t = c + a + d + b;
    if (max < t)
    {
        max = t;
    }
    t = c + b + a + d;
    // 15
    if (max < t)
    {
        max = t;
    }
    t = c + b + d + a;
    if (max < t)
    {
        max = t;
    }
    t = c + d + a + b;
    if (max < t)
    {
        max = t;
    }
    t = c + d + b + a;
    if (max < t)
    {
        max = t;
    }
    t = d + a + b + c;
    if (max < t)
    {
        max = t;
    }
    t = d + a + c + b;
    // 20
    if (max < t)
    {
        max = t;
    }
    t = d + b + a + c;
    if (max < t)
    {
        max = t;
    }
    t = d + b + c + a;
    if (max < t)
    {
        max = t;
    }
    t = d + c + a + b;
    if (max < t)
    {
        max = t;
    }
    t = d + c + b + a;
    if (max < t)
    {
        max = t;
    }
    cout << max << endl;
    return 0;
}