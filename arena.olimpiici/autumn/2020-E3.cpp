// TEST_ZIP: https://arena.olimpiici.com/api/public/problems/1341/zip?download=true
#include <iostream>
#if 1
#define P(a) cout << a << " "
#else
#define P(a)
#endif
using namespace std;
int main()
{
    int h, m, dh, dm, c, oh, om;
    cin >> h >> m >> dh >> dm >> c;
    om = (m + dm);
    oh = (h + dh + om / 60) % 12;
    om %= 60;
    if (c == 1)
    {
        cout << oh << " " << om << endl;
    }
    else
    {
        if (om % 12)
        {
            cout <<(om / 12 + oh * 5)%60 << " " << ((om / 12 + oh * 5)+1)%60 << endl;
            
        }else
        {
            cout << "@ " << om / 12 + oh * 5 << endl;
        }
    }
}