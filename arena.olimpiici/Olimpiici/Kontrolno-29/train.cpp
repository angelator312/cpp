#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
using pI = pair<int, int>;
const int N = 1e5 + 2;

int n;
inline bool bigProverka(const vector<int> &things) {
  stack<int> st;
  int posl = n;
  for(auto e:things) {
    st.push(e);
    while (!st.empty()&& st.top() == posl) {
      --posl;
      st.pop();
    }
  }
  while (!st.empty() && st.top() == posl) {
    --posl;
    st.pop();
  }
  return posl<=0 && st.empty();
}
int main() {
  // ios_base::sync_with_stdio(false);
  //   cin.tie(nullptr);
  //   cout.tie(nullptr);
  scanf("%d", &n);
  for (int i = 0; i < 5; ++i) {
    vector<int> a;
    for (int j = 0, e; j < n; ++j) {
      scanf("%d", &e);
      a.push_back(e);
    }
    reverse(a.begin(), a.end());
    bool bl = bigProverka(a);
    printf(bl ? "1" : "0");
  }
  printf("\n");
}