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
    document_title: "\u533A\u9593 [start, end)"
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
    \ \u533A\u9593 [start, end)\n *\n * @tparam T\n */\ntemplate <class T = ll> class\
    \ Interval {\n  T s, e;\n  // \u7A7A\u306E\u533A\u9593\n  bool is_n;\n\npublic:\n\
    \  constexpr Interval(T start_, T end_)\n      : s(start_), e(end_), is_n(start_\
    \ == end_) {\n    assert(start_ <= end_);\n  }\n  constexpr Interval() : s(0),\
    \ e(0), is_n(true) {}\n  constexpr auto operator<=>(const Interval &r) const =\
    \ default;\n\n  constexpr T start() { return s; }\n  constexpr T end() { return\
    \ e; }\n  constexpr bool is_null() { return is_n; }\n  constexpr T length() {\
    \ return e - s; }\n\n  Interval<T> intersection(const Interval<T> &b) const {\n\
    \    if (b.s >= e || s >= b.e) {\n      return Interval<T>();\n    }\n    return\
    \ Interval(max(s, b.s), min(e, b.e));\n  }\n\n  friend istream &operator>>(istream\
    \ &is, Interval &m) {\n    is >> m.s >> m.e;\n    return is;\n  }\n  friend ostream\
    \ &operator<<(ostream &os, const Interval &m) {\n    os << '[' << m.s << \", \"\
    \ << m.e << ')';\n    return os;\n  }\n};"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/interval/interval.hpp
  requiredBy: []
  timestamp: '2024-10-10 19:14:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp/interval/interval.hpp
layout: document
redirect_from:
- /library/cpp/interval/interval.hpp
- /library/cpp/interval/interval.hpp.html
title: "\u533A\u9593 [start, end)"
---
