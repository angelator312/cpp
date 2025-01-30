#include <iostream>
#include <vector>
// #include
using namespace std;

const int N = 1e6+2;

int eratosten[N];
int pref[N];
void eratostenFill() {
  eratosten[0] = 0;
  eratosten[1] = 0;
  for (int i = 2; i < N; ++i) {
    for (int j = i * 2; j <= N; j += i) {
      eratosten[j] += i;
    }
  }
}
void prefFill() {
  pref[0] = 0;
  pref[1] = 0;
  for (int i = 2; i < N; i++) {
    if (eratosten[i] + 1 >= i)
      ++pref[i];
    pref[i] += pref[i - 1];
    /*
    if(i<100)
    {
        cerr<<i<<" "<<eratosten[i]+1<<endl;
    }
    //*/
  }
}
void init() {
  eratostenFill();
  prefFill();
}
int main() {
  init();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    cout << pref[b] - pref[a - 1] << endl;
  }
}