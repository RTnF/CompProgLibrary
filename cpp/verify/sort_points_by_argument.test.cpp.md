---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp/geometry/vector.hpp
    title: cpp/geometry/vector.hpp
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sort_points_by_argument
    links:
    - https://judge.yosupo.jp/problem/sort_points_by_argument
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: geometry/vector.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \n#include \"geometry/vector.hpp\"\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int n;\n  cin >> n;\n  vector<Vec2<ll>> ps;\n  ps.reserve(n);\n  while (n--)\
    \ {\n    ll x, y;\n    cin >> x >> y;\n    ps.emplace_back(x, y);\n  }\n  sort(ps.begin(),\
    \ ps.end(), Vec2<ll>::compare_arg);\n  for (auto &&p : ps) {\n    cout << p.x\
    \ << ' ' << p.y << '\\n';\n  }\n}"
  dependsOn:
  - cpp/geometry/vector.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: true
  path: cpp/verify/sort_points_by_argument.test.cpp
  requiredBy: []
  timestamp: '2024-11-23 22:11:34+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: cpp/verify/sort_points_by_argument.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/sort_points_by_argument.test.cpp
- /verify/cpp/verify/sort_points_by_argument.test.cpp.html
title: cpp/verify/sort_points_by_argument.test.cpp
---
