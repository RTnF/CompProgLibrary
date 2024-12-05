---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/range_chmax_chmin_add_range_sum.test.cpp
    title: cpp/verify/range_chmax_chmin_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://tjkendev.github.io/procon-library/cpp/range_query/segment_tree_beats_2.html
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
  code: "#include \"template/small_template.hpp\"\n\n// https://tjkendev.github.io/procon-library/cpp/range_query/segment_tree_beats_2.html\n\
    // sum\u304C\u3042\u308B\u306E\u3067INF\u306F\u7A4D\u3081\u306A\u3044\nclass SegmentTreeBeatsSum\
    \ {\n  int n, n0;\n  vector<ll> max_v, smax_v, max_c;\n  vector<ll> min_v, smin_v,\
    \ min_c;\n  vector<ll> sum;\n  vector<ll> len, ladd, lval;\n\n  void update_node_max(int\
    \ k, ll x) {\n    sum[k] += (x - max_v[k]) * max_c[k];\n    if (max_v[k] == min_v[k])\
    \ {\n      max_v[k] = min_v[k] = x;\n    } else if (max_v[k] == smin_v[k]) {\n\
    \      max_v[k] = smin_v[k] = x;\n    } else {\n      max_v[k] = x;\n    }\n \
    \   if (lval[k] != INF && x < lval[k]) {\n      lval[k] = x;\n    }\n  }\n\n \
    \ void update_node_min(int k, ll x) {\n    sum[k] += (x - min_v[k]) * min_c[k];\n\
    \    if (max_v[k] == min_v[k]) {\n      max_v[k] = min_v[k] = x;\n    } else if\
    \ (smax_v[k] == min_v[k]) {\n      min_v[k] = smax_v[k] = x;\n    } else {\n \
    \     min_v[k] = x;\n    }\n    if (lval[k] != INF && lval[k] < x) {\n      lval[k]\
    \ = x;\n    }\n  }\n\n  void push(int k) {\n    if (n0 - 1 <= k) {\n      return;\n\
    \    }\n    if (lval[k] != INF) {\n      update_all(2 * k + 1, lval[k]);\n   \
    \   update_all(2 * k + 2, lval[k]);\n      lval[k] = INF;\n      return;\n   \
    \ }\n    if (ladd[k] != 0) {\n      add_all(2 * k + 1, ladd[k]);\n      add_all(2\
    \ * k + 2, ladd[k]);\n      ladd[k] = 0;\n    }\n    if (max_v[k] < max_v[2 *\
    \ k + 1]) {\n      update_node_max(2 * k + 1, max_v[k]);\n    }\n    if (min_v[2\
    \ * k + 1] < min_v[k]) {\n      update_node_min(2 * k + 1, min_v[k]);\n    }\n\
    \    if (max_v[k] < max_v[2 * k + 2]) {\n      update_node_max(2 * k + 2, max_v[k]);\n\
    \    }\n    if (min_v[2 * k + 2] < min_v[k]) {\n      update_node_min(2 * k +\
    \ 2, min_v[k]);\n    }\n  }\n\n  void update(int k) {\n    sum[k] = sum[2 * k\
    \ + 1] + sum[2 * k + 2];\n    if (max_v[2 * k + 1] < max_v[2 * k + 2]) {\n   \
    \   max_v[k] = max_v[2 * k + 2];\n      max_c[k] = max_c[2 * k + 2];\n      smax_v[k]\
    \ = max(max_v[2 * k + 1], smax_v[2 * k + 2]);\n    } else if (max_v[2 * k + 1]\
    \ > max_v[2 * k + 2]) {\n      max_v[k] = max_v[2 * k + 1];\n      max_c[k] =\
    \ max_c[2 * k + 1];\n      smax_v[k] = max(smax_v[2 * k + 1], max_v[2 * k + 2]);\n\
    \    } else {\n      max_v[k] = max_v[2 * k + 1];\n      max_c[k] = max_c[2 *\
    \ k + 1] + max_c[2 * k + 2];\n      smax_v[k] = max(smax_v[2 * k + 1], smax_v[2\
    \ * k + 2]);\n    }\n    if (min_v[2 * k + 1] < min_v[2 * k + 2]) {\n      min_v[k]\
    \ = min_v[2 * k + 1];\n      min_c[k] = min_c[2 * k + 1];\n      smin_v[k] = min(smin_v[2\
    \ * k + 1], min_v[2 * k + 2]);\n    } else if (min_v[2 * k + 1] > min_v[2 * k\
    \ + 2]) {\n      min_v[k] = min_v[2 * k + 2];\n      min_c[k] = min_c[2 * k +\
    \ 2];\n      smin_v[k] = min(min_v[2 * k + 1], smin_v[2 * k + 2]);\n    } else\
    \ {\n      min_v[k] = min_v[2 * k + 1];\n      min_c[k] = min_c[2 * k + 1] + min_c[2\
    \ * k + 2];\n      smin_v[k] = min(smin_v[2 * k + 1], smin_v[2 * k + 2]);\n  \
    \  }\n  }\n\n  void _chmin(ll x, int a, int b, int k, int l, int r) {\n    if\
    \ (b <= l || r <= a || max_v[k] <= x) {\n      return;\n    }\n    if (a <= l\
    \ && r <= b && smax_v[k] < x) {\n      update_node_max(k, x);\n      return;\n\
    \    }\n    push(k);\n    _chmin(x, a, b, 2 * k + 1, l, (l + r) / 2);\n    _chmin(x,\
    \ a, b, 2 * k + 2, (l + r) / 2, r);\n    update(k);\n  }\n\n  void _chmax(ll x,\
    \ int a, int b, int k, int l, int r) {\n    if (b <= l || r <= a || x <= min_v[k])\
    \ {\n      return;\n    }\n    if (a <= l && r <= b && x < smin_v[k]) {\n    \
    \  update_node_min(k, x);\n      return;\n    }\n    push(k);\n    _chmax(x, a,\
    \ b, 2 * k + 1, l, (l + r) / 2);\n    _chmax(x, a, b, 2 * k + 2, (l + r) / 2,\
    \ r);\n    update(k);\n  }\n\n  void add_all(int k, ll x) {\n    max_v[k] += x;\n\
    \    if (smax_v[k] != -INF) {\n      smax_v[k] += x;\n    }\n    min_v[k] += x;\n\
    \    if (smin_v[k] != INF) {\n      smin_v[k] += x;\n    }\n\n    sum[k] += len[k]\
    \ * x;\n    (lval[k] == INF ? ladd[k] : lval[k]) += x;\n  }\n\n  void update_all(int\
    \ k, ll x) {\n    max_v[k] = x;\n    smax_v[k] = -INF;\n    min_v[k] = x;\n  \
    \  smin_v[k] = INF;\n    max_c[k] = min_c[k] = len[k];\n\n    sum[k] = x * len[k];\n\
    \    lval[k] = x;\n    ladd[k] = 0;\n  }\n\n  void _add_val(ll x, int a, int b,\
    \ int k, int l, int r) {\n    if (b <= l || r <= a) {\n      return;\n    }\n\
    \    if (a <= l && r <= b) {\n      add_all(k, x);\n      return;\n    }\n\n \
    \   push(k);\n    _add_val(x, a, b, 2 * k + 1, l, (l + r) / 2);\n    _add_val(x,\
    \ a, b, 2 * k + 2, (l + r) / 2, r);\n    update(k);\n  }\n\n  void _update_val(ll\
    \ x, int a, int b, int k, int l, int r) {\n    if (b <= l || r <= a) {\n     \
    \ return;\n    }\n    if (a <= l && r <= b) {\n      update_all(k, x);\n     \
    \ return;\n    }\n    push(k);\n    _update_val(x, a, b, 2 * k + 1, l, (l + r)\
    \ / 2);\n    _update_val(x, a, b, 2 * k + 2, (l + r) / 2, r);\n    update(k);\n\
    \  }\n\n  ll _calc_max(int a, int b, int k, int l, int r) {\n    if (b <= l ||\
    \ r <= a) {\n      return -INF;\n    }\n    if (a <= l && r <= b) {\n      return\
    \ max_v[k];\n    }\n    push(k);\n    ll lv = _calc_max(a, b, 2 * k + 1, l, (l\
    \ + r) / 2);\n    ll rv = _calc_max(a, b, 2 * k + 2, (l + r) / 2, r);\n    return\
    \ max(lv, rv);\n  }\n\n  ll _calc_min(int a, int b, int k, int l, int r) {\n \
    \   if (b <= l || r <= a) {\n      return INF;\n    }\n    if (a <= l && r <=\
    \ b) {\n      return min_v[k];\n    }\n    push(k);\n    ll lv = _calc_min(a,\
    \ b, 2 * k + 1, l, (l + r) / 2);\n    ll rv = _calc_min(a, b, 2 * k + 2, (l +\
    \ r) / 2, r);\n    return min(lv, rv);\n  }\n\n  ll _calc_sum(int a, int b, int\
    \ k, int l, int r) {\n    if (b <= l || r <= a) {\n      return 0;\n    }\n  \
    \  if (a <= l && r <= b) {\n      return sum[k];\n    }\n    push(k);\n    ll\
    \ lv = _calc_sum(a, b, 2 * k + 1, l, (l + r) / 2);\n    ll rv = _calc_sum(a, b,\
    \ 2 * k + 2, (l + r) / 2, r);\n    return lv + rv;\n  }\n\npublic:\n  SegmentTreeBeatsSum(vector<ll>\
    \ a) : n(a.size()) {\n    max_v = smax_v = max_c = min_v = smin_v = min_c = sum\
    \ = len = ladd = lval =\n        vector<ll>(4 * n);\n    n0 = 1;\n    while (n0\
    \ < n)\n      n0 <<= 1;\n\n    for (int i = 0; i < 2 * n0; ++i)\n      ladd[i]\
    \ = 0, lval[i] = INF;\n    len[0] = n0;\n    for (int i = 0; i < n0 - 1; ++i)\n\
    \      len[2 * i + 1] = len[2 * i + 2] = (len[i] >> 1);\n\n    for (int i = 0;\
    \ i < n; ++i) {\n      max_v[n0 - 1 + i] = min_v[n0 - 1 + i] = sum[n0 - 1 + i]\
    \ = a[i];\n      smax_v[n0 - 1 + i] = -INF;\n      smin_v[n0 - 1 + i] = INF;\n\
    \      max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 1;\n    }\n\n    for (int i = n;\
    \ i < n0; ++i) {\n      max_v[n0 - 1 + i] = smax_v[n0 - 1 + i] = -INF;\n     \
    \ min_v[n0 - 1 + i] = smin_v[n0 - 1 + i] = INF;\n      max_c[n0 - 1 + i] = min_c[n0\
    \ - 1 + i] = 0;\n    }\n    for (int i = n0 - 2; i >= 0; i--) {\n      update(i);\n\
    \    }\n  }\n\n  void chmin(int a, int b, ll x) { _chmin(x, a, b, 0, 0, n0); }\n\
    \  void chmax(int a, int b, ll x) { _chmax(x, a, b, 0, 0, n0); }\n  void add_val(int\
    \ a, int b, ll x) { _add_val(x, a, b, 0, 0, n0); }\n  void update_val(int a, int\
    \ b, ll x) { _update_val(x, a, b, 0, 0, n0); }\n  ll calc_max(int a, int b) {\
    \ return _calc_max(a, b, 0, 0, n0); }\n  ll calc_min(int a, int b) { return _calc_min(a,\
    \ b, 0, 0, n0); }\n  ll calc_sum(int a, int b) { return _calc_sum(a, b, 0, 0,\
    \ n0); }\n};\n"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/segment_tree/segment_tree_beats_sum.hpp
  requiredBy: []
  timestamp: '2024-12-03 01:33:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/range_chmax_chmin_add_range_sum.test.cpp
documentation_of: cpp/segment_tree/segment_tree_beats_sum.hpp
layout: document
redirect_from:
- /library/cpp/segment_tree/segment_tree_beats_sum.hpp
- /library/cpp/segment_tree/segment_tree_beats_sum.hpp.html
title: cpp/segment_tree/segment_tree_beats_sum.hpp
---
