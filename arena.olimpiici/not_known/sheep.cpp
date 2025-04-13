#include <iostream>
using namespace std;
bool proverka(int ch, int l, int chs[]) {
  for (int i = 0; i < l; i++) {
    if (chs[i] == ch) {
      return false;
    }
  }
  return true;
}
int main() {
  int n, l;
  cin >> n >> l;
  int ls[l], out=0, br = 0, br2 = 0;
  for (int i = 0; i < l; i++) {
    cin >> ls[i];
  }
  while (true) {
    br++;
    if (br > 9) {
      br = br % 10;
      br2++;
      out = br2 * 10 + br;
      cout << "1 "<<out <<endl;
    } else {
      while (!proverka(br, l, ls)) {
        if (br > 9) {
          br = br % 10;
          br2++;
          out = br2 * 10 + br;
        }else{
            br++;
            out = br2 * 10 + br;
        }
        cout << "2 "<<out << endl;
      }
      out=br2 * 10 + br;
    }
    cout<<out<<endl;
    if(out>=n)break;
  }
}