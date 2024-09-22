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
      if ((a[i] > p && a[i] > p2) || (b[i] > p2 && b[i] > p)) {
        //cout<<i<<endl;
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
    bool pb = false;
    for (int i = 1; i < N; i++) {
      int e = a[i], e2 = b[i];
      if (pb) {
        if (e > p2 || e2 > p) {
          res.push_back(i+1);
          //cout<<endl;
        }else{
            pb = false;
        }
      } else {
        if (e > p || e2 > p2) {
          res.push_back(i+1);
          //cout<<2<<i<<p<<e<<p2<<e2<<endl;
          pb = true;
        }
      }
      p=e;p2=e2;
    }
    cout<<res.size()<<endl;
    for (auto i=res.begin();i<res.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    return 0;
}