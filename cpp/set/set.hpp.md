---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/template/small_template.hpp
    title: cpp/template/small_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\n// Treap\ntemplate<typename\
    \ T = ll>\nclass TreapSet {\n  struct Xor64 {\n    ull a = 0xAF180B8D7E239CC1;\n\
    \    ull next() {\n      ull x = a;\n      x ^= x << 3;\n      x ^= x >> 35;\n\
    \      x ^= x << 14;\n      return a = x;\n    }\n  };\n  static inline Xor64\
    \ rnd;\n  struct Node {\n    T key;\n    int c = 1;\n    ull priority = rnd.next();\n\
    \    Node *l = nullptr, *r = nullptr;\n    Node(T val): key(val) {}\n  };\n  using\
    \ Tree = Node *;\n  Tree root = nullptr;\n\n  void split(Tree t, T key, Tree &l,\
    \ Tree &r) {\n    if (!t) {\n      l = r = nullptr;\n    } else if (key < t->key)\
    \ {\n      split(t->l, key, l, t->l), r = t;\n    } else {\n      split(t->r,\
    \ key, t->r, r), l = t;\n    }\n  }\n\n  void merge(Tree &t, Tree l, Tree r) {\n\
    \    if (!l || !r) {\n      t = l ? l : r;\n    } else if (l->priority > r->priority)\
    \ {\n      merge(l->r, l->r, r), t = l;\n    } else {\n      merge(r->l, l, r->l),\
    \ t = r;\n    }\n  }\n\n  void insert(Tree &t, Tree item) {\n    if (!t) {\n \
    \     t = item;\n    } else if (item->priority > t->priority) {\n      split(t,\
    \ item->key, item->l, item->r), t = item;\n    } else {\n      insert(item->key\
    \ < t->key ? t->l : t->r, item);\n    }\n  }\n\n  void erase(Tree &t, T key) {\n\
    \    if (t->key == key) {\n      merge(t, t->l, t->r);\n    } else {\n      erase(key\
    \ < t->key ? t->l : t->r, key);\n    }\n  }\n\n  bool find(Tree &t, T key) {\n\
    \    if (!t) {\n      return false;\n    } else if (t->key == key) {\n      return\
    \ true;\n    } else {\n      return find(key < t->key ? t->l : t->r, key);\n \
    \   }\n  }\n\npublic:\n  TreapSet() = default;\n  void add(T key) { insert(root,\
    \ new Node(key)); }\n  void remove(T key) { erase(root, key); }\n  bool count(T\
    \ key) { return count(root, key); }\n  T min() {\n    Tree t = root;\n    while\
    \ (t->l) {\n      t = t->l;\n    }\n    return t->key;\n  }\n};"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/set/set.hpp
  requiredBy: []
  timestamp: '2024-09-10 15:51:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp/set/set.hpp
layout: document
redirect_from:
- /library/cpp/set/set.hpp
- /library/cpp/set/set.hpp.html
title: cpp/set/set.hpp
---
