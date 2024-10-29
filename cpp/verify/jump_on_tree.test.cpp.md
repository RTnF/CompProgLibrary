---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/array/doubling.hpp
    title: cpp/array/doubling.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/graph/edge.hpp
    title: cpp/graph/edge.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  - icon: ':heavy_check_mark:'
    path: cpp/tree/tree.hpp
    title: cpp/tree/tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/jump_on_tree
    links:
    - https://judge.yosupo.jp/problem/jump_on_tree
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: tree/tree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\n#include\
    \ \"tree/tree.hpp\"\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int n, q;\n  cin >> n >> q;\n  vector<int> a(n - 1), b(n - 1);\n  for (int\
    \ i = 0; i < n - 1; i++) {\n    cin >> a[i] >> b[i];\n  }\n  Tree<int> t(a, b);\n\
    \  t.build_ancestor();\n  while (q--) {\n    int u, v, i;\n    cin >> u >> v >>\
    \ i;\n    int lca = t.lowest_common_ancestor(u, v);\n    int d1 = t.depth(u) -\
    \ t.depth(lca);\n    int d2 = t.depth(v) - t.depth(lca);\n    if (i > d1 + d2)\
    \ {\n      cout << \"-1\\n\";\n    } else if (i < d1) {\n      cout << t.ancestor(u,\
    \ i) << '\\n';\n    } else {\n      cout << t.ancestor(v, d1 + d2 - i) << '\\\
    n';\n    }\n  }\n}"
  dependsOn:
  - cpp/tree/tree.hpp
  - cpp/array/doubling.hpp
  - cpp/template/small_template.hpp
  - cpp/graph/edge.hpp
  isVerificationFile: true
  path: cpp/verify/jump_on_tree.test.cpp
  requiredBy: []
  timestamp: '2024-10-30 08:24:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/jump_on_tree.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/jump_on_tree.test.cpp
- /verify/cpp/verify/jump_on_tree.test.cpp.html
title: cpp/verify/jump_on_tree.test.cpp
---
