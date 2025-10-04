// 6
#include "wordle.h"
#include <iostream>
#include <unordered_set>
#include <vector>
#if 0
#define eprintf(args...) fprintf(stderr, args)
#else
#define eprintf(args...)
#endif
// ₳₦₲ɆⱠ₳₮ØⱤ312 𝕨𝕒𝕤 hêrê
using namespace std;

const int ALPHABET_SIZE = 26;
const int MAX_WORDS = 1e4 + 67;

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
  int seenTimes[MAX_WORDS]{};
  string s = query(words[0]); // s=b/y/g*
  if (s == "ggggg")
    return;
  unordered_set<int> newWordsIdxs;
  bool anotherTime = false;
  int gTimes = 0;
  for (int idx = 0; idx < s.size(); ++idx) {
    if (s[idx] == 'b')
      continue;
    if (s[idx] == 'g') {
      ++gTimes;
      // Get All Words with right
      for (int i : idxsOfWordsWith[idx][words[0][idx] - 'a']) {
        if (i == 0) // if is the same
          continue;
        eprintf("add %d;", i);
        if (anotherTime) {
          if (newWordsIdxs.find(i) != newWordsIdxs.end())
            ++seenTimes[i];
        } else
          newWordsIdxs.insert(i);
      }
      anotherTime = true;
      eprintf("\n");
    }
  }
  eprintf("1\n");
  for (int idx = 0; idx < s.size(); ++idx) {
    if (s[idx] != 'y')
      continue;
    // Get All Words with right
    for (int idx2 = 0; idx2 < 5; ++idx2)
      for (int i : idxsOfWordsWith[idx2][words[0][idx] - 'a']) {
        if (i == 0) // if is the same
          continue;
        eprintf("added %d;", i);
        newWordsIdxs.insert(i);
      }
  }
  if (newWordsIdxs.size() == 0) {
    words.erase(words.begin() + 1);
    if (words.size() > 0)
      solve(words);
  } else {
    vector<string> newWords;
    for (int i : newWordsIdxs) {
      eprintf("push %d:%d\n", i, seenTimes[i]);
      if (seenTimes[i] == gTimes - 1) {
        newWords.push_back(words[i]);
      }
    }
    solve(newWords);
  }
}
/*
3
geeky point sheep
sheep
 */
