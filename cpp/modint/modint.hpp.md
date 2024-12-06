---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: cpp/fps/convolution.hpp
    title: cpp/fps/convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/combination.test.cpp
    title: cpp/verify/combination.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/convolution_ll.test.cpp
    title: cpp/verify/convolution_ll.test.cpp
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
    \ on ACL\n * @tparam mod \u7D20\u6570\u306B\u9650\u308B\n */\ntemplate <uint32_t\
    \ m, enable_if_t<(2 <= m)> * = nullptr> class ModInt {\n  uint32_t x;\n\npublic:\n\
    \  constexpr ModInt() : x(0) {}\n  template <class T, enable_if_t<is_signed_v<T>>\
    \ * = nullptr>\n  constexpr ModInt(T x_) : x(x_ < 0 ? x_ % (ll)m + (ll)m : x_\
    \ % (ll)m) {}\n  template <class U, enable_if_t<!is_signed_v<U>> * = nullptr>\n\
    \  constexpr ModInt(U x_) : x(x_ % m) {}\n\n  uint32_t get() const { return x;\
    \ }\n  static constexpr uint32_t mod() { return m; }\n  template <class T, enable_if_t<is_signed_v<T>>\
    \ * = nullptr>\n  constexpr void set(T x_) {\n    x = x_ < 0 ? x_ % (ll)m + (ll)m\
    \ : x_ % (ll)m;\n  }\n  template <class U, enable_if_t<!is_signed_v<U>> * = nullptr>\n\
    \  constexpr void set(U x_) {\n    x = x_ % m;\n  }\n\n  constexpr ModInt operator++(int)\
    \ {\n    ModInt y = *this;\n    ++*this;\n    return y;\n  }\n  constexpr ModInt\
    \ &operator++() {\n    x = x == m - 1 ? 0u : x + 1;\n    return *this;\n  }\n\
    \  constexpr ModInt operator--(int) {\n    ModInt y = *this;\n    --*this;\n \
    \   return y;\n  }\n  constexpr ModInt &operator--() {\n    x = x == 0u ? m -\
    \ 1 : x - 1;\n    return *this;\n  }\n  constexpr ModInt &operator+=(const ModInt\
    \ &y) {\n    x += y.x;\n    if (x >= m) {\n      x -= m;\n    }\n    return *this;\n\
    \  }\n  constexpr ModInt &operator-=(const ModInt &y) {\n    x -= y.x;\n    if\
    \ (x >= m) {\n      x += m;\n    }\n    return *this;\n  }\n  constexpr ModInt\
    \ &operator*=(const ModInt &y) {\n    x = (ull)x * (ull)y.x % m;\n    return *this;\n\
    \  }\n  constexpr ModInt &operator/=(const ModInt &y) { return *this *= y.inv();\
    \ }\n  constexpr ModInt operator+() const { return *this; }\n  constexpr ModInt\
    \ operator-() const { return ModInt(m - x); }\n\n  constexpr ModInt pow(ll n)\
    \ const {\n    if (n < 0) {\n      return pow(-n).inv();\n    }\n    ModInt y\
    \ = *this, r = 1;\n    while (n) {\n      if (n & 1) {\n        r *= y;\n    \
    \  }\n      y *= y;\n      n >>= 1;\n    }\n    return r;\n  }\n  constexpr ModInt\
    \ inv() const {\n    assert(x);\n    return pow(m - 2);\n  }\n\n  constexpr friend\
    \ ModInt operator+(const ModInt &a, const ModInt &b) {\n    return ModInt(a) +=\
    \ b;\n  }\n  constexpr friend ModInt operator-(const ModInt &a, const ModInt &b)\
    \ {\n    return ModInt(a) -= b;\n  }\n  constexpr friend ModInt operator*(const\
    \ ModInt &a, const ModInt &b) {\n    return ModInt(a) *= b;\n  }\n  constexpr\
    \ friend ModInt operator/(const ModInt &a, const ModInt &b) {\n    return ModInt(a)\
    \ /= b;\n  }\n  constexpr friend bool operator==(const ModInt &a, const ModInt\
    \ &b) {\n    return a.x == b.x;\n  }\n  constexpr friend bool operator!=(const\
    \ ModInt &a, const ModInt &b) {\n    return a.x != b.x;\n  }\n\n  friend istream\
    \ &operator>>(istream &is, ModInt &t) {\n    ll y;\n    is >> y;\n    t.set(y);\n\
    \    return is;\n  }\n  friend ostream &operator<<(ostream &os, const ModInt &t)\
    \ {\n    os << t.x;\n    return os;\n  }\n};\n\nusing mint = ModInt<998244353u>;\n\
    using mint17 = ModInt<1000000007u>;\n\nconst int MAX_FAC = 20000003;\nmint fac[MAX_FAC];\n\
    \n// combination\nconstexpr mint C(int n, int k) { return fac[n] / (fac[k] * fac[n\
    \ - k]); }\n\nconstexpr void init() {\n  fac[0] = 1;\n  for (int i = 1; i < MAX_FAC;\
    \ i++) {\n    fac[i] = fac[i - 1] * i;\n  }\n}\n"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/modint/modint.hpp
  requiredBy:
  - cpp/fps/convolution.hpp
  timestamp: '2024-11-24 09:02:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/point_set_range_composite.test.cpp
  - cpp/verify/combination.test.cpp
  - cpp/verify/convolution_ll.test.cpp
documentation_of: cpp/modint/modint.hpp
layout: document
redirect_from:
- /library/cpp/modint/modint.hpp
- /library/cpp/modint/modint.hpp.html
title: "\u5270\u4F59\u3092\u53D6\u308A[0, mod)\u306B\u53CE\u3081\u308Bint"
---