---
data:
  _extendedDependsOn:
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
    PROBLEM: https://atcoder.jp/contests/past202203-open/tasks/past202203_j
    links:
    - https://atcoder.jp/contests/past202203-open/tasks/past202203_j
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: modint/modint.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/past202203-open/tasks/past202203_j\"\
    \n#include \"modint/modint.hpp\"\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int n, k;\n  cin >> n >> k;\n  vector<int> at(n);\n  for (int i = 0; i < n;\
    \ i++) {\n    cin >> at[i];\n  }\n  sort(at.begin(), at.end());\n  vector<mint>\
    \ a(n);\n  for (int i = 0; i < n; i++) {\n    a[i] = at[i];\n  }\n\n  mint ans\
    \ = 0;\n  for (int i = k - 1; i < n; i++) {\n    ans += C(i, k - 1) * a[i];\n\
    \    ans -= C(i, k - 1) * a[n - 1 - i];\n  }\n  ans /= C(n, k);\n  cout << ans\
    \ << '\\n';\n}"
  dependsOn:
  - cpp/modint/modint.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: true
  path: cpp/verify/combination.test.cpp
  requiredBy: []
  timestamp: '2024-11-04 20:54:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/combination.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/combination.test.cpp
- /verify/cpp/verify/combination.test.cpp.html
title: cpp/verify/combination.test.cpp
---
