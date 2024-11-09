#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    vector<int> a;
    cin >> n >> q;
    for (int i = 0; i < n; i++) 
    {
        int e;
        cin >> e;
        a.push_back(e);
    }
    for (int i = 0; i < q; i++) {
        int e;
        cin >> e;
        if (e == 1)
            a.pop_back();
        else if (e == 3) 
        {
            int b;
            cin >> b;
            cout << a.at(b - 1) << endl;
        }
        else 
        {
            int b;
            cin >> b;
            a.push_back(b);
        }
    }
    return 0;
}
