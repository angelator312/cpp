#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N = 5e5 + 2;
string s;
vector<int> t;
int n;
void init() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    t.push_back(i);
  }
}
int main() {
  init();
//   int lastU = 0;
  int lastD = 0;
  bool isDRedica = false;
  char a;
  for (int i = 0; i < n - 1; ++i) {
    cin >> a;
    if (a == '<') {
      if (isDRedica) {
        // cerr<<lastD<<" "<<i+1<<endl;
        reverse(t.begin() + lastD, t.begin() + i + 1);
      }
      isDRedica = false;
      continue;
    } else {
      if (!isDRedica) {
        lastD = i;
        isDRedica = true;
      }
    }
  }
  if (isDRedica) {
    // cerr << lastD << " " << i + 1 << endl;
    reverse(t.begin() + lastD, t.end());
  }
//   cerr << "end" << endl;
  for (int i = 0; i < n - 1; ++i) {
    cout << t[i] << " ";
  }
  cout << t[n - 1] << endl;

  return 0;
}

/*
Представяме ви, сайт за книги игри, в който можеш да създаваш и четеш книги игри и е напълно безплатен: https://bookgames.angelator312.top/


*/