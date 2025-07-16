#include <iostream>
#include <stack>
using namespace std;
const int N = 5e5 + 2;
int n, k;
int heights[N];
int time_for_travel[N];
void Read() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    cin >> heights[i];
  for (int i = 1; i < n; ++i)
    cin >> time_for_travel[i];
}
int main() {
  Read();
  // left pokazalka
  stack<int> st;
  for (int i = 0; i < n; ++i) {
    if (st.empty())
      cerr << -1 << endl;
    else {
      stack<int> st2 = st;
      cerr << i << ":";
      while (!st2.empty()) {
        cerr << st2.top() << " ";
        st2.pop();
      }
      cerr<<endl;
    }
    while (!st.empty() && heights[i] >= heights[st.top()])
      st.pop();
    st.push(i);
  }
  //right pokazalka
  st=stack<int>();
  for (int i = n-1; i >=0; --i) {
    if (st.empty())
      cerr << -1 << endl;
    else {
      stack<int> st2 = st;
      cerr << i << ":";
      while (!st2.empty()) {
        cerr << st2.top() << " ";
        st2.pop();
      }
      cerr<<endl;
    }
    while (!st.empty() && heights[i] >= heights[st.top()])
      st.pop();
    st.push(i);
  }
}
