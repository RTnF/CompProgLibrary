---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/graph/edge.hpp
    title: cpp/graph/edge.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/edge.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"graph/edge.hpp\"\n#include \"template/small_template.hpp\"\
    \n\n// \u6839\u4ED8\u304D\u6728(\u6839=0)\ntemplate <class Cost = ll, class E\
    \ = Edge<Cost>> class ListGraph {\n  int n_;\n  vector<vector<E>> adj;\n  vector<int>\
    \ parent; // 0\u306E\u89AA\u306F0\n\n  void build_parent() {\n    parent[0] =\
    \ 0;\n    stack<int> s;\n    basic_string<bool> visited(n_, false);\n    visited[0]\
    \ = true;\n    while (s.size()) {\n      int node = s.top();\n      s.pop();\n\
    \      for (auto &&e : adj[node]) {\n        if (!visited[e.to]) {\n         \
    \ visited[e.to] = true;\n          parent[e.to] = node;\n          s.emplace(e.to);\n\
    \        }\n      }\n    }\n  }\n\n  // \u6700\u9060\u30CE\u30FC\u30C9 O(N)\n\
    \  pair<int, Cost> farthest_node(int from) const {\n    basic_string<bool> visited(n_,\
    \ false);\n    stack<pair<int, Cost>> s;\n    Cost max_cost = -1;\n    int farthest\
    \ = -1;\n    s.emplace(from, 0);\n    visited[from] = true;\n    while (s.size())\
    \ {\n      auto [node, d] = s.top();\n      s.pop();\n      if (max_cost < d)\
    \ {\n        max_cost = d;\n        farthest = node;\n      }\n      for (auto\
    \ &&e : adj[node]) {\n        if (!visited[e.to]) {\n          visited[e.to] =\
    \ true;\n          s.emplace(e.to, d + e.cost);\n        }\n      }\n    }\n \
    \   return {farthest, max_cost};\n  }\n\npublic:\n  ListGraph(vector<int> &from,\
    \ vector<int> &to, vector<Cost> &cost)\n      : n_(from.size() + 1), adj(n_),\
    \ parent(n_) {\n    assert(n_ == (int)to.size() + 1);\n    assert(n_ == (int)cost.size()\
    \ + 1);\n    for (int i = 0; i < n_; i++) {\n      assert(0 <= from[i]);\n   \
    \   assert(from[i] < n_);\n      assert(0 <= to[i]);\n      assert(to[i] < n_);\n\
    \      adj[from[i]].emplace_back(from[i], to[i], cost[i]);\n      adj[to[i]].emplace_back(to[i],\
    \ from[i], cost[i]);\n    }\n    build_parent();\n  }\n\n  // \u76F4\u5F84(from,\
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
    \  }\n\n  vector<E> &operator[](int i) const { return adj[i]; }\n\n  template\
    \ <class C_, class E_>\n  friend ostream &operator<<(ostream &, const ListGraph<C_,\
    \ E_> &);\n};\n\ntemplate <class C_, class E_>\nostream &operator<<(ostream &os,\
    \ const ListGraph<C_, E_> &graph) {\n  os << \"N = \" << graph.n_ << '\\n';\n\
    \  for (const auto &ev : graph.adj) {\n    for (const auto &e : ev) {\n      os\
    \ << e << '\\n';\n    }\n  }\n  return os;\n}"
  dependsOn:
  - cpp/graph/edge.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/tree/tree.hpp
  requiredBy: []
  timestamp: '2024-10-29 23:42:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/tree_diameter.test.cpp
documentation_of: cpp/tree/tree.hpp
layout: document
redirect_from:
- /library/cpp/tree/tree.hpp
- /library/cpp/tree/tree.hpp.html
title: cpp/tree/tree.hpp
---
