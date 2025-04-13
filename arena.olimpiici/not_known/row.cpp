#include <iostream>
using namespace std;
int main() {
  int k, br = 0;
  string s;
  cin >> s >> k;
  for (int i = 0; i < s.size(); i++) {
    int n = 0;
    if (s[i] == '0')
        n++;
    if (n == k)
        br++;
    for (int j = i + 1; j < s.size(); j++) {
      if (s[j] == '0')
        n++;
      if (n == k)
        br++;
      if (n > k)
        break;
    }
  }
  cout<<br << endl;
  return 0;
}