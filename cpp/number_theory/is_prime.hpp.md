---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: cpp/template/small_template.hpp
    title: cpp/template/small_template.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: cpp/number_theory/factorize.hpp
    title: cpp/number_theory/factorize.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: cpp/verify/factorize.test.cpp
    title: cpp/verify/factorize.test.cpp
  - icon: ':x:'
    path: cpp/verify/factorize2.test.cpp
    title: cpp/verify/factorize2.test.cpp
  - icon: ':x:'
    path: cpp/verify/is_prime.test.cpp
    title: cpp/verify/is_prime.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test
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
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\n// Miller test\
    \ for 64bit\n// https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test\n\
    bool is_prime(ull n) {\n  if (n == 2) {\n    return true;\n  }\n  if (!(n & 1)\
    \ || n <= 1) {\n    return false;\n  }\n  auto powmod64 = [](ull x, ull y, ull\
    \ mod) -> ull {\n    ull pm = 1;\n    while (y) {\n      if (y & 1) {\n      \
    \  pm = (__uint128_t)pm * x % mod;\n      }\n      x = (__uint128_t)x * x % mod;\n\
    \      y >>= 1;\n    }\n    return pm;\n  };\n  int r = 0;\n  ull d = n - 1;\n\
    \  while (!(d & 1)) {\n    d >>= 1;\n    ++r;\n  }\n  for (const ull p: {2, 3,\
    \ 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {\n    if (p > n - 2) {\n      break;\n\
    \    }\n    ull x = powmod64(p, d, n);\n    if (x == 1 || x == n - 1) {\n    \
    \  continue;\n    }\n    bool cf = true;\n    for (int i = 0; i < r - 1; ++i)\
    \ {\n      x = powmod64(x, 2, n);\n      if (x == n - 1) {\n        cf = false;\n\
    \        break;\n      }\n    }\n    if (cf) {\n      return false;\n    }\n \
    \ }\n  return true;\n}"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/number_theory/is_prime.hpp
  requiredBy:
  - cpp/number_theory/factorize.hpp
  timestamp: '2024-09-18 18:24:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - cpp/verify/is_prime.test.cpp
  - cpp/verify/factorize2.test.cpp
  - cpp/verify/factorize.test.cpp
documentation_of: cpp/number_theory/is_prime.hpp
layout: document
redirect_from:
- /library/cpp/number_theory/is_prime.hpp
- /library/cpp/number_theory/is_prime.hpp.html
title: cpp/number_theory/is_prime.hpp
---
