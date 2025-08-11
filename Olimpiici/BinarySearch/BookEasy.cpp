#include <iostream>
using namespace std;

using LL = long long;

const LL N = 1e3 + 1;
const LL BIGGEST_OUT = 1e7 + 1;

LL studentsCount, bookCount;
LL bookPages[N];

void Read() {
  cin >> studentsCount >> bookCount;
  for (int i = 0; i < bookCount; ++i) {
    cin >> bookPages[i];
  }
}

bool CanGet(int mostAllowedPages) {
  LL pageCount = 0, studentsHavingBooks = 0;
  for (int i = 0; i < bookCount; ++i) {
    pageCount += bookPages[i];
    if (pageCount > mostAllowedPages) {
      ++studentsHavingBooks;
      if (studentsHavingBooks > studentsCount)
        return false;
      pageCount = bookPages[i];
    }
  }
  ++studentsHavingBooks;
  return !(studentsHavingBooks > studentsCount);
}

int main() {
  Read();

  LL leftPointer = 0, rightPointer = BIGGEST_OUT, ans = -1;
  while (leftPointer <= rightPointer) {
    LL m = leftPointer + (rightPointer - leftPointer) / 2;
    if (CanGet(m)) {
      rightPointer = m - 1;
      ans = m;
    } else
      leftPointer = m + 1;
  }
  cout << ans << endl;

  return 0;
}
