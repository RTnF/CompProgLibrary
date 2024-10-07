---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: cpp/template/small_template.hpp
    title: cpp/template/small_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: cpp/verify/disjoint_set.test.cpp
    title: cpp/verify/disjoint_set.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: template/small_template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\n// based on ACL\n\
    class DisjointSet {\n  // root: -1 * \u9023\u7D50\u6210\u5206\u30B5\u30A4\u30BA\
    \n  // otherwise: parent\n  vector<int> ps;\n  int num_groups;\n\npublic:\n  DisjointSet(int\
    \ n): ps(n, -1), num_groups(n) {}\n\n  // a \u3068 b \u3092\u7D50\u5408\u3059\u308B\
    \n  int unite(int a, int b) {\n    int x = root(a), y = root(b);\n    if (x ==\
    \ y) {\n      return x;\n    }\n    if (-ps[x] < -ps[y]) {\n      swap(x, y);\n\
    \    }\n    ps[x] += ps[y];\n    ps[y] = x;\n    num_groups--;\n    return x;\n\
    \  }\n\n  // a \u3068 b \u304C\u540C\u3058\u6728\u306B\u5C5E\u3059\u308B\u304B\
    \n  bool same(int a, int b) { return root(a) == root(b); }\n\n  // a \u304C\u5C5E\
    \u3059\u308B\u6728\u306E\u6839\n  int root(int a) {\n    if (ps[a] < 0) {\n  \
    \    return a;\n    }\n    return ps[a] = root(ps[a]);\n  }\n\n  // a \u304C\u5C5E\
    \u3059\u308B\u6728\u306E\u30B5\u30A4\u30BA\n  int size(int a) { return -ps[root(a)];\
    \ }\n\n  // \u68EE\u306E\u6728\u306E\u6570\n  int getNum() { return num_groups;\
    \ }\n};"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/set/disjoint_set.hpp
  requiredBy: []
  timestamp: '2024-09-07 19:01:33+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - cpp/verify/disjoint_set.test.cpp
documentation_of: cpp/set/disjoint_set.hpp
layout: document
redirect_from:
- /library/cpp/set/disjoint_set.hpp
- /library/cpp/set/disjoint_set.hpp.html
title: cpp/set/disjoint_set.hpp
---
