#include <iostream>
using namespace std;
int main() {
  string in;
  cin >> in;
  int br = 0;
  for (int i = 0; i < in.size(); i++) {
    int j = i + 1, a = 0, b = 0;
    if (in[i] == 'a')
      a++;
    else
      continue;
    while (j < in.size()) {
      if (in[j] == 'a') {
        a++;
      }else break;
      j++;
    }

    while (j < in.size()) {
      if (in[j] == 'b') {
        b++;
        if (a == b) {
          br++;
          break;
        }
      }else break;
      j++;
    }
  }
  cout << br << endl;
  return 0;
}