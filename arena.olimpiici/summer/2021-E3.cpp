#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int P = 3e3;
const int K = 3e4; // max chislo

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int h, m, s, br = 0;
        int h2, m2, s2;
        char a;
        bool mas[7]{};

        cin >> h2 >> a >> m2 >> a >> s2;
        cin >> h >> a >> m >> a >> s;

        if (h2 == h)
        {
            if (m == m2)
            {
                int ms[7]{};
                ms[h2 / 10]++;
                ms[h2 % 10]++;
                ms[m2 / 10]++;
                ms[m2 % 10]++;
                ms[s2 / 10]++;
                ms[s2 % 10]++;
                if (ms[0])
                {
                    cout << 0 << " ";
                    continue;
                }
                else if (ms[1] + ms[2] + ms[3] + ms[4] + ms[5] + ms[6] > 6)
                {
                    cout << 0 << " ";
                    continue;
                }
                else
                {
                    for (int j = 0; j < n; j++)
                    {
                        /* code */
                    }
                }
            }
        }

        if (h / 10 > 0 && h % 10 > 0 && m > 11)
        {
            mas[0] = 1;
            mas[h / 10] = 1;
            mas[h % 10] = 1;
            for (int j = m / 10; j < 6; j++)
            {
                if (mas[j])
                    continue;
                if (j * 10 < m)
                    continue;
                mas[j] = 1;
                for (int k = 1; k < 7; k++)
                {
                    if (mas[k] || (j * 10 + k) < m)
                        continue;
                    cout << j << " " << k << endl;
                    br += 2;
                }
                mas[j] = 0;
            }
        }
        h++;
        cout << br << endl;

        for (; h < h2; h++)
        {
            if (h / 10 == 0)
            {
                h = 10;
                continue;
            }
            if (h % 10 == 0)
                continue;

            br += 18;
        }

        // if (h / 10 > 0 && h % 10 > 0)
        //     {
        //         mas[0] = 1;
        //         mas[h / 10] = 1;
        //         mas[h % 10] = 1;
        //         for (int j = 1; j < 7; j++)
        //         {
        //             if (mas[j])
        //                 continue;
        //             mas[j] = 1;
        //             for (int k = 1; k < 7; k++)
        //             {
        //                 if (mas[k])
        //                     continue;
        //                 if ()
        //                     br += 2;
        //             }
        //             mas[j] = 0;
        //         }
        //     }
        //
    }

    return 0;
}