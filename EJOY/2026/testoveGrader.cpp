#include "testove.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
namespace gr {
    vector<vector<pair<int,int>>> v;
}

int main() {
    int n,t,q; cin >> n >> t >> q;
    gr::v = generate(n, t);

    if(gr::v.size() != t) {
        cout << "Wrong tree count!" << endl;
        return 0;
    }

    set<vector<pair<int,int>>> s;
    for(int i = 0; i < t; i++) {
        sort(gr::v[i].begin(), gr::v[i].end());
        s.insert(gr::v[i]);
    }
    if(s.size() != t) {
        cout << "Trees not unique!" << endl;
        return 0;
    }
    cout << "{";
    for(auto tree : gr::v) {
        cout << "{";
        for(auto edge : tree) {
            cout << "{" << edge.first << "," << edge.second << "},";
        }
        cout << "},";
    }
    cout << "}" << endl;
    for(int i = 0; i < q; i++) {
        int type; cin >> type;

        if(type==0) {
            int l,r; cin >> l >> r;
            cout << query(l,r) << endl;
        }
        else if(type==1) {
            int ind; cin >> ind;
            add(ind);
        }
        else if(type==2) {
            int ind; cin >> ind;
            remove(ind);
        }
    }
}
