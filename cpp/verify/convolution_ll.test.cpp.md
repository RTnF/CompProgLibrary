---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/fps/convolution.hpp
    title: cpp/fps/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/modint/modint.hpp
    title: "\u5270\u4F59\u3092\u53D6\u308A[0, mod)\u306B\u53CE\u3081\u308Bint"
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
    PROBLEM: https://atcoder.jp/contests/past202203-open/tasks/past202203_n
    links:
    - https://atcoder.jp/contests/past202203-open/tasks/past202203_n
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: fps/convolution.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/past202203-open/tasks/past202203_n\"\
    \n#include \"fps/convolution.hpp\"\n\nconst int MAX = 200003;\n\nint main() {\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(false);\n  int n;\n  cin >> n;\n  vector<ll>\
    \ a(MAX, 0);\n  for (int i = 0; i < n; i++) {\n    int m;\n    cin >> m;\n   \
    \ a[m]++;\n  }\n  vector<ll> b = a;\n  reverse(b.begin(), b.end());\n  auto conv\
    \ = convolution_ll(a, b);\n  ll ans = 0;\n  for (int i = 0; i < MAX - 1; i++)\
    \ {\n    if (conv[i] > 0) {\n      ans++;\n    }\n  }\n  cout << ans * 2 + 1 <<\
    \ '\\n';\n}"
  dependsOn:
  - cpp/fps/convolution.hpp
  - cpp/modint/modint.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: true
  path: cpp/verify/convolution_ll.test.cpp
  requiredBy: []
  timestamp: '2024-11-24 09:02:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/convolution_ll.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/convolution_ll.test.cpp
- /verify/cpp/verify/convolution_ll.test.cpp.html
title: cpp/verify/convolution_ll.test.cpp
---
