#include "GeometryDefaultFloat.h"
vector<pll> hull(vector<pll> dots) { // n=1 => ans = {}
  sort(dots.begin(), dots.end());
  vector<pll> ans(1, dots[0]);
  for (int ct = 0; ct < 2; ++ct, reverse(all(dots)))
    for (int i = 1, t = (int)ans.size();
         i < (int)dots.size();
         ans.emplace_back(dots[i++]))
      while ((int)ans.size() > t &&
        ori(ans.end()[-2], ans.back(), dots[i]) <= 0)
        ans.pop_back(); // "<" for keeping collinear
  ans.pop_back();
  return ans;
}
