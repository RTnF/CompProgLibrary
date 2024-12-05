---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/segment_tree/segment_tree_beats_sum.hpp
    title: cpp/segment_tree/segment_tree_beats_sum.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: segment_tree/segment_tree_beats_sum.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM                                                         \
    \       \\\n  \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#include \"segment_tree/segment_tree_beats_sum.hpp\"\n\nint main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(false);\n\n  int nn, Q;\n  cin >> nn >> Q;\n  vector<ll>\
    \ a(nn);\n  for (int i = 0; i < nn; i++) {\n    cin >> a[i];\n  }\n  SegmentTreeBeatsSum\
    \ segb(a);\n  while (Q--) {\n    int ty, l, r;\n    cin >> ty >> l >> r;\n   \
    \ switch (ty) {\n    case 0: {\n      ll b;\n      cin >> b;\n      segb.chmin(l,\
    \ r, b);\n      break;\n    }\n    case 1: {\n      ll b;\n      cin >> b;\n \
    \     segb.chmax(l, r, b);\n      break;\n    }\n    case 2: {\n      ll b;\n\
    \      cin >> b;\n      segb.add_val(l, r, b);\n      break;\n    }\n    case\
    \ 3: {\n      cout << segb.calc_sum(l, r) << '\\n';\n      break;\n    }\n   \
    \ }\n  }\n}"
  dependsOn:
  - cpp/segment_tree/segment_tree_beats_sum.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: true
  path: cpp/verify/range_chmax_chmin_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-12-03 01:33:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/range_chmax_chmin_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/range_chmax_chmin_add_range_sum.test.cpp
- /verify/cpp/verify/range_chmax_chmin_add_range_sum.test.cpp.html
title: cpp/verify/range_chmax_chmin_add_range_sum.test.cpp
---
