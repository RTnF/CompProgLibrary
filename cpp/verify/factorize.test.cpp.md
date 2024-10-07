---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: cpp/array/search_util.hpp
    title: "\u500B\u6570\u3092\u6570\u3048\u308B"
  - icon: ':x:'
    path: cpp/number_theory/factorize.hpp
    title: cpp/number_theory/factorize.hpp
  - icon: ':x:'
    path: cpp/number_theory/is_prime.hpp
    title: cpp/number_theory/is_prime.hpp
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: cpp/template/small_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: number_theory/factorize.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n#include \"number_theory/factorize.hpp\"\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  ull n;\n  cin >> n;\n  auto f = factorize(n);\n  cout << n << ':';\n  for (auto\
    \ p: f) {\n    cout << ' ' << p;\n  }\n  cout << '\\n';\n}"
  dependsOn:
  - cpp/number_theory/factorize.hpp
  - cpp/array/search_util.hpp
  - cpp/template/small_template.hpp
  - cpp/number_theory/is_prime.hpp
  isVerificationFile: true
  path: cpp/verify/factorize.test.cpp
  requiredBy: []
  timestamp: '2024-09-29 16:45:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: cpp/verify/factorize.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/factorize.test.cpp
- /verify/cpp/verify/factorize.test.cpp.html
title: cpp/verify/factorize.test.cpp
---
