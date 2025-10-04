//10.9
#include <iostream>
#include <vector>
#if 1
#define eprintf(args...) fprintf(stderr, args)
#else
#define eprintf(args...)
#endif
// ₳₦₲ɆⱠ₳₮ØⱤ312 𝕨𝕒𝕤 hêrê
using namespace std;

using num = int;
using idx_t = int;
string query(std::string B);
void solve(vector<string> words) {
  for (int i = 0; i < words.size(); ++i) {
    string s = query(words[i]);
    if (s == "ggggg")
      return;
  }
}
