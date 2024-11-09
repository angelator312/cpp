// TEST_ZIP: https://arena.olimpiici.com/api/public/problems/1341/zip?download=true
#include <iostream>
#if 1
#define P(a) cout << a<<" "
#else
#define P(a)
#endif
using namespace std;
int main()
{
    int m = 0, a = 0, b = 0, n, h = 0;
    cin >> n;
    // cout<<n<<endl;
    for (int i = 0; i < n; i++)
    {
        int e1, e2;
        cin >> e1 >> e2;
        h += e1 + e2 / 60;
        m += e2 % 60;
    }
    m = m + h * 60;
    // m -= 180;
    // a++;
    // while (m > 0)
    // {
    //     if (a>0 && m>60)
    //     {
    //         m -= 60;
    //         a--;b++;
    //     }else
    //     {
    //         m -= 180;
    //         a++;
    //     }
    // }
    // cout<<m<<endl;
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
    int b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0;
    int m1 = m, m2 = m, m3 = m, m4 = m, m5 = m;
    // 720
    a1 += (m1 / 720) * 3;
    b1 += m1 / 720;
    m1 -= (m1 / 720) * 720;
    // 240
    a1 += (m1 / 240);
    b1 += m1 / 240;
    m1 -= (m1 / 240) * 240;
    // 180
    a1 += (m1 / 180);
    b1 += m1 / 180;
    m1 -= (m1 / 180) * 180;
    if (m1 > 0)
    {
        a1++;
        m1 = 0;
    }

    // 600
    a2 += (m2 / 600) * 2;
    b2 += m2 / 600;
    m2 -= (m2 / 600) * 600;
    // 600 240
    a2 += (m2 / 240);
    b2 += m2 / 240;
    m2 -= (m2 / 240) * 240;
    // 600 180
    a2 += (m2 / 180);
    b2 += m2 / 180;
    m2 -= (m2 / 180) * 180;
    if (m2 > 0)
    {
        a2++;
        m2 = 0;
    }

    // 320
    a3 += (m3 / 320);
    b3 += m3 / 320;
    m3 -= (m3 / 320) * 320;
    // 240
    a3 += (m3 / 240);
    b3 += m3 / 240;
    m3 -= (m3 / 240) * 240;
    // 180
    a3 += (m3 / 180);
    b3 += m3 / 180;
    m3 -= (m3 / 180) * 180;
    if (m3 > 0)
    {
        a3++;
        m3 = 0;
    }

    // 240
    a4 += (m4 / 240);
    b4 += m4 / 240;
    m4 -= (m4 / 240) * 240;
    if (m4 > 0)
    {
        a4++;
        m4 = 0;
    }
    // 180
    a5 += (m5 / 180);
    b5 += m5 / 180;
    m5 -= (m5 / 180) * 180;
    if (m5 > 0)
    {
        a5++;
        m5 = 0;
    }

    //  240
    // a += (m / 240);
    // b += m / 240;
    // m-=(m/240)*240;
    // // 180
    // a += (m / 180);
    // b += m / 180;
    // m-=(m/180)*180;


    int st1 = a1 * 915 + b1 * 1090;
    int st2 = a2* 915 + b2* 1090;
    int st3 = a3 * 915 + b3* 1090;
    int st4 = a4* 915 + b4 * 1090;
    int st5 = a5* 915 + b5* 1090;
    P(st1);P(st2);P(st3);P(st4);P(st5);cout<<endl;
    int st = min(min(st1,st2),min(min(st3,st5),st4));
    
    string out = to_string(st / 100) + "." + to_string(st % 100);
    cout << out << endl;
    return 0;
}