---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: cpp/geometry/point.hpp
    title: cpp/geometry/point.hpp
  - icon: ':x:'
    path: cpp/template/small_template.hpp
    title: cpp/template/small_template.hpp
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: template/small_template.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \n#include \"template/small_template.hpp\"\n#include \"geometry/point.hpp\"\n\n\
    int main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  int n;\n  cin >>\
    \ n;\n  vector<Point<ll>> ps;\n  ps.reserve(n);\n  while (n--) {\n    ll x, y;\n\
    \    cin >> x >> y;\n    ps.emplace_back(x, y);\n  }\n  sort(ps.begin(), ps.end());\n\
    \  for (auto &&p: ps) {\n    cout << p << '\\n';\n  }\n}"
  dependsOn:
  - cpp/template/small_template.hpp
  - cpp/geometry/point.hpp
  isVerificationFile: true
  path: cpp/verify/sort_points_by_argument.test.cpp
  requiredBy: []
  timestamp: '2024-09-18 18:24:28+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: cpp/verify/sort_points_by_argument.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/sort_points_by_argument.test.cpp
- /verify/cpp/verify/sort_points_by_argument.test.cpp.html
title: cpp/verify/sort_points_by_argument.test.cpp
---
