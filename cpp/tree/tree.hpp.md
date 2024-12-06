---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp/array/doubling.hpp
    title: cpp/array/doubling.hpp
  - icon: ':question:'
    path: cpp/graph/edge.hpp
    title: cpp/graph/edge.hpp
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/full_tree_dp.test.cpp
    title: cpp/verify/full_tree_dp.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/jump_on_tree.test.cpp
    title: cpp/verify/jump_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/lowest_common_ancestor.test.cpp
    title: cpp/verify/lowest_common_ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/lowest_common_ancestor_2.test.cpp
    title: cpp/verify/lowest_common_ancestor_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/tree_diameter.test.cpp
    title: cpp/verify/tree_diameter.test.cpp
  - icon: ':x:'
    path: cpp/verify/tree_diameter_2.test.cpp
    title: cpp/verify/tree_diameter_2.test.cpp
  - icon: ':x:'
    path: cpp/verify/tree_height.test.cpp
    title: cpp/verify/tree_height.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u5168\u65B9\u4F4D\u6728DP"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: array/doubling.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"array/doubling.hpp\"\n#include \"graph/edge.hpp\"\
    \n\n// \u6839\u4ED8\u304D\u6728\ntemplate<class Cost = ll, class E = Edge<Cost>>\n\
    class Tree {\n  int n_, root_;\n  vector<vector<E>> adj;\n  // 0\u306E\u89AA\u306F\
    0, \u6DF1\u3055(\u6839\u304B\u3089\u306E\u8FBA\u306E\u6570/\u30B3\u30B9\u30C8\u5408\
    \u8A08)\n  vector<vector<int>> parent_, depth_, cost_depth_;\n  vector<vector<int>>\
    \ ancestor_; // 2**i\u56DE\u9061\u3063\u305F\u7956\u5148\n  vector<int> farthest_node_;\
    \    // \u6700\u9060\u70B9\n  vector<Cost> height_;          // \u9AD8\u3055(\u6700\
    \u9060\u70B9\u307E\u3067\u306E\u8DDD\u96E2)\n\n  // \u8FD4\u308A\u5024\uFF1A\u6700\
    \u9060\u30CE\u30FC\u30C9 O(N)\n  void build_depth(int from) {\n    if (farthest_node_[from]\
    \ != -1) {\n      return;\n    }\n    parent_[from] = vector<int>(n_);\n    depth_[from]\
    \ = vector<int>(n_);\n    cost_depth_[from] = vector<int>(n_);\n    parent_[from][from]\
    \ = from;\n    depth_[from][from] = 0;\n    cost_depth_[from][from] = 0;\n   \
    \ basic_string<bool> visited(n_, false);\n    stack<tuple<int, int, Cost>> s;\n\
    \    Cost max_cost = -1;\n    int farthest = -1;\n    s.emplace(from, 0, 0);\n\
    \    visited[from] = true;\n    while (s.size()) {\n      auto [node, d, dc] =\
    \ s.top();\n      s.pop();\n      if (max_cost < dc) {\n        max_cost = dc;\n\
    \        farthest = node;\n      }\n      for (auto &&e: adj[node]) {\n      \
    \  if (!visited[e.to]) {\n          visited[e.to] = true;\n          parent_[from][e.to]\
    \ = node;\n          depth_[from][e.to] = d + 1;\n          cost_depth_[from][e.to]\
    \ = dc + e.cost;\n          s.emplace(e.to, d + 1, dc + e.cost);\n        }\n\
    \      }\n    }\n    farthest_node_[from] = farthest;\n    height_[from] = max_cost;\n\
    \  }\n\npublic:\n  Tree(int root, vector<int> &from, vector<int> &to, vector<Cost>\
    \ &cost):\n    n_(from.size() + 1), root_(root), adj(n_), parent_(n_), depth_(n_),\
    \ cost_depth_(n_),\n    farthest_node_(n_, -1), height_(n_, -1) {\n    assert(n_\
    \ == (int)to.size() + 1);\n    assert(n_ == (int)cost.size() + 1);\n    for (int\
    \ i = 0; i < n_ - 1; i++) {\n      assert(0 <= from[i]);\n      assert(from[i]\
    \ < n_);\n      assert(0 <= to[i]);\n      assert(to[i] < n_);\n      adj[from[i]].emplace_back(from[i],\
    \ to[i], cost[i]);\n      adj[to[i]].emplace_back(to[i], from[i], cost[i]);\n\
    \    }\n    build_depth(root_);\n  }\n  Tree(int root, vector<int> &from, vector<int>\
    \ &to):\n    n_(from.size() + 1), root_(root), adj(n_), parent_(n_), depth_(n_),\
    \ cost_depth_(n_),\n    farthest_node_(n_, -1), height_(n_, -1) {\n    assert(n_\
    \ == (int)to.size() + 1);\n    for (int i = 0; i < n_ - 1; i++) {\n      assert(0\
    \ <= from[i]);\n      assert(from[i] < n_);\n      assert(0 <= to[i]);\n     \
    \ assert(to[i] < n_);\n      adj[from[i]].emplace_back(from[i], to[i]);\n    \
    \  adj[to[i]].emplace_back(to[i], from[i]);\n    }\n    build_depth(root_);\n\
    \  }\n  Tree(int root, vector<int> &parent):\n    n_(parent.size()), root_(root),\
    \ adj(n_), parent_(n_), depth_(n_), cost_depth_(n_),\n    farthest_node_(n_, -1),\
    \ height_(n_, -1) {\n    assert(n_ > 0);\n    for (int i = 0; i < n_; i++) {\n\
    \      if (i != parent[i] && 0 <= parent[i] && parent[i] < n_) {\n        adj[parent[i]].emplace_back(parent[i],\
    \ i);\n        adj[i].emplace_back(i, parent[i]);\n      }\n    }\n    build_depth(root_);\n\
    \  }\n  Tree(vector<int> &parent):\n    n_(parent.size()), adj(n_), parent_(n_),\
    \ depth_(n_), cost_depth_(n_), farthest_node_(n_, -1),\n    height_(n_, -1) {\n\
    \    assert(n_ > 0);\n    int r = -1;\n    for (int i = 0; i < n_; i++) {\n  \
    \    if (parent[i] == i || parent[i] < 0) {\n        r = i;\n      }\n    }\n\
    \    root_ = r;\n    assert(r >= 0);\n    for (int i = 0; i < n_; i++) {\n   \
    \   if (i != parent[i] && 0 <= parent[i] && parent[i] < n_) {\n        adj[parent[i]].emplace_back(parent[i],\
    \ i);\n        adj[i].emplace_back(i, parent[i]);\n      }\n    }\n    build_depth(root_);\n\
    \  }\n\n  vector<E> &operator[](int i) { return adj[i]; }\n\n  template<class\
    \ C_, class E_>\n  friend ostream &operator<<(ostream &, const Tree<C_, E_> &);\n\
    \n  // \u76F4\u5F84(from, to, cost) O(N)\n  tuple<int, int, Cost> diameter() {\n\
    \    build_depth(0);\n    int f0 = farthest_node_[0];\n    build_depth(f0);\n\
    \    return {f0, farthest_node_[f0], height_[f0]};\n  }\n\n  // v\u304B\u3089\u6700\
    \u9060\u70B9\u307E\u3067\u306E\u8DDD\u96E2 O(N)\n  vector<Cost> height() {\n \
    \   auto [f0, f1, d] = diameter();\n    build_depth(f1);\n    vector<Cost> h(n_);\n\
    \    for (int i = 0; i < n_; i++) {\n      h[i] = max(cost_depth_[f0][i], cost_depth_[f1][i]);\n\
    \    }\n    return h;\n  }\n\n  // \u7D4C\u8DEF O(N)\n  vector<int> path(int from,\
    \ int to) const {\n    stack<int> s;\n    s.emplace(from);\n    vector<int> path_parent(n_,\
    \ -1);\n    path_parent[from] = from;\n    while (s.size()) {\n      int node\
    \ = s.top();\n      if (node == to) {\n        vector<int> path;\n        for\
    \ (int i = node; i != path_parent[i]; i = path_parent[i]) {\n          path.emplace_back(i);\n\
    \        }\n        path.emplace_back(from);\n        return path;\n      }\n\
    \      s.pop();\n      for (auto &&e: adj[node]) {\n        if (path_parent[e.to]\
    \ == -1) {\n          path_parent[e.to] = node;\n          s.emplace(e.to);\n\
    \        }\n      }\n    }\n    return {}; // \u5230\u9054\u3057\u306A\u3044\n\
    \  }\n\n  // \u30C0\u30D6\u30EA\u30F3\u30B0\u306B\u3088\u308B\u7956\u5148\u69CB\
    \u7BC9 O(N log N)\n  void build_ancestor() { ancestor_ = doubling(parent_[root_],\
    \ n_ - 1); }\n\n  // i\u56DE\u9061\u3063\u305F\u7956\u5148 O(log N)\n  int ancestor(int\
    \ v, int i) const {\n    int k = 0;\n    for (int j = 1; j <= i; j <<= 1, k++)\
    \ {\n      if (i & j) {\n        v = ancestor_[k][v];\n      }\n    }\n    return\
    \ v;\n  }\n\n  // LCA O(log N)\n  int lowest_common_ancestor(int u, int v) const\
    \ {\n    int du = depth_[root_][u];\n    int dv = depth_[root_][v];\n    if (du\
    \ > dv) {\n      u = ancestor(u, du - dv);\n      du = dv;\n    } else if (du\
    \ < dv) {\n      v = ancestor(v, dv - du);\n    }\n    if (u == v) {\n      return\
    \ u;\n    }\n    for (int k = bit_width((unsigned)du); k >= 0; k--) {\n      int\
    \ nu = ancestor_[k][u];\n      int nv = ancestor_[k][v];\n      if (nu != nv)\
    \ {\n        u = nu;\n        v = nv;\n      }\n    }\n    return ancestor_[0][u];\n\
    \  }\n\n  // \u8DDD\u96E2 O(log N)\n  Cost distance(int u, int v) const {\n  \
    \  assert(0 <= u);\n    assert(u < n_);\n    assert(0 <= v);\n    assert(v < n_);\n\
    \    return cost_depth_[root_][u] + cost_depth_[root_][v]\n         - cost_depth_[root_][lowest_common_ancestor(u,\
    \ v)] * 2;\n  }\n\n  int depth(int v) const { return depth_[root_][v]; }\n\n \
    \ Cost cost_depth(int v) const { return cost_depth_[root_][v]; }\n\n  /**\n  \
    \ * @brief \u5168\u65B9\u4F4D\u6728DP\n   * @tparam M \u30E2\u30CE\u30A4\u30C9\
    \n   * @tparam F (M, M) -> M\n   * @tparam G M -> M\n   * @param e \u5358\u4F4D\
    \u5143\n   * @param op \u30E2\u30CE\u30A4\u30C9\u306E\u4E8C\u9805\u6F14\u7B97\n\
    \   * @param sum_up \u3059\u3079\u3066\u306E\u5B50\u306E\u7DCF\u7A4D\u304B\u3089\
    \u6728\u306EDP\u5024\u3092\u6C42\u3081\u308B\n   * @return vector<M> \n   */\n\
    \  template<class M, class F, class G>\n  vector<M> full_tree_dp(M e, F op, G\
    \ sum_up) {\n    vector<M> dp(n_), dp_full(n_);\n    vector<vector<M>> dp_sub(n_),\
    \ dp_sub_left(n_), dp_sub_right(n_);\n    for (int i = 0; i < n_; i++) {\n   \
    \   dp_sub[i].reserve(adj[i].size());\n      dp_sub_left[i].reserve(adj[i].size());\n\
    \      dp_sub_right[i].reserve(adj[i].size());\n    }\n    auto dfs = [&](auto\
    \ &Self, int node, int par) -> void {\n      dp[node] = e;\n      for (auto &&edge:\
    \ adj[node]) {\n        if (edge.to != par) {\n          Self(Self, edge.to, node);\n\
    \          dp[node] = op(dp[node], dp[edge.to]);\n          dp_sub[node].emplace_back(dp[edge.to]);\n\
    \        }\n      }\n      dp[node] = sum_up(dp[node]);\n      dp_sub_left[node].emplace_back(e);\n\
    \      dp_sub_right[node].emplace_back(e);\n      for (int i = 0; i < (int)adj[node].size();\
    \ i++) {\n        if (adj[node][i].to != par) {\n          dp_sub_left[node].emplace_back(op(dp_sub_left[node].back(),\
    \ dp[adj[node][i].to]));\n        }\n      }\n      for (int i = (int)adj[node].size()\
    \ - 1; i >= 0; i--) {\n        if (adj[node][i].to != par) {\n          dp_sub_right[node].emplace_back(op(dp_sub_right[node].back(),\
    \ dp[adj[node][i].to]));\n        }\n      }\n    };\n    dfs(dfs, root_, -1);\n\
    \n    queue<tuple<int, int, M>> q;\n    q.emplace(root_, -1, e);\n    dp_full[root_]\
    \ = dp[root_];\n    while (q.size()) {\n      auto [node, par, v] = q.front();\n\
    \      q.pop();\n      if (node != root_) {\n        dp_full[node] = sum_up(op(v,\
    \ dp_sub_left[node].back()));\n      }\n      int i = 0;\n      for (auto &&edge:\
    \ adj[node]) {\n        if (edge.to != par) {\n          q.emplace(edge.to,\n\
    \                    node,\n                    sum_up(op(op(v, dp_sub_left[node][i]),\n\
    \                              dp_sub_right[node][dp_sub_right[node].size() -\
    \ i - 2])));\n          i++;\n        }\n      }\n    }\n    return dp_full;\n\
    \  }\n};\n\ntemplate<class C_, class E_>\nostream &operator<<(ostream &os, const\
    \ Tree<C_, E_> &graph) {\n  os << \"N = \" << graph.n_ << '\\n';\n  for (const\
    \ auto &ev: graph.adj) {\n    for (const auto &e: ev) {\n      os << e << '\\\
    n';\n    }\n  }\n  return os;\n}"
  dependsOn:
  - cpp/array/doubling.hpp
  - cpp/template/small_template.hpp
  - cpp/graph/edge.hpp
  isVerificationFile: false
  path: cpp/tree/tree.hpp
  requiredBy: []
  timestamp: '2024-12-07 00:34:35+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - cpp/verify/tree_diameter_2.test.cpp
  - cpp/verify/tree_diameter.test.cpp
  - cpp/verify/jump_on_tree.test.cpp
  - cpp/verify/tree_height.test.cpp
  - cpp/verify/full_tree_dp.test.cpp
  - cpp/verify/lowest_common_ancestor.test.cpp
  - cpp/verify/lowest_common_ancestor_2.test.cpp
documentation_of: cpp/tree/tree.hpp
layout: document
redirect_from:
- /library/cpp/tree/tree.hpp
- /library/cpp/tree/tree.hpp.html
title: "\u5168\u65B9\u4F4D\u6728DP"
---
