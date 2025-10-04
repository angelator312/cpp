#include "wordle.h"
#include <bits/stdc++.h>
using namespace std;
int queries = 0;
string a;
bool found = 0;
string query(string b) {
    if (queries == 6 || b.size() != 5) return "";
    queries++;
    cout << b << "? ";
    string res;
    cin >> res;
    if(res=="ggggg") found=1;
    return res;
}
int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; i++) cin >> words[i];
    cin >> a;
    solve(words);
    cout << (found?"Word guessed in ":"Word not guessed in ") << queries << " queries!" << endl;
}
