---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: cpp/graph/graph_flow.hpp
    title: cpp/graph/graph_flow.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/max_flow.test.cpp
    title: cpp/verify/max_flow.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/min_cost_flow.test.cpp
    title: cpp/verify/min_cost_flow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\n// \u8FBA\ntemplate\
    \ <class T> class FlowEdge {\n  static int next_id;\n\npublic:\n  int from, to,\
    \ rev, id;\n  T cap, cost;\n  FlowEdge(int from_, int to_, int rev_, T cap_, T\
    \ cost_)\n      : from(from_), to(to_), rev(rev_), id(next_id++), cap(max(cap_,\
    \ (T)0)),\n        cost(cost_) {}\n  FlowEdge(int from_, int to_, int rev_, T\
    \ cap_)\n      : from(from_), to(to_), rev(rev_), id(next_id++), cap(max(cap_,\
    \ (T)0)),\n        cost(0) {}\n  FlowEdge(int from_, int to_, int rev_)\n    \
    \  : from(from_), to(to_), rev(rev_), id(next_id++), cap(0), cost(0) {}\n};\n\n\
    template <class T> int FlowEdge<T>::next_id = 0;\n\ntemplate <class T> ostream\
    \ &operator<<(ostream &os, const FlowEdge<T> &e) {\n  os << e.id << \": \" <<\
    \ e.from << \" -> \" << e.to << \" (\" << e.cap << \", \"\n     << e.cost << \"\
    )\";\n  return os;\n}"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/graph/edge_flow.hpp
  requiredBy:
  - cpp/graph/graph_flow.hpp
  timestamp: '2024-11-10 02:02:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/max_flow.test.cpp
  - cpp/verify/min_cost_flow.test.cpp
documentation_of: cpp/graph/edge_flow.hpp
layout: document
redirect_from:
- /library/cpp/graph/edge_flow.hpp
- /library/cpp/graph/edge_flow.hpp.html
title: cpp/graph/edge_flow.hpp
---
