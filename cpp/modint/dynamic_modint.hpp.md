---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/full_tree_dp.test.cpp
    title: cpp/verify/full_tree_dp.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5270\u4F59\u3092\u53D6\u308A[0, mod)\u306B\u53CE\u3081\u308B\
      int"
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
    \ \u5270\u4F59\u3092\u53D6\u308A[0, mod)\u306B\u53CE\u3081\u308Bint\n * based\
    \ on ACL\n * @tparam mod \u7D20\u6570\u306B\u9650\u308B\n */\nstruct DynamicModInt\
    \ {\n  static uint32_t m;\n  uint32_t x;\n\n  DynamicModInt() : x(0) {}\n  template\
    \ <class T, enable_if_t<is_signed_v<T>> * = nullptr>\n  DynamicModInt(T x_) :\
    \ x(x_ < 0 ? x_ % (ll)m + (ll)m : x_ % (ll)m) {}\n  template <class U, enable_if_t<!is_signed_v<U>>\
    \ * = nullptr>\n  DynamicModInt(U x_) : x(x_ % m) {}\n\n  uint32_t get() const\
    \ { return x; }\n  template <class T, enable_if_t<is_signed_v<T>> * = nullptr>\
    \ void set(T x_) {\n    x = x_ < 0 ? x_ % (ll)m + (ll)m : x_ % (ll)m;\n  }\n \
    \ template <class U, enable_if_t<!is_signed_v<U>> * = nullptr> void set(U x_)\
    \ {\n    x = x_ % m;\n  }\n\n  DynamicModInt operator++(int) {\n    DynamicModInt\
    \ y = *this;\n    ++*this;\n    return y;\n  }\n  DynamicModInt &operator++()\
    \ {\n    x = x == m - 1 ? 0u : x + 1;\n    return *this;\n  }\n  DynamicModInt\
    \ operator--(int) {\n    DynamicModInt y = *this;\n    --*this;\n    return y;\n\
    \  }\n  DynamicModInt &operator--() {\n    x = x == 0u ? m - 1 : x - 1;\n    return\
    \ *this;\n  }\n  DynamicModInt &operator+=(const DynamicModInt &y) {\n    x +=\
    \ y.x;\n    if (x >= m) {\n      x -= m;\n    }\n    return *this;\n  }\n  DynamicModInt\
    \ &operator-=(const DynamicModInt &y) {\n    x -= y.x;\n    if (x >= m) {\n  \
    \    x += m;\n    }\n    return *this;\n  }\n  DynamicModInt &operator*=(const\
    \ DynamicModInt &y) {\n    x = (ull)x * (ull)y.x % m;\n    return *this;\n  }\n\
    \  DynamicModInt &operator/=(const DynamicModInt &y) { return *this *= y.inv();\
    \ }\n  DynamicModInt operator+() const { return *this; }\n  DynamicModInt operator-()\
    \ const { return DynamicModInt(m - x); }\n\n  DynamicModInt pow(ll n) const {\n\
    \    if (n < 0) {\n      return pow(-n).inv();\n    }\n    DynamicModInt y = *this,\
    \ r = 1;\n    while (n) {\n      if (n & 1) {\n        r *= y;\n      }\n    \
    \  y *= y;\n      n >>= 1;\n    }\n    return r;\n  }\n  DynamicModInt inv() const\
    \ {\n    assert(x);\n    return pow(m - 2);\n  }\n\n  friend DynamicModInt operator+(const\
    \ DynamicModInt &a,\n                                 const DynamicModInt &b)\
    \ {\n    return DynamicModInt(a) += b;\n  }\n  friend DynamicModInt operator-(const\
    \ DynamicModInt &a,\n                                 const DynamicModInt &b)\
    \ {\n    return DynamicModInt(a) -= b;\n  }\n  friend DynamicModInt operator*(const\
    \ DynamicModInt &a,\n                                 const DynamicModInt &b)\
    \ {\n    return DynamicModInt(a) *= b;\n  }\n  friend DynamicModInt operator/(const\
    \ DynamicModInt &a,\n                                 const DynamicModInt &b)\
    \ {\n    return DynamicModInt(a) /= b;\n  }\n  friend bool operator==(const DynamicModInt\
    \ &a, const DynamicModInt &b) {\n    return a.x == b.x;\n  }\n  friend bool operator!=(const\
    \ DynamicModInt &a, const DynamicModInt &b) {\n    return a.x != b.x;\n  }\n\n\
    \  friend istream &operator>>(istream &is, DynamicModInt &t) {\n    ll y;\n  \
    \  is >> y;\n    t.set(y);\n    return is;\n  }\n  friend ostream &operator<<(ostream\
    \ &os, const DynamicModInt &t) {\n    os << t.x;\n    return os;\n  }\n};\nuint32_t\
    \ DynamicModInt::m = 998244353;\n\nDynamicModInt factorial(int n) {\n  assert(0\
    \ <= n);\n  static const int sz_ini = 100000;\n  static int sz = 1;\n  static\
    \ vector<DynamicModInt> fac(1, 1);\n  int sz_new = max(sz_ini, n + 1);\n  if (sz_new\
    \ > sz) {\n    fac.resize(sz_new);\n    for (int i = sz; i < sz_new; i++) {\n\
    \      fac[i] = fac[i - 1] * i;\n    }\n    sz = sz_new;\n  }\n  return fac[n];\n\
    }\n\nDynamicModInt factorial_inv(int n) {\n  assert(0 <= n);\n  static const int\
    \ sz_ini = 100000;\n  static int sz = 1;\n  static vector<DynamicModInt> fac_inv(1,\
    \ 1);\n  int sz_new = max(sz_ini, n + 1);\n  if (sz_new > sz) {\n    fac_inv.resize(sz_new);\n\
    \    for (int i = sz; i < sz_new; i++) {\n      fac_inv[i] = fac_inv[i - 1] /\
    \ i;\n    }\n    sz = sz_new;\n  }\n  return fac_inv[n];\n}\n\n// combination\n\
    DynamicModInt C(int n, int k) {\n  assert(0 <= n);\n  assert(0 <= k);\n  assert(k\
    \ <= n);\n  return factorial(n) * factorial_inv(k) * factorial_inv(n - k);\n}"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/modint/dynamic_modint.hpp
  requiredBy: []
  timestamp: '2024-11-16 13:35:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/full_tree_dp.test.cpp
documentation_of: cpp/modint/dynamic_modint.hpp
layout: document
redirect_from:
- /library/cpp/modint/dynamic_modint.hpp
- /library/cpp/modint/dynamic_modint.hpp.html
title: "\u5270\u4F59\u3092\u53D6\u308A[0, mod)\u306B\u53CE\u3081\u308Bint"
---
