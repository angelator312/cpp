#include <iostream>
using namespace std;


int main() {
  int n, a, b, m, br = 0,sm=0,sbm=0,sam=0;
  cin >> a >> b >> n;
  for (int i = 0; i < n; i++) {
    int xi;
    cin >> xi;
    if(xi > b){
        br++;
    }else if(xi <= b && xi > a){
        sbm++;
    }else {
        sam++;
    }
  }
  do{
      if (sbm>0 && sam>0 ) {
        br++;
        sbm--;
        sam--;
      } else {
        if (sbm>0) {
          br++;
          sbm--;
        } else {
          if(sam>0){
            br++;
            sam-=2;
          }
        }
      }
    
    // 123=A+b
    // a=21 b=45
    // b=50
  } while (sam>0 || sbm>0);
  cout << br << endl;
  return 0;
}