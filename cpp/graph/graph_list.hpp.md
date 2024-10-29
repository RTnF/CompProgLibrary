---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/graph/edge.hpp
    title: cpp/graph/edge.hpp
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/edge.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"graph/edge.hpp\"\n#include \"template/small_template.hpp\"\
    \n\n// \u30B0\u30E9\u30D5(\u96A3\u63A5\u30EA\u30B9\u30C8)\ntemplate <class Cost\
    \ = ll, class E = Edge<Cost>> class ListGraph {\n  int n_, m_;\n  vector<vector<E>>\
    \ adj;\n  unordered_map<int, vector<Cost>> shortest_path_dist;\n  unordered_map<int,\
    \ vector<int>> shortest_path_parent;\n\npublic:\n  static const Cost UNREACHABLE;\n\
    \  static const Cost NEGATIVE_CYCLE;\n  // \u9802\u70B9\u6570 0\n  ListGraph()\
    \ : n_(0), m_(0), adj(0) {}\n  // \u9802\u70B9\u6570 n\n  ListGraph(int n) : n_(n),\
    \ m_(0), adj(n) {}\n\n  vector<E> &operator[](int i) const { return adj[i]; }\n\
    \n  void add_node() {\n    adj.emplace_back();\n    n_++;\n    reset_shortest();\n\
    \  }\n  template <class... Args> void add_edge(int from, int to, Args... args)\
    \ {\n    adj[from].emplace_back(from, to, args...);\n    m_++;\n    reset_shortest();\n\
    \  }\n  // \u53CC\u65B9\u5411\n  template <class... Args>\n  void add_bidirectional_edge(int\
    \ from, int to, Args... args) {\n    adj[from].emplace_back(from, to, args...);\n\
    \    adj[to].emplace_back(to, from, args...);\n    m_ += 2;\n    reset_shortest();\n\
    \  }\n  void reset_shortest() {\n    shortest_path_dist.clear();\n    shortest_path_parent.clear();\n\
    \  }\n\n  // \u6700\u77ED\u8DDD\u96E2\n  void dijkstra(int start_node);\n  void\
    \ bellman_ford(int start_node);\n  Cost distance(int from, int to) { return shortest_path_dist[from][to];\
    \ }\n  vector<Cost> distance(int from) { return shortest_path_dist[from]; }\n\
    \  vector<int> shortest_path(int from, int to) {\n    vector<int> path;\n    for\
    \ (int cur = to; cur != -1; cur = shortest_path_parent[from][cur]) {\n      path.emplace_back(cur);\n\
    \    }\n    reverse(path.begin(), path.end());\n    return path;\n  }\n\n  //\
    \ \u6700\u5C0F\u5168\u57DF\u68EE\n  Cost prim();\n\n  // \u95A2\u7BC0\u70B9\u30FB\
    \u6A4B\n  pair<vector<int>, vector<pair<int, int>>> lowlink();\n\n  // \u30C8\u30DD\
    \u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n  vector<int> topological_sort();\n\
    \  vector<int> topological_sort_minimum();\n\n  template <class C_, class E_>\n\
    \  friend ostream &operator<<(ostream &, const ListGraph<C_, E_> &);\n};\n\ntemplate\
    \ <class Cost, class E>\nconst Cost ListGraph<Cost, E>::UNREACHABLE = numeric_limits<Cost>::max()\
    \ >> 2;\ntemplate <class Cost, class E>\nconst Cost ListGraph<Cost, E>::NEGATIVE_CYCLE\
    \ =\n    numeric_limits<Cost>::min() >> 2;\n\ntemplate <class C_, class E_>\n\
    ostream &operator<<(ostream &os, const ListGraph<C_, E_> &graph) {\n  os << \"\
    N = \" << graph.n_ << \", M = \" << graph.m_ << '\\n';\n  for (const auto &ev\
    \ : graph.adj) {\n    for (const auto &e : ev) {\n      os << e << '\\n';\n  \
    \  }\n  }\n  return os;\n}"
  dependsOn:
  - cpp/graph/edge.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/graph/graph_list.hpp
  requiredBy:
  - cpp/graph/prim.hpp
  - cpp/graph/dijkstra.hpp
  - cpp/graph/bellman_ford.hpp
  - cpp/graph/lowlink.hpp
  - cpp/graph/topological_sort.hpp
  timestamp: '2024-10-29 23:42:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/bellman_ford.test.cpp
  - cpp/verify/dijkstra.test.cpp
  - cpp/verify/articulation_points.test.cpp
  - cpp/verify/detect_cycle_directed.test.cpp
  - cpp/verify/prim.test.cpp
  - cpp/verify/dijkstra2.test.cpp
  - cpp/verify/bridges.test.cpp
documentation_of: cpp/graph/graph_list.hpp
layout: document
title: "\u30B0\u30E9\u30D5 (\u96A3\u63A5\u30EA\u30B9\u30C8\u5F62\u5F0F)"
---
<link rel="stylesheet" type="text/css" href="../../css/common.css">

隣接リスト。  
最短距離と `Dijkstra Tree` のうちの一つをもつ

グラフアルゴリズム：
- [Bellman-Ford](bellman_ford.hpp)
- [Dijkstra](dijkstra.hpp)
- [lowlink](lowlink.hpp)
- [prim](prim.hpp)
- [Topological Sort](topological_sort.hpp)
- [Warshall-Floyd](warshall_floyd.hpp)

## コンストラクタ

```cpp
ListGraph<Cost = ll, E = Edge<Cost>> graph()
```

$n$ 頂点、結合がない状態で初期化する

## add_node

```cpp
void graph.add_node()
```

頂点を $1$ つ追加する

**計算量**

- ならし $ O(1) $

## add_edge

```cpp
void graph.add_edge(int from, int to, Args... args)
```

頂点 $from → to$ の有向辺を追加する  
`args` は `Edge` のコンストラクタに渡る

**計算量**

- ならし $ O(1) $

## add_bidirectional_edge

```cpp
void graph.add_bidirectional_edge(int from, int to, Args... args)
```

頂点 $from → to$ と $to → from$ の有向辺を追加する  
`args` は `Edge` のコンストラクタに渡る

**計算量**

- ならし $ O(1) $

## operator[]

```cpp
vector<E> graph.&operator[](int i)
```

頂点 $i$ の隣接リストを返す

## reset_shortest

```cpp
void graph.reset_shortest()
```

最短距離のキャッシュをクリアする。  
`add_edge` か `add_node` で発動する。

**計算量**

- キャッシュがある場合 $ O(size) $

## get_dist

```cpp
Cost graph.get_dist(int from, int to)
vector<Cost> graph.get_dist(int from)
```

キャッシュから最短距離を返す

## get_shortest_path

```cpp
vector<int> graph.get_shortest_path(int from, int to)
```

キャッシュから最短パスを求める

## 定数

```cpp
Cost ListGraph<Cost, E>::UNREACHABLE
Cost ListGraph<Cost, E>::NEGATIVE_CYCLE
```

- `UNREACHABLE` : 最短距離において到達不能 $(\infty)$ を表す
- `NEGATIVE_CYCLE` : 最短距離において負のループ $(-\infty)$ を表す

## operator<< (出力)

```cpp
ostream &operator<<(ostream &os, const ListGraph<C_, E_> &graph)
```

デバッグ用