// 6
#include "wordle.h"
#include <iostream>
#include <unordered_set>
#include <vector>
#if 1
#define eprintf(args...) fprintf(stderr, args)
#else
#define eprintf(args...)
#endif
// ₳₦₲ɆⱠ₳₮ØⱤ312 𝕨𝕒𝕤 hêrê
using namespace std;

const int ALPHABET_SIZE = 26;

vector<int> idxsOfWordsWith[5][ALPHABET_SIZE];

string query(std::string B);

void ClearIndexes() {
  for (int i = 0; i < 5; ++i)
    for (int j = 0; j < ALPHABET_SIZE; ++j)
      idxsOfWordsWith[i][j].clear();
}

void FillArr(vector<string> words) {
  for (int i = 0; i < words.size(); ++i)
    for (int j = 0; j < words[i].size(); ++j)
      idxsOfWordsWith[j][words[i][j] - 'a'].push_back(i);
}

void solve(vector<string> words) {
  ClearIndexes();
  FillArr(words);
  string s = query(words[0]); // s=b/y/g*
  if (s == "ggggg")
    return;
  vector<string> newWords;
  for (int idx = 0; idx < s.size(); ++idx) {
    if (words[0][idx] == 'b')
      continue;
    // Get All Words with right
    for (int i : idxsOfWordsWith[idx][words[0][idx] - 'a']) {
      if (i == 0) // if is the same
        continue;
      newWords.push_back(words[i]);
    }
  }
  if (newWords.size() == 0) {
    words.erase(words.begin() + 1);
    if (words.size() > 0)
      solve(words);
  } else
    solve(newWords);
}
/*
3
geeky point sheep
sheep
 */
