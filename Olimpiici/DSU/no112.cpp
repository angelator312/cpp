#include <ios>
#include <iostream>

using namespace std;
const int N = 1e3 + 2;

int parent[N];
int Find(int e)
{
    if (parent[e] == e)
        return e;
    return parent[e] = Find(parent[e]);
}
void Union(int e, int e2)
{
    e=Find(e);
    e2=Find(e2);
    if (e == e2)
        return;
    parent[e] = e2;
}
void Init(int biggest_n)
{
    for (int i = 1; i <= biggest_n; ++i)
    {
        parent[i] = i;
    }
}

int n, m,q;

void Read()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    Init(n);
    for(int i=0,e,e2; i<m; ++i) {
        cin>>e>>e2;
        Union(e,e2);
    }
    cin>>q;
    for (int i = 0, t, e, e2; i < q; ++i)
    {
        cin >> t>>e >> e2;
        if (t == 2)
            Union(e, e2);
        else if (t == 1)
            cout << (Find(e) == Find(e2) ? "1" : "0");
    }
}

int main()
{
    Read();
    cout<<endl;
}
