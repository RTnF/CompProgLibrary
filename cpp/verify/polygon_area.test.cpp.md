---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/geometry/line.hpp
    title: cpp/geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/geometry/polygon.hpp
    title: cpp/geometry/polygon.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/geometry/vector.hpp
    title: cpp/geometry/vector.hpp
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
    ERROR: 1e-8
    PROBLEM: https://atcoder.jp/contests/past202112-open/tasks/past202112_n
    links:
    - https://atcoder.jp/contests/past202112-open/tasks/past202112_n
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: geometry/polygon.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/past202112-open/tasks/past202112_n\"\
    \n#define ERROR 1e-8\n#include \"geometry/polygon.hpp\"\n\nvoid solve() {\n  int\
    \ n, m;\n  cin >> n >> m;\n  Polygon<ld> S(n), T(m);\n  for (int i = 0; i < n;\
    \ i++) {\n    ld x, y;\n    cin >> x >> y;\n    S[i] = Vec2<ld>(x, y);\n  }\n\
    \  for (int i = 0; i < m; i++) {\n    ld x, y;\n    cin >> x >> y;\n    T[i] =\
    \ Vec2<ld>(x, y);\n  }\n  vector<Vec2<ld>> ps;\n  for (int i = 0; i < n; i++)\
    \ {\n    int ii = i + 1 == n ? 0 : i + 1;\n    for (int j = 0; j < m; j++) {\n\
    \      int jj = j + 1 == m ? 0 : j + 1;\n      auto seg_inter =\n          segment_intersection(Line{S[i],\
    \ S[ii]}, Line{T[j], T[jj]});\n      if (seg_inter) {\n        ps.emplace_back(seg_inter.value());\n\
    \      }\n    }\n  }\n  for (int i = 0; i < n; i++) {\n    if (in_polygon(S[i],\
    \ T)) {\n      ps.emplace_back(S[i]);\n    }\n  }\n  for (int i = 0; i < m; i++)\
    \ {\n    if (in_polygon(T[i], S)) {\n      ps.emplace_back(T[i]);\n    }\n  }\n\
    \  auto ch = convex_hull(ps);\n  cout << area(ch) << '\\n';\n}\n\nint main() {\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(false);\n  cout << fixed << setprecision(20);\n\
    \  solve();\n}"
  dependsOn:
  - cpp/geometry/polygon.hpp
  - cpp/geometry/line.hpp
  - cpp/geometry/vector.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: true
  path: cpp/verify/polygon_area.test.cpp
  requiredBy: []
  timestamp: '2024-11-23 22:11:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/polygon_area.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/polygon_area.test.cpp
- /verify/cpp/verify/polygon_area.test.cpp.html
title: cpp/verify/polygon_area.test.cpp
---
