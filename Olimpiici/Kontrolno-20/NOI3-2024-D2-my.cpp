#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
using LL = long long;
const int N = 1e4 + 1;
char matrix[N][N];
bool plusJ[N];
//-----------------------------------------------------
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string all;
  getline(cin, all);
  int allSize = all.size();
  int ptr_now = 0, d = 0, s = 0, i = 0, j = 4;
  while (all[ptr_now] >= '0' && all[ptr_now] <= '9') {
    d *= 10;
    d += ('9' - all[ptr_now]);
    ++ptr_now;
  }
  //   cerr << d << endl;
  int firstB = ptr_now;
  while (all[ptr_now] < '0' || all[ptr_now] > '9') {
    ++ptr_now;
  }

  int firstCifra = ptr_now;
  while (ptr_now < allSize && all[ptr_now] >= '0' && all[ptr_now] <= '9') {
    s *= 10;
    s += ('9' - all[ptr_now]);
    ++ptr_now;
  }
  firstCifra -= firstB;
  all = all.substr(firstB, firstCifra);
  cerr << firstCifra << endl;
  int x = 0, y = 0;
  x = (firstCifra - 1) / d;
  x = (firstCifra - 1) % d;

  for (int i = 0; i <= x; i++) {
    int e = (d - s + i) % d;
    plusJ[e] = 1;
    cerr << e << endl;
  }  

  cerr << "i ? j 543210\n";

  cerr << i << " " << plusJ[i] << " ";
  if (plusJ[0]) {
    j = y;
  } else {
    matrix[i][5] = '*';
    cerr << "*";
  }
  for (ptr_now = 0; ptr_now < firstCifra; ++ptr_now) {
    // cerr << ptr_now << " " << all[ptr_now] << endl;
    matrix[i][j] = all[ptr_now];
    // cerr << j;
    cerr << all[ptr_now];
    --j;
    if (j == -1) {
      cerr << endl;
      ++i;
      if (plusJ[i]) {
          j = y;
        } else {
            matrix[i][y-1] = '*';
            cerr << matrix[i][y-1];
            j = y - 1;
        }
        cerr << i << " " <<j<<" ";
    }
  }
  //   cerr << endl << s << endl;
  //   i = 0;
  //   j = 0;
  //   for (ptr_now = 0; ptr_now < firstCifra + 10; ++ptr_now) {
  //     cerr << matrix[i][j] << " ";
  //     ++j;
  //     if (j == d) {
  //       cerr << endl;
  //       j = 0;
  //       ++i;
  //     }
  //   }
  // cerr << endl;
  if (s == 0) {
    s = d + 1;
  }
  i = d - s + 1;
  j = 0;
  for (ptr_now = firstB; ptr_now < firstCifra + 10; ++ptr_now) {
    // cerr << i << " " << j << " ";
    if (matrix[i][j] != '*')
      cout << matrix[i][j];
    // cerr << endl;
    ++i;
    if (i == d) {
      // cerr<<endl;
      i = 0;
    }
    if (d - s + 1 == i) {
      ++j;
    }
  }
  cout << endl;
  return 0;
}

/*
3an al ansaNlak Oa ovI fv !nioHE7
Ela v Haskovo na finala na NOI!

3pan al ansaNlak Oa ovI fv !nioHE7
Ela v Haskovo na finala na NOI!p

*/
