#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
const int N = 1e5;
int a[N];
// vector<pI> arr;
int main() {
  int n, q, br = 0;
  cin >> n >> q;
  if (q == 1) {
    stack<int> s;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      while (!s.empty() && a[s.top()] < a[i]) {
        s.pop();
      }
      if (!s.empty()) {
        if (a[s.top()] == a[i]) {
          ++br;
          s.pop();
        }
      }
      s.push(i);
    }
    cout << br << endl;
  } else if (q == 2) {
    stack<int> s;
    stack<int> predNiva;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      while (!s.empty() && a[s.top()] < a[i]) {
        s.pop();
      }
      if (!s.empty()) {
        if (a[s.top()] == a[i]) {

          if (predNiva.empty()) {
            predNiva.push(a[i]);
          } else {
            // if (i == 10) {
            //   // cerr << predNiva.top() << endl;
            // }
            if (predNiva.top() == a[i]) {
              cerr<<"predNiva.pop()"<<endl;
              // nishto
            } else if (predNiva.top() < a[i]) {
              ++br;
              // cerr << "predNiva+= " << i << endl;
              predNiva.pop();
              predNiva.push(a[i]);
            } else
              predNiva.push(a[i]);
          }
          s.pop();
        }
      }
      s.push(i);
    }
    cout << br << endl;
  }
}