---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/graph/bellman_ford.hpp
    title: cpp/graph/bellman_ford.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/graph/graph_list.hpp
    title: cpp/graph/graph_list.hpp
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: cpp/template/small_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/bellman_ford.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n#include \"graph/bellman_ford.hpp\"\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int V, E, r;\n  cin >> V >> E >> r;\n  ListGraph graph(V);\n  for (int i =\
    \ 0; i < E; ++i) {\n    int s, t, d;\n    cin >> s >> t >> d;\n    graph.add_edge(s,\
    \ t, d);\n  }\n  graph.bellman_ford(r);\n  for (int i = 0; i < V; ++i) {\n   \
    \ ll dist = graph.get_dist(r, i);\n    if (dist == ListGraph<>::NEGATIVE_CYCLE)\
    \ {\n      cout << \"NEGATIVE CYCLE\\n\";\n      return 0;\n    }\n  }\n  for\
    \ (int i = 0; i < V; ++i) {\n    ll dist = graph.get_dist(r, i);\n    if (dist\
    \ == ListGraph<>::UNREACHABLE) {\n      cout << \"INF\\n\";\n    } else {\n  \
    \    cout << dist << '\\n';\n    }\n  }\n}"
  dependsOn:
  - cpp/graph/bellman_ford.hpp
  - cpp/template/small_template.hpp
  - cpp/graph/graph_list.hpp
  isVerificationFile: true
  path: cpp/verify/bellman_ford.test.cpp
  requiredBy: []
  timestamp: '2024-09-18 18:24:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/bellman_ford.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/bellman_ford.test.cpp
- /verify/cpp/verify/bellman_ford.test.cpp.html
title: cpp/verify/bellman_ford.test.cpp
---
