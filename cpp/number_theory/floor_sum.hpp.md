---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\nconstexpr ll safe_mod(ll\
    \ x, ll m) {\n  x %= m;\n  if (x < 0) {\n    x += m;\n  }\n  return x;\n}\n\n\
    // ACL\n// sum[i=0 .. n-1] floor((a*i + b) / m)\null floor_sum_unsigned(ull n,\
    \ ull m, ull a, ull b) {\n  ull ans = 0;\n  while (true) {\n    if (a >= m) {\n\
    \      ans += n * (n - 1) / 2 * (a / m);\n      a %= m;\n    }\n    if (b >= m)\
    \ {\n      ans += n * (b / m);\n      b %= m;\n    }\n\n    ull y_max = a * n\
    \ + b;\n    if (y_max < m) {\n      break;\n    }\n    n = (ull)(y_max / m);\n\
    \    b = (ull)(y_max % m);\n    swap(m, a);\n  }\n  return ans;\n}\n\n// ACL\n\
    // sum[i=0 .. n-1] floor((a*i + b) / m)\n// 0 <= n < 2^32\n// 1 <= m < 2^32\n\
    ll floor_sum(ll n, ll m, ll a, ll b) {\n  assert(0 <= n && n < (1ll << 32));\n\
    \  assert(1 <= m && m < (1ll << 32));\n  ull ans = 0;\n  if (a < 0) {\n    ull\
    \ a2 = safe_mod(a, m);\n    ans -= (ull)n * (n - 1) / 2 * ((a2 - a) / m);\n  \
    \  a = a2;\n  }\n  if (b < 0) {\n    ull b2 = safe_mod(b, m);\n    ans -= (ull)n\
    \ * ((b2 - b) / m);\n    b = b2;\n  }\n  return ans + floor_sum_unsigned(n, m,\
    \ a, b);\n}\n"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/number_theory/floor_sum.hpp
  requiredBy: []
  timestamp: '2024-11-03 09:29:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp/number_theory/floor_sum.hpp
layout: document
redirect_from:
- /library/cpp/number_theory/floor_sum.hpp
- /library/cpp/number_theory/floor_sum.hpp.html
title: cpp/number_theory/floor_sum.hpp
---
