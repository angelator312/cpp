#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
const int N = 1e5 + 2;
// set<string> hs;
vector<string> hashes;
vector<int> edges[N];
bool visited[N];
int hashesSz = 0;
int n, br = 0;
string problemen;
int hashName(const string &str) {
  auto a = find(hashes.begin(), hashes.end(), str);
  if (a != hashes.end()) {
    return distance(hashes.begin(), a);
  } else {
    hashes.push_back(str);
    return hashesSz++;
  }
}
void Read() {
  string str, str2, end = "";
  while (true) {
    cin >> str;
    if (!cin.good()) {
      problemen = str;
      break;
    }
    cin >> str2;
    int hs1 = hashName(str);
    int hs2 = hashName(str2);
    edges[hs1].push_back(hs2);
    edges[hs2].push_back(hs1);
  }
}
void bfs(const int i) {
  queue<int> q;
  q.push(i);
  // int br = 0;
  while (!q.empty()) {
    ++br;
    int last = q.front();
    visited[last]=true;
    q.pop();
    for (int e : edges[last]) {
      if (!visited[e])
        q.push(e);
    }
  }
}
int main() {
  Read();
  bfs(hashName(problemen));
  cout << br - 1 << endl;
  return 0;
}