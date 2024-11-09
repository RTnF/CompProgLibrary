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
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\n// \u6587\u5B57\
    \u3001\u500B\u6570\nvector<pair<char, int>> char_count(const string &s) {\n  vector<pair<char,\
    \ int>> ret;\n  int n = s.size();\n  if (n == 0) {\n    return ret;\n  }\n  char\
    \ pre = s[0];\n  int cnt = 0;\n  for (int i = 0; i < n; i++) {\n    if (pre ==\
    \ s[i]) {\n      cnt++;\n    } else {\n      ret.emplace_back(pre, cnt);\n   \
    \   pre = s[i];\n      cnt = 1;\n    }\n  }\n  ret.emplace_back(pre, cnt);\n \
    \ return ret;\n}"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/string/char_count.hpp
  requiredBy: []
  timestamp: '2024-10-19 16:46:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp/string/char_count.hpp
layout: document
title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E"
---
<link rel="stylesheet" type="text/css" href="../../css/common.css">

## char_count

```cpp
vector<pair<char, int>> char_count(const string &s)
```

**制約**

文字はASCIIに含まれる。

**計算量**

- $ O(|S|) $

**例**

```cpp
char_count("")
// -> []

char_count("abc")
// -> [('a', 1), ('b', 1), ('c', 1)]

char_count("aaaAAABBbb")
// -> [('a', 3), ('A', 3), ('B', 2), ('b', 2)]
```