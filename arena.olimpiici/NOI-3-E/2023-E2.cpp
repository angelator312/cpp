#include <bits/stdc++.h>
#include <algorithm>
#define endl "\n"
using namespace std;
using LL = long long;
string MoveToString(int nom, int colour, int start, int end)
{
    string str = "Move ";
    str += to_string(nom + 1) + ": ";
    str += to_string(colour) + " ";
    str += to_string(start + 1) + " ";
    str += to_string(end + 1) + " ";
    return str;
}
bool izp[1000000]{};
int start[1000000]{};
int kray[1000000]{};
vector<string> moves;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int m[n];
    int izpBoq = 0, izpCvet = 0;

    for (int i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        m[i] = e;
        if (e > 0)
            if (!izp[e])
            {
                start[e] = i;
                kray[e] = i;
                izp[e] = 1;

                izpCvet++;
            }
            else
            {
                kray[e] = i;
                // cout << i << endl;
                m[i] = 0;
            }
    }

    for (int i = 0; i < n; i++)
    {
        int e = m[i];
        if (e == 0)
            continue;

        izpBoq += (kray[e] - start[e]) + 1;
        moves.push_back(MoveToString(moves.size(), e, start[e], kray[e]));
    }
    cout << izpCvet << " " << izpBoq << endl;
    for (int i = 0; i < moves.size(); i++)
    {
        cout << moves[i] << endl;
    }

    return 0;
}