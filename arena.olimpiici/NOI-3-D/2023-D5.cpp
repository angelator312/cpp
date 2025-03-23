#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
const int A = 1e9 + 1;
const int N = 1e5 + 2;
int n, el, br;
stack<int> st;
stack<int> tmpSt;
stack<int> st2;
stack<int> tmpSt2;
vector<int> udovolstvieDoSegaR[N];
int udovolstvieDoSegaL[N];
// void fillUdolvolstvieRDoI(int i) {
//   tmpSt=st;
//   vector<int> v;
//   while (!tmpSt.empty()) {
//     v.push_back(tmpSt.top());
//     tmpSt.pop();
//   }
//   sort(v.begin(), v.end());
//   int posl = -1;
//   for (auto it=v.begin();it!=v.end();++it) {
//     if(posl!=*it) {
//       udovolstvieDoSegaR[i].push_back(*it);
//       posl=*it;
//     }
//   }
// }
// void fillUdolvolstvieLDoI(int i) {
//   tmpSt2=st2;
//   vector<int> v;
//   while (!tmpSt2.empty()) {
//     v.push_back(tmpSt2.top());
//     tmpSt2.pop();
//   }
//   sort(v.begin(), v.end());
//   int posl = -1;
//   for (auto it=v.begin();it!=v.end();++it) {
//     if(posl!=*it) {
//       udovolstvieDoSegaL[i].push_back(*it);
//       posl=*it;
//     }
//   }
// }
// void init() {
//   cin >> n;
//   for (int i = 1; i <= n; ++i) {
//     cin >> el;
//     while (!st.empty() && st.top() <= el) {
//       st.pop();
//     }
//     st.push(el);
//     fillUdolvolstvieRDoI(i);
//   }
// }

int main() {
  // init();
  cout << br << endl;
  return 0;
}
