---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/template/small_template.hpp
    title: cpp/template/small_template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: cpp/graph/bellman_ford.hpp
    title: cpp/graph/bellman_ford.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/graph/dijkstra.hpp
    title: cpp/graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/graph/lowlink.hpp
    title: cpp/graph/lowlink.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/graph/prim.hpp
    title: cpp/graph/prim.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/graph/topological_sort.hpp
    title: cpp/graph/topological_sort.hpp
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/rtnf/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
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
    \ edge.cost\n     << \")\";\n  return os;\n}\n\n// \u30B0\u30E9\u30D5(\u96A3\u63A5\
    \u30EA\u30B9\u30C8)\ntemplate <class Cost = ll, class E = Edge<Cost>> class ListGraph\
    \ {\n  int n, m;\n  vector<vector<E>> adj;\n  unordered_map<int, vector<Cost>>\
    \ shortest_path_dist;\n  unordered_map<int, vector<int>> shortest_path_parent;\n\
    \npublic:\n  static const Cost UNREACHABLE;\n  static const Cost NEGATIVE_CYCLE;\n\
    \  // \u9802\u70B9\u6570 0\n  ListGraph() : n(0), m(0), adj(0) {}\n  // \u9802\
    \u70B9\u6570 n_\n  ListGraph(int n_) : n(n_), m(0), adj(n_) {}\n\n  vector<E>\
    \ &operator[](int i) { return adj[i]; }\n\n  void add_node() {\n    adj.emplace_back();\n\
    \    n++;\n    reset_shortest();\n  }\n  template <class... Args> void add_edge(int\
    \ from, int to, Args... args) {\n    adj[from].emplace_back(from, to, args...);\n\
    \    m++;\n    reset_shortest();\n  }\n  // \u53CC\u65B9\u5411\n  template <class...\
    \ Args>\n  void add_bidirectional_edge(int from, int to, Args... args) {\n   \
    \ adj[from].emplace_back(from, to, args...);\n    adj[to].emplace_back(to, from,\
    \ args...);\n    m += 2;\n    reset_shortest();\n  }\n  void reset_shortest()\
    \ {\n    shortest_path_dist.clear();\n    shortest_path_parent.clear();\n  }\n\
    \n  // \u6700\u77ED\u8DDD\u96E2\n  void dijkstra(int start_node);\n  void bellman_ford(int\
    \ start_node);\n  Cost get_dist(int from, int to) { return shortest_path_dist[from][to];\
    \ }\n  vector<int> get_shortest_path(int from, int to) {\n    vector<int> path;\n\
    \    for (int cur = to; cur != -1; cur = shortest_path_parent[from][cur]) {\n\
    \      path.emplace_back(cur);\n    }\n    reverse(path.begin(), path.end());\n\
    \    return path;\n  }\n\n  // \u6700\u5C0F\u5168\u57DF\u68EE\n  Cost prim();\n\
    \n  // \u95A2\u7BC0\u70B9\u30FB\u6A4B\n  pair<vector<int>, vector<pair<int, int>>>\
    \ lowlink();\n\n  // \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n\
    \  vector<int> topological_sort();\n  vector<int> topological_sort_minimum();\n\
    \n  template <class C_, class E_>\n  friend ostream &operator<<(ostream &, const\
    \ ListGraph<C_, E_> &);\n};\n\ntemplate <class Cost, class E>\nconst Cost ListGraph<Cost,\
    \ E>::UNREACHABLE = numeric_limits<Cost>::max() >> 2;\ntemplate <class Cost, class\
    \ E>\nconst Cost ListGraph<Cost, E>::NEGATIVE_CYCLE =\n    numeric_limits<Cost>::min()\
    \ >> 2;\n\ntemplate <class C_, class E_>\nostream &operator<<(ostream &os, const\
    \ ListGraph<C_, E_> &graph) {\n  os << \"N = \" << graph.n << \", M = \" << graph.m\
    \ << '\\n';\n  for (const auto &ev : graph.adj) {\n    for (const auto &e : ev)\
    \ {\n      os << e << '\\n';\n    }\n  }\n  return os;\n}"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/graph/graph_list.hpp
  requiredBy:
  - cpp/graph/lowlink.hpp
  - cpp/graph/topological_sort.hpp
  - cpp/graph/bellman_ford.hpp
  - cpp/graph/prim.hpp
  - cpp/graph/dijkstra.hpp
  timestamp: '2024-09-29 16:37:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/bridges.test.cpp
  - cpp/verify/dijkstra.test.cpp
  - cpp/verify/bellman_ford.test.cpp
  - cpp/verify/prim.test.cpp
  - cpp/verify/articulation_points.test.cpp
  - cpp/verify/detect_cycle_directed.test.cpp
  - cpp/verify/dijkstra2.test.cpp
documentation_of: cpp/graph/graph_list.hpp
layout: document
redirect_from:
- /library/cpp/graph/graph_list.hpp
- /library/cpp/graph/graph_list.hpp.html
title: cpp/graph/graph_list.hpp
---
