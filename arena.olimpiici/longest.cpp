#include <iostream>
using namespace std;
bool nt [27]{};
bool isLetter(int k, char c) {
  return !nt[c - 'a'];
}
int main() {
  int k, mL = 0, ind = 0;
  string s;
  cin >> k;
  cin >> s;
  for (int i = 0; i < k; i++) {
    nt[i]=1;
  }
  for (int i = 0; i < s.size(); i++) {
    char sp = '#';
    int l = 0;
    if (!isLetter(k, s[i])) {
      sp = s[i];
    }
    for (int j = i + 1; j < s.size(); j++) {
      l++;
      if (sp != '#') {
        if (!isLetter(k, s[j]) && s[j] != sp) {
          // cout<<s[j]<<sp<<endl;
          if (l > mL) {
            mL = l;
            ind = i;
          }
          break;
        }
      } else if (!isLetter(k, s[j])) {
        sp = s[j];
      }
    }
  }
  cout << mL << endl;
  for (int i = ind; i < ind + mL; i++) {
    cout << s[i];
  }
  if (mL > 0) {
    cout << endl;
  }
  return 0;
}