---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/graph/graph_matrix.hpp
    title: cpp/graph/graph_matrix.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/graph/warshall_floyd.hpp
    title: cpp/graph/warshall_floyd.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/template/small_template.hpp
    title: cpp/template/small_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
  bundledCode: "Traceback (most recent call last):\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/warshall_floyd.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM                                                         \
    \       \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n#include \"graph/warshall_floyd.hpp\"\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int V, E;\n  cin >> V >> E;\n  MatrixGraph g(V);\n  for (int i = 0; i < E;\
    \ ++i) {\n    int s, t;\n    ll d;\n    cin >> s >> t >> d;\n    g.add_edge(s,\
    \ t, d);\n  }\n  g.warshall_floyd();\n  if (g.has_negative_cycle()) {\n    cout\
    \ << \"NEGATIVE CYCLE\\n\";\n  } else {\n    for (int i = 0; i < V; ++i) {\n \
    \     for (int j = 0; j < V; ++j) {\n        if (g.get_dist(i, j) >= MatrixGraph<>::UNREACHABLE)\
    \ {\n          cout << \"INF\";\n        } else {\n          cout << g.get_dist(i,\
    \ j);\n        }\n        cout << \" \\n\"[j == V - 1];\n      }\n    }\n  }\n\
    }"
  dependsOn:
  - cpp/graph/warshall_floyd.hpp
  - cpp/graph/graph_matrix.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: true
  path: cpp/verify/warshall_floyd.test.cpp
  requiredBy: []
  timestamp: '2024-09-29 16:26:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/warshall_floyd.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/warshall_floyd.test.cpp
- /verify/cpp/verify/warshall_floyd.test.cpp.html
title: cpp/verify/warshall_floyd.test.cpp
---
