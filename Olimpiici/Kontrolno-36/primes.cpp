#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
const int N = 1e6;
const int PRIMES_BROI = 78498;
vector<int> primes;
vector<bool> eratosten(N + 2);
int prefix_of_primes[PRIMES_BROI];
void fillEratosten() {
  primes.push_back(2);
  for (int i = 3; i <= N; i += 2) {
    if (eratosten[i]) {
      continue;
    }
    primes.push_back(i);
    for (int j = i << 1; j <= N; j += i) {
      eratosten[j] = true;
    }
  }
}
void Init() {
  // primes.reserve(PRIMES_BROI);
  fillEratosten();
  prefix_of_primes[0] = primes[0];
  for (int i = 1; i < PRIMES_BROI; ++i)
    prefix_of_primes[i] = prefix_of_primes[i - 1] + primes[i];
}
int search_for(int chislo) {
  return distance(primes.begin(),
                  lower_bound(primes.begin(), primes.end(), chislo));
}
/*
 * Outputs {index of first_prime,lenght}
 */
pair<int, int> dilzhina_na_veriga(const int &n) {
  int idx_of_n = search_for(n);
  int len = 0, idx_of_first_prime = idx_of_n;
  for (int i = idx_of_n - 1; i >= 0; --i) {
    if (i <= len)
      break;
    if (prefix_of_primes[i] < n)
      break;
    if (prefix_of_primes[i] == n) {
      // if(i>len){...}
      // if (i > len) {...}
      idx_of_first_prime = 0;
      len = i;
      continue;
      // return {0, i};
    }
    for (int j = 0; j < i; ++j) {
      if(i-j<len)break;
      if (prefix_of_primes[i] - prefix_of_primes[j] == n && i - j > len) {
        // cerr << prefix_of_primes[i] << " " << prefix_of_primes[j] << endl;
        len = i - j;
        idx_of_first_prime = j;
        // return {j, i - j + 1};
      }
    }
  }
  return {idx_of_first_prime, len + 1};
}
int main() {
  Init();
  // cerr << "filled\n";
  int a, b;
  cin >> a >> b;
  int best_prime_idx = -1, best_length = -1, best_prime = 0;
  a += !(a % 2);
  for (; a <= b; a += 2) {
    if (!eratosten[a]) {
      pair<int, int> e = dilzhina_na_veriga(a);
      // cerr << a << ":" << e.first << " " << e.second << endl;
      if (e.second > best_length) {
        best_prime = a;
        best_length = e.second;
        best_prime_idx = e.first;
      }
    }
  }
  // cerr << primes.size() << endl;
  if (best_length == -1)
    cout << "no prime\n";
  else {
    // cerr << best_prime_idx << " " << best_length << endl;
    cout << best_prime << " " << best_length << endl;
    for (int i = best_prime_idx; i < best_prime_idx + best_length; ++i) {
      cout << primes[i] << " ";
    }
    cout << endl;
  }
}
