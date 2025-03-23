#include <iostream>
#include <vector>
using namespace std;
using pI = pair<int, int>;
const int N = 3e6 + 1;
int broiDeliteli[N], maxCnt = 1;
vector<int> maxes;
void reshEratosten() {
  maxes.push_back(1);
  broiDeliteli[1] = 0;
  for (int i = 2; i < N; ++i) {
    for (int j = i; j < N; j += i) {
      ++broiDeliteli[j];
    }
    if (broiDeliteli[maxes.back()] < broiDeliteli[i]) {
      maxes.push_back(i);
    //   cerr<<broiDeliteli[i]<<" "<<i<<endl;
      ++maxCnt;
    }
  }
  // cerr << endl;
}

int main() {
  reshEratosten();
  int n, mx = 0, ch = 0;
  cin >> n;
  for (int i = 1; i < maxCnt; i++) {
    if (maxes[i] > n) {
        --i;
      cout << maxes[i] << endl;
      cout << broiDeliteli[maxes[i]]+1 << endl;
      return 0;
    }
  }
}