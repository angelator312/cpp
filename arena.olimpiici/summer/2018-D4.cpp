#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int board[101]{}; // -2 - Нещастие ; -1 -Късмет ;0-нищо; останалите къде отива от това поле;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    vector<int> zar;
    int a;
    cin >> a;
    while (a > 0)
    {
        zar.push_back(a);
        cin >> a;
    }

    int n, b;
    cin >> n;
    int igrachi[n]{}; // x --- hoda izigrani ; -x  --- hoda izigrani , no shte propuska
    int miastoIgr[n]{};
    // for (int i = 0; i < n; i++)
    //     miastoIgr[i] = 1;

    cin >> a >> b;
    while (a > 0)
    {
        board[a] = b;
        cin >> a >> b;
    }
    cin >> a;
    while (a != 0)
    {
        if (a < 0)
            board[abs(a)] = -2;
        else
            board[a] = -1;
        cin >> a;
    }

    int zarNo = 0;
    while (true)
    {
        // cout<<zarNo<<endl;
        for (int i = 0; i < n; i++)
        {
            if (igrachi[i] < 0)
            {
                igrachi[i] = 0 - igrachi[i];
                // igrachi[i]++;
                continue;
            }

            miastoIgr[i] += zar[zarNo];
            if (miastoIgr[i] > 100)
            {
                miastoIgr[i] -= zar[zarNo];
                igrachi[i]++;
                zarNo++;
                // cout << i << " " << miastoIgr[i] << " zar: " << zar[zarNo - 1] << " hod:" << igrachi[i] << endl;
                continue;
            }

            igrachi[i]++;
            zarNo++;
            b = board[miastoIgr[i]];
            if (b == -2)
                igrachi[i] = 0 - igrachi[i];
            else if (b > 0)
                while (b > 0)
                {
                    miastoIgr[i] = b;
                    b = board[miastoIgr[i]];
                }
            if (miastoIgr[i] == 100)
            {
                cout << i + 1 << " " << igrachi[i] << endl;
                return 0;
            }

            // cout << i << " " << miastoIgr[i] << " zar: " << zar[zarNo - 1] << " hod:" << igrachi[i] << endl;

            if (b == -1)
                i--;
        }
    }

    cout << 0 << endl;
    return 0;
}