#include <cstdio>
#include <iostream>
#include <stack>
#ifdef eval
#define fprintf(args...)
#endif
using namespace std;

using num = int;
using idx_t = int;

const int MAX_SIZE_OF_STRING = 1e5 + 2;

num sizeOfString, countOfRequests;
string s;

num idxOfAnotherSkoba[MAX_SIZE_OF_STRING];

bool SolveRequest(idx_t leftPointer, idx_t rightPointer) {

  const num opositeBracketOfLeft = idxOfAnotherSkoba[leftPointer];
  const num opositeBracketOfRight = idxOfAnotherSkoba[rightPointer];
  if (opositeBracketOfLeft == -1)
    return false;
  if (opositeBracketOfRight == -1)
    return false;
  if (opositeBracketOfLeft == rightPointer)
    return true;
  if (!(leftPointer <= opositeBracketOfLeft &&
        opositeBracketOfLeft <= rightPointer))
    return false;

  if (!(leftPointer <= opositeBracketOfRight &&
        opositeBracketOfRight <= rightPointer))
    return false;
  return true;
  // return SolveRequest(leftPointer, opositeBracketOfLeft) &&
  //        SolveRequest(opositeBracketOfRight, rightPointer)
}

void Read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> sizeOfString;
  cin >> s;
  cin >> countOfRequests;
}

void FillIndexes() {
  stack<idx_t> skobi;

  for (idx_t i = 0; i < sizeOfString; ++i)
    idxOfAnotherSkoba[i] = -1;
  for (idx_t i = 0; i < sizeOfString; ++i) {
    if (s[i] == ')') {
      if (skobi.empty())
        // Think about here
        // idxOfAnotherSkoba[i] = -1;
        ;
      else {
        fprintf(stderr, "%d<->%d\n", skobi.top(), i);
        idxOfAnotherSkoba[skobi.top()] = i;
        idxOfAnotherSkoba[i] = skobi.top();
        skobi.pop();
      }
    } else
      skobi.push(i);
  }
}

int main() {
  Read();
  FillIndexes();
  for (idx_t i = 0; i < sizeOfString; ++i)
    fprintf(stderr, "%d", idxOfAnotherSkoba[i]);
  fprintf(stderr, "\n");
  for (idx_t i = 0; i < countOfRequests; ++i) {
    idx_t leftPointer, rightPointer;
    cin >> leftPointer >> rightPointer;
    --leftPointer;
    --rightPointer;
    cout << SolveRequest(leftPointer, rightPointer) << endl;
  }
  return 0;
}
