#include <algorithm>
#include <iostream>
using namespace std;
const int A = 1e6 + 1;
int prefReshEratosten[A];

void fillReshetoNaEratosten() {
  for (int i = 4; i < A; i += 2) {
    prefReshEratosten[i] = 1;
  }
  for (int i = 3; i < A; i += 2) {

    if (prefReshEratosten[i]) {
    //   prefReshEratosten[i] = prefReshEratosten[i - 1];
      continue;
    }
    // prefReshEratosten[i] = prefReshEratosten[i - 1] + 1;

    for (int j = 2 * i; j < A; j += i) {
      prefReshEratosten[j] = 1;
    }
  }
}

void init() {
  fillReshetoNaEratosten();
  for (int i = 2; i < A; ++i) {
    prefReshEratosten[i] = prefReshEratosten[i - 1] + !prefReshEratosten[i];
  }
}
int main() {
  init();
  int k, a, b;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    cin >> a >> b;
    cout << prefReshEratosten[b] - prefReshEratosten[a - 1] << endl;
  }
}