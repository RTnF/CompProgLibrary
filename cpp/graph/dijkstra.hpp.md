---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/graph/graph_list.hpp
    title: cpp/graph/graph_list.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/template/small_template.hpp
    title: cpp/template/small_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/dijkstra.test.cpp
    title: cpp/verify/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/dijkstra2.test.cpp
    title: cpp/verify/dijkstra2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://algo-logic.info/dijkstra/
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/graph_list.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"graph/graph_list.hpp\"\n\n/**\n * \u30C0\u30A4\u30AF\
    \u30B9\u30C8\u30E9\u6CD5\n * \u6709\u5411\u30B0\u30E9\u30D5\u306E\u5358\u4E00\u59CB\
    \u70B9\u6700\u77ED\u7D4C\u8DEF O((E+V)logV)\n * \u8FBA\u306E\u30B3\u30B9\u30C8\
    \u304C\u5168\u30660\u4EE5\u4E0A\n * \u5230\u9054\u4E0D\u80FD\uFF1Amax\n * https://algo-logic.info/dijkstra/\n\
    \ */\ntemplate <class Cost, class E>\nvoid ListGraph<Cost, E>::dijkstra(int start_node)\
    \ {\n  if (shortest_path_dist.count(start_node)) {\n    return;\n  }\n  using\
    \ P = pair<Cost, int>;\n  vector<Cost> dist(n, ListGraph::UNREACHABLE);\n  vector<int>\
    \ parent(n, -1);\n  dist[start_node] = 0;\n  priority_queue<P, vector<P>, greater<P>>\
    \ pq;\n  pq.emplace(0, start_node);\n  while (!pq.empty()) {\n    P p = pq.top();\n\
    \    pq.pop();\n    Cost v = p.second;\n    if (dist[v] < p.first) {\n      continue;\n\
    \    }\n    for (const auto &e : adj[v]) {\n      if (dist[v] + e.cost < dist[e.to])\
    \ {\n        dist[e.to] = dist[v] + e.cost;\n        parent[e.to] = v;\n     \
    \   pq.emplace(dist[e.to], e.to);\n      }\n    }\n  }\n  shortest_path_dist[start_node]\
    \ = std::move(dist);\n  shortest_path_parent[start_node] = std::move(parent);\n\
    }"
  dependsOn:
  - cpp/graph/graph_list.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2024-09-29 16:45:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/dijkstra.test.cpp
  - cpp/verify/dijkstra2.test.cpp
documentation_of: cpp/graph/dijkstra.hpp
layout: document
redirect_from:
- /library/cpp/graph/dijkstra.hpp
- /library/cpp/graph/dijkstra.hpp.html
title: cpp/graph/dijkstra.hpp
---
