---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/array/search_util.hpp
    title: "\u500B\u6570\u3092\u6570\u3048\u308B"
  - icon: ':heavy_check_mark:'
    path: cpp/number_theory/is_prime.hpp
    title: cpp/number_theory/is_prime.hpp
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: cpp/template/small_template.hpp
  _extendedRequiredBy: []
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: array/search_util.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"array/search_util.hpp\"\n#include \"number_theory/is_prime.hpp\"\
    \n#include \"template/small_template.hpp\"\n\nnamespace in {\nvector<ull> factorize(ull\
    \ n) {\n  auto f = [n](ull x, ull c) -> ull { return ((__uint128_t)x * x + c)\
    \ % n; };\n  auto rho = [f](ull m, ull c) -> ull {\n    ull x = 2, y = 2, d =\
    \ 1;\n    while (d == 1) {\n      x = f(x, c);\n      y = f(f(y, c), c);\n   \
    \   d = gcd(x > y ? x - y : y - x, m);\n    }\n    return d == m ? 0 : d;\n  };\n\
    \  vector<ull> factor;\n  while (!(n & 1)) {\n    factor.emplace_back(2);\n  \
    \  n >>= 1;\n  }\n  if (n <= 1) {\n    return factor;\n  }\n  if (is_prime(n))\
    \ {\n    factor.emplace_back(n);\n    return factor;\n  }\n  ull r = 0;\n  for\
    \ (int i = 1; !r && i <= 3; ++i) {\n    r = rho(n, i);\n  }\n  if (r) {\n    auto\
    \ f1 = factorize(r);\n    auto f2 = factorize(n / r);\n    factor.insert(factor.end(),\
    \ f1.begin(), f1.end());\n    factor.insert(factor.end(), f2.begin(), f2.end());\n\
    \    return factor;\n  } else {\n    // fallback O(sqrt(n))\n    for (ull i =\
    \ 3; i * i <= n; i += 2) {\n      while (n % i == 0) {\n        factor.emplace_back(i);\n\
    \        n /= i;\n      }\n    }\n    if (n > 1) {\n      factor.emplace_back(n);\n\
    \    }\n    return factor;\n  }\n  return factor;\n}\n}; // namespace in\n\nvector<ull>\
    \ factorize(ull n) {\n  auto f = in::factorize(n);\n  sort(f.begin(), f.end());\n\
    \  return f;\n}\n\nvector<pair<ull, int>> factorize_count(ull n) { return counts(factorize(n));\
    \ }\n"
  dependsOn:
  - cpp/array/search_util.hpp
  - cpp/template/small_template.hpp
  - cpp/number_theory/is_prime.hpp
  isVerificationFile: false
  path: cpp/number_theory/factorize.hpp
  requiredBy: []
  timestamp: '2024-09-29 16:45:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/factorize2.test.cpp
  - cpp/verify/factorize.test.cpp
documentation_of: cpp/number_theory/factorize.hpp
layout: document
redirect_from:
- /library/cpp/number_theory/factorize.hpp
- /library/cpp/number_theory/factorize.hpp.html
title: cpp/number_theory/factorize.hpp
---
