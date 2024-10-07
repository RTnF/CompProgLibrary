---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/template/small_template.hpp
    title: cpp/template/small_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/point_add_range_sum.test.cpp
    title: cpp/verify/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/point_set_range_composite.test.cpp
    title: cpp/verify/point_set_range_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 based on ACL"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: template/small_template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\n/**\n * @brief\
    \ \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 based on ACL\n * @tparam M \u30E2\u30CE\
    \u30A4\u30C9\n */\ntemplate<class M>\nclass SegmentTree {\n  // ex. n=5, n_node=8,\
    \ h_node=3\n  //                 [1]\n  //       [2]                 [3]\n  //\
    \   [4]      [5]       [6]       [7]\n  // (8) (9) (10) (11) (12) [13] [14] [15]\n\
    \  int n, n_node, h_node;\n  vector<M> node;\n  void update(int i) { node[i] =\
    \ op(node[i * 2], node[i * 2 + 1]); }\n\npublic:\n  SegmentTree(): SegmentTree(0)\
    \ {}\n  SegmentTree(int n_): SegmentTree(vector<M>(n_, M::e())) {}\n  SegmentTree(const\
    \ vector<M> &v): n(v.size()) {\n    h_node = 0;\n    n_node = 0;\n    while (n_node\
    \ < n) {\n      h_node++;\n      n_node = 1 << h_node;\n    }\n    node = vector<M>(n_node\
    \ * 2, M::e());\n    for (int i = 0; i < n; i++) {\n      node[n_node + i] = v[i];\n\
    \    }\n    for (int i = n_node - 1; i >= 1; i--) {\n      update(i);\n    }\n\
    \  }\n\n  // v[idx] = val\n  void set(int idx, M val) {\n    assert(0 <= idx &&\
    \ idx < n);\n    idx += n_node;\n    node[idx] = val;\n    for (int i = 1; i <=\
    \ h_node; i++) {\n      update(idx >> i);\n    }\n  }\n\n  // v[idx]\n  M get(int\
    \ idx) {\n    assert(0 <= idx && idx < n);\n    return node[idx + n_node];\n \
    \ }\n\n  /**\n   * @brief \u533A\u9593[l, r)\u306E\u7DCF\u7A4D\n   * @return op(v[l]\
    \ ... v[r-1])\n   */\n  M product(int l, int r) {\n    assert(0 <= l && l <= r\
    \ && r <= n);\n    M l_op = M::e(), r_op = M::e();\n    l += n_node;\n    r +=\
    \ n_node;\n\n    while (l < r) {\n      if (l & 1) {\n        l_op = op(l_op,\
    \ node[l++]);\n      }\n      if (r & 1) {\n        r_op = op(node[--r], r_op);\n\
    \      }\n      l >>= 1;\n      r >>= 1;\n    }\n    return op(l_op, r_op);\n\
    \  }\n\n  /**\n   * @brief \u7DCF\u7A4D\n   *\n   * @returns op(v[0] ... v[n-1])\n\
    \   */\n  M product_all() { return node[1]; }\n\n  /**\n   * @brief \u4E8C\u5206\
    \u63A2\u7D22 O(log n) l\u304B\u3089\u306E\u7DCF\u7A4D\u304Cf\u3092\u6E80\u305F\
    \u3055\u306A\u304F\u306A\u308Br\n   * @tparam F\n   * @param l [0, n], \u63A2\u7D22\
    \u533A\u9593[l, n)\n   * @param f [](M x) -> bool {...}, f(e) == true\n   * @return\
    \ [l, n]\u304B\u30891\u3064, f(op(v[l] ... v[r-1])) == true && f(op(v[l] ... v[r]))\
    \ == false\n   */\n  template<class F>\n  int search_prod_right(int l, F f) {\n\
    \    assert(0 <= l && l <= n);\n    assert(f(M::e()));\n    if (l == n) {\n  \
    \    return n;\n    }\n    l += n_node;\n    M sm = M::e();\n    do {\n      while\
    \ (l % 2 == 0) {\n        l >>= 1;\n      }\n      if (!f(op(sm, node[l]))) {\n\
    \        while (l < n_node) {\n          l = l * 2;\n          if (f(op(sm, node[l])))\
    \ {\n            sm = op(sm, node[l]);\n            l++;\n          }\n      \
    \  }\n        return l - n_node;\n      }\n      sm = op(sm, node[l]);\n     \
    \ l++;\n    } while ((l & -l) != l);\n    return n;\n  }\n\n  /**\n   * @brief\
    \ \u4E8C\u5206\u63A2\u7D22 O(log n) r\u304B\u3089\u306E\u7DCF\u7A4D\u304Cf\u3092\
    \u6E80\u305F\u3055\u306A\u304F\u306A\u308Bl\n   * @tparam F\n   * @param r [0,\
    \ n], \u63A2\u7D22\u533A\u9593[0, r)\n   * @param f [](M x) -> bool {...}, f(e)\
    \ == true\n   * @return [0, r]\u304B\u30891\u3064\u3001f(op(v[l] ... v[r-1]))\
    \ == true && f(op(v[l-1] ... v[r-1])) == false\n   */\n  template<class F>\n \
    \ int search_prod_left(int r, F f) {\n    assert(0 <= r && r <= n);\n    assert(f(M::e()));\n\
    \    if (r == 0) {\n      return 0;\n    }\n    r += n_node;\n    M sm = M::e();\n\
    \    do {\n      r--;\n      while (r > 1 && (r % 2)) {\n        r >>= 1;\n  \
    \    }\n      if (!f(op(node[r], sm))) {\n        while (r < n_node) {\n     \
    \     r = r * 2 + 1;\n          if (f(op(node[r], sm))) {\n            sm = op(node[r],\
    \ sm);\n            r--;\n          }\n        }\n        return r + 1 - n_node;\n\
    \      }\n      sm = op(node[r], sm);\n    } while ((r & -r) != r);\n    return\
    \ 0;\n  }\n};\n"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/segment_tree/segment_tree.hpp
  requiredBy: []
  timestamp: '2024-09-17 06:24:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/point_add_range_sum.test.cpp
  - cpp/verify/point_set_range_composite.test.cpp
documentation_of: cpp/segment_tree/segment_tree.hpp
layout: document
redirect_from:
- /library/cpp/segment_tree/segment_tree.hpp
- /library/cpp/segment_tree/segment_tree.hpp.html
title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 based on ACL"
---
