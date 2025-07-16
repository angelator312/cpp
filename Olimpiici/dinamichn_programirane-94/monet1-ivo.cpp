#include <bits/stdc++.h>
using namespace std;
int n=0, k=0;
int m[20];
int s[1000001];

inline int moneti(const int&cn=0) {
    if (!cn) {
        return 0;
    }
    if (s[cn]) {
        return s[cn];
    }
    int ans=1000001;
    for (int i=0;i<k;i+=1) {
        if (cn>=m[i]) {
            ans=min(ans, moneti(cn-m[i])+1);
        }
    }
    s[cn]=ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=0;i<k;i+=1) cin>>m[i];
    cout<<moneti(n)<<endl;
    return 0;
}
