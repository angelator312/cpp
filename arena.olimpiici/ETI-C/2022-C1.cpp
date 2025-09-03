#include <iostream>
using namespace std;

using num = int;
using idx_t = int;

const int MAX_SIZE_OF_ROW = 1e5 + 1;

num row[MAX_SIZE_OF_ROW];

num sizeOfRow, countOfRequests;

void ReadRow() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> sizeOfRow >> countOfRequests;
  for (idx_t i = 0; i < sizeOfRow; ++i)
    cin >> row[i];
}

num l, r, d;

void SolveRequest() {
  cin >> l >> r >> d;
  num cnt = 0;
  for (idx_t i = l - 1; i < r; ++i)
    cnt += ((row[i] % d == 0) || (d % row[i] == 0));
  cout << cnt << " ";
}

int main() {
  ReadRow();
  for (idx_t i = 0; i < countOfRequests; ++i)
    SolveRequest();
  cout << endl;
  return 0;
}
