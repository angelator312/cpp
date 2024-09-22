#include <algorithm>
#include <iostream>

using namespace std;
using LL = long long;

int main() {
  int sr[7],br=0;
  bool no=false;
  for (int i = 0; i < 7; i++) {
    cin >> sr[i];
    if (sr[i] == 2) {
      no = true;
    }
    if (sr[i] == 6) {
      br++;
    }
  }

  if (!no && br>0) {
    cout << string(br,'*') << endl;
  } else
    cout << "No\n";

  return 0;
}
