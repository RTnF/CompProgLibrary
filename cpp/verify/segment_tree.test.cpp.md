---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: cpp/algebraic_structure/monoid.hpp
    title: cpp/algebraic_structure/monoid.hpp
  - icon: ':x:'
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
    PROBLEM: https://atcoder.jp/contests/practice2/tasks/practice2_j
    links:
    - https://atcoder.jp/contests/practice2/tasks/practice2_j
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: segment_tree/segment_tree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/practice2/tasks/practice2_j\"\
    \n#include \"segment_tree/segment_tree.hpp\"\n#include \"algebraic_structure/monoid.hpp\"\
    \n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  int N, Q;\n\
    \  cin >> N >> Q;\n  vector<MonoidMax<>> A(N);\n  for (int i = 0; i < N; i++)\
    \ {\n    ll a;\n    cin >> a;\n    A[i] = MonoidMax(a);\n  }\n  SegmentTree<MonoidMax<>>\
    \ sg(A);\n  while (Q--) {\n    int T;\n    cin >> T;\n    ll X, V;\n    int L,\
    \ R;\n    switch (T) {\n    case 1:\n      cin >> X >> V;\n      sg.set(X - 1,\
    \ MonoidMax(V));\n      break;\n    case 2:\n      cin >> L >> R;\n      cout\
    \ << sg.product(L - 1, R).x << '\\n';\n      break;\n    case 3:\n      cin >>\
    \ X >> V;\n      cout << sg.search_prod_right(\n                  X - 1, [&](MonoidMax<ll>\
    \ m) -> bool { return m.x < V; }) +\n                  1\n           << '\\n';\n\
    \      break;\n    }\n  }\n}"
  dependsOn:
  - cpp/segment_tree/segment_tree.hpp
  - cpp/template/small_template.hpp
  - cpp/algebraic_structure/monoid.hpp
  isVerificationFile: true
  path: cpp/verify/segment_tree.test.cpp
  requiredBy: []
  timestamp: '2024-10-13 18:16:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: cpp/verify/segment_tree.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/segment_tree.test.cpp
- /verify/cpp/verify/segment_tree.test.cpp.html
title: cpp/verify/segment_tree.test.cpp
---
