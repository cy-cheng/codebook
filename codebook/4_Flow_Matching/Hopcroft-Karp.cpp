#include "include/common.h"
struct HopcroftKarp { // 0-based, return btoa to get matching, O(E sqrt(V)) bipartite graph matching
  bool dfs(int a, int L, vector<vector<int>> &g,
    vector<int> &btoa, vector<int> &A,
    vector<int> &B) {
    if (A[a] != L) return 0;
    A[a] = -1;
    for (int b : g[a])
      if (B[b] == L + 1) {
        B[b] = 0;
        if (btoa[b] == -1 ||
          dfs(btoa[b], L + 1, g, btoa, A, B))
          return btoa[b] = a, 1;
      }
    return 0;
  }
  int solve(vector<vector<int>> &g, int m) {
    int res = 0;
    vector<int> btoa(m, -1), A(g.size()),
      B(btoa.size()), cur, next;
    for (;;) {
      fill(all(A), 0), fill(all(B), 0);
      cur.clear();
      for (int a : btoa)
        if (a != -1) A[a] = -1;
      for (int a = 0; a < (int)g.size(); a++)
        if (A[a] == 0) cur.push_back(a);
      for (int lay = 1;; lay++) {
        bool islast = 0;
        next.clear();
        for (int a : cur)
          for (int b : g[a]) {
            if (btoa[b] == -1) {
              B[b] = lay;
              islast = 1;
            } else if (btoa[b] != a && !B[b]) {
              B[b] = lay;
              next.push_back(btoa[b]);
            }
          }
        if (islast) break;
        if (next.empty()) return res;
        for (int a : next) A[a] = lay;
        cur.swap(next);
      }
      for (int a = 0; a < (int)g.size(); a++)
        res += dfs(a, 0, g, btoa, A, B);
    }
    return res;
    // or btoa
  }
};
