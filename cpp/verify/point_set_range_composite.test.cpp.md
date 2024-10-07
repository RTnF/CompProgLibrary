---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp/algebraic_structure/group.hpp
    title: "\u30A2\u30D5\u30A3\u30F3\u5199\u50CF y = ax + b"
  - icon: ':x:'
    path: cpp/modint/modint.hpp
    title: "\u5270\u4F59\u3092\u53D6\u308A[0, mod)\u306B\u53CE\u3081\u308Bint"
  - icon: ':question:'
    path: cpp/segment_tree/segment_tree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 based on ACL"
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: cpp/template/small_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: modint/modint.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include \"modint/modint.hpp\"\n#include \"algebraic_structure/group.hpp\"\n\
    #include \"segment_tree/segment_tree.hpp\"\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  vector<GroupAffine<mint>> v(N);\n  for (int\
    \ i = 0; i < N; i++) {\n    int a, b;\n    cin >> a >> b;\n    v[i] = {a, b};\n\
    \  }\n  SegmentTree<GroupAffine<mint>> sg(v);\n  while (Q--) {\n    int type;\n\
    \    cin >> type;\n    if (type) {\n      int l, r;\n      mint x;\n      cin\
    \ >> l >> r >> x;\n      auto p = sg.product(l, r);\n      cout << p.a * x + p.b\
    \ << '\\n';\n    } else {\n      int p;\n      mint c, d;\n      cin >> p >> c\
    \ >> d;\n      sg.set(p, {c, d});\n    }\n  }\n}"
  dependsOn:
  - cpp/modint/modint.hpp
  - cpp/template/small_template.hpp
  - cpp/algebraic_structure/group.hpp
  - cpp/segment_tree/segment_tree.hpp
  isVerificationFile: true
  path: cpp/verify/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2024-10-06 17:36:52+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: cpp/verify/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/point_set_range_composite.test.cpp
- /verify/cpp/verify/point_set_range_composite.test.cpp.html
title: cpp/verify/point_set_range_composite.test.cpp
---
