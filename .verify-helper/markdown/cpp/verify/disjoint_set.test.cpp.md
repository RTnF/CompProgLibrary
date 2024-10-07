---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/set/disjoint_set.hpp
    title: cpp/set/disjoint_set.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
  bundledCode: "Traceback (most recent call last):\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: set/disjoint_set.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n#include \"set/disjoint_set.hpp\"\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \n  int n, q;\n  cin >> n >> q;\n\n  auto ds = DisjointSet(n);\n\n  for (int i\
    \ = 0; i < q; i++) {\n    int com, x, y;\n    cin >> com >> x >> y;\n\n    if\
    \ (com == 0) {\n      ds.unite(x, y);\n    } else {\n      cout << (ds.same(x,\
    \ y) ? 1 : 0) << endl;\n    }\n  }\n}"
  dependsOn:
  - cpp/set/disjoint_set.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: true
  path: cpp/verify/disjoint_set.test.cpp
  requiredBy: []
  timestamp: '2024-09-19 20:31:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/disjoint_set.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/disjoint_set.test.cpp
- /verify/cpp/verify/disjoint_set.test.cpp.html
title: cpp/verify/disjoint_set.test.cpp
---
