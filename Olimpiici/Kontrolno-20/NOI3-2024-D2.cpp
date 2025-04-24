#include <iostream>
using namespace std;
using LL = long long;
const int N = 1e4 + 1;
char matrix[N][N];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string all;
  getline(cin, all);
  int allSize = all.size();
  int ptr_now = 0, d = 0, s = 0, i = 0, j = 4;
  while (all[ptr_now] >= '0' && all[ptr_now] <= '9')
  {
    d *= 10;
    d += ('9' - all[ptr_now]);
    ++ptr_now;
  }
  int firstB = ptr_now;
  while (all[ptr_now] < '0' || all[ptr_now] > '9')
  {
    ++ptr_now;
  }

  int firstCifra = ptr_now;
  while (ptr_now < allSize && all[ptr_now] >= '0' && all[ptr_now] <= '9')
  {
    s *= 10;
    s += ('9' - all[ptr_now]);
    ++ptr_now;
  }
  firstCifra -= firstB;

  return 0;
}