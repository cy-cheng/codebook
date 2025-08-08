#include "BoundedFlow.cpp"
// 最小割樹, 樹上兩點最小割 = 樹上兩點最小割
BoundedFlow Dinic;
int g[N]; 
void add_edge(int u, int v, int w); // TODO
void GomoryHu(int n) { // 0-base
  fill_n(g, n, 0);
  for (int i = 1; i < n; ++i) {
    Dinic.init(n);
    // build the graph
    add_edge(i, g[i], Dinic.maxflow(i, g[i]));
    for (int j = i + 1; j <= n; ++j)
      if (g[j] == g[i] && ~Dinic.dis[j])
        g[j] = i;
  }
}
