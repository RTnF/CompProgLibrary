---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/template/small_template.hpp
    title: cpp/template/small_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  code: "#pragma once\n#include \"template/small_template.hpp\"\n\n// \u8FBA\ntemplate<class\
    \ T>\nclass Edge {\n  static int nextId;\n\npublic:\n  const int from, to, id;\n\
    \  const T cost;\n  Edge(int from_, int to_, T cost_): from(from_), to(to_), id(nextId++),\
    \ cost(cost_) {}\n  Edge(int from_, int to_): from(from_), to(to_), id(nextId++),\
    \ cost(1) {}\n};\n\ntemplate<class T>\nint Edge<T>::nextId = 0;\n\ntemplate<class\
    \ T>\nostream &operator<<(ostream &os, const Edge<T> &edge) {\n  os << edge.id\
    \ << \": \" << edge.from << \" -> \" << edge.to << \" (\" << edge.cost << \")\"\
    ;\n  return os;\n}\n\n// \u30B0\u30E9\u30D5(\u96A3\u63A5\u30EA\u30B9\u30C8)\n\
    template<class Cost = ll, class E = Edge<Cost>>\nclass ListGraph {\n  int n, m;\n\
    \  vector<vector<E>> adj;\n  unordered_map<int, vector<Cost>> shortest_path_dist;\n\
    \  unordered_map<int, vector<int>> shortest_path_parent;\n\npublic:\n  static\
    \ const Cost UNREACHABLE = numeric_limits<Cost>::max();\n  static const Cost NEGATIVE_CYCLE\
    \ = numeric_limits<Cost>::min();\n  ListGraph() {}\n  ListGraph(int n_): n(n_),\
    \ m(0), adj(n_) {}\n\n  void addNode() {\n    adj.emplace_back();\n    n++;\n\
    \    resetShortest();\n  }\n  template<class... Args>\n  void addEdge(int from,\
    \ int to, Args... args) {\n    adj[from].emplace_back(from, to, args...);\n  \
    \  m++;\n    resetShortest();\n  }\n  // \u53CC\u65B9\u5411\n  template<class...\
    \ Args>\n  void addBidirectionalEdge(int from, int to, Args... args) {\n    adj[from].emplace_back(from,\
    \ to, args...);\n    adj[to].emplace_back(to, from, args...);\n    m += 2;\n \
    \   resetShortest();\n  }\n  void resetShortest() {\n    shortest_path_dist.clear();\n\
    \    shortest_path_parent.clear();\n  }\n  vector<E> &operator[](int i) { return\
    \ adj[i]; }\n\n  // \u6700\u77ED\u8DDD\u96E2\n  void dijkstra(int start_node);\n\
    \  void bellmanFord(int start_node);\n  Cost getDist(int from, int to) { return\
    \ shortest_path_dist[from][to]; }\n  vector<int> getShortestPath(int from, int\
    \ to) {\n    vector<int> path;\n    for (int cur = to; cur != -1; cur = shortest_path_parent[from][cur])\
    \ {\n      path.emplace_back(cur);\n    }\n    reverse(path.begin(), path.end());\n\
    \    return path;\n  }\n\n  // \u6700\u5C0F\u5168\u57DF\u68EE\n  Cost prim();\n\
    \n  // \u95A2\u7BC0\u70B9\u30FB\u6A4B\n  pair<vector<int>, vector<pair<int, int>>>\
    \ lowlink();\n\n  // \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n\
    \  vector<int> topologicalSort();\n  vector<int> topologicalSortMinimum();\n\n\
    \  template<class C_, class E_>\n  friend ostream &operator<<(ostream &, const\
    \ ListGraph<C_, E_> &);\n};\n\ntemplate<class C_, class E_>\nostream &operator<<(ostream\
    \ &os, const ListGraph<C_, E_> &graph) {\n  os << \"N = \" << graph.n << \", M\
    \ = \" << graph.m << '\\n';\n  for (const auto &ev: graph.adj) {\n    for (const\
    \ auto &e: ev) {\n      os << e << '\\n';\n    }\n  }\n  return os;\n}"
  dependsOn:
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/graph/list_graph.hpp
  requiredBy: []
  timestamp: '2024-09-07 19:01:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp/graph/list_graph.hpp
layout: document
redirect_from:
- /library/cpp/graph/list_graph.hpp
- /library/cpp/graph/list_graph.hpp.html
title: cpp/graph/list_graph.hpp
---
