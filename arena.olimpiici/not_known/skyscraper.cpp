#include <iostream>
#include <vector>
using namespace std;
int main() {
  int N;
  cin >> N;
  bool im = 0;
  int a[N], b[N], p = -1, p2 = -1;
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
    if (p > 0) {
      if (!((a[i] <= p && a[i] <= p2) || (b[i] <= p && b[i] <= p2))) {
        // cout<<i<<endl;
        im = 1;
      }
    }
    p = a[i];
    p2 = b[i];
  }
  if (im) {
    cout << "Impossible!" << endl;
    return 0;
  }
  vector<int> res;
  p = a[0];
  p2 = b[0];
  for (int i = 0; i < N; i++) {
    int e = a[i], e2 = b[i], brRN = 0, brNN = 0;
    bool pb = false;
    // cout<<"["<<i<<"]e:"<<e<<" p:"<<p<<" e2:"<<e2<<" p2:"<<p2<<endl;
    if (e > p || e2 > p2) {
      res.push_back(i + 1);
      // cout<<"["<<i<<"]"<<endl;
      p = e2;
      p2 = e;
      continue;
    }
    for (int j = i + 1; j < N; j++) {
      if (pb) {
        if (b[j - 1] >= a[j] && a[j - 1] >= b[j]) {
          brNN++;
          pb = 0;
        } else {
          brRN++;
        }
      } else {
        if (a[j - 1] >= a[j] && b[j - 1] >= b[j]) {
          brNN++;
        } else {
          brRN++;
          pb = 1;
        }
      }
    }
    // cout << "[" << i << "]brRN: " << brRN << " ; brNN: " << brNN << endl;
    if (brNN < brRN) {
      if (e2 <= p && e <= p2) {
        res.push_back(i + 1);
        p = e2;
        p2 = e;
        continue;
      }
    }
    p = e;
    p2 = e2;
  }
  cout << res.size() << endl;
  for (auto i = res.begin(); i < res.end(); i++) {
    cout << *i << " ";
  }
  cout << endl;
  return 0;
}