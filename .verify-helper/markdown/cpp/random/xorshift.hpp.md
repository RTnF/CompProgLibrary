---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/template/small_template.hpp
    title: cpp/template/small_template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: cpp/set/multiset.hpp
    title: "\u91CD\u8907\u3042\u308A\u306E\u96C6\u5408"
  - icon: ':warning:'
    path: cpp/set/set.hpp
    title: "\u91CD\u8907\u306A\u3057\u306E\u96C6\u5408"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/multi_set.test.cpp
    title: cpp/verify/multi_set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://ja.wikipedia.org/wiki/Xorshift
  bundledCode: "Traceback (most recent call last):\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: template/small_template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\n// https://ja.wikipedia.org/wiki/Xorshift\n\
    class Xor64 {\n  ull s;\n\npublic:\n  Xor64(ull s_): s(s_) {}\n  // [0, 2**64)\n\
    \  ull get() {\n    ull x = s;\n    x ^= x << 7;\n    return s = x ^ (x >> 9);\n\
    \  }\n  // [min, max)\n  int get_int(int mi, int ma) { return mi + get() % (ma\
    \ - mi); }\n  // [min, max)\n  ll get_ll(ll mi, ll ma) { return mi + get() % (ma\
    \ - mi); }\n  // [0, 1)\n  double get_double() { return get() / pow(2.0, 64);\
    \ }\n  // [min, max)\n  double get_double(double mi, double ma) {\n    return\
    \ mi + get_double() * (ma - mi);\n  }\n  // normal\n  double get_normal() {\n\
    \    double x = get_double(), y = get_double();\n    return sqrt(-2.0 * log(x))\
    \ * cos(2.0 * M_PI * y);\n  }\n};"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/random/xorshift.hpp
  requiredBy:
  - cpp/set/multiset.hpp
  - cpp/set/set.hpp
  timestamp: '2024-09-16 23:23:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/multi_set.test.cpp
documentation_of: cpp/random/xorshift.hpp
layout: document
redirect_from:
- /library/cpp/random/xorshift.hpp
- /library/cpp/random/xorshift.hpp.html
title: cpp/random/xorshift.hpp
---
