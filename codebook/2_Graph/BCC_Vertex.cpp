#include "include/common.h"
struct vertex_cc {
  struct edge {
    int to, nt;
  } e[M << 1];
  int hd[N], tot = 1;

  void add(int u, int v) { 
    e[++tot] = edge{v, hd[u]}, hd[u] = tot; }
  void uadd(int u, int v) { add(u, v), add(v, u); }

  int ans, top, cnt, ord, root;
  int dfn[N], low[N], sta[N];
  bool cut[N];
  vector<int> dcc[N];

  void tarjan(int u) {
    dfn[u] = low[u] = ++ord, sta[++top] = u;
    if (u == root && hd[u] == 0) {
      dcc[++cnt].push_back(u);
      return;
    }
    int f = 0;
    for (int i = hd[u]; i; i = e[i].nt) {
      int v = e[i].to;
      if (!dfn[v]) {
        tarjan(v);
        low[u] = min(low[u], low[v]);
        if (low[v] >= dfn[u]) {
          if (++f > 1 || u != root) cut[u] = true;
          cnt++;
          do dcc[cnt].push_back(sta[top--]);
          while (sta[top + 1] != v);
          dcc[cnt].push_back(u);
        }
      } else low[u] = min(low[u], dfn[v]);
    }
  }
  int solve(int L, int R) { // vertex index range [L, R)
    for (int i = L; i < R; ++i) dfn[i] = 0;
    for (int i = L; i < R; ++i)
      if (!dfn[i]) { root = i; tarjan(i); }
    return cnt;
  } // answer in dcc, BCCs are 1-based
};
