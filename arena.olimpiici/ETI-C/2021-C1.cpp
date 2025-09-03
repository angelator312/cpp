#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
using namespace std;

using num = int;
using idx_t = int;

const int MAX_COUNT_OF_TASKS = 51;
const int MAX_COUNT_OF_PLAYERS = 1e5 + 1;

num countOfTasks, countOfPlayers, ivailoSum;
num hackedSolutions = 0;
idx_t indexOfIvailo, indexOfIvailoInSums;

array<num, MAX_COUNT_OF_TASKS> tasksOfIvailo;

// pair<array[Tasks],sum>
pair<num, array<num, MAX_COUNT_OF_TASKS>> tasksOfOthers[MAX_COUNT_OF_PLAYERS];

inline num GenerateSum(const array<num, MAX_COUNT_OF_TASKS> &tasks) noexcept {
  num sum = 0;
  for (idx_t i = 0; i < countOfTasks; ++i)
    sum += tasks[i];
  return sum;
}

inline void ReadRow(array<num, MAX_COUNT_OF_TASKS> &tasks) noexcept {
  for (idx_t i = 0; i < countOfTasks; ++i)
    cin >> tasks[i];
}

inline void Read() noexcept {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  bool isIvailoReaded = false;
  cin >> countOfTasks >> countOfPlayers >> indexOfIvailo;
  --indexOfIvailo;
  for (idx_t i = 0; i < countOfPlayers - 1; ++i) {
    if (i == indexOfIvailo && !isIvailoReaded) {
      ReadRow(tasksOfIvailo);
      --i;
      isIvailoReaded = true;
    } else {
      ReadRow(tasksOfOthers[i].second);
    }
  }
  if (countOfPlayers - 1 == indexOfIvailo) {
    isIvailoReaded = true;
    ReadRow(tasksOfIvailo);
  }
}

inline void GenerateOthersSums() noexcept {
  for (idx_t i = 0; i < countOfPlayers; ++i)
    tasksOfOthers[i].first = GenerateSum(tasksOfOthers[i].second);
}

inline void GenerateSums() noexcept {
  GenerateOthersSums();
  ivailoSum = GenerateSum(tasksOfIvailo);
}

inline void HackPlayerSolution(idx_t player, idx_t idxOfTask) {
  ++hackedSolutions;
  ivailoSum += 100;
  tasksOfOthers[player].first -= tasksOfOthers[player].second[idxOfTask];
  tasksOfOthers[player].second[idxOfTask] = 0;
}

inline void SortIvailosSolution() {

  while (ivailoSum > tasksOfOthers[indexOfIvailoInSums].first &&
         indexOfIvailoInSums >= 0) {
    --indexOfIvailoInSums;
  }
}

inline bool IsIvailoFirst() {
  return (indexOfIvailoInSums == -1 && tasksOfOthers[0].first != ivailoSum);
}

void HackLoop() {
  bool changed = true;
  while (!IsIvailoFirst() && changed) {
    changed = false;
    for (idx_t i = 0; i < countOfTasks; ++i) {
      if (tasksOfIvailo[i] && tasksOfOthers[indexOfIvailoInSums].second[i]) {
        HackPlayerSolution(indexOfIvailoInSums, i);
        SortIvailosSolution();
        changed = true;
        break;
      }
    }
  }
}

int main() {
  Read();
  --countOfPlayers;

  GenerateSums();
  sort(tasksOfOthers, tasksOfOthers + countOfPlayers);
  indexOfIvailoInSums = countOfPlayers - 1;
  SortIvailosSolution();
  HackLoop();

  // sort(tasksOfOthers, tasksOfOthers + countOfPlayers);
  // indexOfIvailoInSums = countOfPlayers - 1;
  // SortIvailosSolution();
  // HackLoop();

  cout << -1 << endl;
  return 0;
}
// TODO: Fix the problem with equals
