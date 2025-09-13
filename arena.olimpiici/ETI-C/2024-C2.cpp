#include <iomanip>
#include <ios>
#include <iostream>
#include <stack>
#define endl "\n"
using namespace std;
const int N = 1e5 + 2;
//<km,maxSpeed>
pair<int, int> tabeli[N];
double speeds[N];
double times[N];
double timesSum = 0;
int n, maxKM;

void Read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> maxKM;
  for (int i = 0; i < n; ++i) {
    cin >> tabeli[i].first >> tabeli[i].second;
  }
}

void PreCalculate() {
  stack<int> st;
  int lastKilometer = 0;
  // double speeds[i] = 120;
  double time = 0;
  for (int i = 0; i < n; ++i) {
    if (tabeli[i].second == -1) {
      if (st.empty())
        speeds[i] = 120;
      else {
        speeds[i] = st.top();
        st.pop();
      }

    } else {
      if (st.empty())
        speeds[i] = 120;
      else
        speeds[i] = st.top();
      st.push(tabeli[i].second);
    }
    // cerr << i + 1 << " " << (tabeli[i].first - lastKilometer) << " " <<
    // speeds[i]
    //      << endl;
    times[i] = (tabeli[i].first - lastKilometer) / speeds[i];
    lastKilometer = tabeli[i].first;
    timesSum += times[i];
  }
  if (st.empty())
    speeds[n] = 120;
  else
    speeds[n] = st.top();
  // cerr << n + 1 << " " << (l - lastKilometer) << " " << speeds[n] << endl;
  times[n] = (maxKM - lastKilometer) / speeds[n];
  timesSum += times[n];
}

double Calculate(int idx, int newMaxSpeed) {
  // ++idx;
  double timeOnThisPath = 0;
  if(newMaxSpeed==-1)newMaxSpeed=speeds[idx-1];
  if (idx < n)
    timeOnThisPath =
        (tabeli[idx].first - tabeli[idx - 1].first) / double(newMaxSpeed);
  else
    timeOnThisPath =
        (maxKM - tabeli[idx - 1].first) / double(newMaxSpeed);
  // cerr << timeOnThisPath << " " << times[idx] << ""
  //      << timesSum - times[idx] + timeOnThisPath << endl;
  return timesSum - times[idx] + timeOnThisPath;
}

int main() {
  Read();

  PreCalculate();
  for (int i = 0; i <= n; ++i)
    cerr << speeds[i] << " ";
  cerr << endl;
  for (int i = 0; i <= n; ++i)
    cerr << times[i] << " ";
  cerr << endl;

  int q;
  cin >> q;
  for (int i = 0, idx, e; i < q; ++i) {
    cin >> idx >> e;
    // if (e == -1) {
    // --idx;
    //   swap(tabeli[idx].second, e);
    //   cout << std::fixed << std::setprecision(4) << SlowCalculate() << endl;
    //   swap(tabeli[idx].second, e);
    // } else {
    cout << std::fixed << std::setprecision(4) << Calculate(idx, e) << endl;
    // }
  }
  // for (int i = 1, idx, e; i < q; ++i) {
  //   cin >> idx >> e;
  // }
}
