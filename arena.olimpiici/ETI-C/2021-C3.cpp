#include <iostream>
#include <set>
using namespace std;

using num = int;
using idx_t = int;

const int MAX_SIZE_OF_POINTS = 1e3 + 2;
const int MAX_POINTS_ON_XY = 1e4 + 2;
num countOfPoints;

// pair<num,num> points[MAX_SIZE_OF_POINTS];

set<num> pointsX;
set<num> pointsY;

set<num> xPointsOnY[MAX_POINTS_ON_XY];
set<num> yPointsOnX[MAX_POINTS_ON_XY];

void Read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> countOfPoints;
  num x, y;
  for (idx_t i = 0; i < countOfPoints; ++i) {
    cin >> x >> y;
    pointsX.insert(x);
    pointsY.insert(y);
    xPointsOnY[y].insert(x);
    yPointsOnX[x].insert(y);
  }
}

int main() {
  Read();
  num countOfRectangles = 0;
  for (num x : pointsX)
    for (num y : pointsY)
      for (num x2 : xPointsOnY[y]) {
        for (num y2 : yPointsOnX[x]) {
          if (yPointsOnX[x2].find(y2) != yPointsOnX[x2].end()) {
            if (x2 == x && y2 == y)
              continue;
            ++countOfRectangles;
            // cerr << x << " " << y << endl;
            // cerr << x2 << " " << y << endl;
            // cerr << x << " " << y2 << endl;
            // cerr << x2 << " " << y2 << endl;
          }
        }
      }
  cout << countOfRectangles << endl;
  return 0;
}
