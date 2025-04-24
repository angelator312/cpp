#include <iostream>
using namespace std;

const int N = 1e7 + 2;
bool del[N];
int prefd[N];

void eratosten() {
  for (long long d = 2; d <= N; d++) {
    if (del[d])
      continue;
    prefd[d] = 1;
    for (long long k = d * d; k <= N; k += d) {
      del[k] = true;
    }
  }
  return;
}

int main() {
  int n, a, b; 
  cin >> n;
  eratosten();
  for (int i = 2; i < N; i++) { 
    prefd[i] += prefd[i - 1];
  }
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    cout << prefd[b] - prefd[a - 1] << "\n";
  }

  return 0;
}
