---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: cpp/number_theory/factorize.hpp
    title: cpp/number_theory/factorize.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/factorize.test.cpp
    title: cpp/verify/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/factorize2.test.cpp
    title: cpp/verify/factorize2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u500B\u6570\u3092\u6570\u3048\u308B"
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
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\ntemplate <class\
    \ T>\nint count(const vector<T> &v, T value, int idx_begin = 0, int idx_end =\
    \ -1) {\n  if (idx_end == -1) {\n    idx_end = v.size();\n  }\n  int cnt = 0;\n\
    \  for (int i = idx_begin; i < idx_end; i++) {\n    if (v[i] == value) {\n   \
    \   cnt++;\n    }\n  }\n  return cnt;\n}\n\n/**\n * @brief \u500B\u6570\u3092\u6570\
    \u3048\u308B\n *\n * @tparam T\n * @param v_sorted \u30BD\u30FC\u30C8\u6E08\u307F\
    \u3067\u306A\u3051\u308C\u3070\u306A\u3089\u306A\u3044\n * @return vector<pair<T,\
    \ int>> (\u5024, \u500B\u6570)\n */\ntemplate <class T> vector<pair<T, int>> counts(const\
    \ vector<T> &v_sorted) {\n  vector<pair<T, int>> ret;\n  int s = v_sorted.size();\n\
    \  for (int i = 0; i < s; i++) {\n    if (i == 0 || ret.back().first != v_sorted[i])\
    \ {\n      ret.emplace_back(v_sorted[i], 1);\n    } else {\n      ret.back().second++;\n\
    \    }\n  }\n  return ret;\n}"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/array/search_util.hpp
  requiredBy:
  - cpp/number_theory/factorize.hpp
  timestamp: '2024-10-19 16:46:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/factorize2.test.cpp
  - cpp/verify/factorize.test.cpp
documentation_of: cpp/array/search_util.hpp
layout: document
redirect_from:
- /library/cpp/array/search_util.hpp
- /library/cpp/array/search_util.hpp.html
title: "\u500B\u6570\u3092\u6570\u3048\u308B"
---
