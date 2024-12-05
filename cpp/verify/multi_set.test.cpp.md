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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_7_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_7_D
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
  code: "#define PROBLEM                                                         \
    \       \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_7_D\"\
    \n#include \"set/multiset.hpp\"\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \n  TreeMultiSet ms;\n  int q;\n  cin >> q;\n  while (q--) {\n    int type;\n\
    \    cin >> type;\n    int x, l, r;\n    switch (type) {\n    case 0: // insert\n\
    \      cin >> x;\n      ms.add(x);\n      cout << ms.size() << \"\\n\";\n    \
    \  break;\n    case 1: // find\n      cin >> x;\n      cout << ms.count(x) <<\
    \ \"\\n\";\n      break;\n    case 2: // delete\n      cin >> x;\n      ms.remove_all(x);\n\
    \      break;\n    case 3: // dump\n      cin >> l >> r;\n      ms.aoj_dump(l,\
    \ r);\n      break;\n    }\n    if (ms.size() < 3000) {\n      ms.verify();\n\
    \    }\n  }\n}"
  dependsOn:
  - cpp/set/multiset.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: true
  path: cpp/verify/multi_set.test.cpp
  requiredBy: []
  timestamp: '2024-12-03 01:33:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/multi_set.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/multi_set.test.cpp
- /verify/cpp/verify/multi_set.test.cpp.html
title: cpp/verify/multi_set.test.cpp
---
