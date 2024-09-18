---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp/template/template.cpp\"\n#pragma region template\n#include\
    \ <bits/stdc++.h>\n//#include <boost/multiprecision/cpp_int.hpp>\n//#include <atcoder/all>\n\
    using namespace std;\n// using namespace atcoder;\n// using cpp_int = boost::multiprecision::cpp_int;\n\
    using ll = int64_t;\nusing ull = uint64_t;\nusing ld = long double;\nusing vi\
    \ = vector<int>;\nusing vvi = vector<vi>;\nusing vvvi = vector<vvi>;\nusing vll\
    \ = vector<ll>;\nusing vvll = vector<vll>;\nusing vvvll = vector<vvll>;\nusing\
    \ vld = vector<ld>;\nusing vvld = vector<vld>;\nusing vvvld = vector<vvld>;\n\
    using vs = vector<string>;\nusing pii = pair<int, int>;\nusing pll = pair<ll,\
    \ ll>;\nusing pdd = pair<double, double>;\nusing pld = pair<ld, ld>;\nusing vpii\
    \ = vector<pii>;\nusing vp = vector<pll>;\nusing vpdd = vector<pdd>;\nusing vpld\
    \ = vector<pld>;\ntemplate<typename T>\nusing pqrev = priority_queue<T, vector<T>,\
    \ greater<T>>;\n#define rep(i, n) for (ll i = 0, i##_end = (n); i < i##_end; i++)\n\
    #define repb(i, n) for (ll i = (n) - 1; i >= 0; i--)\n#define repr(i, a, b) for\
    \ (ll i = (a), i##_end = (b); i < i##_end; i++)\n#define reprb(i, a, b) for (ll\
    \ i = (b) - 1, i##_end = (a); i >= i##_end; i--)\n#define ALL(a) begin(a), end(a)\n\
    #define SZ(x) ((ll)(x).size())\nconstexpr ll INF = 1e+18;\nconstexpr ld EPS =\
    \ 1e-12L;\nconstexpr ld PI = 3.14159265358979323846L;\ntemplate<typename T>\n\
    constexpr T local([[maybe_unused]] const T &lcl, [[maybe_unused]] const T &oj)\
    \ {\n#ifdef OJ_LOCAL\n  return lcl;\n#else\n  return oj;\n#endif\n}\ntemplate<typename\
    \ S, typename T>\nconstexpr bool chmax(S &a, const T &b) {\n  if (a < b) {\n \
    \   a = b;\n    return 1;\n  }\n  return 0;\n}\ntemplate<typename S, typename\
    \ T>\nconstexpr bool chmin(S &a, const T &b) {\n  if (b < a) {\n    a = b;\n \
    \   return 1;\n  }\n  return 0;\n}\ntemplate<typename T>\nT max(const vector<T>\
    \ &x) {\n  return *max_element(ALL(x));\n}\ntemplate<typename T>\nT min(const\
    \ vector<T> &x) {\n  return *min_element(ALL(x));\n}\ntemplate<typename T>\npair<T,\
    \ int> argmax(const vector<T> &x) {\n  int idx = 0;\n  T m = x[0];\n  repr (i,\
    \ 1, SZ(x)) {\n    if (chmax(m, x[i]))\n      idx = i;\n  }\n  return {m, idx};\n\
    }\ntemplate<typename T>\npair<T, int> argmin(const vector<T> &x) {\n  int idx\
    \ = 0;\n  T m = x[0];\n  repr (i, 1, SZ(x)) {\n    if (chmin(m, x[i]))\n     \
    \ idx = i;\n  }\n  return {m, idx};\n}\ntemplate<typename T>\nT sum(const vector<T>\
    \ &x) {\n  return accumulate(ALL(x), T(0));\n}\n// last param -> T\ntemplate<typename\
    \ T>\nvector<T> makev(size_t a, T b) {\n  return vector<T>(a, b);\n}\ntemplate<typename...\
    \ Args>\nauto makev(size_t sz, Args... args) {\n  return vector<decltype(makev(args...))>(sz,\
    \ makev(args...));\n}\n\nnamespace in {\n  template<typename T>\n  bool print(const\
    \ T &a) {\n    cout << a;\n    return true;\n  }\n  template<typename T>\n  bool\
    \ print(const vector<T> &vec) {\n    for (auto &a: vec) {\n      cout << a;\n\
    \      if (&a != &vec.back())\n        cout << ' ';\n    }\n    return false;\n\
    \  }\n  template<typename T>\n  bool print(const vector<vector<T>> &vv) {\n  \
    \  for (auto &v: vv) {\n      for (auto &a: v) {\n        cout << a;\n       \
    \ if (&a != &v.back())\n          cout << ' ';\n      }\n      if (&v != &vv.back())\n\
    \        cout << '\\n';\n    }\n    return false;\n  }\n}; // namespace in\nvoid\
    \ print() { cout << '\\n'; }\ntemplate<typename Head, typename... Tail>\nvoid\
    \ print(Head &&head, Tail &&...tail) {\n  bool f = in::print(head);\n  if (sizeof...(tail)\
    \ != 0) {\n    cout << (f ? ' ' : '\\n');\n  }\n  print(std::forward<Tail>(tail)...);\n\
    }\n#pragma endregion\n\n/*\nconstexpr ll MOD = 1e9 + 7;\n/*/\nconstexpr ll MOD\
    \ = 998244353;\n//*/\n\n#define PRF(f)                            \\\n  do { \
    \                                   \\\n    cout << ((f) ? \"Yes\" : \"No\") <<\
    \ '\\n'; \\\n    return;                               \\\n  } while (0)\n#define\
    \ PR()        \\\n  do {              \\\n    cout << \"-1\\n\"; \\\n    return;\
    \         \\\n  } while (0)\n\nvoid solve() {}\n\nint main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(false);\n  cout << fixed << setprecision(20);\n  //*\n\
    \  solve();\n  /*/\n  ll _cases;\n  cin >> _cases;\n  while (_cases--) solve();\n\
    \  //*/\n}\n"
  code: "#pragma region template\n#include <bits/stdc++.h>\n//#include <boost/multiprecision/cpp_int.hpp>\n\
    //#include <atcoder/all>\nusing namespace std;\n// using namespace atcoder;\n\
    // using cpp_int = boost::multiprecision::cpp_int;\nusing ll = int64_t;\nusing\
    \ ull = uint64_t;\nusing ld = long double;\nusing vi = vector<int>;\nusing vvi\
    \ = vector<vi>;\nusing vvvi = vector<vvi>;\nusing vll = vector<ll>;\nusing vvll\
    \ = vector<vll>;\nusing vvvll = vector<vvll>;\nusing vld = vector<ld>;\nusing\
    \ vvld = vector<vld>;\nusing vvvld = vector<vvld>;\nusing vs = vector<string>;\n\
    using pii = pair<int, int>;\nusing pll = pair<ll, ll>;\nusing pdd = pair<double,\
    \ double>;\nusing pld = pair<ld, ld>;\nusing vpii = vector<pii>;\nusing vp = vector<pll>;\n\
    using vpdd = vector<pdd>;\nusing vpld = vector<pld>;\ntemplate<typename T>\nusing\
    \ pqrev = priority_queue<T, vector<T>, greater<T>>;\n#define rep(i, n) for (ll\
    \ i = 0, i##_end = (n); i < i##_end; i++)\n#define repb(i, n) for (ll i = (n)\
    \ - 1; i >= 0; i--)\n#define repr(i, a, b) for (ll i = (a), i##_end = (b); i <\
    \ i##_end; i++)\n#define reprb(i, a, b) for (ll i = (b) - 1, i##_end = (a); i\
    \ >= i##_end; i--)\n#define ALL(a) begin(a), end(a)\n#define SZ(x) ((ll)(x).size())\n\
    constexpr ll INF = 1e+18;\nconstexpr ld EPS = 1e-12L;\nconstexpr ld PI = 3.14159265358979323846L;\n\
    template<typename T>\nconstexpr T local([[maybe_unused]] const T &lcl, [[maybe_unused]]\
    \ const T &oj) {\n#ifdef OJ_LOCAL\n  return lcl;\n#else\n  return oj;\n#endif\n\
    }\ntemplate<typename S, typename T>\nconstexpr bool chmax(S &a, const T &b) {\n\
    \  if (a < b) {\n    a = b;\n    return 1;\n  }\n  return 0;\n}\ntemplate<typename\
    \ S, typename T>\nconstexpr bool chmin(S &a, const T &b) {\n  if (b < a) {\n \
    \   a = b;\n    return 1;\n  }\n  return 0;\n}\ntemplate<typename T>\nT max(const\
    \ vector<T> &x) {\n  return *max_element(ALL(x));\n}\ntemplate<typename T>\nT\
    \ min(const vector<T> &x) {\n  return *min_element(ALL(x));\n}\ntemplate<typename\
    \ T>\npair<T, int> argmax(const vector<T> &x) {\n  int idx = 0;\n  T m = x[0];\n\
    \  repr (i, 1, SZ(x)) {\n    if (chmax(m, x[i]))\n      idx = i;\n  }\n  return\
    \ {m, idx};\n}\ntemplate<typename T>\npair<T, int> argmin(const vector<T> &x)\
    \ {\n  int idx = 0;\n  T m = x[0];\n  repr (i, 1, SZ(x)) {\n    if (chmin(m, x[i]))\n\
    \      idx = i;\n  }\n  return {m, idx};\n}\ntemplate<typename T>\nT sum(const\
    \ vector<T> &x) {\n  return accumulate(ALL(x), T(0));\n}\n// last param -> T\n\
    template<typename T>\nvector<T> makev(size_t a, T b) {\n  return vector<T>(a,\
    \ b);\n}\ntemplate<typename... Args>\nauto makev(size_t sz, Args... args) {\n\
    \  return vector<decltype(makev(args...))>(sz, makev(args...));\n}\n\nnamespace\
    \ in {\n  template<typename T>\n  bool print(const T &a) {\n    cout << a;\n \
    \   return true;\n  }\n  template<typename T>\n  bool print(const vector<T> &vec)\
    \ {\n    for (auto &a: vec) {\n      cout << a;\n      if (&a != &vec.back())\n\
    \        cout << ' ';\n    }\n    return false;\n  }\n  template<typename T>\n\
    \  bool print(const vector<vector<T>> &vv) {\n    for (auto &v: vv) {\n      for\
    \ (auto &a: v) {\n        cout << a;\n        if (&a != &v.back())\n         \
    \ cout << ' ';\n      }\n      if (&v != &vv.back())\n        cout << '\\n';\n\
    \    }\n    return false;\n  }\n}; // namespace in\nvoid print() { cout << '\\\
    n'; }\ntemplate<typename Head, typename... Tail>\nvoid print(Head &&head, Tail\
    \ &&...tail) {\n  bool f = in::print(head);\n  if (sizeof...(tail) != 0) {\n \
    \   cout << (f ? ' ' : '\\n');\n  }\n  print(std::forward<Tail>(tail)...);\n}\n\
    #pragma endregion\n\n/*\nconstexpr ll MOD = 1e9 + 7;\n/*/\nconstexpr ll MOD =\
    \ 998244353;\n//*/\n\n#define PRF(f)                            \\\n  do {   \
    \                                 \\\n    cout << ((f) ? \"Yes\" : \"No\") <<\
    \ '\\n'; \\\n    return;                               \\\n  } while (0)\n#define\
    \ PR()        \\\n  do {              \\\n    cout << \"-1\\n\"; \\\n    return;\
    \         \\\n  } while (0)\n\nvoid solve() {}\n\nint main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(false);\n  cout << fixed << setprecision(20);\n  //*\n\
    \  solve();\n  /*/\n  ll _cases;\n  cin >> _cases;\n  while (_cases--) solve();\n\
    \  //*/\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp/template/template.cpp
  requiredBy: []
  timestamp: '2024-09-16 23:28:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp/template/template.cpp
layout: document
redirect_from:
- /library/cpp/template/template.cpp
- /library/cpp/template/template.cpp.html
title: cpp/template/template.cpp
---
