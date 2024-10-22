---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/sort_points_by_argument.test.cpp
    title: cpp/verify/sort_points_by_argument.test.cpp
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: template/small_template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\ntemplate <class\
    \ T = ll> struct Point {\n  T x, y;\n  int8_t quadrant; // 0-index \u8C61\u9650\
    \n  Point() : x(0), y(0) { setQuadrant(); }\n  Point(T x_, T y_) : x(x_), y(y_)\
    \ { setQuadrant(); }\n  void setX(T x_) {\n    x = x_;\n    setQuadrant();\n \
    \ }\n  void setY(T y_) {\n    y = y_;\n    setQuadrant();\n  }\n\nprivate:\n \
    \ void setQuadrant() {\n    int8_t xm = x < 0, ym = y < 0;\n    // 0123\n    //\
    \ quadrant = (ym << 1) + (xm ^ ym);\n    // 2301\n    quadrant = (!ym << 1) +\
    \ (xm ^ ym);\n  }\n};\n\ntemplate <class T> bool operator<(const Point<T> &a,\
    \ const Point<T> &b) {\n  if (a.quadrant != b.quadrant) {\n    return a.quadrant\
    \ < b.quadrant;\n  }\n  T cross = a.x * b.y - b.x * a.y;\n  if (cross != 0) {\n\
    \    return cross > 0;\n  } else if (a.x != b.x) {\n    return a.x < b.x;\n  }\
    \ else {\n    return a.y < b.y;\n  }\n}\n\ntemplate <class T> ostream &operator<<(ostream\
    \ &os, const Point<T> &p) {\n  os << p.x << ' ' << p.y;\n  return os;\n}\n\ntemplate\
    \ <class T = ll> struct Point3 {\n  T x, y, z;\n  Point3(T x_, T y_, T z_) : x(x_),\
    \ y(y_), z(z_) {}\n};\n"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/geometry/point.hpp
  requiredBy: []
  timestamp: '2024-10-19 16:46:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/sort_points_by_argument.test.cpp
documentation_of: cpp/geometry/point.hpp
layout: document
redirect_from:
- /library/cpp/geometry/point.hpp
- /library/cpp/geometry/point.hpp.html
title: cpp/geometry/point.hpp
---
