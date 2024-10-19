---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/template/small_template.hpp
    title: cpp/template/small_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/segment_tree.test.cpp
    title: cpp/verify/segment_tree.test.cpp
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
    \ T = ll> struct MonoidMul {\n  T x;\n  MonoidMul(T x_) : x(x_) {}\n  MonoidMul()\
    \ : MonoidMul(e()) {}\n  static MonoidMul e() { return 1; }\n  friend MonoidMul\
    \ op(const MonoidMul &a, const MonoidMul &b) {\n    return a.x * b.x;\n  }\n};\n\
    \ntemplate <class T = ll> struct MonoidMax {\n  T x;\n  MonoidMax(T x_) : x(x_)\
    \ {}\n  MonoidMax() : MonoidMax(e()) {}\n  static MonoidMax e() { return numeric_limits<T>::min();\
    \ }\n  friend MonoidMax op(const MonoidMax &a, const MonoidMax &b) {\n    return\
    \ max(a.x, b.x);\n  }\n};\n\ntemplate <class T = ll> struct MonoidMin {\n  T x;\n\
    \  MonoidMin(T x_) : x(x_) {}\n  MonoidMin() : MonoidMin(e()) {}\n  static MonoidMin\
    \ e() { return numeric_limits<T>::max(); }\n  friend MonoidMin op(const MonoidMin\
    \ &a, const MonoidMin &b) {\n    return min(a.x, b.x);\n  }\n};\n"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/algebraic_structure/monoid.hpp
  requiredBy: []
  timestamp: '2024-10-13 18:16:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/segment_tree.test.cpp
documentation_of: cpp/algebraic_structure/monoid.hpp
layout: document
title: "\u30E2\u30CE\u30A4\u30C9 (Monoid)"
---
<link rel="stylesheet" type="text/css" href="../../css/common.css">

[Wikipedia - モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)

群は集合と二項演算の組であって、以下の条件を満たす。

- 結合法則
- 単位元の存在

もし逆元があるなら、群になる。

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

## モノイド

|クラス名|対象の集合|二項演算|単位元|
|--|--|--|--|
|`MonoidMul`|整数、実数など|乗算|$1$|
|`MonoidMax`|整数、実数など|$\max (a, b)$|最小値または $-\infty$|
|`MonoidMin`|整数、実数など|$\min (a, b)$|最大値または $\infty$|