---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp/array/doubling.hpp
    title: cpp/array/doubling.hpp
  - icon: ':question:'
    path: cpp/graph/edge.hpp
    title: cpp/graph/edge.hpp
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  - icon: ':question:'
    path: cpp/tree/tree.hpp
    title: "\u5168\u65B9\u4F4D\u6728DP"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n#include\
    \ \"tree/tree.hpp\"\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int N;\n  cin >> N;\n  vector<int> a(N - 1), b(N - 1);\n  vector<ll> c(N -\
    \ 1);\n  for (int i = 0; i < N - 1; i++) {\n    cin >> a[i] >> b[i] >> c[i];\n\
    \  }\n  Tree t(0, a, b, c);\n  auto [df, dt, d] = t.diameter();\n  auto path =\
    \ t.path(df, dt);\n  cout << d << ' ' << path.size() << '\\n';\n  for (int i =\
    \ 0; i < (int)path.size(); i++) {\n    cout << path[i] << \" \\n\"[i + 1 == (int)path.size()];\n\
    \  }\n}"
  dependsOn:
  - cpp/tree/tree.hpp
  - cpp/array/doubling.hpp
  - cpp/template/small_template.hpp
  - cpp/graph/edge.hpp
  isVerificationFile: true
  path: cpp/verify/tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2024-12-07 00:34:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/tree_diameter.test.cpp
- /verify/cpp/verify/tree_diameter.test.cpp.html
title: cpp/verify/tree_diameter.test.cpp
---
