#include <bits/stdc++.h>
#include <cmath>
using namespace std;
// const int N;
int teglo(string s, int n)
{
    // s="abcd";
    // cout<<s<<endl;
    // cout<<s[1]<<endl;
    int mxedn = 1, seg = 0;
    char pr = '*', a = s[0], b;
    int curr_max = 1, max_so_far = 1;
    int aCurr_max = 1, aMax_so_far = 1;
    for (int i = 0; i < n; i++)
    {
        int aEI,eI;
        char e = s[i];
        if (e == a)
        {
            eI = 1;
            aEI = -1;
            /* code */
        }
        else
        {
            aEI = 1;
            eI = -1;
        }

        // cout << pr << " " << e << endl;

        if (pr != '*')
        {
            if (pr != e)
            {
                if (e == a)
                {
                    eI = -1;

                    /* code */
                }
                else
                {
                    aEI = -1;
                }
            }
            else
            {
                aEI = 1;
            }
        }

        curr_max = max(curr_max + eI, eI);
        max_so_far = max(curr_max, max_so_far);
        aCurr_max = max(aCurr_max + aEI, aEI);
        aMax_so_far = max(aCurr_max, aMax_so_far);
        cout << max_so_far << "  " << curr_max << endl;
        pr = e;
    }
    return max(max_so_far, aMax_so_far);
}
int main()
{
    int out, n;
    string s;
    cin >> n;
    cin >> s;
    // cout<<s<<endl;
    // cout<<s[1]<<endl;
    out = teglo(s, n);
    cout << out << endl;
}
