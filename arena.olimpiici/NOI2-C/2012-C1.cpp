#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N = 1e5 + 2;
// set<string> hs;
vector<string> hashes;
vector<int> edges[N];
bool is_child[N];
int visited[N];
int hashesSz = 0;
int n;
int mxBr = 0;
string mx = "";
int hashName(const string &str) {
  // auto a=hs.find(a);
  // if(a!=hs.end())
  //     return distance(hs.begin(),a);
  // else
  auto a = find(hashes.begin(), hashes.end(), str);
  if (a != hashes.end()) {
    return distance(hashes.begin(), a);
  } else {
    hashes.push_back(str);
    return hashesSz++;
  }
}
bool find(int hs1, int hs2) {
  for (int e : edges[hs1]) {
    if (e == hs2)
      return true;
  }
  return false;
}
void Read() {
  cin >> n;
  string str, str2, end = "";
  for (int i = 0; i < n; ++i) {
    cin >> str >> str2;
    int hs1 = hashName(str);
    int hs2 = hashName(str2);
    if (find(hs1, hs2))
      continue;

    edges[hs1].push_back(hs2);

    if (is_child[hs2]) {
      end = hashes[hs2];
    }
    is_child[hs2] = true;
  }
  if (!end.empty()) {
    cerr << "end:";
    cout << end << endl;
    exit(0);
  }
}
int dfs(int i) {
  visited[i] = 1;
  // cerr << "in:" << i << endl;
  for (int e : edges[i]) {
    // cerr << e << endl;
    if (!visited[e])
      dfs(e);
    visited[i] += visited[e];
  }
  // --visited[i];
  // cerr << "out:" << i << endl;
  return visited[i];
}
int main() {
  Read();
  for (int i = 0; i < hashesSz; ++i) {
    if (!visited[i]) {
      dfs(i);
    }
    int e = visited[i];
    // cerr << hashes[i] << " " << e << endl;
    if (e > mxBr) {
      mxBr = e;
      mx = hashes[i];
    } else if (e == mxBr) {
      mx = max(hashes[i], mx);
    }
  }
  cout << mx << endl;
  return 0;
}