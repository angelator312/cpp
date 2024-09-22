#include <bits/stdc++.h>
using namespace std;
const int W = 1e7;
const int H = 51;
bool televizori[W][H]; // W-x; H-y;

bool inTelevizor(int x, int y)
{
    if (y > H)
        return false;
    if (televizori[x][y])
    {
        // cout << x << " " << y << endl;
        return true;
    }
    return false;
}

void write(int x, int w, int h)
{
    for (int i = 0; i <= w; i++)
    {
        for (int j = 0; j <= h; j++)
        {
            // if(x+i==7)
            //     cout<<x<<endl;
            televizori[x + i][j] = 1;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    int x = 0, br = 0;

    for (int i = 0; i < n; i++)
    {
        int e, e2;
        cin >> e >> e2;

        write(x, e, e2);
        x += e;
    }

    for (int i = 0; i < m; i++)
    {
        int e, e2;
        cin >> e >> e2;
        if (inTelevizor(e, e2))
        {

            br++;
            if (br == 4157)
            {
                cout << e << " " << e2 << endl;
            }
        }
    }
    cout << br << endl;
    return 0;
}