---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy:
  - icon: ':question:'
    path: cpp/tree/tree.hpp
    title: cpp/tree/tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/jump_on_tree.test.cpp
    title: cpp/verify/jump_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/lowest_common_ancestor.test.cpp
    title: cpp/verify/lowest_common_ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/lowest_common_ancestor_2.test.cpp
    title: cpp/verify/lowest_common_ancestor_2.test.cpp
  - icon: ':x:'
    path: cpp/verify/tree_diameter.test.cpp
    title: cpp/verify/tree_diameter.test.cpp
  - icon: ':x:'
    path: cpp/verify/tree_diameter_2.test.cpp
    title: cpp/verify/tree_diameter_2.test.cpp
  - icon: ':x:'
    path: cpp/verify/tree_height.test.cpp
    title: cpp/verify/tree_height.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\n// \u30C0\u30D6\
    \u30EA\u30F3\u30B0\n// \u5024\u304C[0, n)\u3067\u3042\u308B\u914D\u5217\u306E\u305D\
    \u308C\u305E\u308C\u3067\n// j = v[j] \u3092 2**i \u56DE\u7E70\u308A\u8FD4\u3057\
    \u305F\u7D50\u679C\u306E2\u6B21\u5143\u914D\u5217\u3092\u4F5C\u308B\n// O(n log\
    \ kmax)\nvector<vector<int>> doubling(vector<int> &v, uint64_t kmax) {\n  // 0:0\
    \ 1:1 2:2 4:3 8:4 ...\n  assert(kmax > 0);\n  int n = v.size();\n  for (int i\
    \ = 0; i < n; i++) {\n    assert(0 <= v[i]);\n    assert(v[i] < n);\n  }\n  int\
    \ w = bit_width(kmax);\n  vector<vector<int>> ret(w);\n  ret[0].assign(v.begin(),\
    \ v.end());\n  for(int i = 1; i < w; i++){\n    ret[i].reserve(n);\n    for(int\
    \ j = 0; j < n; j++){\n      ret[i].emplace_back(ret[i-1][ret[i-1][j]]);\n   \
    \ }\n  }\n  return ret;\n}"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/array/doubling.hpp
  requiredBy:
  - cpp/tree/tree.hpp
  timestamp: '2024-10-30 01:21:21+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - cpp/verify/tree_diameter_2.test.cpp
  - cpp/verify/tree_diameter.test.cpp
  - cpp/verify/jump_on_tree.test.cpp
  - cpp/verify/tree_height.test.cpp
  - cpp/verify/lowest_common_ancestor.test.cpp
  - cpp/verify/lowest_common_ancestor_2.test.cpp
documentation_of: cpp/array/doubling.hpp
layout: document
redirect_from:
- /library/cpp/array/doubling.hpp
- /library/cpp/array/doubling.hpp.html
title: cpp/array/doubling.hpp
---
