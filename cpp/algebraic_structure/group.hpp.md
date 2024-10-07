---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: cpp/template/small_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/point_add_range_sum.test.cpp
    title: cpp/verify/point_add_range_sum.test.cpp
  - icon: ':x:'
    path: cpp/verify/point_set_range_composite.test.cpp
    title: cpp/verify/point_set_range_composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u30A2\u30D5\u30A3\u30F3\u5199\u50CF y = ax + b"
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
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\ntemplate<class\
    \ T = ll>\nstruct GroupSum {\n  T x;\n  GroupSum(T x_): x(x_) {}\n  GroupSum():\
    \ GroupSum(e()) {}\n  static GroupSum e() { return 0; }\n  friend GroupSum op(const\
    \ GroupSum &a, const GroupSum &b) { return a.x + b.x; }\n  GroupSum inv() const\
    \ { return e().x - x; }\n};\n\n/**\n * @brief \u30A2\u30D5\u30A3\u30F3\u5199\u50CF\
    \ y = ax + b\n * @tparam T \n */\ntemplate<class T = ll>\nstruct GroupAffine {\n\
    \  T a, b;\n  GroupAffine(T a_, T b_): a(a_), b(b_) {}\n  GroupAffine(): GroupAffine(e())\
    \ {}\n  static GroupAffine e() { return {1, 0}; }\n  friend GroupAffine op(const\
    \ GroupAffine &p, const GroupAffine &q) {\n    return {p.a * q.a, p.b * q.a +\
    \ q.b};\n  }\n  GroupAffine inv() const { return {1 / a, -b / a}; }\n};\n"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/algebraic_structure/group.hpp
  requiredBy: []
  timestamp: '2024-09-18 18:24:28+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - cpp/verify/point_set_range_composite.test.cpp
  - cpp/verify/point_add_range_sum.test.cpp
documentation_of: cpp/algebraic_structure/group.hpp
layout: document
redirect_from:
- /library/cpp/algebraic_structure/group.hpp
- /library/cpp/algebraic_structure/group.hpp.html
title: "\u30A2\u30D5\u30A3\u30F3\u5199\u50CF y = ax + b"
---
