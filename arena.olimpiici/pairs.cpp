#include <iostream>

using namespace std;

const int MAX_SBOR = 50000;
int main() {
  int n;
  cin >> n;
  int a[n], sbors[MAX_SBOR], p = 0;
  for (int i = 0; i < n; i++) 
    cin>>a[i];
  
  for (int i = 0; i < MAX_SBOR; i++)
    sbors[i] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      sbors[a[i] + a[j]]++;
      p = max(sbors[a[i] + a[j]], p);
    }
  }
  for (int i = 0; i < MAX_SBOR; i++) {
    //cout << i <<" "<<sbors[i] <<endl;
    if (sbors[i] == p) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}