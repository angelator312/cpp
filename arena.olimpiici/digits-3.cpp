#include <iostream>
using namespace std;
int main() {
  string d;
  cin >> d;
  int br = 0;
  for (int i = 0; i < d.size()-2; i++) {
    if(d[i]=='9' || d[i]=='8')continue;
    for (int j = i + 1; j < d.size()-1; j++) {
      if (d[i] >= d[j])
        continue;
      for (int k = j + 1; k < d.size(); k++) {
        if (d[j] >= d[k])
          continue;
        br++; // cout<<d[i]<<" "<<d[j]<<" "<<d[k]<<endl;
      }
    }
  }
  cout << br << endl;
  return 0;
}