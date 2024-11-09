---
data:
  _extendedDependsOn:
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
    PROBLEM: https://judge.yosupo.jp/problem/many_aplusb
    links:
    - https://judge.yosupo.jp/problem/many_aplusb
    - https://qiita.com/nojima/items/57b9d39d7d73362ac883
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\n#include\
    \ \"template/small_template.hpp\"\n\n// https://qiita.com/nojima/items/57b9d39d7d73362ac883\n\
    ll read_ll() {\n  ll ret = 0, sgn = 1;\n  int ch = getchar_unlocked();\n  while\
    \ (isspace(ch)) {\n    ch = getchar_unlocked();\n  }\n  if (ch == '-') {\n   \
    \ sgn = -1;\n    ch = getchar_unlocked();\n  }\n  for (; isdigit(ch); ch = getchar_unlocked())\n\
    \    ret = (ret * 10) + (ch - '0');\n  ungetc(ch, stdin);\n  return sgn * ret;\n\
    }\n\n// https://qiita.com/nojima/items/57b9d39d7d73362ac883\nint read_int() {\n\
    \  int ret = 0, sgn = 1;\n  int ch = getchar_unlocked();\n  while (isspace(ch))\
    \ {\n    ch = getchar_unlocked();\n  }\n  if (ch == '-') {\n    sgn = -1;\n  \
    \  ch = getchar_unlocked();\n  }\n  for (; isdigit(ch); ch = getchar_unlocked())\n\
    \    ret = (ret * 10) + (ch - '0');\n  ungetc(ch, stdin);\n  return sgn * ret;\n\
    }\n\nint main() {\n  // cin.tie(0);\n  // ios::sync_with_stdio(false);\n\n  int\
    \ T = read_int();\n\n  while (T--) {\n    ll A = read_ll();\n    ll B = read_ll();\n\
    \    cout << A + B << '\\n';\n  }\n}"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: true
  path: cpp/verify/many_a_plus_b.test.cpp
  requiredBy: []
  timestamp: '2024-10-19 16:46:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/many_a_plus_b.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/many_a_plus_b.test.cpp
- /verify/cpp/verify/many_a_plus_b.test.cpp.html
title: cpp/verify/many_a_plus_b.test.cpp
---
