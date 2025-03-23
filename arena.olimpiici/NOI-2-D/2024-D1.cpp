#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
using pI = pair<int, int>;
const int N = 25e4 + 2;
const int A = 65540;
int broiNumber[A];
int brPairs;

vector<int> arrayOfPairs[A];
vector<int> pairs;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  int n;
  cin >> n;
  if(n%2==1)
  {
    cout<<0<<endl;
    return 0;
  }
  int a;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    ++broiNumber[a];
    arrayOfPairs[a].push_back(i);
    if (broiNumber[a] == 2)
      pairs.push_back(a);
  }
  int minPrem = N;
  for (int e : pairs) {
    for (int i = 0; i < broiNumber[e]; ++i) {
      int sr = n + 1 - arrayOfPairs[e][i];
      if (sr > arrayOfPairs[e][i])
        for (int j = i + 1; j < broiNumber[e]; ++j) {
          minPrem = min(minPrem, abs(sr - arrayOfPairs[e][j]));
        }
      else
        for (int j =0; j < i; ++j) {
          minPrem = min(minPrem, abs(sr - arrayOfPairs[e][j]));
        }

      // cerr<<e<<" "<<sr<<endl;
    }
  }
  if (minPrem == N)
    minPrem = 0;
  cout << minPrem << endl;
}