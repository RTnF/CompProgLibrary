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
    document_title: "\u9006\u7F6E\u63DB"
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
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\n/**\n * @brief\
    \ \u9006\u7F6E\u63DB\n * \u4F8B\uFF1A[2, 4, 0, 1, 3] -> [2, 3, 0, 4, 1]\n * @param\
    \ v 0-indexed \u9806\u5217\n */\ntemplate<class T>\nvector<int> inv_perm(const\
    \ vector<T> &v) {\n  int n = v.size();\n  vector<int> inv(n, -1);\n  for (int\
    \ i = 0; i < n; i++) {\n    assert(0 <= v[i] && v[i] < n);\n    assert(inv[v[i]]\
    \ == -1);\n    inv[v[i]] = i;\n  }\n  return inv;\n}\n\n/**\n * @brief \u30BD\u30FC\
    \u30C8\u7D50\u679C\u3092\u914D\u5217\u306Eindex\u3067\u5F97\u308B O(n log n)\n\
    \ * \u4F8B\uFF1A[3, 3, 1, 5, 2] -> [1(2), 2(4), 3(0), 3(1), 5(3)] -> [2, 4, 0,\
    \ 1, 3]\n */\ntemplate<class T>\nvector<int> arg_sort(const vector<T> &v) {\n\
    \  vector<int> arg(v.size());\n  iota(arg.begin(), arg.end(), 0);\n  stable_sort(\n\
    \    arg.begin(), arg.end(), [&](int a, int b) { return v[a] < v[b]; });\n  return\
    \ arg;\n}\n\n/**\n * @brief \u30BD\u30FC\u30C8\u3067index\u304C\u3069\u3053\u306B\
    \u79FB\u52D5\u3059\u308B\u304B O(n log n)\n * \u4F8B\uFF1A[3, 3, 1, 5, 2] -> [2,\
    \ 3, 0, 4, 1]\n */\ntemplate<class T>\nvector<int> inv_arg_sort(const vector<T>\
    \ &v) {\n  return inv_perm(arg_sort(v));\n}\n\n/**\n * @brief \u5EA7\u6A19\u5727\
    \u7E2E O(n log n)\n * \u4F8B\uFF1A[3, 3, 1, 5, 2] -> [2, 2, 0, 3, 1] + offset\n\
    \ * unzip: [1, 2, 3, 5]\n */\ntemplate<class T>\nvector<T> compress(const vector<T>\
    \ &x, vector<T> &unzip, int offset = 0) {\n  int n = x.size();\n  vector<T> cmp(n);\n\
    \  unzip = x;\n  sort(unzip.begin(), unzip.end());\n  unzip.erase(unique(unzip.begin(),\
    \ unzip.end()), unzip.end());\n  for (int i = 0; i < n; i++) {\n    cmp[i] =\n\
    \      lower_bound(unzip.begin(), unzip.end(), x[i]) - unzip.begin() + offset;\n\
    \  }\n  return cmp;\n}\n\n/**\n * @brief \u5EA7\u6A19\u5727\u7E2E O(n log n)\n\
    \ * \u4F8B\uFF1A[3, 3, 1, 5, 2] -> [2, 2, 0, 3, 1] + offset\n */\ntemplate<class\
    \ T>\nvector<T> compress(const vector<T> &x, int offset = 0) {\n  vector<T> y\
    \ = x;\n  return compress(x, y, offset);\n}"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/array/sort_util.hpp
  requiredBy: []
  timestamp: '2024-09-17 06:19:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp/array/sort_util.hpp
layout: document
redirect_from:
- /library/cpp/array/sort_util.hpp
- /library/cpp/array/sort_util.hpp.html
title: "\u9006\u7F6E\u63DB"
---
