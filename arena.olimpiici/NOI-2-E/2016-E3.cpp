#include <bits/stdc++.h>
using namespace std;
using LL = long long;
inline LL znaci(LL k){return to_string(k).size();}
int main()
{
    char a, p = 'A';
    LL br = 1,brR=0;
    cin >> a;
    while (a != '.')
    {
        if (a == p)
        {
            br++;
        }
        else
        {
            if (br > 1 && p!='A')
            {
                brR+=br-(znaci(br)+1);
                // cout << br << p;
                br = 1;
            }
        }
        p = a;
        cin >> a;
    }
    if (br > 1)
    {
        brR+=br-(znaci(br)+1);
        // cout << br << p;
        br = 1;
    }

    // cout << endl;
    cout << brR << endl;
    return 0;
}