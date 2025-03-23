#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using pI = pair<int, int>;
const int BUKVI = 30; // 26 Lupi pravila
int br[BUKVI];
vector<pI> v[BUKVI];
int vSize = 0;
int main() {
  string s;
  cin >> s;
  int n = s.size();
  for (auto e : s) {
    ++br[e - 'a'];
  }
  for (int i = 0; i < n;) {
    int ptr_r = i;
    while (s[ptr_r] == s[i])
      ++ptr_r;
    int sz = ptr_r - i;
    int d3 = sz / 3;
    if (d3 > 0) {
      if (sz % 2)
        ++d3;
      char z = 'a';
      char ourZ = s[i];
      if (z == ourZ) {
        ++z;
      }
      //   //cerr << i << " " << ptr_r << endl;
      ourZ -= 'a';
      int x = 2;
      int posl = i;
      while (x < sz) {
        // //cerr << z << " " << i + x  << endl;
        s[i + x] = z;
        ++br[z - 'a'];
        --br[ourZ];
        v[ourZ].push_back(make_pair(posl, i + x));
        posl = i + x + 1;
        x += 3;
      }
    } else {
      //cerr << (char)(s[i]) << " " << s[i] - 'a' + 0 << endl;
      v[s[i] - 'a'].push_back(make_pair(i, ptr_r));
      ++vSize;
    }
    i = ptr_r;
  }
  int brZAMAH = 0;
  do {
    brZAMAH=0;
    for (int i = 0; i < BUKVI; i++) {
      int zaMah = br[i] - n / 2;
      //   //cerr << zaMah << endl;
      if (zaMah > 0) {
        ++brZAMAH;
        char z = 'a';
        if (i == 0)
          ++z;
        int zI=z-'a';
        int puti = 0;
        for (auto e : v[i]) {
          for (int j = e.first; j < e.second && zaMah > 0; ++j) {
            if (puti == 2) {
              puti = 0;
              v[zI].push_back(make_pair(i-2,i));
            } else {
              s[j] = z;
              --zaMah;
              --br[i];
              ++br[zI];
            }
          }
        }
      }
    }
    ////cerr<<brZAMAH<<endl;
  } while (brZAMAH>0);

  cout << s << endl;
  return 0;
}