---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/random/xorshift.hpp
    title: cpp/random/xorshift.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/template/small_template.hpp
    title: cpp/template/small_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/multi_set.test.cpp
    title: cpp/verify/multi_set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u91CD\u8907\u3042\u308A\u306E\u96C6\u5408"
    links:
    - https://xuzijian629.hatenablog.com/entry/2018/12/08/000452
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
  code: "#pragma once\n#include \"template/small_template.hpp\"\n#include \"random/xorshift.hpp\"\
    \n\n/**\n * @brief \u91CD\u8907\u3042\u308A\u306E\u96C6\u5408\n * \u633F\u5165\
    \ O(log n)\n * \u524A\u9664 O(log n)\n * \u691C\u7D22 O(log n)\n * \u5B9F\u88C5\
    \uFF1ATreap https://xuzijian629.hatenablog.com/entry/2018/12/08/000452\n * @tparam\
    \ T \u8981\u7D20\u306E\u578B\n */\ntemplate<typename T = ll>\nclass TreeMultiSet\
    \ {\n  static inline Xor64 rnd = Xor64(192865741288375612ull);\n  struct Node\
    \ {\n    T k;\n    int c = 1;\n    ull p = rnd.get();\n    Node *l = nullptr,\
    \ *r = nullptr;\n    Node(T key): k(key) {}\n  };\n  using Tree = Node *;\n  Tree\
    \ root = nullptr;\n  int n = 0;\n\n  void split(Tree t, T key, Tree &l, Tree &r)\
    \ {\n    if (!t) {\n      l = r = nullptr;\n    } else if (key < t->k) {\n   \
    \   split(t->l, key, l, t->l);\n      r = t;\n    } else {\n      split(t->r,\
    \ key, t->r, r);\n      l = t;\n    }\n  }\n\n  void merge(Tree &t, Tree l, Tree\
    \ r) {\n    if (!l || !r) {\n      t = l ? l : r;\n    } else if (l->p > r->p)\
    \ {\n      merge(l->r, l->r, r);\n      t = l;\n    } else {\n      merge(r->l,\
    \ l, r->l);\n      t = r;\n    }\n  }\n\n  void insert(Tree &t, Tree item) {\n\
    \    if (!t) {\n      t = item;\n    } else if (item->p > t->p) {\n      split(t,\
    \ item->k, item->l, item->r);\n      t = item;\n    } else {\n      insert(item->k\
    \ < t->k ? t->l : t->r, item);\n    }\n  }\n\n  void remove(Tree &t, T key) {\n\
    \    if (t->k == key) {\n      merge(t, t->l, t->r);\n    } else {\n      remove(key\
    \ < t->k ? t->l : t->r, key);\n    }\n  }\n\n  // AOJ\n  void dump(Tree &t, int\
    \ l, int r) {\n    if (t->l && t->k > l) {\n      dump(t->l, l, r);\n    }\n \
    \   if (l <= t->k && t->k <= r) {\n      for (int i = 0; i < t->c; i++) {\n  \
    \      cout << t->k << '\\n';\n      }\n    }\n    if (t->r && t->k < r) {\n \
    \     dump(t->r, l, r);\n    }\n  }\n\npublic:\n  TreeMultiSet() = default;\n\n\
    \  /**\n   * @brief \u8981\u7D20\u306E\u8FFD\u52A0\n   * \n   * @param key \n\
    \   * @return int \u8FFD\u52A0\u5F8C\u306E\u540C\u3058\u8981\u7D20\u306E\u6570\
    \n   */\n  int add(T key) {\n    n++;\n    Tree t = root;\n    while (t) {\n \
    \     if (key == t->k) {\n        t->c++;\n        return t->c;\n      }\n   \
    \   t = key < t->k ? t->l : t->r;\n    }\n    insert(root, new Node(key));\n \
    \   return 1;\n  }\n\n  /**\n   * @brief \u6307\u5B9A\u3057\u305F\u8981\u7D20\u306E\
    1\u500B\u524A\u9664\n   * \n   * @param key \n   * @return bool \u524A\u9664\u51FA\
    \u6765\u305F\u5834\u5408true\n   */\n  bool remove(T key) {\n    Tree t = root;\n\
    \    while (t) {\n      if (key == t->k) {\n        if (t->c > 1) {\n        \
    \  t->c--;\n        } else {\n          remove(root, key);\n        }\n      \
    \  n--;\n        return true;\n      }\n      t = key < t->k ? t->l : t->r;\n\
    \    }\n    return false;\n  }\n\n  /**\n   * @brief \u6307\u5B9A\u3057\u305F\u8981\
    \u7D20\u306E\u5168\u524A\u9664\n   * \n   * @param key \n   * @return int \u524A\
    \u9664\u3057\u305F\u8981\u7D20\u6570\n   */\n  int removeAll(T key) {\n    Tree\
    \ t = root;\n    while (t) {\n      if (key == t->k) {\n        int ret = t->c;\n\
    \        n -= ret;\n        remove(root, key);\n        return ret;\n      }\n\
    \      t = key < t->k ? t->l : t->r;\n    }\n    return 0;\n  }\n\n  int count(T\
    \ key) {\n    Tree t = root;\n    while (t) {\n      if (key == t->k) {\n    \
    \    return t->c;\n      }\n      t = key < t->k ? t->l : t->r;\n    }\n    return\
    \ 0;\n  }\n\n  T min() {\n    Tree t = root;\n    while (t->l) {\n      t = t->l;\n\
    \    }\n    return t->k;\n  }\n\n  // AOJ\n  void dump(int l, int r) {\n    if\
    \ (root) {\n      dump(root, l, r);\n    }\n  }\n\n  int size() { return n; }\n\
    };\n"
  dependsOn:
  - cpp/template/small_template.hpp
  - cpp/random/xorshift.hpp
  isVerificationFile: false
  path: cpp/set/multiset.hpp
  requiredBy: []
  timestamp: '2024-09-18 18:24:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/multi_set.test.cpp
documentation_of: cpp/set/multiset.hpp
layout: document
redirect_from:
- /library/cpp/set/multiset.hpp
- /library/cpp/set/multiset.hpp.html
title: "\u91CD\u8907\u3042\u308A\u306E\u96C6\u5408"
---
