---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/graph/edge.hpp
    title: cpp/graph/edge.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/graph/graph_list.hpp
    title: "\u30B0\u30E9\u30D5 (\u96A3\u63A5\u30EA\u30B9\u30C8\u5F62\u5F0F)"
  - icon: ':heavy_check_mark:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/prim.test.cpp
    title: cpp/verify/prim.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://algo-logic.info/prim-mst/
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
  code: "#pragma once\n#include \"graph/graph_list.hpp\"\n#include \"template/small_template.hpp\"\
    \n\n/**\n * \u30D7\u30EA\u30E0\u6CD5\n * \u7121\u5411\u30B0\u30E9\u30D5\u306E\u6700\
    \u5C0F\u5168\u57DF\u68EE O((E+V)logV)\n * \u8FBA\u306E\u30B3\u30B9\u30C8\u304C\
    \u5168\u30660\u4EE5\u4E0A\n * \u8FD4\u308A\u5024\uFF1A\u30B3\u30B9\u30C8\u306E\
    \u7DCF\u548C\n * https://algo-logic.info/prim-mst/\n */\ntemplate <class Cost,\
    \ class E> Cost ListGraph<Cost, E>::prim() {\n  Cost mst_dist = 0;\n  using P\
    \ = pair<Cost, int>;\n  vector<Cost> dist(n_, ListGraph<Cost>::UNREACHABLE);\n\
    \  vector<bool> used(n_, false);\n  auto span = [&](int start_node) {\n    dist[start_node]\
    \ = 0;\n    priority_queue<P, vector<P>, greater<P>> pq;\n    pq.emplace(0, start_node);\n\
    \    while (!pq.empty()) {\n      P p = pq.top();\n      pq.pop();\n      Cost\
    \ v = p.second;\n      if (used[v] || dist[v] < p.first) {\n        continue;\n\
    \      }\n      mst_dist += dist[v];\n      used[v] = true;\n      for (const\
    \ auto &e : adj[v]) {\n        if (!used[e.to] && e.cost < dist[e.to]) {\n   \
    \       dist[e.to] = e.cost;\n          pq.emplace(dist[e.to], e.to);\n      \
    \  }\n      }\n    }\n  };\n  for (int i = 0; i < n_; ++i) {\n    if (!used[i])\
    \ {\n      span(i);\n    }\n  }\n  return mst_dist;\n}"
  dependsOn:
  - cpp/graph/graph_list.hpp
  - cpp/graph/edge.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/graph/prim.hpp
  requiredBy: []
  timestamp: '2024-11-03 09:29:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/prim.test.cpp
documentation_of: cpp/graph/prim.hpp
layout: document
redirect_from:
- /library/cpp/graph/prim.hpp
- /library/cpp/graph/prim.hpp.html
title: cpp/graph/prim.hpp
---
