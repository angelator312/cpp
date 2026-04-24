// https://arena.olimpiici.com/#/catalog/802/problem/102122
#include <array>
#include <bits/stdc++.h>
#include <utility>
using namespace std;
const double xC = 0, ERR = 1e-6;
struct pii
{
  double x, y;
}; // format-off
inline double sq(double a) { return a * a; }
double dist(pii A, pii B) { return sqrt(sq(A.x - B.x) + sq(A.y - B.y)); }
double area(pii A, pii B, pii C)
{
  return abs((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y));
}
pair<pii, pii> lrFromPoints(pii A, pii B)
{
  return {{min(A.x, B.x), min(A.y, B.y)}, {max(A.x, B.x), max(A.y, B.y)}};
}
pii mid(pii A, pii B)
{
  return {(A.x + B.x) / 2.0,
          (A.y + B.y) / 2.0};
}
pii SolveFor(pii P, pii A, pii B, double target)
{
  pii B1=B;
  // auto [A, B] = lrFromPoints(A, B);
  // cerr << dist({A.x, A.y}, {r.x, r.y}) << endl;
  while (dist(A, B) > ERR)
  {
    pii M=mid(A,B);
    auto chArea = area(B1,M,P);
    // cerr << m.x << " " << m.y << " " << chArea << endl;
    if ((chArea - target)> ERR)
      A = M;
    else
      B = M;
  }
  return mid(A, B);
}
pii pC, pB, pP, pA;
int main()
{
  pC.x = 0;
  cin >> pC.y >> pB.x >> pB.y >> pP.x >> pP.y;
  pii ansG;
  if (area(pA, pB, pP) == 0)
    swap(pA, pC);
  if (area(pA, pC, pP) == 0)
    swap(pA, pB);
  double areaABC = area(pA, pB, pC);
  double areaABP = area(pA, pB, pP);
  double areaACP = area(pA, pC, pP);
  if (areaABP < areaACP)
    ansG = SolveFor(pP, pA, pC, areaABC / 2.0);
  else
    ansG = SolveFor(pP, pA, pB, areaABC / 2.0);
  cout << fixed << setprecision(6) << ansG.x << " " << ansG.y << endl;
}