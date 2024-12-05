---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp/geometry/vector.hpp
    title: cpp/geometry/vector.hpp
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy:
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: geometry/vector.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"geometry/vector.hpp\"\n\ntemplate <class T> struct\
    \ Line {\n  Vec2<T> p, q;\n\n  Line(const Vec2<T> &p_, const Vec2<T> &q_) : p(p_),\
    \ q(q_) { assert(p != q); }\n};\n\n// \u4EA4\u5DEE\u3059\u308B\ntemplate <class\
    \ T>\noptional<pair<T, T>> vector_intersection(const Line<T> &l, const Line<T>\
    \ &m) {\n  T cross = Vec2<T>::cross(l.q - l.p, m.q - m.p);\n  if (sign(cross)\
    \ == 0) {\n    return nullopt;\n  }\n  T a = l.q.x - l.p.x;\n  T b = -(m.q.x -\
    \ m.p.x);\n  T c = l.q.y - l.p.y;\n  T d = -(m.q.y - m.p.y);\n  T e = m.p.x -\
    \ l.p.x;\n  T f = m.p.y - l.p.y;\n  T g = a * d - b * c;\n  return pair<T, T>((d\
    \ * e - b * f) / g, (a * f - c * e) / g);\n}\n\n// \u4EA4\u5DEE\u3059\u308B\n\
    template <class T>\noptional<Vec2<T>> line_intersection(const Line<T> &l, const\
    \ Line<T> &m) {\n  auto vec_inter = vector_intersection(l, m);\n  if (!vec_inter)\
    \ {\n    return nullopt;\n  }\n  return l.p + (l.q - l.p) * vec_inter->first;\n\
    }\n\n// \u5185\u90E8\u3067\u4EA4\u5DEE\u3059\u308B\ntemplate <class T>\noptional<Vec2<T>>\
    \ segment_intersection(const Line<T> &l, const Line<T> &m) {\n  auto vec_inter\
    \ = vector_intersection(l, m);\n  if (!vec_inter || vec_inter->first < 0 || 1\
    \ < vec_inter->first ||\n      vec_inter->second < 0 || 1 < vec_inter->second)\
    \ {\n    return nullopt;\n  }\n  return l.p + (l.q - l.p) * vec_inter->first;\n\
    }\n\ntemplate <class T> T find_point(const Line<T> &l, T x) {\n  assert(sign(l.p.x\
    \ - l.q.x));\n  T a = (l.q.y - l.p.y) / (l.q.x - l.p.x);\n  T b = l.p.y - a *\
    \ l.p.x;\n  return a * x + b;\n}"
  dependsOn:
  - cpp/geometry/vector.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/geometry/line.hpp
  requiredBy:
  - cpp/geometry/polygon.hpp
  timestamp: '2024-11-23 22:11:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/polygon_area.test.cpp
  - cpp/verify/convex_hull.test.cpp
documentation_of: cpp/geometry/line.hpp
layout: document
redirect_from:
- /library/cpp/geometry/line.hpp
- /library/cpp/geometry/line.hpp.html
title: cpp/geometry/line.hpp
---
