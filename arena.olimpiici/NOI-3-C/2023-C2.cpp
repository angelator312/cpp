#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct com
{
    bool type; // 0-rand,1-set
    int k;
    vector<int> vars;
};
vector<com> v;
int lastId = 0;
map<string, int> idS;
int main()
{
    int n;
    cin >> n;
    string s;
    com a;
    for (int i = 0, k; i < n; ++i)
    {
        cin >> s >> k;
        a.type = (s == "set");
        a.k = k;
        a.vars.clear(), a.vars.shrink_to_fit();
        for (int i = 0; i < k; ++i)
        {
            cin >> s;
            int id = idS[s];
            if (id == 0)
                idS[s] = ++lastId, id = lastId;
            a.vars.push_back(id);
        }
        v.push_back(a);
    }
    int i = 1;
    for (auto [t, k, vars] : v)
    {
        cerr << "[" << i << "]" << t << ":";
        for (auto e : vars)
            cerr << e << " ";
        cerr << endl;
        i++;
    }
}