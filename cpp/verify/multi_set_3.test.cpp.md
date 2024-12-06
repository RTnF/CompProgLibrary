---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/set/multiset.hpp
    title: "\u91CD\u8907\u3042\u308A\u306E\u96C6\u5408"
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/double_ended_priority_queue
    links:
    - https://judge.yosupo.jp/problem/double_ended_priority_queue
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: set/multiset.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n#include \"set/multiset.hpp\"\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \n  TreeMultiSet<int> ms;\n  int n, q;\n  cin >> n >> q;\n  for (int i = 0; i\
    \ < n; i++) {\n    int s;\n    cin >> s;\n    ms.add(s);\n  }\n  while (q--) {\n\
    \    int c;\n    cin >> c;\n    switch (c) {\n    case 0:\n      int x;\n    \
    \  cin >> x;\n      ms.add(x);\n      break;\n    case 1: {\n      int m = ms.min();\n\
    \      cout << m << '\\n';\n      ms.remove(m);\n      break;\n    }\n    case\
    \ 2: {\n      int m = ms.max();\n      cout << m << '\\n';\n      ms.remove(m);\n\
    \      break;\n    }\n    }\n  }\n}"
  dependsOn:
  - cpp/set/multiset.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: true
  path: cpp/verify/multi_set_3.test.cpp
  requiredBy: []
  timestamp: '2024-12-03 01:33:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/multi_set_3.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/multi_set_3.test.cpp
- /verify/cpp/verify/multi_set_3.test.cpp.html
title: cpp/verify/multi_set_3.test.cpp
---