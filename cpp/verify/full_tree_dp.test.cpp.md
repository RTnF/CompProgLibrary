---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp/array/doubling.hpp
    title: cpp/array/doubling.hpp
  - icon: ':question:'
    path: cpp/graph/edge.hpp
    title: cpp/graph/edge.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/modint/dynamic_modint.hpp
    title: "\u5270\u4F59\u3092\u53D6\u308A[0, mod)\u306B\u53CE\u3081\u308Bint"
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  - icon: ':question:'
    path: cpp/tree/tree.hpp
    title: "\u5168\u65B9\u4F4D\u6728DP"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/dp/tasks/dp_v
    links:
    - https://atcoder.jp/contests/dp/tasks/dp_v
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: tree/tree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/dp/tasks/dp_v\"\n#include \"\
    tree/tree.hpp\"\n#include \"modint/dynamic_modint.hpp\"\n\nvoid solve() {\n  int\
    \ n;\n  cin >> n >> DynamicModInt::m;\n  vector<int> x(n - 1), y(n - 1);\n  for\
    \ (int i = 0; i < n - 1; i++) {\n    cin >> x[i] >> y[i];\n    x[i]--;\n    y[i]--;\n\
    \  }\n  Tree tree(0, x, y);\n  auto dp = tree.full_tree_dp(DynamicModInt(1), [](DynamicModInt\
    \ a, DynamicModInt b) -> auto {\n    return a * b;\n  }, [](DynamicModInt a) ->\
    \ auto { return a + 1; });\n  for (auto &&e: dp) {\n    cout << e - 1 << '\\n';\n\
    \  }\n}\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  cout\
    \ << fixed << setprecision(20);\n  //*\n  solve();\n  /*/\n  ll _cases;\n  cin\
    \ >> _cases;\n  while (_cases--) solve();\n  //*/\n}"
  dependsOn:
  - cpp/tree/tree.hpp
  - cpp/array/doubling.hpp
  - cpp/template/small_template.hpp
  - cpp/graph/edge.hpp
  - cpp/modint/dynamic_modint.hpp
  isVerificationFile: true
  path: cpp/verify/full_tree_dp.test.cpp
  requiredBy: []
  timestamp: '2024-12-07 00:34:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/full_tree_dp.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/full_tree_dp.test.cpp
- /verify/cpp/verify/full_tree_dp.test.cpp.html
title: cpp/verify/full_tree_dp.test.cpp
---
