---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    PROBLEM: https://atcoder.jp/contests/past202303-open/tasks/past202303_j
    links:
    - https://atcoder.jp/contests/past202303-open/tasks/past202303_j
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/past202303-open/tasks/past202303_j\"\
    \n#include \"string/rolling_hash.hpp\"\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \n  int h, w;\n  cin >> h >> w;\n  vector<string> s(h), t(h);\n  for (int i =\
    \ 0; i < h; i++) {\n    cin >> s[i];\n  }\n  for (int i = 0; i < h; i++) {\n \
    \   cin >> t[i];\n  }\n\n  string ss, tt;\n  for (int j = 0; j < w; j++) {\n \
    \   for (int i = 0; i < h; i++) {\n      ss += s[i][j];\n      tt += t[i][j];\n\
    \    }\n  }\n  ss += ss;\n  RollingHash r(ss, 3);\n  vector<int> v;\n  for (int\
    \ i = 0; i < w; i++) {\n    v.emplace_back(i * h);\n  }\n  cout << (r.match_custom(tt,\
    \ v) != string::npos ? \"Yes\\n\" : \"No\\n\");\n}"
  dependsOn:
  - cpp/string/rolling_hash.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: true
  path: cpp/verify/rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2024-11-07 00:23:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/rolling_hash.test.cpp
- /verify/cpp/verify/rolling_hash.test.cpp.html
title: cpp/verify/rolling_hash.test.cpp
---
