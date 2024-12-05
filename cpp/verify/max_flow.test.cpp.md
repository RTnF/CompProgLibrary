---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/graph/edge_flow.hpp
    title: cpp/graph/edge_flow.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/graph/graph_flow.hpp
    title: cpp/graph/graph_flow.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/graph_flow.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM                                                         \
    \       \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n#include \"graph/graph_flow.hpp\"\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int V, E;\n  cin >> V >> E;\n  FlowGraph g(V);\n  for (int i = 0; i < E; i++)\
    \ {\n    int u, v;\n    cin >> u >> v;\n    ll c;\n    cin >> c;\n    g.add_edge_max_flow(u,\
    \ v, c);\n  }\n  cout << g.max_flow(0, V - 1) << '\\n';\n}"
  dependsOn:
  - cpp/graph/graph_flow.hpp
  - cpp/graph/edge_flow.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: true
  path: cpp/verify/max_flow.test.cpp
  requiredBy: []
  timestamp: '2024-11-10 02:48:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/max_flow.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/max_flow.test.cpp
- /verify/cpp/verify/max_flow.test.cpp.html
title: cpp/verify/max_flow.test.cpp
---
