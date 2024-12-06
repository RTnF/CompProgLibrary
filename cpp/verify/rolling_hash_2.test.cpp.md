---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/string/rolling_hash.hpp
    title: cpp/string/rolling_hash.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc141/tasks/abc141_e
    links:
    - https://atcoder.jp/contests/abc141/tasks/abc141_e
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: string/rolling_hash.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc141/tasks/abc141_e\"\n#include\
    \ \"string/rolling_hash.hpp\"\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \n  int n;\n  cin >> n;\n  string s;\n  cin >> s;\n  SimpleRollingHash rh(s);\n\
    \n  int ans = 0;\n  for (int sz = 1; sz <= n / 2; sz++) {\n    unordered_set<ull>\
    \ hashes;\n    for (int i = 0; i <= n - sz * 2; i++) {\n      hashes.emplace(rh.hash(i,\
    \ i + sz));\n      if (hashes.contains(rh.hash(i + sz, i + sz * 2)) && ans < sz)\
    \ {\n        ans = sz;\n      }\n    }\n  }\n  cout << ans << \"\\n\";\n}"
  dependsOn:
  - cpp/string/rolling_hash.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: true
  path: cpp/verify/rolling_hash_2.test.cpp
  requiredBy: []
  timestamp: '2024-11-07 00:23:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/rolling_hash_2.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/rolling_hash_2.test.cpp
- /verify/cpp/verify/rolling_hash_2.test.cpp.html
title: cpp/verify/rolling_hash_2.test.cpp
---
