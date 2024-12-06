---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/graph/dijkstra.hpp
    title: cpp/graph/dijkstra.hpp
  - icon: ':question:'
    path: cpp/graph/edge.hpp
    title: cpp/graph/edge.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/graph/graph_list.hpp
    title: "\u30B0\u30E9\u30D5 (\u96A3\u63A5\u30EA\u30B9\u30C8\u5F62\u5F0F)"
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/dijkstra.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ \"graph/dijkstra.hpp\"\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int V, E, start, goal;\n  cin >> V >> E >> start >> goal;\n  ListGraph graph(V);\n\
    \  for (int i = 0; i < E; ++i) {\n    int s, t, d;\n    cin >> s >> t >> d;\n\
    \    graph.add_edge(s, t, d);\n  }\n  graph.dijkstra(start);\n  ll dist = graph.distance(start,\
    \ goal);\n  if (dist == ListGraph<>::UNREACHABLE) {\n    cout << \"-1\\n\";\n\
    \  } else {\n    auto ans = graph.shortest_path(start, goal);\n    int n = (int)ans.size()\
    \ - 1;\n    cout << dist << ' ' << n << '\\n';\n    for (int i = 0; i < n; ++i)\
    \ {\n      cout << ans[i] << ' ' << ans[i + 1] << '\\n';\n    }\n  }\n}"
  dependsOn:
  - cpp/graph/dijkstra.hpp
  - cpp/graph/graph_list.hpp
  - cpp/graph/edge.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: true
  path: cpp/verify/dijkstra2.test.cpp
  requiredBy: []
  timestamp: '2024-11-03 09:29:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/dijkstra2.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/dijkstra2.test.cpp
- /verify/cpp/verify/dijkstra2.test.cpp.html
title: cpp/verify/dijkstra2.test.cpp
---