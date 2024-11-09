---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/number_theory/enumerate_quotients.hpp
    title: cpp/number_theory/enumerate_quotients.hpp
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_quotients
    links:
    - https://judge.yosupo.jp/problem/enumerate_quotients
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: number_theory/enumerate_quotients.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n\
    #include \"number_theory/enumerate_quotients.hpp\"\n\nint main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(false);\n\n  ull x;\n  cin >> x;\n  auto q = enumerate_quotients(x);\n\
    \  cout << q.size() << '\\n';\n  for (ull y : q) {\n    cout << y << ' ';\n  }\n\
    }"
  dependsOn:
  - cpp/number_theory/enumerate_quotients.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: true
  path: cpp/verify/enumerate_quotients.test.cpp
  requiredBy: []
  timestamp: '2024-10-30 22:03:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/enumerate_quotients.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/enumerate_quotients.test.cpp
- /verify/cpp/verify/enumerate_quotients.test.cpp.html
title: cpp/verify/enumerate_quotients.test.cpp
---
