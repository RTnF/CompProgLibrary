---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/enumerate_quotients.test.cpp
    title: cpp/verify/enumerate_quotients.test.cpp
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: template/small_template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\n// \u6574\u6570\
    \u3068\u306E\u5546 floor(n / x) \u3092\u5217\u6319\u3059\u308B\nvector<ull> enumerate_quotients(ull\
    \ n) {\n  // N/k - N/(k+1) > 1\n  // N/k(k+1) > 1\n  // N > k(k+1)\n  ull ok =\
    \ 4294967295;\n  ull ng = 0;\n  ull k;\n  while (ok - ng > 1) {\n    k = (ok +\
    \ ng) / 2;\n    (k * (k + 1) >= n ? ok : ng) = k;\n  }\n  vector<ull> ret;\n \
    \ ull p = n / ok;\n  for (ull i = 1; i <= p; i++) {\n    ret.emplace_back(i);\n\
    \  }\n  for (ull i = ok - 1; i >= 1; i--) {\n    ret.emplace_back(n / i);\n  }\n\
    \  return ret;\n}\n"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/number_theory/enumerate_quotients.hpp
  requiredBy: []
  timestamp: '2024-10-30 22:03:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/enumerate_quotients.test.cpp
documentation_of: cpp/number_theory/enumerate_quotients.hpp
layout: document
redirect_from:
- /library/cpp/number_theory/enumerate_quotients.hpp
- /library/cpp/number_theory/enumerate_quotients.hpp.html
title: cpp/number_theory/enumerate_quotients.hpp
---
