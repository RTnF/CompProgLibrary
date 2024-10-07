---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/graph/graph_matrix.hpp
    title: cpp/graph/graph_matrix.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/template/small_template.hpp
    title: cpp/template/small_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/warshall_floyd.test.cpp
    title: cpp/verify/warshall_floyd.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://algo-logic.info/warshall-floyd/
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/graph_matrix.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"graph/graph_matrix.hpp\"\n#include \"template/small_template.hpp\"\
    \n\n/**\n * \u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5\n * \u6709\
    \u5411\u30B0\u30E9\u30D5\u306E\u5168\u70B9\u5BFE\u6700\u77ED\u7D4C\u8DEF O(V^3)\n\
    \ * \u5230\u9054\u4E0D\u80FD\uFF1Amax\n * https://algo-logic.info/warshall-floyd/\n\
    \ */\ntemplate <class Cost> void MatrixGraph<Cost>::warshall_floyd() {\n  if (shortest_path_dist.size())\
    \ {\n    return;\n  }\n  shortest_path_dist = mat;\n  shortest_path_parent = vector<vector<int>>(n,\
    \ vector<int>(n, -1));\n  for (int i = 0; i < n; ++i) {\n    shortest_path_parent[i][i]\
    \ = i;\n  }\n  for (int k = 0; k < n; ++k) {\n    for (int i = 0; i < n; ++i)\
    \ {\n      for (int j = 0; j < n; ++j) {\n        if (shortest_path_dist[i][k]\
    \ + shortest_path_dist[k][j] <\n            shortest_path_dist[i][j]) {\n    \
    \      shortest_path_dist[i][j] =\n              shortest_path_dist[i][k] + shortest_path_dist[k][j];\n\
    \          shortest_path_parent[i][j] = shortest_path_parent[k][j];\n        }\n\
    \      }\n    }\n  }\n  for (int i = 0; i < n; ++i) {\n    for (int j = 0; j <\
    \ n; ++j) {\n      if (shortest_path_dist[i][j] > MatrixGraph<Cost>::UNREACHABLE\
    \ / 2) {\n        shortest_path_dist[i][j] = MatrixGraph<Cost>::UNREACHABLE;\n\
    \      }\n    }\n  }\n  for (int i = 0; i < n; ++i) {\n    if (shortest_path_dist[i][i]\
    \ < 0) {\n      negative_cycle = true;\n      break;\n    }\n  }\n}\n"
  dependsOn:
  - cpp/graph/graph_matrix.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/graph/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2024-09-29 16:45:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/warshall_floyd.test.cpp
documentation_of: cpp/graph/warshall_floyd.hpp
layout: document
redirect_from:
- /library/cpp/graph/warshall_floyd.hpp
- /library/cpp/graph/warshall_floyd.hpp.html
title: cpp/graph/warshall_floyd.hpp
---
