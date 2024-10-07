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
  bundledCode: "Traceback (most recent call last):\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: template/small_template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\ntemplate<typename\
    \ T = ll>\nclass Ratio {\n  // n / d\n  T n, d;\n\n  void normalize() {\n    if\
    \ (n == 0) {\n      d = 1;\n      return;\n    }\n    if (d < 0) {\n      n =\
    \ -n;\n      d = -d;\n    }\n    T g = gcd(n, d);\n    n /= g;\n    d /= g;\n\
    \  }\n\npublic:\n  Ratio(T nominator, T denominator): n(nominator), d(denominator)\
    \ { normalize(); }\n  Ratio(T nominator): n(nominator), d(1) {}\n\n  strong_ordering\
    \ operator<=>(const Ratio &r) const {\n    T g = gcd(d, r.d);\n    return r.d\
    \ / g * n <=> d / g * r.n;\n  }\n  bool operator==(const Ratio &r) const = default;\n\
    \n  Ratio operator++(int) {\n    Ratio r = *this;\n    ++*this;\n    return r;\n\
    \  }\n  Ratio &operator++() {\n    n += d;\n    return *this;\n  }\n  Ratio operator--(int)\
    \ {\n    Ratio r = *this;\n    --*this;\n    return r;\n  }\n  Ratio &operator--()\
    \ {\n    n -= d;\n    return *this;\n  }\n  Ratio &operator+=(const Ratio &r)\
    \ {\n    T l = lcm(d, r.d);\n    n = l / d * n + l / r.d * r.n;\n    d = l;\n\
    \    normalize();\n    return *this;\n  }\n  Ratio &operator-=(const Ratio &r)\
    \ {\n    T l = lcm(d, r.d);\n    n = l / d * n - l / r.d * r.n;\n    d = l;\n\
    \    normalize();\n    return *this;\n  }\n  Ratio &operator*=(const Ratio &r)\
    \ {\n    T g1 = gcd(n, r.d);\n    T g2 = gcd(r.n, d);\n    n = n / g1 * (r.n /\
    \ g2);\n    d = d / g2 * (r.d / g1);\n    return *this;\n  }\n  Ratio &operator/=(const\
    \ Ratio &r) {\n    assert(r.n != 0);\n    T g1 = gcd(n, r.n);\n    T g2 = gcd(d,\
    \ r.d);\n    n = n / g1 * (r.d / g2);\n    d = d / g2 * (r.n / g1);\n    return\
    \ *this;\n  }\n  Ratio operator+() const { return *this; }\n  Ratio operator-()\
    \ const { return Ratio(-n, d); }\n\n  friend Ratio operator+(const Ratio &a, const\
    \ Ratio &b) { return Ratio(a) += b; }\n  friend Ratio operator-(const Ratio &a,\
    \ const Ratio &b) { return Ratio(a) -= b; }\n  friend Ratio operator*(const Ratio\
    \ &a, const Ratio &b) { return Ratio(a) *= b; }\n  friend Ratio operator/(const\
    \ Ratio &a, const Ratio &b) { return Ratio(a) /= b; }\n  friend Ratio operator+(const\
    \ Ratio &a, const T &b) { return Ratio(a) += b; }\n  friend Ratio operator-(const\
    \ Ratio &a, const T &b) { return Ratio(a) -= b; }\n  friend Ratio operator*(const\
    \ Ratio &a, const T &b) { return Ratio(a) *= b; }\n  friend Ratio operator/(const\
    \ Ratio &a, const T &b) { return Ratio(a) /= b; }\n  friend Ratio operator+(const\
    \ T &a, const Ratio &b) { return a += b; }\n  friend Ratio operator-(const T &a,\
    \ const Ratio &b) { return a -= b; }\n  friend Ratio operator*(const T &a, const\
    \ Ratio &b) { return a *= b; }\n  friend Ratio operator/(const T &a, const Ratio\
    \ &b) { return a /= b; }\n\n  friend istream &operator>>(istream &is, Ratio &r)\
    \ {\n    is >> r.n >> r.d;\n    return is;\n  }\n  friend ostream &operator<<(ostream\
    \ &os, const Ratio &r) {\n    os << r.n;\n    if (r.d > 1) {\n      os << '/'\
    \ << r.d;\n    }\n    return os;\n  }\n};"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/number/ratio.hpp
  requiredBy: []
  timestamp: '2024-09-13 22:46:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp/number/ratio.hpp
layout: document
redirect_from:
- /library/cpp/number/ratio.hpp
- /library/cpp/number/ratio.hpp.html
title: cpp/number/ratio.hpp
---
