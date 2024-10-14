---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: cpp/template/small_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: cpp/verify/point_add_range_sum.test.cpp
    title: cpp/verify/point_add_range_sum.test.cpp
  - icon: ':x:'
    path: cpp/verify/point_set_range_composite.test.cpp
    title: cpp/verify/point_set_range_composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ T = ll> class GroupSum {\n  T _x;\n\npublic:\n  GroupSum(T x_) : _x(x_) {}\n\
    \  GroupSum() : GroupSum(e()) {}\n  T x() const { return _x; }\n  static GroupSum\
    \ e() { return 0; }\n  friend GroupSum op(const GroupSum &a, const GroupSum &b)\
    \ {\n    return a._x + b._x;\n  }\n  GroupSum inv() const { return -_x; }\n};\n\
    \ntemplate <class T = ll> class GroupMul {\n  T _x;\n\npublic:\n  GroupMul(T x)\
    \ : _x(x) { assert(x != 0); }\n  GroupMul() : GroupMul(e()) {}\n  T x() const\
    \ { return _x; }\n  static GroupMul e() { return 1; }\n  friend GroupMul op(const\
    \ GroupMul &a, const GroupMul &b) {\n    return a._x * b._x;\n  }\n  GroupMul\
    \ inv() const { return 1 / _x; }\n};\n\n// \u30A2\u30D5\u30A3\u30F3\u5199\u50CF\
    \ y = ax + b\ntemplate <class T = ll> class GroupAffine {\n  T _a, _b;\n\npublic:\n\
    \  GroupAffine(T a, T b) : _a(a), _b(b) {}\n  GroupAffine() : GroupAffine(e())\
    \ {}\n  T a() const { return _a; }\n  T b() const { return _b; }\n  static GroupAffine\
    \ e() { return {1, 0}; }\n  friend GroupAffine op(const GroupAffine &p, const\
    \ GroupAffine &q) {\n    return {p._a * q._a, p._b * q._a + q._b};\n  }\n  GroupAffine\
    \ inv() const { return {1 / _a, -_b / _a}; }\n  T apply(const T &x) const { return\
    \ _a * x + _b; }\n};\n"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/algebraic_structure/group.hpp
  requiredBy: []
  timestamp: '2024-10-14 15:39:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - cpp/verify/point_add_range_sum.test.cpp
  - cpp/verify/point_set_range_composite.test.cpp
documentation_of: cpp/algebraic_structure/group.hpp
layout: document
title: "\u7FA4 (Group)"
---
<link rel="stylesheet" type="text/css" href="/css/common.css">

[Wikipedia - 群 (数学)](https://ja.wikipedia.org/wiki/%E7%BE%A4_(%E6%95%B0%E5%AD%A6))

群は集合と二項演算の組であって、以下の条件を満たす。

- 結合法則
- 単位元の存在
- 逆元の存在

## コンストラクタ

```cpp
Group g()
```

引数がない場合、単位元で初期化するものとする。

## op

```cpp
Group op(Group a, Group b)
```

演算 $a \cdot b$ を行う。

## e

```cpp
Group e()
```

単位元を返す。

## inv

```cpp
Group g.inv()
```

$g$ の逆元を返す。

## 群

|クラス名|対象の集合|二項演算|単位元|逆元|
|--|--|--|--|--|
|`GroupSum`|整数、実数など|加算|$0$|$-x$|
|`GroupMul`|整数、実数など(0を除く)|乗算|$1$|$\frac{1}{x}$|
|`GroupAffine`|アフィン写像 $y=a x + b$|合成 $y = a_1 (a_2 x + b) + b$|$y = x$|$ y = \frac{x}{a} - \frac{b}{a} $|