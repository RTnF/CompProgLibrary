---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/array/search_util.hpp
    title: "\u500B\u6570\u3092\u6570\u3048\u308B"
  - icon: ':heavy_check_mark:'
    path: cpp/number_theory/factorize.hpp
    title: cpp/number_theory/factorize.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/number_theory/is_prime.hpp
    title: cpp/number_theory/is_prime.hpp
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: cpp/template/small_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n#include \"\
    number_theory/factorize.hpp\"\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int q;\n  cin >> q;\n  while (q--) {\n    ull n;\n    cin >> n;\n    auto f\
    \ = factorize(n);\n    cout << f.size();\n    for (auto p: f) {\n      cout <<\
    \ ' ' << p;\n    }\n    cout << '\\n';\n  }\n}"
  dependsOn:
  - cpp/number_theory/factorize.hpp
  - cpp/array/search_util.hpp
  - cpp/template/small_template.hpp
  - cpp/number_theory/is_prime.hpp
  isVerificationFile: true
  path: cpp/verify/factorize2.test.cpp
  requiredBy: []
  timestamp: '2024-09-29 16:45:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/factorize2.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/factorize2.test.cpp
- /verify/cpp/verify/factorize2.test.cpp.html
title: cpp/verify/factorize2.test.cpp
---
