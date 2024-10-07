---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/graph/graph_list.hpp
    title: cpp/graph/graph_list.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/graph/lowlink.hpp
    title: cpp/graph/lowlink.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A
  bundledCode: "Traceback (most recent call last):\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/lowlink.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A\"\
    \n#include \"graph/lowlink.hpp\"\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int V, E;\n  cin >> V >> E;\n  ListGraph graph(V);\n  for (int i = 0; i < E;\
    \ ++i) {\n    int s, t;\n    cin >> s >> t;\n    graph.add_bidirectional_edge(s,\
    \ t);\n  }\n  auto [aps, bridges] = graph.lowlink();\n  for (auto &&ap: aps) {\n\
    \    cout << ap << '\\n';\n  }\n}"
  dependsOn:
  - cpp/graph/lowlink.hpp
  - cpp/template/small_template.hpp
  - cpp/graph/graph_list.hpp
  isVerificationFile: true
  path: cpp/verify/articulation_points.test.cpp
  requiredBy: []
  timestamp: '2024-09-29 16:37:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/articulation_points.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/articulation_points.test.cpp
- /verify/cpp/verify/articulation_points.test.cpp.html
title: cpp/verify/articulation_points.test.cpp
---