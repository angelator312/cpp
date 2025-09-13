#include <iostream>
#include <vector>
using namespace std;

const int S_MAX_SIZE = 1e5 + 1;
const int FAVOURITE_WORD_MAX_SIZE = 1e2 + 1;

int dp[S_MAX_SIZE];
int endOfFavouriteWords[S_MAX_SIZE];
bool isEndOfFavouriteWord[S_MAX_SIZE];

string s, favouriteWord;
int sSize, favouriteWordSize;

inline void Read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> s >> favouriteWord;
}

inline void Init() {
  sSize = s.size();
  favouriteWordSize = favouriteWord.size();

  int loc = 0;

  for (int i = 0; i <= sSize - favouriteWordSize; ++i)
    isEndOfFavouriteWord[i + favouriteWordSize - 1] =
        s.substr(i, favouriteWordSize) == favouriteWord;
}
// otgovor,words
inline pair<int, vector<int>> f(int i, int j) {
  if (j < 0)
    return {0, {}};
  pair<int, vector<int>> out = f(i, j - 1);
  // is adding new
  if (isEndOfFavouriteWord[j]) {
    int k = out.second.size();
    while (k > 0 && j - out.second[k - 1] + 1 < favouriteWordSize)
      --k;
    out.first += k;
    // cerr<<"add j"<<j<<endl;
    out.second.push_back(j);
  }
  return out;
}

int main() {
  Read();
  Init();
  /*
      for(int i=0;i<sSize;++i)
          cerr<<isEndOfFavouriteWord[i];
      cerr<<endl;
  */
  int q;
  cin >> q;
  for (int i = 0, a, b; i < q; ++i) {
    cin >> a >> b;
    --a;
    --b;
    cout << f(a, b).first << endl;
  }

  return 0;
}
