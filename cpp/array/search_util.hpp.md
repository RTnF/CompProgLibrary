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
    \ T>\nint count(vector<T> v, T value, int idx_begin = 0, int idx_end = -1) {\n\
    \  if (idx_end == -1) {\n    idx_end = v.size();\n  }\n  int cnt = 0;\n  for (int\
    \ i = idx_begin; i < idx_end; i++) {\n    if (v[i] == value) {\n      cnt++;\n\
    \    }\n  }\n  return cnt;\n}\n"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/array/search_util.hpp
  requiredBy: []
  timestamp: '2024-09-18 18:24:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp/array/search_util.hpp
layout: document
redirect_from:
- /library/cpp/array/search_util.hpp
- /library/cpp/array/search_util.hpp.html
title: cpp/array/search_util.hpp
---
