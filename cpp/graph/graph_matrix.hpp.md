---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: cpp/graph/warshall_floyd.hpp
    title: cpp/graph/warshall_floyd.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/warshall_floyd.test.cpp
    title: cpp/verify/warshall_floyd.test.cpp
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: template/small_template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\n// \u30B0\u30E9\
    \u30D5(\u96A3\u63A5\u884C\u5217)\ntemplate <class Cost = ll> class MatrixGraph\
    \ {\n  int n, m;\n  vector<vector<Cost>> mat;\n  vector<vector<Cost>> shortest_path_dist;\n\
    \  vector<vector<int>> shortest_path_parent;\n  bool negative_cycle = false;\n\
    \npublic:\n  static const Cost UNREACHABLE;\n\n  MatrixGraph(int n_)\n      :\
    \ n(n_), m(0), mat(n_, vector<Cost>(n_, MatrixGraph::UNREACHABLE)) {\n    for\
    \ (int i = 0; i < n; ++i) {\n      mat[i][i] = 0;\n    }\n  }\n\n  void add_edge(int\
    \ from, int to, Cost cost = 1) {\n    mat[from][to] = cost;\n    m++;\n  }\n\n\
    \  // \u6700\u77ED\u8DDD\u96E2\n  void warshall_floyd();\n  Cost distance(int\
    \ from, int to) { return shortest_path_dist[from][to]; }\n  vector<int> get_shortest_path(int\
    \ from, int to) {\n    vector<int> path;\n    for (int cur = to; cur != from;\
    \ cur = shortest_path_parent[from][cur]) {\n      path.emplace_back(cur);\n  \
    \    if (cur == -1) {\n        return vector<int>();\n      }\n    }\n    path.emplace_back(from);\n\
    \    reverse(path.begin(), path.end());\n    return path;\n  }\n  bool has_negative_cycle()\
    \ const { return negative_cycle; }\n\n  template <class T>\n  friend std::ostream\
    \ &operator<<(std::ostream &, const MatrixGraph<T> &);\n};\n\ntemplate <class\
    \ Cost>\nconst Cost MatrixGraph<Cost>::UNREACHABLE = numeric_limits<Cost>::max()\
    \ >> 2;\n\ntemplate <class T>\nostream &operator<<(ostream &os, const MatrixGraph<T>\
    \ &graph) {\n  os << \"N = \" << graph.n << \", M = \" << graph.m << '\\n';\n\
    \  for (int i = 0; i < graph.n; ++i) {\n    for (int j = 0; j < graph.n; ++j)\
    \ {\n      os << graph.mat[i][j] << \" \\n\"[j == graph.n - 1];\n    }\n  }\n\
    \  return os;\n}"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/graph/graph_matrix.hpp
  requiredBy:
  - cpp/graph/warshall_floyd.hpp
  timestamp: '2024-10-29 23:42:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/warshall_floyd.test.cpp
documentation_of: cpp/graph/graph_matrix.hpp
layout: document
redirect_from:
- /library/cpp/graph/graph_matrix.hpp
- /library/cpp/graph/graph_matrix.hpp.html
title: cpp/graph/graph_matrix.hpp
---
