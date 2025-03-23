#include <iostream>
#include <stack>
using namespace std;
const char NACHALO = '!';
const int N = 72;
int s, m, h, n;
string redicaNow = "";
int denonoshtia = 0;
bool isNotOk() {
  int i=0;
  for (char a : redicaNow) {
    if (a != NACHALO+i) {
      return true;
    }
    ++i;
  }
  return false;
}

void init() {
  cin >> s >> m >> h >> n;
  for (int i = 0; i < n; ++i) {
    redicaNow += NACHALO + i;
  }
}

int main() {
  init();
  cerr << redicaNow << endl;
  stack<char> stOfMin;
  stack<char> stOfHours;
  do {
    int sz = redicaNow.size();
    int sekIntervali = min(sz / s, m);
    for (int i = 0; i < sekIntervali;) {
      redicaNow += redicaNow.substr(i * s, s - 1);
      stOfMin.push(redicaNow[(++i) * s - 1]);
    }
    redicaNow = redicaNow.substr(sekIntervali * s);
    while (stOfMin.size() >= m) {
      int m2 = m;
      while (--m2) {
        redicaNow += stOfMin.top();
        stOfMin.pop();
      }
      // cerr<<m2<<endl;
      stOfHours.push(redicaNow.back());
    }
    while (stOfHours.size() >= h) {
      int h2 = h;
      while (--h2) {
        redicaNow += stOfHours.top();
        stOfHours.pop();
      }
      ++denonoshtia;
    }
  } while (isNotOk());

  return 0;
}
