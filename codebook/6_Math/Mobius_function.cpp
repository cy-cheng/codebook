#include "include/common.h"
vector<int> mobius_up_to(int N) {
  vector<int> mu(N + 1, 1), prm;
  vector<bool> is_prm(N + 1, 1);
  mu[0] = 0; // place holder
  for (int i = 2; i <= N; ++i) {
    if (is_prm[i]) {
      prm.push_back(i);
      mu[i] = -1;
    }
    for (auto &p : prm) {
      if (i * p > N) break;
      is_prm[i * p] = 0;
      if (i % p == 0) {
        mu[i * p] = 0;
        break;
      } else mu[i * p] = -mu[i];
    }
  }
  return mu;
}
