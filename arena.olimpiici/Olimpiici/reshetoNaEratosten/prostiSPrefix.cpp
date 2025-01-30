#include <algorithm>
#include <iostream>
using namespace std;
using LL = long long;
const int N = 1e7 + 2;
bool eratosten[N];
int pref_is_prime[N];

void prefixFill() {
  pref_is_prime[0] = 0;
  pref_is_prime[0] = 0;
  for (int i = 2; i < N; i++) {
    pref_is_prime[i] += pref_is_prime[i - 1];
  }
}
void eratostenFill() {
  eratosten[0] = 1;
  eratosten[1] = 1;
  pref_is_prime[2] = 1;
  for (int j = 2 * 2; j <= N; j += 2) {
    eratosten[j] = 1;
  }
  for (int i = 3; i < N; i += 2) {
    if (eratosten[i])
      continue;
    pref_is_prime[i] = 1;
    for (int j = i * 2; j <= N; j += i) {
      eratosten[j] = 1;
    }
  }
}
void init() {
  eratostenFill();
  prefixFill();
}
int main() {
  init();
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a,b;
    cin>>a>>b;
    cout<<pref_is_prime[b]-pref_is_prime[a-1]<<endl;
  }
  //cout << endl;
  return 0;
}