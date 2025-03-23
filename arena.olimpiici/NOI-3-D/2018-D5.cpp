#include <iostream>
#include <vector>
using namespace std;

int br = 0, rez = 0;
int maxBr = 0, n, e;
vector<int> redica;
void fromSum(int sum) {
  cerr << sum << endl;
  for (int e : redica) {
    sum += e;
    ++br;
    if (sum >= rez) {
      if (sum == rez) {
        maxBr = max(maxBr, sum);
      }
    } else {
      cerr << sum << endl;
      fromSum(sum);
    }
    sum -= e;
    --br;
  }
}

int main() {
  cin >> rez >> n;
  for (int i = 0; i < n; ++i) {
    cin >> e;
    redica.push_back(e);
  }
  fromSum(0);
  cout << maxBr << endl;
}