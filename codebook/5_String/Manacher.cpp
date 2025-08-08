#include "include/common.h"
int man[N]; // len: man[i] - 1
void manacher(string s) { // uses 2|s|+1
  string t;
  for (int i = 0; i < (int)s.size(); i++) {
    t.push_back('$');
    t.push_back(s[i]);
  }
  t.push_back('$');
  int mx = 1;
  for (int i = 0; i < (int)t.size(); i++) {
    man[i] = 1;
    man[i] = min(man[mx] + mx - i, man[2 * mx - i]);
    while (man[i] + i < (int)t.size() && i >= man[i] &&
      t[i + man[i]] == t[i - man[i]])
      man[i]++;
    if (i + man[i] > mx + man[mx]) mx = i;
  }
}
