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
    document_title: "\u5EA7\u6A19\u5727\u7E2E O(n log n)"
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
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\n// \u9006\u7F6E\
    \u63DB\n// v: 0-indexed \u9806\u5217\n// \u4F8B\uFF1A[2, 4, 0, 1, 3] -> [2, 3,\
    \ 0, 4, 1]\ntemplate <class T> vector<int> inv_perm(const vector<T> &v) {\n  int\
    \ n = v.size();\n  vector<int> inv(n, -1);\n  for (int i = 0; i < n; i++) {\n\
    \    assert(0 <= v[i] && v[i] < n);\n    assert(inv[v[i]] == -1);\n    inv[v[i]]\
    \ = i;\n  }\n  return inv;\n}\n\n// \u30BD\u30FC\u30C8\u7D50\u679C\u3092\u914D\
    \u5217\u306Eindex\u3067\u5F97\u308B O(n log n)\n// \u4F8B\uFF1A[3, 3, 1, 5, 2]\
    \ -> [1(2), 2(4), 3(0), 3(1), 5(3)] -> [2, 4, 0, 1, 3]\ntemplate <class T> vector<int>\
    \ arg_sort(const vector<T> &v) {\n  vector<int> arg(v.size());\n  iota(arg.begin(),\
    \ arg.end(), 0);\n  stable_sort(arg.begin(), arg.end(),\n              [&](int\
    \ a, int b) { return v[a] < v[b]; });\n  return arg;\n}\n\n// \u30BD\u30FC\u30C8\
    \u3067index\u304C\u3069\u3053\u306B\u79FB\u52D5\u3059\u308B\u304B O(n log n)\n\
    // \u4F8B\uFF1A[3, 3, 1, 5, 2] -> [2, 3, 0, 4, 1]\ntemplate <class T> vector<int>\
    \ inv_arg_sort(const vector<T> &v) {\n  return inv_perm(arg_sort(v));\n}\n\n//\
    \ @brief \u5EA7\u6A19\u5727\u7E2E O(n log n)\n// \u4F8B\uFF1A[3, 3, 1, 5, 2] ->\
    \ [2, 2, 0, 3, 1] + offset\n// unzip: [1, 2, 3, 5]\ntemplate <class T>\nvector<T>\
    \ compress(const vector<T> &x, vector<T> &unzip, int offset = 0) {\n  int n =\
    \ x.size();\n  vector<T> cmp(n);\n  unzip = x;\n  sort(unzip.begin(), unzip.end());\n\
    \  unzip.erase(unique(unzip.begin(), unzip.end()), unzip.end());\n  for (int i\
    \ = 0; i < n; i++) {\n    cmp[i] =\n        lower_bound(unzip.begin(), unzip.end(),\
    \ x[i]) - unzip.begin() + offset;\n  }\n  return cmp;\n}\n\n// \u5EA7\u6A19\u5727\
    \u7E2E O(n log n)\n// \u4F8B\uFF1A[3, 3, 1, 5, 2] -> [2, 2, 0, 3, 1] + offset\n\
    template <class T> vector<T> compress(const vector<T> &x, int offset = 0) {\n\
    \  vector<T> y = x;\n  return compress(x, y, offset);\n}"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/array/sort_util.hpp
  requiredBy: []
  timestamp: '2024-10-14 15:39:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp/array/sort_util.hpp
layout: document
redirect_from:
- /library/cpp/array/sort_util.hpp
- /library/cpp/array/sort_util.hpp.html
title: "\u5EA7\u6A19\u5727\u7E2E O(n log n)"
---
