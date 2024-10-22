---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/set/disjoint_set_union.hpp
    title: "\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020 (Union Find)"
  - icon: ':heavy_check_mark:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: set/disjoint_set_union.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM                                                         \
    \       \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n#include \"set/disjoint_set_union.hpp\"\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \n  int n, q;\n  cin >> n >> q;\n\n  auto ds = DisjointSetUnion(n);\n\n  for (int\
    \ i = 0; i < q; i++) {\n    int com, x, y;\n    cin >> com >> x >> y;\n\n    if\
    \ (com == 0) {\n      ds.unite(x, y);\n    } else {\n      cout << (ds.same(x,\
    \ y) ? 1 : 0) << endl;\n    }\n  }\n}"
  dependsOn:
  - cpp/set/disjoint_set_union.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: true
  path: cpp/verify/disjoint_set_union.test.cpp
  requiredBy: []
  timestamp: '2024-10-19 16:46:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/disjoint_set_union.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/disjoint_set_union.test.cpp
- /verify/cpp/verify/disjoint_set_union.test.cpp.html
title: cpp/verify/disjoint_set_union.test.cpp
---
