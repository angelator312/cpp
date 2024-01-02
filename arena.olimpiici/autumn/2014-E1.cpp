#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
void next_day(int &d, int &m, int &g)
{
    int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((g % 4 == 0 && g % 100 > 0) || g % 400 == 0)
    {
        months[2] = 29;
    }
    // cout<<d<<endl;
    d++;
    // cout<<d<<endl;
    if (months[m] < d)
    {
        d = 1;
        m++;
        if (m > 12)
        {
            m = 1;
            g++;
        }
    }
}
int main()
{
    int d, m, g, n, k, x, dni;
    cin >> d >> m >> g >> n >> k >> x;
    dni = ((n - k)+((k-x)-1)) / (k - x);
    
    // cout<<dni<<endl;
    if (dni<0)
    {
        dni=0;
    }
    for (int i = 0; i < dni; i++)
    {
        next_day(d, m, g);
    }
    cout << d << " " << m << " " << g << endl;
    // cout <<max(max(a*b+c,a+b*c),max(a*b*c,a+b+c)) << endl;
    return 0;
}