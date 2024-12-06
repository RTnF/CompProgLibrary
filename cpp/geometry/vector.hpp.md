---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: cpp/geometry/line.hpp
    title: cpp/geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/geometry/polygon.hpp
    title: cpp/geometry/polygon.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/convex_hull.test.cpp
    title: cpp/verify/convex_hull.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/polygon_area.test.cpp
    title: cpp/verify/polygon_area.test.cpp
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
    \ T> int sign(T x) { return x > EPS ? 1 : x < -EPS ? -1 : 0; }\n\ntemplate <class\
    \ T = ld> struct Vec2 {\n  T x, y;\n  Vec2() : x(0), y(0) {}\n  Vec2(T x_, T y_)\
    \ : x(x_), y(y_) {}\n\n  Vec2 operator+(const Vec2 &p) const { return {x + p.x,\
    \ y + p.y}; }\n  Vec2 operator-(const Vec2 &p) const { return {x - p.x, y - p.y};\
    \ }\n  Vec2 operator*(T p) { return {x * p, y * p}; }\n  Vec2 operator/(T p) {\
    \ return {x / p, y / p}; }\n  // \u8907\u7D20\u6570\n  Vec2 operator*(Vec2 p)\
    \ {\n    return {x * p.x - y * p.y, x * p.y + y * p.x};\n  }\n  Vec2 operator/(Vec2\
    \ p) {\n    return {(x * p.x + y * p.y) / (p.x * p.x + p.y * p.y),\n         \
    \   (y * p.x - x * p.y) / (p.x * p.x + p.y * p.y)};\n  }\n  bool operator==(const\
    \ Vec2 &p) {\n    return sign(x - p.x) == 0 && sign(y - p.y) == 0;\n  }\n  bool\
    \ operator!=(const Vec2 &p) { return !(*this == p); }\n\n  //  3  2  1\n  // \
    \ 4  0  0\n  // -3 -2 -1\n  int arg_zone() const {\n    static int q[3][3] = {{-3,\
    \ 4, 3}, {-2, 0, 2}, {-1, 0, 1}};\n    return q[sign(x) + 1][sign(y) + 1];\n \
    \ }\n\n  static T cross(const Vec2 &a, const Vec2 &b) { return a.x * b.y - a.y\
    \ * b.x; }\n\n  static bool compare_arg(const Vec2 &a, const Vec2 &b) {\n    int\
    \ az = a.arg_zone();\n    int bz = b.arg_zone();\n    if (az == bz) {\n      return\
    \ sign(cross(a, b)) > 0;\n    }\n    return az < bz;\n  }\n\n  static bool compare_x(const\
    \ Vec2 &a, const Vec2 &b) {\n    if (sign(a.x - b.x) == 0) {\n      return a.y\
    \ < b.y;\n    }\n    return a.x < b.x;\n  }\n};"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/geometry/vector.hpp
  requiredBy:
  - cpp/geometry/polygon.hpp
  - cpp/geometry/line.hpp
  timestamp: '2024-11-23 22:11:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/polygon_area.test.cpp
  - cpp/verify/sort_points_by_argument.test.cpp
  - cpp/verify/convex_hull.test.cpp
documentation_of: cpp/geometry/vector.hpp
layout: document
redirect_from:
- /library/cpp/geometry/vector.hpp
- /library/cpp/geometry/vector.hpp.html
title: cpp/geometry/vector.hpp
---
