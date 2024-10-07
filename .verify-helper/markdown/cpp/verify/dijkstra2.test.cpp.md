---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/graph/dijkstra.hpp
    title: cpp/graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/graph/graph_list.hpp
    title: cpp/graph/graph_list.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "Traceback (most recent call last):\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/dijkstra.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ \"graph/dijkstra.hpp\"\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int V, E, start, goal;\n  cin >> V >> E >> start >> goal;\n  ListGraph graph(V);\n\
    \  for (int i = 0; i < E; ++i) {\n    int s, t, d;\n    cin >> s >> t >> d;\n\
    \    graph.add_edge(s, t, d);\n  }\n  graph.dijkstra(start);\n  ll dist = graph.get_dist(start,\
    \ goal);\n  if (dist == ListGraph<>::UNREACHABLE) {\n    cout << \"-1\\n\";\n\
    \  } else {\n    auto ans = graph.get_shortest_path(start, goal);\n    int n =\
    \ (int)ans.size() - 1;\n    cout << dist << ' ' << n << '\\n';\n    for (int i\
    \ = 0; i < n; ++i) {\n      cout << ans[i] << ' ' << ans[i + 1] << '\\n';\n  \
    \  }\n  }\n}"
  dependsOn:
  - cpp/graph/dijkstra.hpp
  - cpp/graph/graph_list.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: true
  path: cpp/verify/dijkstra2.test.cpp
  requiredBy: []
  timestamp: '2024-09-29 16:37:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/dijkstra2.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/dijkstra2.test.cpp
- /verify/cpp/verify/dijkstra2.test.cpp.html
title: cpp/verify/dijkstra2.test.cpp
---