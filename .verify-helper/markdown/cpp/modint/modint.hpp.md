---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/template/small_template.hpp
    title: cpp/template/small_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/point_set_range_composite.test.cpp
    title: cpp/verify/point_set_range_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5270\u4F59\u3092\u53D6\u308A[0, mod)\u306B\u53CE\u3081\u308B\
      int"
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
    \ \u5270\u4F59\u3092\u53D6\u308A[0, mod)\u306B\u53CE\u3081\u308Bint\n * based\
    \ on ACL\n * @tparam mod \u7D20\u6570\u306B\u9650\u308B\n */\ntemplate <uint32_t\
    \ mod, enable_if_t<(2 <= mod)> * = nullptr> class ModInt {\n  uint32_t x;\n\n\
    public:\n  constexpr ModInt() : x(0) {}\n  template <class T, enable_if_t<is_signed_v<T>>\
    \ * = nullptr>\n  constexpr ModInt(T x_) : x(x_ < 0 ? x_ % (ll)mod + (ll)mod :\
    \ x_ % (ll)mod) {}\n  template <class U, enable_if_t<!is_signed_v<U>> * = nullptr>\n\
    \  constexpr ModInt(U x_) : x(x_ % mod) {}\n\n  uint32_t get() const { return\
    \ x; }\n  template <class T, enable_if_t<is_signed_v<T>> * = nullptr>\n  constexpr\
    \ void set(T x_) {\n    x = x_ < 0 ? x_ % (ll)mod + (ll)mod : x_ % (ll)mod;\n\
    \  }\n  template <class U, enable_if_t<!is_signed_v<U>> * = nullptr>\n  constexpr\
    \ void set(U x_) {\n    x = x_ % mod;\n  }\n\n  constexpr ModInt operator++(int)\
    \ {\n    ModInt y = *this;\n    ++*this;\n    return y;\n  }\n  constexpr ModInt\
    \ &operator++() {\n    x = x == mod - 1 ? 0u : x + 1;\n    return *this;\n  }\n\
    \  constexpr ModInt operator--(int) {\n    ModInt y = *this;\n    --*this;\n \
    \   return y;\n  }\n  constexpr ModInt &operator--() {\n    x = x == 0u ? mod\
    \ - 1 : x - 1;\n    return *this;\n  }\n  constexpr ModInt &operator+=(const ModInt\
    \ &y) {\n    x += y.x;\n    if (x >= mod) {\n      x -= mod;\n    }\n    return\
    \ *this;\n  }\n  constexpr ModInt &operator-=(const ModInt &y) {\n    x -= y.x;\n\
    \    if (x >= mod) {\n      x += mod;\n    }\n    return *this;\n  }\n  constexpr\
    \ ModInt &operator*=(const ModInt &y) {\n    x = (ull)x * (ull)y.x % mod;\n  \
    \  return *this;\n  }\n  constexpr ModInt &operator/=(const ModInt &y) { return\
    \ *this *= y.inv(); }\n  constexpr ModInt operator+() const { return *this; }\n\
    \  constexpr ModInt operator-() const { return ModInt(mod - x); }\n\n  constexpr\
    \ ModInt pow(ll n) const {\n    if (n < 0) {\n      return pow(-n).inv();\n  \
    \  }\n    ModInt y = *this, r = 1;\n    while (n) {\n      if (n & 1) {\n    \
    \    r *= y;\n      }\n      y *= y;\n      n >>= 1;\n    }\n    return r;\n \
    \ }\n  constexpr ModInt inv() const {\n    assert(x);\n    return pow(mod - 2);\n\
    \  }\n\n  constexpr friend ModInt operator+(const ModInt &a, const ModInt &b)\
    \ {\n    return ModInt(a) += b;\n  }\n  constexpr friend ModInt operator-(const\
    \ ModInt &a, const ModInt &b) {\n    return ModInt(a) -= b;\n  }\n  constexpr\
    \ friend ModInt operator*(const ModInt &a, const ModInt &b) {\n    return ModInt(a)\
    \ *= b;\n  }\n  constexpr friend ModInt operator/(const ModInt &a, const ModInt\
    \ &b) {\n    return ModInt(a) /= b;\n  }\n  constexpr friend bool operator==(const\
    \ ModInt &a, const ModInt &b) {\n    return a.x == b.x;\n  }\n  constexpr friend\
    \ bool operator!=(const ModInt &a, const ModInt &b) {\n    return a.x != b.x;\n\
    \  }\n\n  friend istream &operator>>(istream &is, ModInt &m) {\n    ll y;\n  \
    \  is >> y;\n    m.set(y);\n    return is;\n  }\n  friend ostream &operator<<(ostream\
    \ &os, const ModInt &m) {\n    os << m.x;\n    return os;\n  }\n};\n\nusing mint\
    \ = ModInt<998244353u>;\nusing mint17 = ModInt<1000000007u>;\n\nmint factorial(int\
    \ n) {\n  assert(0 <= n);\n  static int sz_ini = 100000;\n  static int sz = 1;\n\
    \  static vector<mint> fac(1, 1);\n  int sz_new = sz < sz_ini ? sz_ini : n + 1;\n\
    \  if (sz_new > sz) {\n    fac.resize(sz_new);\n    for (int i = sz; i < sz_new;\
    \ i++) {\n      fac[i] = fac[i - 1] * i;\n    }\n    sz = sz_new;\n  }\n  return\
    \ fac[n];\n}\n\nmint factorial_inv(int n) {\n  assert(0 <= n);\n  static int sz_ini\
    \ = 100000;\n  static int sz = 1;\n  static vector<mint> fac_inv(1, 1);\n  int\
    \ sz_new = sz < sz_ini ? sz_ini : n + 1;\n  if (sz_new > sz) {\n    fac_inv.resize(sz_new);\n\
    \    for (int i = sz; i < sz_new; i++) {\n      fac_inv[i] = fac_inv[i - 1] /\
    \ i;\n    }\n    sz = sz_new;\n  }\n  return fac_inv[n];\n}\n\n// combination\n\
    mint C(int n, int k) {\n  assert(0 <= n);\n  assert(0 <= k);\n  assert(k <= n);\n\
    \  return factorial(n) * factorial_inv(k) * factorial_inv(n - k);\n}"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/modint/modint.hpp
  requiredBy: []
  timestamp: '2024-10-06 17:17:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/point_set_range_composite.test.cpp
documentation_of: cpp/modint/modint.hpp
layout: document
redirect_from:
- /library/cpp/modint/modint.hpp
- /library/cpp/modint/modint.hpp.html
title: "\u5270\u4F59\u3092\u53D6\u308A[0, mod)\u306B\u53CE\u3081\u308Bint"
---
