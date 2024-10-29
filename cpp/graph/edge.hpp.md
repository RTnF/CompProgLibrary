---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: cpp/graph/bellman_ford.hpp
    title: cpp/graph/bellman_ford.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/graph/dijkstra.hpp
    title: cpp/graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/graph/graph_list.hpp
    title: "\u30B0\u30E9\u30D5 (\u96A3\u63A5\u30EA\u30B9\u30C8\u5F62\u5F0F)"
  - icon: ':heavy_check_mark:'
    path: cpp/graph/lowlink.hpp
    title: cpp/graph/lowlink.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/graph/prim.hpp
    title: cpp/graph/prim.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/graph/topological_sort.hpp
    title: cpp/graph/topological_sort.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/tree/tree.hpp
    title: cpp/tree/tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/articulation_points.test.cpp
    title: cpp/verify/articulation_points.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/bellman_ford.test.cpp
    title: cpp/verify/bellman_ford.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/bridges.test.cpp
    title: cpp/verify/bridges.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/detect_cycle_directed.test.cpp
    title: cpp/verify/detect_cycle_directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/dijkstra.test.cpp
    title: cpp/verify/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/dijkstra2.test.cpp
    title: cpp/verify/dijkstra2.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/prim.test.cpp
    title: cpp/verify/prim.test.cpp
  - icon: ':heavy_check_mark:'
    path: cpp/verify/tree_diameter.test.cpp
    title: cpp/verify/tree_diameter.test.cpp
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
    \ <class T> class Edge {\n  static int next_id;\n\npublic:\n  const int from,\
    \ to, id;\n  const T cost;\n  Edge(int from_, int to_, T cost_)\n      : from(from_),\
    \ to(to_), id(next_id++), cost(cost_) {}\n  Edge(int from_, int to_) : from(from_),\
    \ to(to_), id(next_id++), cost(1) {}\n};\n\ntemplate <class T> int Edge<T>::next_id\
    \ = 0;\n\ntemplate <class T> ostream &operator<<(ostream &os, const Edge<T> &edge)\
    \ {\n  os << edge.id << \": \" << edge.from << \" -> \" << edge.to << \" (\" <<\
    \ edge.cost\n     << \")\";\n  return os;\n}"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/graph/edge.hpp
  requiredBy:
  - cpp/graph/graph_list.hpp
  - cpp/graph/prim.hpp
  - cpp/graph/dijkstra.hpp
  - cpp/graph/bellman_ford.hpp
  - cpp/graph/lowlink.hpp
  - cpp/graph/topological_sort.hpp
  - cpp/tree/tree.hpp
  timestamp: '2024-10-29 23:42:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/bellman_ford.test.cpp
  - cpp/verify/tree_diameter.test.cpp
  - cpp/verify/dijkstra.test.cpp
  - cpp/verify/articulation_points.test.cpp
  - cpp/verify/detect_cycle_directed.test.cpp
  - cpp/verify/prim.test.cpp
  - cpp/verify/dijkstra2.test.cpp
  - cpp/verify/bridges.test.cpp
documentation_of: cpp/graph/edge.hpp
layout: document
redirect_from:
- /library/cpp/graph/edge.hpp
- /library/cpp/graph/edge.hpp.html
title: cpp/graph/edge.hpp
---
