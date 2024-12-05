---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
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
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\ntemplate <class\
    \ T, int n> struct SquareMatrix {\n  T mat[n][n];\n  static SquareMatrix<T, n>\
    \ O() {\n    SquareMatrix<T, n> ret;\n    for (int i = 0; i < n; i++) {\n    \
    \  for (int j = 0; j < n; j++) {\n        ret.mat[i][j] = 0;\n      }\n    }\n\
    \    return ret;\n  }\n  static SquareMatrix<T, n> I() {\n    SquareMatrix<T,\
    \ n> ret;\n    for (int i = 0; i < n; i++) {\n      for (int j = 0; j < n; j++)\
    \ {\n        ret.mat[i][j] = (i == j);\n      }\n    }\n    return ret;\n  }\n\
    \  T (&operator[](int i))[n] { return mat[i]; }\n  const T (&operator[](int i)\
    \ const)[n] { return mat[i]; }\n  SquareMatrix<T, n> &operator+=(const SquareMatrix<T,\
    \ n> &y) {\n    for (int i = 0; i < n; i++) {\n      for (int j = 0; j < n; j++)\
    \ {\n        mat[i][j] += y.mat[i][j];\n      }\n    }\n    return *this;\n  }\n\
    \  SquareMatrix<T, n> &operator-=(const SquareMatrix<T, n> &y) {\n    for (int\
    \ i = 0; i < n; i++) {\n      for (int j = 0; j < n; j++) {\n        mat[i][j]\
    \ -= y.mat[i][j];\n      }\n    }\n    return *this;\n  }\n  SquareMatrix<T, n>\
    \ &operator*=(const SquareMatrix<T, n> &y) {\n    SquareMatrix<T, n> tmp;\n  \
    \  for (int i = 0; i < n; i++) {\n      for (int j = 0; j < n; j++) {\n      \
    \  tmp.mat[i][j] = 0;\n        for (int k = 0; k < n; k++) {\n          tmp.mat[i][j]\
    \ += mat[i][k] * y.mat[k][j];\n        }\n      }\n    }\n    for (int i = 0;\
    \ i < n; i++) {\n      for (int j = 0; j < n; j++) {\n        mat[i][j] = tmp.mat[i][j];\n\
    \      }\n    }\n    return *this;\n  }\n  SquareMatrix<T, n> operator+() const\
    \ { return *this; }\n  SquareMatrix<T, n> operator-() const {\n    SquareMatrix<T,\
    \ n> minus;\n    for (int i = 0; i < n; i++) {\n      for (int j = 0; j < n; j++)\
    \ {\n        minus.mat[i][j] - mat[i][j];\n      }\n    }\n    return minus;\n\
    \  }\n  SquareMatrix<T, n> pow(ll e) const {\n    SquareMatrix<T, n> y = *this,\
    \ r = I();\n    while (e) {\n      if (e & 1) {\n        r *= y;\n      }\n  \
    \    y *= y;\n      e >>= 1;\n    }\n    return r;\n  }\n\n  friend SquareMatrix<T,\
    \ n> operator+(const SquareMatrix<T, n> &a,\n                                \
    \      const SquareMatrix<T, n> &b) {\n    return SquareMatrix<T, n>(a) += b;\n\
    \  }\n  friend SquareMatrix<T, n> operator-(const SquareMatrix<T, n> &a,\n   \
    \                                   const SquareMatrix<T, n> &b) {\n    return\
    \ SquareMatrix<T, n>(a) -= b;\n  }\n  friend SquareMatrix<T, n> operator*(const\
    \ SquareMatrix<T, n> &a,\n                                      const SquareMatrix<T,\
    \ n> &b) {\n    return SquareMatrix<T, n>(a) *= b;\n  }\n  friend bool operator==(const\
    \ SquareMatrix<T, n> &a,\n                         const SquareMatrix<T, n> &b)\
    \ {\n    return a.x == b.x;\n  }\n  friend bool operator!=(const SquareMatrix<T,\
    \ n> &a,\n                         const SquareMatrix<T, n> &b) {\n    return\
    \ a.x != b.x;\n  }\n};"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/number/square_matrix.hpp
  requiredBy: []
  timestamp: '2024-11-16 13:35:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp/number/square_matrix.hpp
layout: document
redirect_from:
- /library/cpp/number/square_matrix.hpp
- /library/cpp/number/square_matrix.hpp.html
title: cpp/number/square_matrix.hpp
---
