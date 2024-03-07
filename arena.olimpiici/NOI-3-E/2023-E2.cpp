#include <bits/stdc++.h>
#include <algorithm>
#define endl "\n"
using namespace std;
using LL = long long;
string MovetoString(int nom, int colour, int start, int end)
{
    string str = "Move ";
    str += to_string(nom + 1) + ": ";
    str += to_string(colour) + " ";
    str += to_string(start + 1) + " ";
    str += to_string(end + 1) + " ";
    return str;
}
struct Move
{
    int nom;
    int colour;
    int start;
    int end;
    void printMy()
    {
        cout << "Move " << nom + 1 << ": "
             << colour << " "
             << start + 1 << " "
             << end + 1 << endl;
    }
    string toString()
    {
        string str = "Move ";
        str += to_string(nom + 1) + ": ";
        str += to_string(colour) + " ";
        str += to_string(start + 1) + " ";
        str += to_string(end + 1) + " ";
        return str;
    }
};
vector<string> moves;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int m[n];

    for (int i = 0; i < n; i++)
        cin >> m[i];

    int izpBoq = 0, izpCvet = 0;

    for (int i = 0; i < n; i++)
    {
        if (m[i] == 0)
            continue;

        if (m[i - 1] != m[i])
        {
            izpCvet++;
            int posl = i;
            for (int j = i + 1; j < n; j++)
            {
                if (m[j] == m[i])
                {
                    posl = j;
                    m[j] = 0;
                }
            }

            izpBoq += (posl - i) + 1;

            Move m1;
            m1.nom = moves.size();
            m1.colour = m[i];
            m1.start = i;
            m1.end = posl;
            moves.push_back(MovetoString(moves.size(),m[i],i,posl));
        }
    }
    cout << izpCvet << " " << izpBoq << endl;
    for (int i = 0; i < moves.size(); i++)
    {
        cout << moves[i] << endl;
    }

    return 0;
}
/*

*/