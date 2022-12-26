#include "types.hpp"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << "Usage: " << argv[0] << " <file>" << endl;
    return 1;
  }
  string file = argv[1];
  fstream s(file, s.in);
  fstream outf(file + ".txt", s.out | s.trunc);
  Vs z;
  Vs ls2;
  Vs ls;
  if (!s.is_open()) {
    cout << "failed to open "
         << "1.angelator312" << '\n';
  } else {

    s.seekp(0, ios_base::beg);
    for (size_t i = 0;; i++) {
      string l;
      if (!getline(s, l)) {
        break;
      }
      ls.push_back(l);
    }
    for (size_t i = 0; i < ls.size(); i++) {
      for (size_t i2 = 0; i2 < ls[i].size(); i2++) {
        if (ls[i][i2] == '\\') {
          string si, si2;
          si2 = to_string(i2);
          si = to_string(i);
          z.push_back(si + "." + si2 + "=" + ls[i][i2 + 1]);
        }
      }
    }
    ls2.resize(ls.size());
    for (size_t i = 0; i < z.size(); i++) {
      string e = z[i];
      string d, d2;
      int it = e.find(".", 0);
      int ipr1, ipr2, ir = e.find("=", it);
      ipr1 = stoi(e.substr(0, it));
      ipr2 = stoi(e.substr(it + 1, ir));
      if (e.back() == '!') {
        d = "WARNING:";
      } else if (e.back() == '?') {
        d = "WHAAT?";
      } else if (e.back() == '$') {
        d = "Money,money,much money! YES!!";
      } else if (e.back() == '.') {
        d = "...";
      }
      d2 += ls[ipr1].substr(0, ipr2);
      d2 += d + "  ";
      d2 += ls[ipr1].substr(ipr2 + 2);
      ls2[ipr1] = d2;
    }
    for (size_t i = 0; i < ls2.size(); i++) {
      if (ls2[i].empty()) {
        ls2[i] = ls[i];
      }
    }
    for (size_t i = 0; i < ls2.size(); i++) {
      outf << ls2[i] << '\n';
    }
  }
  return 0;
}