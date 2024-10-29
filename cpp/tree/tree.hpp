#pragma once
#include "graph/edge.hpp"
#include "template/small_template.hpp"

// 根付き木(根=0)
template <class Cost = ll, class E = Edge<Cost>> class ListGraph {
  int n_;
  vector<vector<E>> adj;
  vector<int> parent; // 0の親は0

  void build_parent() {
    parent[0] = 0;
    stack<int> s;
    basic_string<bool> visited(n_, false);
    visited[0] = true;
    while (s.size()) {
      int node = s.top();
      s.pop();
      for (auto &&e : adj[node]) {
        if (!visited[e.to]) {
          visited[e.to] = true;
          parent[e.to] = node;
          s.emplace(e.to);
        }
      }
    }
  }

  // 最遠ノード O(N)
  pair<int, Cost> farthest_node(int from) const {
    basic_string<bool> visited(n_, false);
    stack<pair<int, Cost>> s;
    Cost max_cost = -1;
    int farthest = -1;
    s.emplace(from, 0);
    visited[from] = true;
    while (s.size()) {
      auto [node, d] = s.top();
      s.pop();
      if (max_cost < d) {
        max_cost = d;
        farthest = node;
      }
      for (auto &&e : adj[node]) {
        if (!visited[e.to]) {
          visited[e.to] = true;
          s.emplace(e.to, d + e.cost);
        }
      }
    }
    return {farthest, max_cost};
  }

public:
  ListGraph(vector<int> &from, vector<int> &to, vector<Cost> &cost)
      : n_(from.size() + 1), adj(n_), parent(n_) {
    assert(n_ == (int)to.size() + 1);
    assert(n_ == (int)cost.size() + 1);
    for (int i = 0; i < n_; i++) {
      assert(0 <= from[i]);
      assert(from[i] < n_);
      assert(0 <= to[i]);
      assert(to[i] < n_);
      adj[from[i]].emplace_back(from[i], to[i], cost[i]);
      adj[to[i]].emplace_back(to[i], from[i], cost[i]);
    }
    build_parent();
  }

  // 直径(from, to, cost) O(N)
  tuple<int, int, Cost> diameter() const {
    auto [f0, d0] = farthest_node(0);
    auto [f1, d1] = farthest_node(f0);
    return {f0, f1, d1};
  }

  // 経路 O(N)
  vector<int> path(int from, int to) const {
    stack<int> s;
    s.emplace(from);
    vector<int> path_parent(n_, -1);
    path_parent[from] = from;
    while (s.size()) {
      int node = s.top();
      if (node == to) {
        vector<int> path;
        for (int i = node; i != path_parent[i]; i = path_parent[i]) {
          path.emplace_back(i);
        }
        path.emplace_back(from);
        return path;
      }
      s.pop();
      for (auto &&e : adj[node]) {
        if (path_parent[e.to] == -1) {
          path_parent[e.to] = node;
          s.emplace(e.to);
        }
      }
    }
    return {}; // 到達しない
  }

  vector<E> &operator[](int i) const { return adj[i]; }

  template <class C_, class E_>
  friend ostream &operator<<(ostream &, const ListGraph<C_, E_> &);
};

template <class C_, class E_>
ostream &operator<<(ostream &os, const ListGraph<C_, E_> &graph) {
  os << "N = " << graph.n_ << '\n';
  for (const auto &ev : graph.adj) {
    for (const auto &e : ev) {
      os << e << '\n';
    }
  }
  return os;
}