---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/multi_set.test.cpp
    title: cpp/verify/multi_set.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/multi_set_2.test.cpp
    title: cpp/verify/multi_set_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/multi_set_3.test.cpp
    title: cpp/verify/multi_set_3.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u91CD\u8907\u3042\u308A\u306E\u96C6\u5408"
    links:
    - https://ja.wikipedia.org/wiki/Xorshift
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
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\nnamespace in {\n\
    // https://ja.wikipedia.org/wiki/Xorshift\nclass Xor64 {\n  ull s;\n\npublic:\n\
    \  Xor64(ull s_) : s(s_) {}\n  // [0, 2**64)\n  ull get() {\n    ull x = s;\n\
    \    x ^= x << 7;\n    return s = x ^ (x >> 9);\n  }\n};\nstatic inline Xor64\
    \ rnd = Xor64(192865741288175612ull);\ntemplate <class T = ll> struct Node {\n\
    \  T k;\n  ull p = rnd.get();\n  size_t c = 1;  // \u500B\u6570\n  size_t cr =\
    \ 1; // \u90E8\u5206\u6728\u3092\u5408\u308F\u305B\u305F\u500B\u6570\n  Node *l,\
    \ *r;\n  static int node_count;\n  static Node *const nil;\n  Node(T key, size_t\
    \ c_ = 1) : k(key), c(c_), cr(c_), l(nil), r(nil) {}\n  // nil\u7528\n  Node(T\
    \ key, ull p_, size_t c_)\n      : k(key), p(p_), c(c_), cr(c_), l(nullptr), r(nullptr)\
    \ {}\n  friend ostream &operator<<(ostream &os, const Node &t) {\n    os << \"\
    [\" << &t << \"](k=\" << t.k << \", p=\" << t.p << \", c=\" << t.c\n       <<\
    \ \", cr=\" << t.cr << \", l=\" << t.l << \", r=\" << t.r << \")\";\n    return\
    \ os;\n  }\n};\ntemplate <class T> Node<T> *const Node<T>::nil = new Node<T>({},\
    \ 0, 0);\n} // namespace in\n\n/**\n * @brief \u91CD\u8907\u3042\u308A\u306E\u96C6\
    \u5408\n * \u633F\u5165 O(log n)\n * \u524A\u9664 O(log n)\n * \u691C\u7D22 O(log\
    \ n)\n * \u5B9F\u88C5\uFF1ATreap https://xuzijian629.hatenablog.com/entry/2018/12/08/000452\n\
    \ * @tparam T \u8981\u7D20\u306E\u578B\n */\ntemplate <class T = ll> class TreeMultiSet\
    \ {\n  using Tree = in::Node<T> *;\n  const Tree nil = in::Node<T>::nil;\n  Tree\
    \ root = in::Node<T>::nil;\n  size_t n_ = 0;\n\n  void update_cr(Tree t) {\n \
    \   if (t != nil) {\n      t->cr = t->c;\n      t->cr += t->l->cr;\n      t->cr\
    \ += t->r->cr;\n    }\n  }\n\n  void split(Tree t, T key, Tree &l, Tree &r) {\n\
    \    if (t == nil) {\n      l = r = nil;\n    } else if (key < t->k) {\n     \
    \ split(t->l, key, l, t->l);\n      r = t;\n    } else {\n      split(t->r, key,\
    \ t->r, r);\n      l = t;\n    }\n    update_cr(t);\n  }\n\n  void merge(Tree\
    \ &t, Tree l, Tree r) {\n    if (l == nil) {\n      t = r;\n    } else if (r ==\
    \ nil) {\n      t = l;\n    } else if (l->p > r->p) {\n      merge(l->r, l->r,\
    \ r);\n      t = l;\n    } else {\n      merge(r->l, l, r->l);\n      t = r;\n\
    \    }\n    update_cr(t);\n  }\n\n  void insert(Tree &t, Tree item) {\n    if\
    \ (t == nil) {\n      t = item;\n    } else if (item->p > t->p) {\n      split(t,\
    \ item->k, item->l, item->r);\n      t = item;\n    } else {\n      insert(item->k\
    \ < t->k ? t->l : t->r, item);\n    }\n    update_cr(t);\n  }\n\n  void remove(Tree\
    \ &t, T key) {\n    if (t->k == key) {\n      merge(t, t->l, t->r);\n    } else\
    \ {\n      remove(key < t->k ? t->l : t->r, key);\n    }\n    update_cr(t);\n\
    \  }\n\n  // AOJ\n  void aoj_dump(Tree &t, T l, T r) {\n    if (t->l != nil &&\
    \ t->k > l) {\n      aoj_dump(t->l, l, r);\n    }\n    if (l <= t->k && t->k <=\
    \ r) {\n      for (size_t i = 0; i < t->c; i++) {\n        cout << t->k << '\\\
    n';\n      }\n    }\n    if (t->r != nil && t->k < r) {\n      aoj_dump(t->r,\
    \ l, r);\n    }\n  }\n\n  void print(Tree t) {\n    if (t != nil) {\n      cout\
    \ << (*t) << \"\\n\";\n      if (t->l) {\n        print(t->l);\n      }\n    \
    \  if (t->r) {\n        print(t->r);\n      }\n    }\n  }\n\n  // \u691C\u8A3C\
    \n  void verify(Tree t, size_t &n_v) {\n    if (t != nil) {\n      n_v += t->c;\n\
    \      size_t cr = t->c;\n      if (t->l) {\n        cr += t->l->cr;\n      }\n\
    \      if (t->r) {\n        cr += t->r->cr;\n      }\n      if (cr != t->cr) {\n\
    \        print(root);\n        cout.flush();\n        assert(false);\n      }\n\
    \      if (t->l) {\n        verify(t->l, n_v);\n      }\n      if (t->r) {\n \
    \       verify(t->r, n_v);\n      }\n    }\n  }\n\n  T find_by_order(Tree t, size_t\
    \ k) {\n    assert(t != nil);\n    size_t sz_l = t->l ? t->l->cr : 0;\n    if\
    \ (k < sz_l) {\n      return find_by_order(t->l, k);\n    } else if (k < sz_l\
    \ + t->c) {\n      return t->k;\n    } else {\n      return find_by_order(t->r,\
    \ k - sz_l - t->c);\n    }\n  }\n\n  void enumerate_in(vector<tuple<T, size_t,\
    \ T>> &v, Tree t, const T &l,\n                    const T &r, Tree parent) {\n\
    \    if (t->l != nil && l < t->k) {\n      enumerate_in(v, t->l, l, r, t);\n \
    \   }\n    if (l <= t->k && t->k < r) {\n      v.emplace_back(t->k, t->c, parent\
    \ ? parent->k : -1);\n    }\n    if (t->r != nil && t->k < r - 1) {\n      enumerate_in(v,\
    \ t->r, l, r, t);\n    }\n  }\n\n  void enumerate_all_in(vector<tuple<T, size_t,\
    \ T>> &v, Tree t, Tree parent) {\n    if (t->l != nil) {\n      enumerate_all_in(v,\
    \ t->l, t);\n    }\n    v.emplace_back(t->k, t->c, parent ? parent->k : -1);\n\
    \    if (t->r != nil) {\n      enumerate_all_in(v, t->r, t);\n    }\n  }\n\npublic:\n\
    \  TreeMultiSet() = default;\n\n  /**\n   * @brief \u8981\u7D20\u306En\u500B\u8FFD\
    \u52A0\n   *\n   * @param key\n   * @return size_t \u8FFD\u52A0\u5F8C\u306E\u540C\
    \u3058\u8981\u7D20\u306E\u6570\n   */\n  size_t add(T key, size_t n = 1) {\n \
    \   n_ += n;\n    Tree t = root;\n    bool found = false;\n    while (t != nil)\
    \ {\n      if (key == t->k) {\n        found = true;\n        break;\n      }\n\
    \      t = key < t->k ? t->l : t->r;\n    }\n    if (found) {\n      t = root;\n\
    \      while (t != nil) {\n        t->cr += n;\n        if (key == t->k) {\n \
    \         t->c += n;\n          return t->c;\n        }\n        t = key < t->k\
    \ ? t->l : t->r;\n      }\n    } else {\n      in::Node<T> *node = new in::Node<T>(key,\
    \ n);\n      insert(root, node);\n    }\n    return n;\n  }\n\n  /**\n   * @brief\
    \ \u6307\u5B9A\u3057\u305F\u8981\u7D20\u306En\u500B\u524A\u9664\n   * \u8981\u7D20\
    \u304Cn\u500B\u3092\u4E0B\u56DE\u308B\u5834\u5408\u306F\u4F55\u3082\u3057\u306A\
    \u3044\n   *\n   * @param key\n   * @return bool \u524A\u9664\u51FA\u6765\u305F\
    \u5834\u5408true\n   */\n  bool remove(T key, size_t n = 1) {\n    Tree t = root;\n\
    \    bool found = false;\n    while (t != nil) {\n      if (key == t->k) {\n \
    \       if (t->c == n) {\n          n_ -= n;\n          remove(root, key);\n \
    \       } else if (t->c > n) {\n          n_ -= n;\n          t->c -= n;\n   \
    \       found = true;\n          break;\n        } else {\n          return false;\n\
    \        }\n        return false;\n      }\n      t = key < t->k ? t->l : t->r;\n\
    \    }\n    if (found) {\n      t = root;\n      while (t != nil) {\n        t->cr\
    \ -= n;\n        if (key == t->k) {\n          return true;\n        }\n     \
    \   t = key < t->k ? t->l : t->r;\n      }\n    }\n    return false;\n  }\n\n\
    \  /**\n   * @brief \u6307\u5B9A\u3057\u305F\u8981\u7D20\u306E\u5168\u524A\u9664\
    \n   *\n   * @param key\n   * @return size_t \u524A\u9664\u3057\u305F\u8981\u7D20\
    \u6570\n   */\n  size_t remove_all(T key) {\n    Tree t = root;\n    while (t\
    \ != nil) {\n      if (key == t->k) {\n        size_t ret = t->c;\n        n_\
    \ -= ret;\n        remove(root, key);\n        return ret;\n      }\n      t =\
    \ key < t->k ? t->l : t->r;\n    }\n    return 0;\n  }\n\n  // \u691C\u7D22 \u500B\
    \u6570\u3092\u8FD4\u3059 O(log n)\n  size_t count(T key) {\n    Tree t = root;\n\
    \    while (t != nil) {\n      if (key == t->k) {\n        return t->c;\n    \
    \  }\n      t = key < t->k ? t->l : t->r;\n    }\n    return 0;\n  }\n\n  // \u691C\
    \u7D22 \u306A\u3044\u5834\u5408\u3001\u691C\u7D22\u5024\u3088\u308A\u5C0F\u3055\
    \u3044\u4E2D\u3067\u6700\u5927\u306E\u8981\u7D20\u307E\u305F\u306F\u7121\u52B9\
    \u5024\n  optional<T> find_lower(T key) {\n    Tree t = root;\n    Tree lower\
    \ = nil;\n\n    while (t != nil) {\n      if (key == t->k) {\n        return key;\n\
    \      } else if (key < t->k) {\n        t = t->l;\n      } else {\n        lower\
    \ = t;\n        t = t->r;\n      }\n    }\n    return lower != nil ? optional(lower->k)\
    \ : nullopt;\n  }\n\n  // \u691C\u7D22 \u306A\u3044\u5834\u5408\u3001\u691C\u7D22\
    \u5024\u3088\u308A\u5927\u304D\u3044\u4E2D\u3067\u6700\u5C0F\u306E\u8981\u7D20\
    \u307E\u305F\u306F\u7121\u52B9\u5024\n  optional<T> find_upper(T key) {\n    Tree\
    \ t = root;\n    Tree upper = nil;\n    while (t != nil) {\n      if (key == t->k)\
    \ {\n        return key;\n      } else if (key < t->k) {\n        upper = t;\n\
    \        t = t->l;\n      } else {\n        t = t->r;\n      }\n    }\n    return\
    \ upper != nil ? optional(upper->k) : nullopt;\n  }\n\n  // \u691C\u7D22 \u9806\
    \u4F4D(0-indexed)\u306E\u533A\u9593\u3092\u8FD4\u3059 O(log n)\n  // \u5B58\u5728\
    \u3057\u306A\u3044\u5834\u5408\u3001-1,-1\n  pair<int, int> rank(T key) {\n  \
    \  Tree t = root;\n    int rnk = 0;\n    while (t != nil) {\n      if (key ==\
    \ t->k) {\n        rnk += t->l ? t->l->cr : 0;\n        return {rnk, rnk + t->c};\n\
    \      } else if (key < t->k) {\n        t = t->l;\n      } else {\n        rnk\
    \ += t->c;\n        rnk += t->l ? t->l->cr : 0;\n        t = t->r;\n      }\n\
    \    }\n    return {-1, -1};\n  }\n\n  T min() {\n    Tree t = root;\n    assert(root);\n\
    \    while (t->l != nil) {\n      t = t->l;\n    }\n    return t->k;\n  }\n\n\
    \  T max() {\n    Tree t = root;\n    assert(root);\n    while (t->r != nil) {\n\
    \      t = t->r;\n    }\n    return t->k;\n  }\n\n  // K\u756A\u76EE\u306E\u8981\
    \u7D20(0-indexed)\n  T get_kth(size_t k) {\n    assert(k < n_);\n    return find_by_order(root,\
    \ k);\n  }\n\n  // l <= k < r \u3092\u6E80\u305F\u3059\u8981\u7D20\u306E\u5217\
    \u6319\n  vector<tuple<T, size_t, T>> enumerate(const T &l, const T &r) {\n  \
    \  vector<tuple<T, size_t, T>> ret;\n    if (root != nil) {\n      enumerate_in(ret,\
    \ root, l, r);\n    }\n    return ret;\n  }\n\n  // \u5168\u8981\u7D20\u306E\u5217\
    \u6319\n  vector<tuple<T, size_t, T>> enumerate_all() {\n    vector<tuple<T, size_t,\
    \ T>> ret;\n    if (root != nil) {\n      enumerate_all_in(ret, root, nullptr);\n\
    \    }\n    return ret;\n  }\n\n  // AOJ\n  void aoj_dump(const T &l, const T\
    \ &r) {\n    if (root != nil) {\n      aoj_dump(root, l, r);\n    }\n  }\n\n \
    \ size_t size() { return n_; }\n\n  void verify() {\n    if (root != nil) {\n\
    \      // \u7DCF\u6570\u304Cn_\u306B\u4E00\u81F4\n      size_t n_v = 0;\n    \
    \  verify(root, n_v);\n      assert(n_ == n_v);\n    }\n  }\n};"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/set/multiset.hpp
  requiredBy: []
  timestamp: '2024-12-03 01:33:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/multi_set.test.cpp
  - cpp/verify/multi_set_3.test.cpp
  - cpp/verify/multi_set_2.test.cpp
documentation_of: cpp/set/multiset.hpp
layout: document
redirect_from:
- /library/cpp/set/multiset.hpp
- /library/cpp/set/multiset.hpp.html
title: "\u91CD\u8907\u3042\u308A\u306E\u96C6\u5408"
---
