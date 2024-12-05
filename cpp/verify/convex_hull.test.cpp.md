---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/geometry/line.hpp
    title: cpp/geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/geometry/polygon.hpp
    title: cpp/geometry/polygon.hpp
  - icon: ':question:'
    path: cpp/geometry/vector.hpp
    title: cpp/geometry/vector.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/static_convex_hull
    links:
    - https://judge.yosupo.jp/problem/static_convex_hull
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: geometry/polygon.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_convex_hull\"\n\
    #include \"geometry/polygon.hpp\"\n\nvoid solve() {\n  int n;\n  cin >> n;\n \
    \ Points<ll> ps;\n  ps.reserve(n);\n  while (n--) {\n    ll x, y;\n    cin >>\
    \ x >> y;\n    ps.emplace_back(x, y);\n  }\n  sort(ps.begin(), ps.end(), Vec2<ll>::compare_x);\n\
    \  ps.erase(unique(ps.begin(), ps.end()), ps.end());\n  auto ch = convex_hull(ps);\n\
    \  cout << ch.size() << '\\n';\n  for (auto &&e : ch) {\n    cout << e.x << '\
    \ ' << e.y << '\\n';\n  }\n}\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int n;\n  cin >> n;\n  while (n--) {\n    solve();\n  }\n}"
  dependsOn:
  - cpp/geometry/polygon.hpp
  - cpp/geometry/line.hpp
  - cpp/geometry/vector.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: true
  path: cpp/verify/convex_hull.test.cpp
  requiredBy: []
  timestamp: '2024-11-23 22:11:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: cpp/verify/convex_hull.test.cpp
layout: document
redirect_from:
- /verify/cpp/verify/convex_hull.test.cpp
- /verify/cpp/verify/convex_hull.test.cpp.html
title: cpp/verify/convex_hull.test.cpp
---
