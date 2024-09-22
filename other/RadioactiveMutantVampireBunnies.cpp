#include <bits/stdc++.h>
#if 1
#define p(a) cout << a << endl
#else
#define p(a)
#endif
using namespace std;
// using LL=long long;

struct Index
{
    int x;
    int y;
};

bool inMapOfGame(Index a, int n, int m)
{
    if (a.x >= m || a.y >= n)
        return false;
    else if (a.x < 0 || a.y < 0)
        return false;
    return true;
}
bool inMapOfGame(int x, int y, int n, int m)
{
    if (x >= m || y >= n)
        return false;
    else if (x < 0 || y < 0)
        return false;
    return true;
}

int main()
{
    int n, m;
    vector<Index> bunnies;
    bool mapOfGame[n][m]{};
    Index player;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char a;
            cin >> a;
            if (a == 'P')
            {
                player.x = j;
                player.y = i;
                mapOfGame[i][j]=0;
            }
            else if (a == 'B')
            {
                Index b;

                b.x = j;
                b.y = i;
                cout<<i<<" "<<j<<endl;
                mapOfGame[i][j] = 1;

                bunnies.push_back(b);
            }else
                mapOfGame[i][j]=0;
        }
    }

    while (!mapOfGame[player.y][player.x])
    {
        for (auto e : bunnies)
        {
            int x = e.x, y = e.y;
            int varianti[] = {1, -1};
            for (int i = 0; i < 2; i++)
            {
                x += varianti[i];
                if (!inMapOfGame(x, y, n, m))
                {
                    x -= varianti[i];
                    continue;
                }
                // Index b;

                // b.x = x;
                // b.y = y;
                // bunnies.insert(bunnies.begin(),b);
                cout<<y<<" "<<x<<endl;
                mapOfGame[y][x] = 1;
                x -= varianti[i];
            }
            for (int i = 0; i < 2; i++)
            {
                y += varianti[i];
                if (!inMapOfGame(x, y, n, m))
                {
                    y -= varianti[i];
                    continue;
                }
                cout<<y<<" "<<x<<endl;
                mapOfGame[y][x] = 1;
                y -= varianti[i];
            }
        }
        char a;
        cin >> a;
        Index oldPlayer;
        oldPlayer.x = player.x;
        oldPlayer.y = player.y;

        if (a == 'U')
            player.y++;
        else if (a == 'D')
            player.y--;
        else if (a == 'R')
            player.x++;
        else if (a == 'R')
            player.x--;
        if (!inMapOfGame(player, n, m))
        {

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (mapOfGame[i][j])
                        cout << 'B';
                    else
                        cout << '.';
                }
                cout << endl;
            }

            cout << "won: " << oldPlayer.y << " " << oldPlayer.x << endl;
            return 0;
        }
    }
    return 0;
}