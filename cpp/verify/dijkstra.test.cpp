#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"
#include "graph/dijkstra.hpp"

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int V, E, r;
  cin >> V >> E >> r;
  ListGraph<int> graph(V);
  for (int i = 0; i < E; ++i) {
    int s, t, d;
    cin >> s >> t >> d;
    graph.add_edge(s, t, d);
  }
  graph.dijkstra(r);
  for (int i = 0; i < V; ++i) {
    int dist = graph.get_dist(r, i);
    if (dist >= 2000000000) {
      cout << "INF\n";
    } else {
      cout << dist << '\n';
    }
  }
}