---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: cpp/random/xorshift.hpp
    title: cpp/random/xorshift.hpp
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u91CD\u8907\u306A\u3057\u306E\u96C6\u5408"
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: random/xorshift.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"random/xorshift.hpp\"\n#include \"template/small_template.hpp\"\
    \n\n/**\n * @brief \u91CD\u8907\u306A\u3057\u306E\u96C6\u5408\n * \u633F\u5165\
    \ O(log n)\n * \u524A\u9664 O(log n)\n * \u691C\u7D22 O(log n)\n * \u5B9F\u88C5\
    \uFF1ATreap https://xuzijian629.hatenablog.com/entry/2018/12/08/000452\n * @tparam\
    \ T \u8981\u7D20\u306E\u578B\n */\ntemplate <typename T = ll> class TreeSet {\n\
    \  static inline Xor64 rnd = Xor64(192865741288375612ull);\n  struct Node {\n\
    \    T k;\n    ull p = rnd.get();\n    Node *l = nullptr, *r = nullptr;\n    Node(T\
    \ key) : k(key) {}\n  };\n  using Tree = Node *;\n  Tree root = nullptr;\n  int\
    \ n = 0;\n\n  void split(Tree t, T key, Tree &l, Tree &r) {\n    if (!t) {\n \
    \     l = r = nullptr;\n    } else if (key < t->k) {\n      split(t->l, key, l,\
    \ t->l);\n      r = t;\n    } else {\n      split(t->r, key, t->r, r);\n     \
    \ l = t;\n    }\n  }\n\n  void merge(Tree &t, Tree l, Tree r) {\n    if (!l ||\
    \ !r) {\n      t = l ? l : r;\n    } else if (l->p > r->p) {\n      merge(l->r,\
    \ l->r, r);\n      t = l;\n    } else {\n      merge(r->l, l, r->l);\n      t\
    \ = r;\n    }\n  }\n\n  void insert(Tree &t, Tree item) {\n    if (!t) {\n   \
    \   t = item;\n    } else if (item->p > t->p) {\n      split(t, item->k, item->l,\
    \ item->r);\n      t = item;\n    } else {\n      insert(item->k < t->k ? t->l\
    \ : t->r, item);\n    }\n  }\n\n  void remove(Tree &t, T key) {\n    if (t->k\
    \ == key) {\n      merge(t, t->l, t->r);\n    } else {\n      remove(key < t->k\
    \ ? t->l : t->r, key);\n    }\n  }\n\n  bool find(Tree &t, T key) {\n    if (!t)\
    \ {\n      return false;\n    } else if (t->k == key) {\n      return true;\n\
    \    } else {\n      return find(key < t->k ? t->l : t->r, key);\n    }\n  }\n\
    \npublic:\n  TreeSet() = default;\n  void add(T key) {\n    n++;\n    insert(root,\
    \ new Node(key));\n  }\n  void remove(T key) {\n    n--;\n    remove(root, key);\n\
    \  }\n  bool find(T key) { return find(root, key); }\n  T min() {\n    Tree t\
    \ = root;\n    while (t->l) {\n      t = t->l;\n    }\n    return t->k;\n  }\n\
    \  T max() {\n    Tree t = root;\n    while (t->r) {\n      t = t->r;\n    }\n\
    \    return t->k;\n  }\n\n  int size() { return n; }\n};\n"
  dependsOn:
  - cpp/random/xorshift.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/set/set.hpp
  requiredBy: []
  timestamp: '2024-11-12 22:03:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp/set/set.hpp
layout: document
redirect_from:
- /library/cpp/set/set.hpp
- /library/cpp/set/set.hpp.html
title: "\u91CD\u8907\u306A\u3057\u306E\u96C6\u5408"
---
