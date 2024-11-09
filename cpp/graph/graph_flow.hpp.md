---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/graph/edge_flow.hpp
    title: cpp/graph/edge_flow.hpp
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/max_flow.test.cpp
    title: cpp/verify/max_flow.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/min_cost_flow.test.cpp
    title: cpp/verify/min_cost_flow.test.cpp
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/edge_flow.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"graph/edge_flow.hpp\"\n\n// \u30B0\u30E9\u30D5(\u96A3\
    \u63A5\u30EA\u30B9\u30C8)\ntemplate <class Cost = ll, class E = FlowEdge<Cost>>\
    \ class FlowGraph {\n  int n_, m_;\n  vector<vector<E>> adj;\n  vector<int> level,\
    \ iter;\n\n  void bfs(int s) {\n    level = vector<int>(n_, -1);\n    level[s]\
    \ = 0;\n    queue<int> q;\n    q.emplace(s);\n    while (q.size()) {\n      int\
    \ v = q.front();\n      q.pop();\n      for (auto &&e : adj[v]) {\n        if\
    \ (e.cap > 0 && level[e.to] == -1) {\n          level[e.to] = level[v] + 1;\n\
    \          q.emplace(e.to);\n        }\n      }\n    }\n  }\n  Cost dfs(int v,\
    \ int t, Cost f) {\n    if (v == t) {\n      return f;\n    }\n    int sz_out\
    \ = adj[v].size();\n    for (int i = iter[v]; i < sz_out; i++) {\n      iter[v]\
    \ = i;\n      auto &e = adj[v][i];\n      if (e.cap == 0 || level[v] >= level[e.to])\
    \ {\n        continue;\n      }\n      Cost d = dfs(e.to, t, min(f, e.cap));\n\
    \      if (d == 0) {\n        continue;\n      }\n      e.cap -= d;\n      adj[e.to][e.rev].cap\
    \ += d;\n      return d;\n    }\n    return 0;\n  }\n  tuple<vector<Cost>, vector<int>,\
    \ vector<int>> bellman_ford(int s) {\n    vector<Cost> dist(n_, F_MAX);\n    vector<int>\
    \ pv(n_, 0), pe(n_, 0);\n    dist[s] = 0;\n    while (true) {\n      bool update\
    \ = false;\n      for (int v = 0; v < n_; v++) {\n        if (dist[v] == F_MAX)\
    \ {\n          continue;\n        }\n        for (int i = 0; i < (int)adj[v].size();\
    \ i++) {\n          auto &e = adj[v][i];\n          if (e.cap > 0 && dist[e.to]\
    \ > dist[v] + e.cost) {\n            dist[e.to] = dist[v] + e.cost;\n        \
    \    update = true;\n            pv[e.to] = v;\n            pe[e.to] = i;\n  \
    \        }\n        }\n      }\n      if (!update) {\n        break;\n      }\n\
    \    }\n    return {dist, pv, pe};\n  }\n\npublic:\n  static const Cost F_MAX;\n\
    \  // \u9802\u70B9\u6570 0\n  FlowGraph() : n_(0), m_(0), adj(0) {}\n  // \u9802\
    \u70B9\u6570 n\n  FlowGraph(int n) : n_(n), m_(0), adj(n) {}\n\n  vector<E> &operator[](int\
    \ i) { return adj[i]; }\n\n  void add_node() {\n    n_++;\n    adj.emplace_back();\n\
    \    level.emplace_back();\n  }\n  void add_edge_max_flow(int from, int to, Cost\
    \ cap) {\n    adj[from].emplace_back(from, to, (int)adj[to].size(), cap);\n  \
    \  adj[to].emplace_back(to, from, (int)adj[from].size() - 1, 0);\n    m_++;\n\
    \  }\n  void add_edge_min_cost_flow(int from, int to, Cost cap, Cost cost) {\n\
    \    adj[from].emplace_back(from, to, (int)adj[to].size(), cap, cost);\n    adj[to].emplace_back(to,\
    \ from, (int)adj[from].size() - 1, 0, -cost);\n    m_++;\n  }\n\n  // \u6700\u5927\
    \u6D41(Dinic)\n  Cost max_flow(int source, int sink) {\n    Cost flow = 0;\n \
    \   while (true) {\n      bfs(source);\n      if (level[sink] == -1) {\n     \
    \   return flow;\n      }\n      iter = vector<int>(n_, 0);\n      Cost current_flow\
    \ = dfs(source, sink, F_MAX);\n      while (current_flow > 0) {\n        flow\
    \ += current_flow;\n        current_flow = dfs(source, sink, F_MAX);\n      }\n\
    \    }\n  }\n\n  // \u6700\u5C0F\u8CBB\u7528\u6D41 O(FVE)\n  Cost min_cost_flow(int\
    \ s, int t, int f) {\n    Cost result = 0;\n    while (f > 0) {\n      auto [dist,\
    \ pv, pe] = bellman_ford(s);\n      if (dist[t] == F_MAX) {\n        return -1;\n\
    \      }\n      Cost flow = f;\n      int v = t;\n      while (v != s) {\n   \
    \     flow = min(flow, adj[pv[v]][pe[v]].cap);\n        v = pv[v];\n      }\n\
    \      result += flow * dist[t];\n      f -= flow;\n      v = t;\n      while\
    \ (v != s) {\n        adj[pv[v]][pe[v]].cap -= flow;\n        adj[v][adj[pv[v]][pe[v]].rev].cap\
    \ += flow;\n        v = pv[v];\n      }\n    }\n    return result;\n  }\n\n  template\
    \ <class C_, class E_>\n  friend ostream &operator<<(ostream &, const FlowGraph<C_,\
    \ E_> &);\n};\n\ntemplate <class Cost, class E>\nconst Cost FlowGraph<Cost, E>::F_MAX\
    \ = numeric_limits<Cost>::max() >> 2;\n\ntemplate <class C_, class E_>\nostream\
    \ &operator<<(ostream &os, const FlowGraph<C_, E_> &graph) {\n  os << \"N = \"\
    \ << graph.n_ << \", M = \" << graph.m_ << '\\n';\n  for (const auto &ev : graph.adj)\
    \ {\n    for (const auto &e : ev) {\n      os << e << '\\n';\n    }\n  }\n  return\
    \ os;\n}"
  dependsOn:
  - cpp/graph/edge_flow.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/graph/graph_flow.hpp
  requiredBy: []
  timestamp: '2024-11-10 02:02:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/max_flow.test.cpp
  - cpp/verify/min_cost_flow.test.cpp
documentation_of: cpp/graph/graph_flow.hpp
layout: document
redirect_from:
- /library/cpp/graph/graph_flow.hpp
- /library/cpp/graph/graph_flow.hpp.html
title: cpp/graph/graph_flow.hpp
---
