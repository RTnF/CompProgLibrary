---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/geometry/line.hpp
    title: cpp/geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/geometry/vector.hpp
    title: cpp/geometry/vector.hpp
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/convex_hull.test.cpp
    title: cpp/verify/convex_hull.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/polygon_area.test.cpp
    title: cpp/verify/polygon_area.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: geometry/line.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"geometry/line.hpp\"\n#include \"geometry/vector.hpp\"\
    \n\ntemplate <class T> using Polygon = vector<Vec2<T>>;\ntemplate <class T> using\
    \ Points = vector<Vec2<T>>;\n\ntemplate <class T> Polygon<T> convex_hull(Points<T>\
    \ &p, bool strict = true) {\n  int n = p.size();\n  if (n <= 2) {\n    return\
    \ p;\n  }\n  int k = 0;\n  sort(p.begin(), p.end(), Vec2<T>::compare_x);\n  vector<Vec2<T>>\
    \ ch(2 * n);\n  auto check = [&](int i) {\n    return sign(Vec2<T>::cross(ch[k\
    \ - 1] - ch[k - 2], p[i] - ch[k - 1])) <=\n           -1 + strict;\n  };\n  for\
    \ (int i = 0; i < n; ch[k++] = p[i++]) {\n    while (k >= 2 && check(i)) {\n \
    \     --k;\n    }\n  }\n  for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--])\
    \ {\n    while (k >= t && check(i)) {\n      --k;\n    }\n  }\n  ch.resize(k -\
    \ 1);\n  return ch;\n}\n\ntemplate <class T> T area(const Polygon<T> &s) {\n \
    \ ld ret = 0;\n  int n = (int)s.size();\n  for (int i = 0; i < n; i++) {\n   \
    \ int j = i == n - 1 ? 0 : i + 1;\n    ret += (s[j].y + s[i].y) * (s[j].x - s[i].x);\n\
    \  }\n  return -ret / 2;\n}\n\ntemplate<class T> bool in_polygon(const Vec2<T>\
    \ &p, const Polygon<T> &poly) {\n  // (px, py) - (px, -inf) \u3068poly\u306E\u4EA4\
    \u70B9\u6570\n  int cnt = 0;\n  int n = poly.size();\n  for(int i = 0; i < n;\
    \ i++) {\n    int j = i + 1 == n ? 0 : i + 1;\n    if (sign(poly[i].x - poly[j].x)\
    \ == 0) {\n      continue;\n    }\n    // \u5DE6\u306BEPS\u305A\u3089\u3059\n\
    \    if (((poly[i].x - EPS < p.x && p.x < poly[j].x - EPS) ||\n         (poly[j].x\
    \ - EPS < p.x && p.x < poly[i].x - EPS)) &&\n        find_point(Line{poly[i],\
    \ poly[j]}, p.x) < p.y) {\n      cnt++;\n    }\n  }\n  return cnt & 1;\n}"
  dependsOn:
  - cpp/geometry/line.hpp
  - cpp/geometry/vector.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/geometry/polygon.hpp
  requiredBy: []
  timestamp: '2024-11-23 22:11:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/polygon_area.test.cpp
  - cpp/verify/convex_hull.test.cpp
documentation_of: cpp/geometry/polygon.hpp
layout: document
redirect_from:
- /library/cpp/geometry/polygon.hpp
- /library/cpp/geometry/polygon.hpp.html
title: cpp/geometry/polygon.hpp
---
