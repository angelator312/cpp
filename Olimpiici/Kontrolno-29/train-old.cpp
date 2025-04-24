#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
using pI = pair<int, int>;
const int N = 1e5 + 2;

int redica[N], n;
inline bool bigProverka(vector<int> a) {
  stack<int> st;
//   cerr<<endl;
//   for(auto e:a)
//   {
//     cerr<<e<<" ";
//   }
//   cerr<<endl;
  int posl=n;
  for (auto e : a) {
    st.push(e);
    while(!st.empty()&&st.top()==posl)
    {
        --posl;
        st.pop();
    }
  }
  return posl==0&&st.empty();
}
inline bool proverka(vector<int> redVec) {
  int i = 1, posl = redica[0], redicaLen = 1;
  short whatRedica = 0; // 0-nothing,1-bigger,2-smaller
  vector<pI> intervals;

  while (i < n) {
    if (whatRedica == 0) {
      if (posl - 1 == redica[i])
        whatRedica = 2;
      else if (posl + 1 == redica[i])
        whatRedica = 1;
      else {
        intervals.push_back({i - 1, i - 1});
        --redicaLen;
      }
      ++redicaLen;
    } else if (whatRedica == 2) {
      if (posl - 1 == redica[i]) {
        ++redicaLen;
      } else {
        whatRedica = 0;
//cerr << 2 << endl;
        intervals.push_back({i - redicaLen, i - 1});
        redicaLen = 1;
      }
    } else if (whatRedica == 1) {
      if (posl + 1 == redica[i]) {
        ++redicaLen;
      } else {
        whatRedica = 0;
        intervals.push_back({i - redicaLen, i - 1});
        redicaLen = 1;
      }
    }
    posl = redica[i];
    ++i;
  }
  intervals.push_back({i - redicaLen, i - 1});
//cerr << "Intervals \n";
  int intervalsSize = intervals.size();
  for (int i = intervalsSize - 1; i >= 0; --i) {
    auto e = intervals[i];
//cerr << e.first << " " << e.second << endl;
    if (e.first == e.second)
      continue;
    reverse(redica + e.first, redica + e.second + 1);
  }
//   for (int i = 0; i < n; ++i)
//     cerr << redica[i];
//   cerr << endl;
  for (int i = 0, e = 1; i < n; ++i, ++e) {
    if (redica[i] != e && redica[i] != n - i) {
      return false;
    }
  }
  return (redica[0] == n) ? bigProverka(redVec) : true;
}
int main() {
  ios_base::sync_with_stdio(false);
  //   cin.tie(nullptr);
  //   cout.tie(nullptr);
  scanf("%d", &n);
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &redica[j]);
    }
    vector<int> a;
    for (int i = n - 1; i >= 0; --i)
      a.push_back(redica[i]);
    bool bl = bigProverka(a);
    printf(bl ? "1" : "0");
  }
  printf("\n");
}