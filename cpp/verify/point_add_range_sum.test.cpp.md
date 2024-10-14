---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: cpp/algebraic_structure/group.hpp
    title: "\u7FA4 (Group)"
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algebraic_structure/group.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"algebraic_structure/group.hpp\"\n#include \"segment_tree/segment_tree.hpp\"\
    \n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  int N, Q;\n\
    \  cin >> N >> Q;\n  vector<GroupSum<ll>> a(N);\n  for (int i = 0; i < N; i++)\
    \ {\n    ll x;\n    cin >> x;\n    a[i] = GroupSum(x);\n  }\n  SegmentTree<GroupSum<ll>>\
    \ seg(a);\n  while (Q--) {\n    int cmd;\n    ll x, y;\n    cin >> cmd >> x >>\
    \ y;\n    if (cmd) {\n      cout << seg.product(x, y).x() << '\\n';\n    } else\
    \ {\n      seg.set(x, seg.get(x).x() + y);\n    }\n  }\n}"
  dependsOn:
  - cpp/algebraic_structure/group.hpp
  - cpp/template/small_template.hpp
  - cpp/segment_tree/segment_tree.hpp
  isVerificationFile: true
  path: cpp/verify/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-10-14 15:39:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: cpp/verify/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/point_add_range_sum.test.cpp
- /verify/cpp/verify/point_add_range_sum.test.cpp.html
title: cpp/verify/point_add_range_sum.test.cpp
---
