#include <iostream>
using namespace std;

using num = long long;
using idx_t = int;
const num BIGGEST = 1e18;
const num ANSWERS = 11;
idx_t ustoichivost;
num answers[ANSWERS] = {0, 10, 25, 39, 77, 679, 6788, 68889, 2677889,26888999,3778888999};

num CalculateUstoichivost(num a) {
  if (a < 10)
    return 0;
  num proizvedenie = 1;
  while (a > 0) {
    proizvedenie *= a % 10;
    a /= 10;
  }
  return CalculateUstoichivost(proizvedenie) + 1;
}

void Read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> ustoichivost;
}

int main() {
  Read();
  if (ustoichivost < ANSWERS) {
    cout << answers[ustoichivost] << "\n";
    return 0;
  }
  for (num i = answers[ANSWERS - 1] + 1; i < BIGGEST; ++i) {
    if (CalculateUstoichivost(i) == ustoichivost) {
      cout << i << "\n";
      return 0;
    }
  }
  return 0;
}
