---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/array/doubling.hpp
    title: cpp/array/doubling.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/graph/edge.hpp
    title: cpp/graph/edge.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/jump_on_tree.test.cpp
    title: cpp/verify/jump_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/lowest_common_ancestor.test.cpp
    title: cpp/verify/lowest_common_ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/tree_diameter.test.cpp
    title: cpp/verify/tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
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
    \n\n// \u6839\u4ED8\u304D\u6728(\u6839=0)\ntemplate <class Cost = ll, class E\
    \ = Edge<Cost>> class Tree {\n  int n_;\n  vector<vector<E>> adj;\n  vector<int>\
    \ parent_;           // 0\u306E\u89AA\u306F0\n  vector<int> depth_;          \
    \  // \u6DF1\u3055(\u6839\u304B\u3089\u306E\u8FBA\u306E\u6570)\n  vector<int>\
    \ cost_depth_;       // \u6DF1\u3055(\u30B3\u30B9\u30C8\u5408\u8A08)\n  vector<vector<int>>\
    \ ancestor_; // 2**i\u56DE\u9061\u3063\u305F\u7956\u5148\n\n  void build_parent()\
    \ {\n    stack<tuple<int, int, Cost>> s;\n    basic_string<bool> visited(n_, false);\n\
    \    visited[0] = true;\n    parent_[0] = 0;\n    depth_[0] = 0;\n    cost_depth_[0]\
    \ = 0;\n    s.emplace(0, 0, 0);\n    while (s.size()) {\n      auto [node, d,\
    \ dc] = s.top();\n      s.pop();\n      for (auto &&e : adj[node]) {\n       \
    \ if (!visited[e.to]) {\n          visited[e.to] = true;\n          parent_[e.to]\
    \ = node;\n          depth_[e.to] = d + 1;\n          cost_depth_[e.to] = dc +\
    \ e.cost;\n          s.emplace(e.to, d + 1, dc + e.cost);\n        }\n      }\n\
    \    }\n  }\n\n  // \u6700\u9060\u30CE\u30FC\u30C9 O(N)\n  pair<int, Cost> farthest_node(int\
    \ from) const {\n    basic_string<bool> visited(n_, false);\n    stack<pair<int,\
    \ Cost>> s;\n    Cost max_cost = -1;\n    int farthest = -1;\n    s.emplace(from,\
    \ 0);\n    visited[from] = true;\n    while (s.size()) {\n      auto [node, d]\
    \ = s.top();\n      s.pop();\n      if (max_cost < d) {\n        max_cost = d;\n\
    \        farthest = node;\n      }\n      for (auto &&e : adj[node]) {\n     \
    \   if (!visited[e.to]) {\n          visited[e.to] = true;\n          s.emplace(e.to,\
    \ d + e.cost);\n        }\n      }\n    }\n    return {farthest, max_cost};\n\
    \  }\n\npublic:\n  Tree(vector<int> &from, vector<int> &to, vector<Cost> &cost)\n\
    \      : n_(from.size() + 1), adj(n_), parent_(n_), depth_(n_), cost_depth_(n_)\
    \ {\n    assert(n_ == (int)to.size() + 1);\n    assert(n_ == (int)cost.size()\
    \ + 1);\n    for (int i = 0; i < n_ - 1; i++) {\n      assert(0 <= from[i]);\n\
    \      assert(from[i] < n_);\n      assert(0 <= to[i]);\n      assert(to[i] <\
    \ n_);\n      adj[from[i]].emplace_back(from[i], to[i], cost[i]);\n      adj[to[i]].emplace_back(to[i],\
    \ from[i], cost[i]);\n    }\n    build_parent();\n  }\n  Tree(vector<int> &from,\
    \ vector<int> &to)\n      : n_(from.size() + 1), adj(n_), parent_(n_), depth_(n_),\
    \ cost_depth_(n_) {\n    assert(n_ == (int)to.size() + 1);\n    for (int i = 0;\
    \ i < n_ - 1; i++) {\n      assert(0 <= from[i]);\n      assert(from[i] < n_);\n\
    \      assert(0 <= to[i]);\n      assert(to[i] < n_);\n      adj[from[i]].emplace_back(from[i],\
    \ to[i]);\n      adj[to[i]].emplace_back(to[i], from[i]);\n    }\n    build_parent();\n\
    \  }\n  // \u5F15\u6570parent\u306F0\u304C\u6839\u3067\u306A\u304F\u3066\u3082\
    \u3088\u3044\n  Tree(vector<int> &parent)\n      : n_(parent.size()), adj(n_),\
    \ parent_(n_), depth_(n_), cost_depth_(n_) {\n    assert(n_ > 0);\n    for (int\
    \ i = 0; i < n_; i++) {\n      if (i != parent[i] && 0 <= parent[i] && parent[i]\
    \ < n_) {\n        adj[parent[i]].emplace_back(parent[i], i);\n        adj[i].emplace_back(i,\
    \ parent[i]);\n      }\n    }\n    build_parent();\n  }\n\n  // \u76F4\u5F84(from,\
    \ to, cost) O(N)\n  tuple<int, int, Cost> diameter() const {\n    auto [f0, d0]\
    \ = farthest_node(0);\n    auto [f1, d1] = farthest_node(f0);\n    return {f0,\
    \ f1, d1};\n  }\n\n  // \u7D4C\u8DEF O(N)\n  vector<int> path(int from, int to)\
    \ const {\n    stack<int> s;\n    s.emplace(from);\n    vector<int> path_parent(n_,\
    \ -1);\n    path_parent[from] = from;\n    while (s.size()) {\n      int node\
    \ = s.top();\n      if (node == to) {\n        vector<int> path;\n        for\
    \ (int i = node; i != path_parent[i]; i = path_parent[i]) {\n          path.emplace_back(i);\n\
    \        }\n        path.emplace_back(from);\n        return path;\n      }\n\
    \      s.pop();\n      for (auto &&e : adj[node]) {\n        if (path_parent[e.to]\
    \ == -1) {\n          path_parent[e.to] = node;\n          s.emplace(e.to);\n\
    \        }\n      }\n    }\n    return {}; // \u5230\u9054\u3057\u306A\u3044\n\
    \  }\n\n  // \u30C0\u30D6\u30EA\u30F3\u30B0\u306B\u3088\u308B\u7956\u5148\u69CB\
    \u7BC9 O(N log N)\n  void build_ancestor() { ancestor_ = doubling(parent_, n_\
    \ - 1); }\n\n  // i\u56DE\u9061\u3063\u305F\u7956\u5148 O(log N)\n  int ancestor(int\
    \ v, int i) const {\n    int k = 0;\n    for (int j = 1; j <= i; j <<= 1, k++)\
    \ {\n      if (i & j) {\n        v = ancestor_[k][v];\n      }\n    }\n    return\
    \ v;\n  }\n\n  // LCA O(log N)\n  int lowest_common_ancestor(int u, int v) const\
    \ {\n    assert(0 <= u);\n    assert(u < n_);\n    assert(0 <= v);\n    assert(v\
    \ < n_);\n    int du = depth_[u];\n    int dv = depth_[v];\n    if (du > dv) {\n\
    \      u = ancestor(u, du - dv);\n      du = dv;\n    } else if (du < dv) {\n\
    \      v = ancestor(v, dv - du);\n    }\n    if (u == v) {\n      return u;\n\
    \    }\n    for (int k = bit_width((unsigned)du); k >= 0; k--) {\n      int nu\
    \ = ancestor_[k][u];\n      int nv = ancestor_[k][v];\n      if (nu != nv) {\n\
    \        u = nu;\n        v = nv;\n      }\n    }\n    return ancestor_[0][u];\n\
    \  }\n\n  // \u8DDD\u96E2 O(log N)\n  Cost distance(int u, int v) const {\n  \
    \  assert(0 <= u);\n    assert(u < n_);\n    assert(0 <= v);\n    assert(v < n_);\n\
    \    return cost_depth_[u] + cost_depth_[v] -\n           cost_depth_[lowest_common_ancestor(u,\
    \ v)] * 2;\n  }\n\n  int depth(int v) const {\n    assert(0 <= v);\n    assert(v\
    \ < n_);\n    return depth_[v];\n  }\n\n  Cost cost_depth(int v) const {\n   \
    \ assert(0 <= v);\n    assert(v < n_);\n    return cost_depth_[v];\n  }\n\n  vector<E>\
    \ &operator[](int i) const { return adj[i]; }\n\n  template <class C_, class E_>\n\
    \  friend ostream &operator<<(ostream &, const Tree<C_, E_> &);\n};\n\ntemplate\
    \ <class C_, class E_>\nostream &operator<<(ostream &os, const Tree<C_, E_> &graph)\
    \ {\n  os << \"N = \" << graph.n_ << '\\n';\n  for (const auto &ev : graph.adj)\
    \ {\n    for (const auto &e : ev) {\n      os << e << '\\n';\n    }\n  }\n  return\
    \ os;\n}"
  dependsOn:
  - cpp/array/doubling.hpp
  - cpp/template/small_template.hpp
  - cpp/graph/edge.hpp
  isVerificationFile: false
  path: cpp/tree/tree.hpp
  requiredBy: []
  timestamp: '2024-10-30 08:24:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/tree_diameter.test.cpp
  - cpp/verify/jump_on_tree.test.cpp
  - cpp/verify/lowest_common_ancestor.test.cpp
documentation_of: cpp/tree/tree.hpp
layout: document
redirect_from:
- /library/cpp/tree/tree.hpp
- /library/cpp/tree/tree.hpp.html
title: cpp/tree/tree.hpp
---
