#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  double a[n], b[n], L = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    L += b[i];
  }
  double K[n], Lk=0;
  for (int i = 0; i < n; i++) {
    bool bo = true;
    double Kl[n], Lkl = 0;
    for (int j = 0; j < n; j++) {
      Kl[j] = (a[i] * b[j]) / b[i];
      //cout << "j= "<<j<< " KL="<<Kl[j] <<endl;
      if (Kl[j] > a[j]) {
        bo = false;
        break;
      }
      Lkl += Kl[j];
    }
    //cout << Lkl << " " << Lk << endl;
    if (bo) {
      if (Lkl > Lk) {
        Lk = Lkl;
        for (int i = 0; i < n; i++){
            K[i] = Kl[i];
        }
        
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << setprecision(2) << fixed  <<  a[i] - K[i] << " ";
  }
  cout << endl;
  return 0;
}