// TEST_ZIP: https://arena.olimpiici.com/api/public/problems/1854/zip?download=true
#include <iostream>
#define endl "\n"
#if 0
#define P(a) cout << "[" << __LINE__ << "] : " << a << endl
#else
#define P(a)
#endif
using namespace std;
int main()
{
    int h2, m2, h, m, tH = 0, tM = 0;
    cin >> h >> m;
    P(h);
    P(m);

    if (m >= h)
    {
        int chast = m % 5;
        h2 = m / 5;
        m2 = 12 * chast;
        tM += ((60 - m) + m2) % 60;
        if (h2 <= h)
        {
            tH += (12 - h) + h2;
        }
        else
        {
            P(h2);
            tH += h2 - h;
        }
        if (m + tM >= 60)
        {
            P("m2+tM>=60");
            P(m);
            P(tM);
            tH--;
        }
    }
    else
    {
        int chast = m % 5;
        h2 = m / 5;
        m2 = 12 * chast;
        tM += ((60 - m) + m2) % 60;
        // P(h);
        if (h2 == 0)
        {
            h2 = 12;
        }
        P(h2);
        if (m2 == 60)
        {
            m2 = 0;
        }
        if (h2 < h)
        {
            tH += 11;
            if (tM == 0)
            {
                tH++;
            }
        }
        else
        {
            P(h2);
            tH += h2 - h;
        }

        P(h2);
        if (h == h2 && m < m2)
        {
            P("tH==0");
            tH = 0;
        }
        if (h == h2 && m == m2)
        {
            P("tH==12");
            tH = 12;
        }
    }
    if (h2 == 0)
    {
        h2 = 12;
    }
    if (m2 == 60)
    {
        m2 = 0;
    }

    cout << h2 << " " << m2 << endl;
    cout << tH << " " << tM << endl;
    return 0;
}