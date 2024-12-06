---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/rolling_hash.test.cpp
    title: cpp/verify/rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/rolling_hash_2.test.cpp
    title: cpp/verify/rolling_hash_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
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
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\nnamespace rh_in\
    \ {\nconstexpr ull M30 = (1ul << 30) - 1;\nconstexpr ull M31 = (1ul << 31) - 1;\n\
    constexpr ull M61 = (1ul << 61) - 1;\nconstexpr int SZ_BASE = 16;\nconstexpr ull\
    \ base[SZ_BASE] = {131, 137, 139, 149, 151, 157, 163, 167,\n                 \
    \              173, 179, 181, 191, 193, 197, 199, 211};\nconstexpr ull mul(ull\
    \ a, ull b) {\n  ull au = a >> 31;\n  ull ad = a & M31;\n  ull bu = b >> 31;\n\
    \  ull bd = b & M31;\n  ull mid = ad * bu + au * bd;\n  ull midu = mid >> 30;\n\
    \  ull midd = mid & M30;\n  return au * bu * 2 + midu + (midd << 31) + ad * bd;\n\
    }\nconstexpr ull mod(ull x) {\n  ull xu = x >> 61;\n  ull xd = x & M61;\n  ull\
    \ res = xu + xd;\n  if (res >= M61) {\n    res -= M61;\n  }\n  return res;\n}\n\
    vector<char> to_vec_char(const string &s) {\n  vector<char> vc(s.size());\n  for\
    \ (int i = 0; i < (int)s.size(); i++) {\n    vc[i] = s[i];\n  }\n  return vc;\n\
    }\n}; // namespace rh_in\n\n// https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    class RollingHash {\n  vector<ull> hash_sum_[rh_in::SZ_BASE];\n  vector<ull> pows[rh_in::SZ_BASE];\n\
    \  int n_;\n  int strength_;\n\n  template <class T> void build(const vector<T>\
    \ &s, int i_base) {\n    ull b = rh_in::base[i_base];\n    hash_sum_[i_base].resize(n_\
    \ + 1);\n    pows[i_base].resize(n_ + 1);\n    pows[i_base][0] = 1;\n    for (int\
    \ i = 0; i < n_; i++) {\n      hash_sum_[i_base][i + 1] =\n          rh_in::mod(rh_in::mul(hash_sum_[i_base][i],\
    \ b) + s[i]);\n      pows[i_base][i + 1] = rh_in::mod(rh_in::mul(pows[i_base][i],\
    \ b));\n    }\n  }\n\n  template <class T> ull hash_all(const vector<T> &t, int\
    \ i_base) const {\n    int n_t = t.size();\n    ull hash_t = 0;\n    for (int\
    \ i = 0; i < n_t; i++) {\n      hash_t = rh_in::mod(rh_in::mul(hash_t, rh_in::base[i_base])\
    \ + t[i]);\n    }\n    return hash_t;\n  }\n  template <class T> vector<ull> hash_all(const\
    \ vector<T> &t) const {\n    vector<ull> h(strength_);\n    for (int i = 0; i\
    \ < strength_; i++) {\n      h[i] = hash_all(t, i);\n    }\n    return h;\n  }\n\
    \n  ull hash(int l, int r, int i_base) const {\n    return rh_in::mod(hash_sum_[i_base][r]\
    \ + (rh_in::M61 << 2) -\n                      rh_in::mul(hash_sum_[i_base][l],\
    \ pows[i_base][r - l]));\n  }\n\n  bool match(int l, int r, const vector<ull>\
    \ &h) const {\n    for (int i_base = 0; i_base < strength_; i_base++) {\n    \
    \  if (hash(l, r, i_base) != h[i_base]) {\n        return false;\n      }\n  \
    \  }\n    return true;\n  }\n\npublic:\n  RollingHash(const string &s, int strength\
    \ = 1)\n      : n_(s.size()), strength_(strength) {\n    assert(strength <= rh_in::SZ_BASE);\n\
    \    for (int i = 0; i < strength; i++) {\n      build(rh_in::to_vec_char(s),\
    \ i);\n    }\n  }\n  // T: 4\u30D0\u30A4\u30C8\u4EE5\u4E0B\u306E\u6574\u6570\u578B\
    \n  template <class T>\n  RollingHash(const vector<T> &s, int strength = 1)\n\
    \      : n_(s.size()), strength_(strength) {\n    assert(strength <= rh_in::SZ_BASE);\n\
    \    for (int i = 0; i < strength; i++) {\n      build(s, i);\n    }\n  }\n\n\
    \  // [l, r)\n  vector<ull> hash(int l, int r) const {\n    assert(0 <= l);\n\
    \    assert(l <= r);\n    assert(r <= n_);\n    vector<ull> h(strength_);\n  \
    \  for (int i = 0; i < strength_; i++) {\n      h[i] = hash(l, r, i);\n    }\n\
    \    return h;\n  }\n  // [0,a)\n  vector<ull> hash(int a) const { return hash(0,\
    \ a); }\n\n  // \u306A\u3044\u5834\u5408\u306Fnpos\n  size_t match(const string\
    \ &t) const { return match(rh_in::to_vec_char(t)); }\n  // \u306A\u3044\u5834\u5408\
    \u306Fnpos\n  template <class T> size_t match(const vector<T> &t) const {\n  \
    \  int n_t = t.size();\n    if (n_t > n_) {\n      return string::npos;\n    }\n\
    \    vector<ull> ht = hash_all(t);\n    for (int i = 0; i <= n_ - n_t; i++) {\n\
    \      if (match(i, i + n_t, ht)) {\n        return i;\n      }\n    }\n    return\
    \ string::npos;\n  }\n\n  // \u306A\u3044\u5834\u5408\u306Fnpos\n  size_t match_custom(const\
    \ string &t, const vector<int> &idx) const {\n    return match_custom(rh_in::to_vec_char(t),\
    \ idx);\n  }\n  // \u306A\u3044\u5834\u5408\u306Fnpos\n  template <class T>\n\
    \  size_t match_custom(const vector<T> &t, const vector<int> &idx) const {\n \
    \   int n_t = t.size();\n    if (n_t > n_) {\n      return string::npos;\n   \
    \ }\n    vector<ull> ht = hash_all(t);\n    for (int i = 0; i < (int)idx.size();\
    \ i++) {\n      assert(0 <= idx[i]);\n      assert(idx[i] <= n_ - n_t);\n    \
    \  if (match(idx[i], idx[i] + n_t, ht)) {\n        return idx[i];\n      }\n \
    \   }\n    return string::npos;\n  }\n\n  bool starts_with(const string &t) const\
    \ {\n    return starts_with(rh_in::to_vec_char(t));\n  }\n  template <class T>\
    \ bool starts_with(const vector<T> &t) const {\n    int n_t = t.size();\n    if\
    \ (n_t > n_) {\n      return false;\n    }\n    vector<ull> ht = hash_all(t);\n\
    \    return match(0, n_t, ht);\n  }\n\n  bool ends_with(const string &t) const\
    \ {\n    return ends_with(rh_in::to_vec_char(t));\n  }\n  template <class T> bool\
    \ ends_with(const vector<T> &t) const {\n    int n_t = t.size();\n    if (n_t\
    \ > n_) {\n      return false;\n    }\n    vector<ull> ht = hash_all(t);\n   \
    \ return match(n_ - n_t, n_, ht);\n  }\n};\n\n// https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    class SimpleRollingHash {\n  static constexpr ull base = 131;\n  vector<ull> hash_sum_;\n\
    \  vector<ull> pows;\n  int n_;\n\n  template <class T> void build(const vector<T>\
    \ &s) {\n    hash_sum_.resize(n_ + 1);\n    pows.resize(n_ + 1);\n    pows[0]\
    \ = 1;\n    for (int i = 0; i < n_; i++) {\n      hash_sum_[i + 1] = rh_in::mod(rh_in::mul(hash_sum_[i],\
    \ base) + s[i]);\n      pows[i + 1] = rh_in::mod(rh_in::mul(pows[i], base));\n\
    \    }\n  }\n\n  template <class T> ull hash_all(const vector<T> &t) const {\n\
    \    int n_t = t.size();\n    ull hash_t = 0;\n    for (int i = 0; i < n_t; i++)\
    \ {\n      hash_t = rh_in::mod(rh_in::mul(hash_t, base) + t[i]);\n    }\n    return\
    \ hash_t;\n  }\n\npublic:\n  SimpleRollingHash(const string &s) : n_(s.size())\
    \ {\n    build(rh_in::to_vec_char(s));\n  }\n  // T: 4\u30D0\u30A4\u30C8\u4EE5\
    \u4E0B\u306E\u6574\u6570\u578B\n  template <class T> SimpleRollingHash(const vector<T>\
    \ &s) : n_(s.size()) {\n    build(s);\n  }\n\n  // [l, r)\n  ull hash(int l, int\
    \ r) const {\n    return rh_in::mod(hash_sum_[r] + (rh_in::M61 << 2) -\n     \
    \                 rh_in::mul(hash_sum_[l], pows[r - l]));\n  }\n  // [0,a)\n \
    \ ull hash(int a) const { return hash(0, a); }\n\n  // \u306A\u3044\u5834\u5408\
    \u306Fnpos\n  size_t match(const string &t) const { return match(rh_in::to_vec_char(t));\
    \ }\n  // \u306A\u3044\u5834\u5408\u306Fnpos\n  template <class T> size_t match(const\
    \ vector<T> &t) const {\n    int n_t = t.size();\n    if (n_t > n_) {\n      return\
    \ string::npos;\n    }\n    ull h_t = hash_all(t);\n    for (int i = 0; i <= n_\
    \ - n_t; i++) {\n      if (hash(i, i + n_t) == h_t) {\n        return i;\n   \
    \   }\n    }\n    return string::npos;\n  }\n\n  // \u306A\u3044\u5834\u5408\u306F\
    npos\n  size_t match_custom(const string &t, const vector<int> &idx) const {\n\
    \    return match_custom(rh_in::to_vec_char(t), idx);\n  }\n  // \u306A\u3044\u5834\
    \u5408\u306Fnpos\n  template <class T>\n  size_t match_custom(const vector<T>\
    \ &t, const vector<int> &idx) const {\n    int n_t = t.size();\n    if (n_t >\
    \ n_) {\n      return string::npos;\n    }\n    ull h_t = hash_all(t);\n    for\
    \ (int i = 0; i < (int)idx.size(); i++) {\n      assert(0 <= idx[i]);\n      assert(idx[i]\
    \ <= n_ - n_t);\n      if (hash(idx[i], idx[i] + n_t) == h_t) {\n        return\
    \ idx[i];\n      }\n    }\n    return string::npos;\n  }\n\n  bool starts_with(const\
    \ string &t) const {\n    return starts_with(rh_in::to_vec_char(t));\n  }\n  template\
    \ <class T> bool starts_with(const vector<T> &t) const {\n    int n_t = t.size();\n\
    \    if (n_t > n_) {\n      return false;\n    }\n    ull h_t = hash_all(t);\n\
    \    return hash(0, n_t) == h_t;\n  }\n\n  bool ends_with(const string &t) const\
    \ {\n    return ends_with(rh_in::to_vec_char(t));\n  }\n  template <class T> bool\
    \ ends_with(const vector<T> &t) const {\n    int n_t = t.size();\n    if (n_t\
    \ > n_) {\n      return false;\n    }\n    ull h_t = hash_all(t);\n    return\
    \ hash(n_ - n_t, n_) == h_t;\n  }\n};"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2024-11-07 00:23:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/rolling_hash.test.cpp
  - cpp/verify/rolling_hash_2.test.cpp
documentation_of: cpp/string/rolling_hash.hpp
layout: document
redirect_from:
- /library/cpp/string/rolling_hash.hpp
- /library/cpp/string/rolling_hash.hpp.html
title: cpp/string/rolling_hash.hpp
---
