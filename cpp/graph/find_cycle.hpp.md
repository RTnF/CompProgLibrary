---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/graph/edge.hpp
    title: cpp/graph/edge.hpp
  - icon: ':heavy_check_mark:'
    path: cpp/graph/graph_list.hpp
    title: "\u30B0\u30E9\u30D5 (\u96A3\u63A5\u30EA\u30B9\u30C8\u5F62\u5F0F)"
  - icon: ':heavy_check_mark:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/detect_cycle_directed_2.test.cpp
    title: cpp/verify/detect_cycle_directed_2.test.cpp
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/graph_list.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"graph/graph_list.hpp\"\n\n/**\n * \u30B5\u30A4\u30AF\
    \u30EB\u3092\u898B\u3064\u3051\u308B\n */\ntemplate <class Cost, class E>\nvector<E>\
    \ ListGraph<Cost, E>::find_cycle_directed() {\n  vector<char> visited(n_, 0);\n\
    \  vector<E> in(n_, {-1, -1});\n  vector<E> ret;\n  auto dfs = [&](auto &Self,\
    \ int node) -> void {\n    visited[node] = 1;\n    for (auto &&e : adj[node])\
    \ {\n      if (ret.size()) {\n        break;\n      }\n      if (!visited[e.to])\
    \ {\n        in[e.to] = e;\n        Self(Self, e.to);\n      } else if (visited[e.to]\
    \ == 1) {\n        ret.emplace_back(e);\n        for (int v = node; v != e.to;\
    \ v = in[v].from) {\n          ret.emplace_back(in[v]);\n        }\n        reverse(ret.begin(),\
    \ ret.end());\n        return;\n      }\n    }\n    visited[node] = 2;\n  };\n\
    \  for (int i = 0; i < n_; i++) {\n    if (!visited[i]) {\n      dfs(dfs, i);\n\
    \    }\n  }\n  return ret;\n}"
  dependsOn:
  - cpp/graph/graph_list.hpp
  - cpp/graph/edge.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/graph/find_cycle.hpp
  requiredBy: []
  timestamp: '2024-11-03 09:29:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/detect_cycle_directed_2.test.cpp
documentation_of: cpp/graph/find_cycle.hpp
layout: document
redirect_from:
- /library/cpp/graph/find_cycle.hpp
- /library/cpp/graph/find_cycle.hpp.html
title: cpp/graph/find_cycle.hpp
---
