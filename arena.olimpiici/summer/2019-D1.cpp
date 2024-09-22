#include <bits/stdc++.h>
using namespace std;

using command = pair<bool, int>; // if HLD - 1, if RLS - 0; x - 'A'

short mutexes[26]; // [0] - 'A' ... ; if mutexes[0] > 0 - Holded by thread [i]

int main()
{
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int threadsEnd[n]{};
    vector<command> a[n];
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        threadsEnd[i] = k;
        for (int j = 0; j < k; j++)
        {
            string e;
            char e2;
            cin >> e >> e2;

            command e3(e == "HLD", e2 - 'A');
            a[i].push_back(e3);
        }
    }
    int threads[n]{};
    // cout << "stoped" << endl;
    while (true)
    {
        int conts = 0;

        for (int i = 0; i < n; i++)
        {
            if (threadsEnd[i] == threads[i])
            {
                conts++;
                continue;
            }
            command e = a[i][threads[i]];
            if (e.first) // HLD
            {
                if (mutexes[e.second])
                {
                    conts++;
                    continue;
                }
                else
                {

                    // cout << i << " " << e.second << endl;

                    mutexes[e.second] = i + 1;
                    threads[i]++;
                }
            }
            else
            {
                mutexes[e.second] = 0;
                threads[i]++;
            }
        }

        if (conts == n)
            break;
    }

    for (int i = 0; i < n; i++)
    {
        if (threadsEnd[i] == threads[i])
        {
            cout << "Thread " << i + 1 << " completes successfully.\n";
        }
        else
        {
            int e = (a[i][threads[i]]).second;
            cout << "Thread " << i + 1 << " waits on command "<<threads[i]+1<<" for mutex "<<(char)('A' + e) <<".\n";

        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (mutexes[i])
        {
            cout << "Mutex " << (char)('A' + i) << " is occupied by thread " << mutexes[i] <<".\n";
        }
    }

    return 0;
}