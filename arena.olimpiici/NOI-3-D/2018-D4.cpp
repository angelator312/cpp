#include <iostream>
using namespace std;

// Calculate and return the period
// The length of the period for
// a given m ranges from 3 to m * m
int period(int m) {
  int prev = 0;
  int curr = 1;
  int res = 0;

  for (int i = 0; i < m * m; i++) {
    int temp = 0;
    temp = curr;
    curr = (prev + curr) % m;
    prev = temp;

    if (prev == 0 && curr == 1)
      res = i + 1;
  }
  return res;
}

int fibonacciModulo(int n, int m) {

  int p = period(m);
  // cout << "Lenght of the period p=" << p << endl;

  n = n % p;

  int prev = 0;
  int curr = 1;

  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;

  for (int i = 0; i < n - 1; i++) {
    int temp = 0;
    temp = curr;
    curr = (prev + curr) % m;
    prev = temp;
  }
  return curr % m;
}

int main() {
  int n; 
  int m;
  cin>>n>>m;
  cout << fibonacciModulo(n, m) << endl;
  
}
