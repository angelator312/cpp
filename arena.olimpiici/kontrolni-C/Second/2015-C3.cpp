#include <iostream>
#include <vector>
using namespace std;
using pI = pair<int, int>;
const int N=1e7+2;
int n, k;
int redica_last = 0;
int redica_now = 0;
int a, b, m, sum;

void Read() {
  cin >> n >> k;
  cin >> redica_last >> a >> b >> m;
}
int main() {
  Read();
  int ind = 0;
  int napraveniDoSega=1;
  while (ind <= n) {
    for(int i=napraveniDoSega;i<k;++i)
    {
      swap(redica_now,redica_last);
      redica_now=(redica_last*a+b)%m;
    }
    vector<pI> posl_k;
    sort(posl_k.begin(), posl_5.end());
    sum += posl_k[0].first;
    ind = posl_k[0].second;
  }
}