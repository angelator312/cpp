#include <iostream>
using namespace std;
const int N = 1e5 + 2;
char ants[N];
int cntLeft[N];
int cntRight[N];
int n, m;
int virtLeft(const char&a)
{
    if(a=='u'||a=='d')return 1;
    if(a=='r')return 2;
    return 0;
}

int virtRight(const char &a) {
  if (a == 'u' || a == 'd')
    return 1;
  if (a == 'l')
    return 2;
  return 0;
}

void read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  for (int i = 0, e; i < m; ++i) {
    cin >> e >> ants[e];
  }
  cerr << "readed!\n";
  ants[0] = 'l';
  ants[n + 1] = 'r';
}

int main(int argc, char const *argv[]) {
  read();
  // LEFT
  int beliDoSega = 0;
  int virtMax = 0;
  int lastNotWhite = 0;
  //LEFT
  for (int i = 1, virtSega; i <= n; ++i) {
    virtSega = virtLeft(ants[i]);
    if (ants[i] == 0) {
      ++beliDoSega;
      cntLeft[i] = cntLeft[i - 1] + 1;
    } else if (beliDoSega) {
      cntLeft[i] +=
          virtMax > 0 ? max(virtMax - beliDoSega, -2) : (i - 1) + 1 + virtSega;
      beliDoSega = 0;
      virtMax = virtSega;
    } else {
      //   cerr << i << " " << virtSega << endl;
      cntLeft[i] = max(virtSega - virtMax, 0) + cntLeft[i - 1] + 1;
    }
  }
  // Right
  beliDoSega = 0;
  virtMax = 0;
  lastNotWhite = 0;
  // Right
  for (int i = n, virtSega; i >0;--i) {
    virtSega = virtRight(ants[i]);
    if (ants[i] == 0) {
      ++beliDoSega;
      cntRight[i] = cntRight[i + 1] + 1;
    } else if (beliDoSega) {
      cntRight[i] +=
          virtMax > 0 ? max(virtMax - beliDoSega, -2) : (n-i-1) + 1 + virtSega;
      beliDoSega = 0;
      virtMax = virtSega;
    } else {
      //   cerr << i << " " << virtSega << endl;
      cntRight[i] = max(virtSega - virtMax, 0) + cntRight[i + 1] + 1;
    }
  }

  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    cerr << cntRight[i];
    if (ants[i] != 0)
      mx = max(mx, min(cntLeft[i],cntRight[i]));
  }
  cerr << endl;
  cout<<mx<<endl;
  return 0;
}
