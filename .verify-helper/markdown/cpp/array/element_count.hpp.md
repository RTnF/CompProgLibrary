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
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\n// \u500B\u6570\
    \ntemplate<class T>\nvector<pair<T, int>> element_count(const T &v) {\n  vector<pair<T,\
    \ int>> ret;\n  int n = v.size();\n  if (n == 0) {\n    return ret;\n  }\n  T\
    \ pre = v[0];\n  int cnt = 0;\n  for (int i = 0; i < n; i++) {\n    if (pre ==\
    \ v[i]) {\n      cnt++;\n    } else {\n      ret.emplace_back(pre, cnt);\n   \
    \   pre = v[i];\n      cnt = 1;\n    }\n  }\n  ret.emplace_back(pre, cnt);\n \
    \ return ret;\n}"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/array/element_count.hpp
  requiredBy: []
  timestamp: '2024-10-06 23:24:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp/array/element_count.hpp
layout: document
redirect_from:
- /library/cpp/array/element_count.hpp
- /library/cpp/array/element_count.hpp.html
title: cpp/array/element_count.hpp
---
