#pragma once
#include "array/doubling.hpp"
#include "graph/edge.hpp"

// 根付き木(根=0)
template <class Cost = ll, class E = Edge<Cost>> class Tree {
  int n_;
  vector<vector<E>> adj;
  vector<int> parent_;           // 0の親は0
  vector<int> depth_;            // 深さ(根からの辺の数)
  vector<int> cost_depth_;       // 深さ(コスト合計)
  vector<vector<int>> ancestor_; // 2**i回遡った祖先

  void build_parent() {
    stack<tuple<int, int, Cost>> s;
    basic_string<bool> visited(n_, false);
    visited[0] = true;
    parent_[0] = 0;
    depth_[0] = 0;
    cost_depth_[0] = 0;
    s.emplace(0, 0, 0);
    while (s.size()) {
      auto [node, d, dc] = s.top();
      s.pop();
      for (auto &&e : adj[node]) {
        if (!visited[e.to]) {
          visited[e.to] = true;
          parent_[e.to] = node;
          depth_[e.to] = d + 1;
          cost_depth_[e.to] = dc + e.cost;
          s.emplace(e.to, d + 1, dc + e.cost);
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
  Tree(vector<int> &from, vector<int> &to, vector<Cost> &cost)
      : n_(from.size() + 1), adj(n_), parent_(n_), depth_(n_), cost_depth_(n_) {
    assert(n_ == (int)to.size() + 1);
    assert(n_ == (int)cost.size() + 1);
    for (int i = 0; i < n_ - 1; i++) {
      assert(0 <= from[i]);
      assert(from[i] < n_);
      assert(0 <= to[i]);
      assert(to[i] < n_);
      adj[from[i]].emplace_back(from[i], to[i], cost[i]);
      adj[to[i]].emplace_back(to[i], from[i], cost[i]);
    }
    build_parent();
  }
  Tree(vector<int> &from, vector<int> &to)
      : n_(from.size() + 1), adj(n_), parent_(n_), depth_(n_), cost_depth_(n_) {
    assert(n_ == (int)to.size() + 1);
    for (int i = 0; i < n_ - 1; i++) {
      assert(0 <= from[i]);
      assert(from[i] < n_);
      assert(0 <= to[i]);
      assert(to[i] < n_);
      adj[from[i]].emplace_back(from[i], to[i]);
      adj[to[i]].emplace_back(to[i], from[i]);
    }
    build_parent();
  }
  // 引数parentは0が根でなくてもよい
  Tree(vector<int> &parent)
      : n_(parent.size()), adj(n_), parent_(n_), depth_(n_), cost_depth_(n_) {
    assert(n_ > 0);
    for (int i = 0; i < n_; i++) {
      if (i != parent[i] && 0 <= parent[i] && parent[i] < n_) {
        adj[parent[i]].emplace_back(parent[i], i);
        adj[i].emplace_back(i, parent[i]);
      }
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

  // ダブリングによる祖先構築 O(N log N)
  void build_ancestor() { ancestor_ = doubling(parent_, n_ - 1); }

  // i回遡った祖先 O(log N)
  int ancestor(int v, int i) const {
    int k = 0;
    for (int j = 1; j <= i; j <<= 1, k++) {
      if (i & j) {
        v = ancestor_[k][v];
      }
    }
    return v;
  }

  // LCA O(log N)
  int lowest_common_ancestor(int u, int v) const {
    assert(0 <= u);
    assert(u < n_);
    assert(0 <= v);
    assert(v < n_);
    int du = depth_[u];
    int dv = depth_[v];
    if (du > dv) {
      u = ancestor(u, du - dv);
      du = dv;
    } else if (du < dv) {
      v = ancestor(v, dv - du);
    }
    if (u == v) {
      return u;
    }
    for (int k = bit_width((unsigned)du); k >= 0; k--) {
      int nu = ancestor_[k][u];
      int nv = ancestor_[k][v];
      if (nu != nv) {
        u = nu;
        v = nv;
      }
    }
    return ancestor_[0][u];
  }

  // 距離 O(log N)
  Cost distance(int u, int v) const {
    assert(0 <= u);
    assert(u < n_);
    assert(0 <= v);
    assert(v < n_);
    return cost_depth_[u] + cost_depth_[v] -
           cost_depth_[lowest_common_ancestor(u, v)] * 2;
  }

  int depth(int v) const {
    assert(0 <= v);
    assert(v < n_);
    return depth_[v];
  }

  Cost cost_depth(int v) const {
    assert(0 <= v);
    assert(v < n_);
    return cost_depth_[v];
  }

  vector<E> &operator[](int i) { return adj[i]; }

  template <class C_, class E_>
  friend ostream &operator<<(ostream &, const Tree<C_, E_> &);
};

template <class C_, class E_>
ostream &operator<<(ostream &os, const Tree<C_, E_> &graph) {
  os << "N = " << graph.n_ << '\n';
  for (const auto &ev : graph.adj) {
    for (const auto &e : ev) {
      os << e << '\n';
    }
  }
  return os;
}