#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;
int main()
{
    LL n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        string st, s2;
        cin >> st >> s2;
        int sz=s2.size();
        s2+=st;
        s2 += " "+to_string(sz)+" " + to_string(i);
        s[i] = s2;
    }
    sort(s, s + n);
    string t = s[0];
    int i=t[t.size()-1]-'0';
    int i2=t[t.size()-3]-'0';
    t[t.size()-1]=' ';
    cout << i+1 << endl;
    // cout<<i2<<endl;
    cout << t.substr(0,i2)<< endl;
    return 0;

}