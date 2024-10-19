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
    document_title: "1\u6B21\u5143\u7D2F\u7A4D\u548C"
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
    \ 1\u6B21\u5143\u7D2F\u7A4D\u548C\n * \u69CB\u7BC9 O(n)\n * \u66F4\u65B0\u4E0D\
    \u53EF\n * \u90E8\u5206\u548C O(1)\n * @tparam T\n */\ntemplate<class T = ll>\n\
    class CumulativeSum {\n  vector<T> cs;\n  int n;\n\npublic:\n  CumulativeSum(const\
    \ vector<T> &v): cs(v.size() + 1), n(v.size()) {\n    cs[0] = T(0);\n    for (int\
    \ i = 1; i <= n; i++) {\n      cs[i] = cs[i - 1] + v[i - 1];\n    }\n  }\n  //\
    \ [0, a) 0-n\n  T sum(int a) {\n    assert(0 <= a && a <= n);\n    return cs[a];\n\
    \  }\n  // [a, b) 0-a-b-n\n  T sum(int a, int b) {\n    assert(0 <= a && a <=\
    \ b && b <= n);\n    return cs[b] - cs[a];\n  }\n};\n\n/**\n * @brief 2\u6B21\u5143\
    \u7D2F\u7A4D\u548C\n * \u69CB\u7BC9 O(nm)\n * \u66F4\u65B0\u4E0D\u53EF\n * \u90E8\
    \u5206\u548C O(1)\n * @tparam T\n */\ntemplate<class T = ll>\nclass CumulativeSum2D\
    \ {\n  vector<vector<T>> cs;\n  int n, m;\n\npublic:\n  CumulativeSum2D(const\
    \ vector<vector<T>> &v) {\n    n = v.size();\n    assert(n > 0);\n    m = v[0].size();\n\
    \    assert(m > 0);\n    for (int i = 1; i < n; i++) {\n      assert(int(v[i].size())\
    \ == m);\n    }\n    cs.resize(n + 1);\n    cs[0] = vector<T>(m + 1, T(0));\n\
    \    for (int i = 1; i <= n; i++) {\n      cs[i].reserve(m + 1);\n      cs[i].emplace_back(T(0));\n\
    \      for (int j = 0; j < m; j++) {\n        cs[i].emplace_back(cs[i].back()\
    \ + v[i - 1][j]);\n      }\n    }\n    for (int i = 2; i <= n; i++) {\n      for\
    \ (int j = 1; j <= m; j++)\n        cs[i][j] += cs[i - 1][j];\n    }\n  }\n  //\
    \ [0, a) 0-n\n  // [0, b) 0-m\n  T sum(int a, int b) {\n    assert(0 <= a && a\
    \ <= n);\n    assert(0 <= b && b <= m);\n    return cs[a][b];\n  }\n  // [a1,\
    \ a2) 0-a1-a2-n\n  // [b1, b2) 0-b1-b2-m\n  T sum(int a1, int b1, int a2, int\
    \ b2) {\n    assert(0 <= a1 && a1 <= a2 && a2 <= n);\n    assert(0 <= b1 && b1\
    \ <= b2 && b2 <= m);\n    return cs[a2][b2] - cs[a1][b2] - cs[a2][b1] + cs[a1][b1];\n\
    \  }\n};\n"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/array/cumulative_sum.hpp
  requiredBy: []
  timestamp: '2024-09-18 18:24:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp/array/cumulative_sum.hpp
layout: document
redirect_from:
- /library/cpp/array/cumulative_sum.hpp
- /library/cpp/array/cumulative_sum.hpp.html
title: "1\u6B21\u5143\u7D2F\u7A4D\u548C"
---
