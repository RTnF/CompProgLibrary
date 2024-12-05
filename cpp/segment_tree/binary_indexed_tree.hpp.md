---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Binary Indexed Tree (Fenwick Tree)
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
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\n/**\n * @brief\
    \ Binary Indexed Tree (Fenwick Tree)\n */\ntemplate <class T = ll> class BinaryIndexedTree\
    \ {\n  vector<T> tree; // 1-indexed\npublic:\n  BinaryIndexedTree() {}\n  BinaryIndexedTree(int\
    \ n) : tree(n + 1) {}\n  BinaryIndexedTree(const vector<T> &v) : tree(v.size()\
    \ + 1) {\n    for (int i = 0; i < (int)v.size(); i++) {\n      tree[i + 1] = v[i];\n\
    \    }\n    for (int i = 1; i < (int)v.size(); i++) {\n      tree[i + (i & -i)]\
    \ += tree[i];\n    }\n  }\n  // sum of A[0, r)\n  T sum(int r) const {\n    T\
    \ s = 0;\n    for (; r > 0; r -= (r & -r)) {\n      s += tree[r];\n    }\n   \
    \ return s;\n  }\n  // sum of A[l, r)\n  T sum(int l, int r) const { return sum(r)\
    \ - sum(l); }\n  // A[i] += val\n  void add(int i, T val) {\n    i++;\n    for\
    \ (; i < (int)tree.size(); i += (i & -i)) {\n      tree[i] += val;\n    }\n  }\n\
    };"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/segment_tree/binary_indexed_tree.hpp
  requiredBy: []
  timestamp: '2024-11-19 00:22:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp/segment_tree/binary_indexed_tree.hpp
layout: document
redirect_from:
- /library/cpp/segment_tree/binary_indexed_tree.hpp
- /library/cpp/segment_tree/binary_indexed_tree.hpp.html
title: Binary Indexed Tree (Fenwick Tree)
---
