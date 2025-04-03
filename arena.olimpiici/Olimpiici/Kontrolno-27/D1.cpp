#include <iostream>
using namespace std;
const int A = 1e5 + 2;
int prefix[A];
int main() {
  int n, q, max_number = 0;
  cin >> n;
  for (int i = 0, e; i < n; ++i) {
    cin >> e;
    ++prefix[e];
    max_number = max(max_number, e);
  }
  for (int i = 1; i <= max_number; ++i)
    prefix[i] += prefix[i - 1];
  cin>>q;
  for (int i = 0,l,r; i < q;++i)
  {
    cin>>l>>r;
    if(r>max_number)
      prefix[r] = prefix[max_number];
    if (l > max_number)
      prefix[l-1] = prefix[max_number];
    cout<<prefix[r]-prefix[l-1]<<endl;
  }
  return 0;
}