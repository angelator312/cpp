#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
const int N = 2e5;
bool pravilni[N];
int main() {
  string s;
  cin >> s;
  int n = s.size(),br=0;
  stack<int> st;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      st.push(i);
    } else if (s[i] == ')') {
      if (!st.empty()) {

        int c = i - st.top();
        if (c > 1) {
          br += (c - 1) / 2;
        }
        ++br;
        st.pop();
      }
    }
  }
  cout<<br<<endl;
}