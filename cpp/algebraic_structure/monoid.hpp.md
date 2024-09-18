---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\ntemplate<class\
    \ T = ll>\nstruct MonoidMul {\n  T x;\n  MonoidMul(T x_): x(x_) {}\n  MonoidMul():\
    \ MonoidMul(e()) {}\n  static MonoidMul e() { return 1; }\n  friend MonoidMul\
    \ op(const MonoidMul &a, const MonoidMul &b) {\n    return a.x * b.x;\n  }\n};\n"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/algebraic_structure/monoid.hpp
  requiredBy: []
  timestamp: '2024-09-18 18:24:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp/algebraic_structure/monoid.hpp
layout: document
redirect_from:
- /library/cpp/algebraic_structure/monoid.hpp
- /library/cpp/algebraic_structure/monoid.hpp.html
title: cpp/algebraic_structure/monoid.hpp
---
