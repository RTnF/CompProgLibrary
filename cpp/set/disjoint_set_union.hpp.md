---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: cpp/template/small_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: cpp/verify/disjoint_set_union.test.cpp
    title: cpp/verify/disjoint_set_union.test.cpp
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
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\n// \u7D20\u96C6\
    \u5408\u30C7\u30FC\u30BF\u69CB\u9020 (Union Find)\nclass DisjointSetUnion {\n\
    \  // root: -1 * \u9023\u7D50\u6210\u5206\u30B5\u30A4\u30BA, \u305D\u306E\u4ED6\
    : \u89AA\n  vector<int> _ps;\n  int _num_groups, _n;\n\npublic:\n  DisjointSetUnion()\
    \ : _num_groups(0), _n(0) {}\n  DisjointSetUnion(int n) : _ps(n, -1), _num_groups(n),\
    \ _n(n) {\n    assert(n >= 0);\n  }\n\n  // a \u3068 b \u3092\u7D50\u5408\u3059\
    \u308B\n  int unite(int a, int b) {\n    assert(0 <= a && a < _n);\n    assert(0\
    \ <= b && b < _n);\n    int x = root(a), y = root(b);\n    if (x == y) {\n   \
    \   return x;\n    }\n    if (-_ps[x] < -_ps[y]) {\n      swap(x, y);\n    }\n\
    \    _ps[x] += _ps[y];\n    _ps[y] = x;\n    _num_groups--;\n    return x;\n \
    \ }\n\n  // a \u3068 b \u304C\u540C\u3058\u6728\u306B\u5C5E\u3059\u308B\u304B\n\
    \  bool same(int a, int b) {\n    assert(0 <= a && a < _n);\n    assert(0 <= b\
    \ && b < _n);\n    return root(a) == root(b);\n  }\n\n  // a \u304C\u5C5E\u3059\
    \u308B\u6728\u306E\u6839\n  int root(int a) {\n    assert(0 <= a && a < _n);\n\
    \    if (_ps[a] < 0) {\n      return a;\n    }\n    return _ps[a] = root(_ps[a]);\n\
    \  }\n\n  // a \u304C\u5C5E\u3059\u308B\u6728\u306E\u30B5\u30A4\u30BA\n  int size(int\
    \ a) {\n    assert(0 <= a && a < _n);\n    return -_ps[root(a)];\n  }\n\n  //\
    \ \u68EE\u306E\u6728\u306E\u6570\n  int num_groups() { return _num_groups; }\n\
    };"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/set/disjoint_set_union.hpp
  requiredBy: []
  timestamp: '2024-10-12 23:57:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - cpp/verify/disjoint_set_union.test.cpp
documentation_of: cpp/set/disjoint_set_union.hpp
layout: document
title: "\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020 (Union Find)"
---
<link rel="stylesheet" type="text/css" href="../../css/common.css">

## コンストラクタ

```cpp
DisjointSetUnion dsu()
DisjointSetUnion dsu(int n)
```

$n$ 頂点、結合がない状態で初期化する

**計算量**

- $O(n)$


## unite

```cpp
int unite(int a, int b)
```

頂点 $a, b$ を結合する

**制約**

- $ 0 \le a < n $
- $ 0 \le b < n $

**計算量**

- ならし $ O(\alpha(n)) $


## same

```cpp
bool same(int a, int b)
```

頂点 $a, b$ が連結か

**制約**

- $0 \leq a < n$
- $0 \leq b < n$

**計算量**

- ならし $O(\alpha(n))$

## root

```cpp
int root(int a)
```

頂点 $a$ の属する連結成分の代表元

**制約**

- $0 \leq a < n$

**計算量**

- ならし $O(\alpha(n))$

## size

```cpp
int size(int a)
```

頂点 $a$ の属する連結成分のサイズ

**制約**

- $0 \leq a < n$

**計算量**

- ならし $O(\alpha(n))$
