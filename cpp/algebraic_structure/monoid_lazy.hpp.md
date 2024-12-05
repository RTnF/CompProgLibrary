---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/range_add_query.test.cpp
    title: cpp/verify/range_add_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/range_add_range_min.test.cpp
    title: cpp/verify/range_add_range_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/range_add_range_sum.test.cpp
    title: cpp/verify/range_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/range_update_query.test.cpp
    title: cpp/verify/range_update_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/range_update_range_min.test.cpp
    title: cpp/verify/range_update_range_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/range_update_range_sum.test.cpp
    title: cpp/verify/range_update_range_sum.test.cpp
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
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\n// \u9045\u5EF6\
    \u30BB\u30B0\u6728\u7528\u306E\u95A2\u6570\n\ntemplate <class T = ll> struct RangeAddRangeMaxMin\
    \ {\n  struct RangeMax {\n    T x;\n    RangeMax(T x_) : x(x_) {}\n    RangeMax()\
    \ : RangeMax(e()) {}\n    static RangeMax e() { return numeric_limits<T>::min();\
    \ }\n    friend RangeMax op(const RangeMax &a, const RangeMax &b) {\n      return\
    \ max(a.x, b.x);\n    }\n  };\n  struct RangeMin {\n    T x;\n    RangeMin(T x_)\
    \ : x(x_) {}\n    RangeMin() : RangeMin(e()) {}\n    static RangeMin e() { return\
    \ numeric_limits<T>::max(); }\n    friend RangeMin op(const RangeMin &a, const\
    \ RangeMin &b) {\n      return min(a.x, b.x);\n    }\n  };\n  struct RangeAdd\
    \ {\n    T v;\n    RangeAdd(T v_) : v(v_) {}\n    static RangeAdd id() { return\
    \ 0; }\n    friend RangeAdd compose(RangeAdd f, RangeAdd g) {\n      return RangeAdd(f.v\
    \ + g.v);\n    }\n    template <class M> M apply(M x) { return x.x + v; }\n  };\n\
    };\n\ntemplate <class T = ll> struct RangeAddRangeSum {\n  struct RangeSum {\n\
    \    T x;\n    int size;\n    RangeSum(T x_, int size_) : x(x_), size(size_) {}\n\
    \    RangeSum() : RangeSum(e()) {}\n    static RangeSum e() { return {0, 0}; }\n\
    \    friend RangeSum op(const RangeSum &a, const RangeSum &b) {\n      return\
    \ {a.x + b.x, a.size + b.size};\n    }\n  };\n  struct RangeAdd {\n    T v;\n\
    \    RangeAdd(T v_) : v(v_) {}\n    static RangeAdd id() { return 0; }\n    friend\
    \ RangeAdd compose(RangeAdd f, RangeAdd g) {\n      return RangeAdd(f.v + g.v);\n\
    \    }\n    RangeSum apply(RangeSum x) { return {x.x + x.size * v, x.size}; }\n\
    \  };\n};\n\ntemplate <class T = ll> struct RangeSetRangeMaxMin {\n  struct RangeMax\
    \ {\n    T x;\n    RangeMax(T x_) : x(x_) {}\n    RangeMax() : RangeMax(e()) {}\n\
    \    static RangeMax e() { return numeric_limits<T>::min(); }\n    friend RangeMax\
    \ op(const RangeMax &a, const RangeMax &b) {\n      return max(a.x, b.x);\n  \
    \  }\n  };\n  struct RangeMin {\n    T x;\n    RangeMin(T x_) : x(x_) {}\n   \
    \ RangeMin() : RangeMin(e()) {}\n    static RangeMin e() { return numeric_limits<T>::max();\
    \ }\n    friend RangeMin op(const RangeMin &a, const RangeMin &b) {\n      return\
    \ min(a.x, b.x);\n    }\n  };\n  struct RangeSet {\n    T v;\n    bool noop;\n\
    \    RangeSet(T v_) : v(v_), noop(false) {}\n    RangeSet() : v(0), noop(true)\
    \ {}\n    static RangeSet id() { return {}; }\n    friend RangeSet compose(RangeSet\
    \ f, RangeSet g) { return f.noop ? g : f; }\n    template <class M> M apply(M\
    \ x) { return noop ? x : v; }\n  };\n};\n\ntemplate <class T = ll> struct RangeSetRangeSum\
    \ {\n  struct RangeSum {\n    T x;\n    int size;\n    RangeSum(T x_, int size_)\
    \ : x(x_), size(size_) {}\n    RangeSum() : RangeSum(e()) {}\n    static RangeSum\
    \ e() { return {0, 0}; }\n    friend RangeSum op(const RangeSum &a, const RangeSum\
    \ &b) {\n      return {a.x + b.x, a.size + b.size};\n    }\n  };\n  struct RangeSet\
    \ {\n    T v;\n    bool noop;\n    RangeSet(T v_) : v(v_), noop(false) {}\n  \
    \  RangeSet() : v(0), noop(true) {}\n    static RangeSet id() { return {}; }\n\
    \    friend RangeSet compose(RangeSet f, RangeSet g) { return f.noop ? g : f;\
    \ }\n    RangeSum apply(RangeSum x) {\n      if (!noop) {\n        x.x = v * x.size;\n\
    \      }\n      return x;\n    }\n  };\n};\n"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/algebraic_structure/monoid_lazy.hpp
  requiredBy: []
  timestamp: '2024-12-03 01:33:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/range_update_query.test.cpp
  - cpp/verify/range_update_range_sum.test.cpp
  - cpp/verify/range_add_range_sum.test.cpp
  - cpp/verify/range_add_query.test.cpp
  - cpp/verify/range_update_range_min.test.cpp
  - cpp/verify/range_add_range_min.test.cpp
documentation_of: cpp/algebraic_structure/monoid_lazy.hpp
layout: document
redirect_from:
- /library/cpp/algebraic_structure/monoid_lazy.hpp
- /library/cpp/algebraic_structure/monoid_lazy.hpp.html
title: cpp/algebraic_structure/monoid_lazy.hpp
---
