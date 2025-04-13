#include <iostream>
using namespace std;
int main() {
  int N;
  cin >> N;
  int A[N], B[N], O[6] = {0, 0, 0, 0, 0, 0}, Omax[6] = {0, 0, 0, 0, 0, 0},
                  max = 0, out;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    cin >> B[i];
  }
  for (int i = 0; i < N; i++) {
    int e = A[i], Oe = O[e];
    int e2 = B[i], Oe2 = O[e2];
    O[e]++;
    if (e != e2)
      O[e2]++;
    for (int j = 1; j <= 5; j++) {
      if ((i + 1 < N) && (j == e || j == e2))
        continue;
      if (Omax[j] < O[j]) {
        Omax[j] = O[j];
      }
      //cout << "=0 : "<<j<<endl;
      O[j] = 0;
    }
    //cout << Omax[2]<<" "<<O[1]<<" "<<O[2]<<" "<<O[3]<<" "<<O[4]<<" "<<O[5]<<endl;
  }
  for (int i = 1; i <= 5; i++)
    if (Omax[i] > max) {
      max = Omax[i];
      out = i;
    }

  cout << max << " " << out << endl;
  return 0;
}