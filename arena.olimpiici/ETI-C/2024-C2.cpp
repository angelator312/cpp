#include <iomanip>
#include <ios>
#include <iostream>
#include <stack>
#define endl "\n"
using namespace std;
const int N = 1e5 + 2;
pair<int, int> tabeli[N];

int n, l;

void Read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> l;
  for (int i = 0; i < n; ++i) {
    cin >> tabeli[i].first >> tabeli[i].second;
  }
}
double Calculate() {
  stack<int> st;
  int lastKilometer = 0;
  double speed = 120;
  double time = 0;
  for (int i = 0; i < n; ++i) {
    if (tabeli[i].second == -1) {
      if (st.empty())
        speed = 120;
      else {
        speed = st.top();
        st.pop();
      }

    } else {
      if (st.empty())
        speed = 120;
      else
        speed = st.top();
      st.push(tabeli[i].second);
    }
    // cerr << i + 1 << " " << (tabeli[i].first - lastKilometer) << " " << speed
    //      << endl;
    time += (tabeli[i].first - lastKilometer) / speed;
    lastKilometer = tabeli[i].first;
  }
  if (st.empty())
    speed = 120;
  else
    speed = st.top();
  // cerr << n + 1 << " " << (l - lastKilometer) << " " << speed << endl;
  time += (l - lastKilometer) / speed;
  return time;
}
int main() {
  Read();
  int q;
  cin >> q;
  for (int i = 0, idx, e; i < q; ++i) {
    cin >> idx >> e;
    --idx;
    swap(tabeli[idx].second, e);
    cout << std::fixed << std::setprecision(4) << Calculate() << endl;
    swap(tabeli[idx].second, e);
  }
  // for (int i = 1, idx, e; i < q; ++i) {
  //   cin >> idx >> e;
  // }
}
