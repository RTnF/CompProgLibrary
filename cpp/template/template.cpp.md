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
  bundledCode: "#line 1 \"cpp/template/template.cpp\"\n#include <bits/stdc++.h>\n\
    // #include <boost/multiprecision/cpp_int.hpp>\n// #include <atcoder/all>\nusing\
    \ namespace std;\n// using namespace atcoder;\n// using cpp_int = boost::multiprecision::cpp_int;\n\
    using ll = int64_t;\nusing ull = uint64_t;\nusing ld = long double;\nusing vi\
    \ = vector<int>;\nusing vvi = vector<vi>;\nusing vvvi = vector<vvi>;\nusing vll\
    \ = vector<ll>;\nusing vvll = vector<vll>;\nusing vvvll = vector<vvll>;\nusing\
    \ vld = vector<ld>;\nusing vvld = vector<vld>;\nusing vvvld = vector<vvld>;\n\
    using vs = vector<string>;\nusing pii = pair<int, int>;\nusing pll = pair<ll,\
    \ ll>;\nusing pdd = pair<double, double>;\nusing pld = pair<ld, ld>;\nusing vpii\
    \ = vector<pii>;\nusing vp = vector<pll>;\nusing vpdd = vector<pdd>;\nusing vpld\
    \ = vector<pld>;\ntemplate <class T> using pqrev = priority_queue<T, vector<T>,\
    \ greater<T>>;\n#define rep(i, n) for (ll i = 0, i##_end = (n); i < i##_end; i++)\n\
    #define repb(i, n) for (ll i = (n) - 1; i >= 0; i--)\n#define repr(i, a, b) for\
    \ (ll i = (a), i##_end = (b); i < i##_end; i++)\n#define reprb(i, a, b) for (ll\
    \ i = (b) - 1, i##_end = (a); i >= i##_end; i--)\n#define ALL(a) begin(a), end(a)\n\
    #define SZ(x) ((ll)(x).size())\nconstexpr ll INF = 4e+18;\nconstexpr ld EPS =\
    \ 1e-12L;\nconstexpr ld PI = 3.14159265358979323846L;\ntemplate <class T>\nconstexpr\
    \ T local([[maybe_unused]] const T &lcl, [[maybe_unused]] const T &oj) {\n#ifdef\
    \ OJ_LOCAL\n  return lcl;\n#else\n  return oj;\n#endif\n}\ntemplate <class S,\
    \ class T> constexpr bool chmax(S &a, const T &b) {\n  if (a < b) {\n    a = b;\n\
    \    return 1;\n  }\n  return 0;\n}\ntemplate <class S, class T> constexpr bool\
    \ chmin(S &a, const T &b) {\n  if (b < a) {\n    a = b;\n    return 1;\n  }\n\
    \  return 0;\n}\ntemplate <class T> T max(const vector<T> &x) { return *max_element(ALL(x));\
    \ }\ntemplate <class T> T min(const vector<T> &x) { return *min_element(ALL(x));\
    \ }\ntemplate <class T> pair<T, int> argmax(const vector<T> &x) {\n  int idx =\
    \ 0;\n  T m = x[0];\n  repr(i, 1, SZ(x)) {\n    if (chmax(m, x[i]))\n      idx\
    \ = i;\n  }\n  return {m, idx};\n}\ntemplate <class T> pair<T, int> argmin(const\
    \ vector<T> &x) {\n  int idx = 0;\n  T m = x[0];\n  repr(i, 1, SZ(x)) {\n    if\
    \ (chmin(m, x[i]))\n      idx = i;\n  }\n  return {m, idx};\n}\ntemplate <class\
    \ T> T sum(const vector<T> &x) {\n  return accumulate(ALL(x), T(0));\n}\n// last\
    \ param -> T\ntemplate <class T> vector<T> makev(size_t a, T b) { return vector<T>(a,\
    \ b); }\ntemplate <class... Args> auto makev(size_t sz, Args... args) {\n  return\
    \ vector<decltype(makev(args...))>(sz, makev(args...));\n}\n\nnamespace in {\n\
    template <class T> bool print(const T &a) {\n  cout << a;\n  return true;\n}\n\
    template <class T> bool print(const vector<T> &vec) {\n  for (auto &a : vec) {\n\
    \    cout << a;\n    if (&a != &vec.back())\n      cout << ' ';\n  }\n  return\
    \ false;\n}\ntemplate <class T> bool print(const vector<vector<T>> &vv) {\n  for\
    \ (auto &v : vv) {\n    for (auto &a : v) {\n      cout << a;\n      if (&a !=\
    \ &v.back())\n        cout << ' ';\n    }\n    if (&v != &vv.back())\n      cout\
    \ << '\\n';\n  }\n  return false;\n}\n}; // namespace in\nvoid print() { cout\
    \ << '\\n'; }\ntemplate <class Head, class... Tail> void print(Head &&head, Tail\
    \ &&...tail) {\n  bool f = in::print(head);\n  if (sizeof...(tail) != 0) {\n \
    \   cout << (f ? ' ' : '\\n');\n  }\n  print(std::forward<Tail>(tail)...);\n}\n\
    \n#define PRF(f)                                                             \
    \    \\\n  do {                                                              \
    \           \\\n    cout << ((f) ? \"Yes\" : \"No\") << '\\n';               \
    \                       \\\n    return;                                      \
    \                              \\\n  } while (0)\n#define PR()               \
    \                                                    \\\n  do {              \
    \                                                           \\\n    cout << \"\
    -1\\n\";                                                            \\\n    return;\
    \                                                                    \\\n  } while\
    \ (0)\n\nvoid solve() {}\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  cout << fixed << setprecision(20);\n  //*\n  solve();\n  /*/\n  ll _cases;\n\
    \  cin >> _cases;\n  while (_cases--) solve();\n  //*/\n}\n"
  code: "#include <bits/stdc++.h>\n// #include <boost/multiprecision/cpp_int.hpp>\n\
    // #include <atcoder/all>\nusing namespace std;\n// using namespace atcoder;\n\
    // using cpp_int = boost::multiprecision::cpp_int;\nusing ll = int64_t;\nusing\
    \ ull = uint64_t;\nusing ld = long double;\nusing vi = vector<int>;\nusing vvi\
    \ = vector<vi>;\nusing vvvi = vector<vvi>;\nusing vll = vector<ll>;\nusing vvll\
    \ = vector<vll>;\nusing vvvll = vector<vvll>;\nusing vld = vector<ld>;\nusing\
    \ vvld = vector<vld>;\nusing vvvld = vector<vvld>;\nusing vs = vector<string>;\n\
    using pii = pair<int, int>;\nusing pll = pair<ll, ll>;\nusing pdd = pair<double,\
    \ double>;\nusing pld = pair<ld, ld>;\nusing vpii = vector<pii>;\nusing vp = vector<pll>;\n\
    using vpdd = vector<pdd>;\nusing vpld = vector<pld>;\ntemplate <class T> using\
    \ pqrev = priority_queue<T, vector<T>, greater<T>>;\n#define rep(i, n) for (ll\
    \ i = 0, i##_end = (n); i < i##_end; i++)\n#define repb(i, n) for (ll i = (n)\
    \ - 1; i >= 0; i--)\n#define repr(i, a, b) for (ll i = (a), i##_end = (b); i <\
    \ i##_end; i++)\n#define reprb(i, a, b) for (ll i = (b) - 1, i##_end = (a); i\
    \ >= i##_end; i--)\n#define ALL(a) begin(a), end(a)\n#define SZ(x) ((ll)(x).size())\n\
    constexpr ll INF = 4e+18;\nconstexpr ld EPS = 1e-12L;\nconstexpr ld PI = 3.14159265358979323846L;\n\
    template <class T>\nconstexpr T local([[maybe_unused]] const T &lcl, [[maybe_unused]]\
    \ const T &oj) {\n#ifdef OJ_LOCAL\n  return lcl;\n#else\n  return oj;\n#endif\n\
    }\ntemplate <class S, class T> constexpr bool chmax(S &a, const T &b) {\n  if\
    \ (a < b) {\n    a = b;\n    return 1;\n  }\n  return 0;\n}\ntemplate <class S,\
    \ class T> constexpr bool chmin(S &a, const T &b) {\n  if (b < a) {\n    a = b;\n\
    \    return 1;\n  }\n  return 0;\n}\ntemplate <class T> T max(const vector<T>\
    \ &x) { return *max_element(ALL(x)); }\ntemplate <class T> T min(const vector<T>\
    \ &x) { return *min_element(ALL(x)); }\ntemplate <class T> pair<T, int> argmax(const\
    \ vector<T> &x) {\n  int idx = 0;\n  T m = x[0];\n  repr(i, 1, SZ(x)) {\n    if\
    \ (chmax(m, x[i]))\n      idx = i;\n  }\n  return {m, idx};\n}\ntemplate <class\
    \ T> pair<T, int> argmin(const vector<T> &x) {\n  int idx = 0;\n  T m = x[0];\n\
    \  repr(i, 1, SZ(x)) {\n    if (chmin(m, x[i]))\n      idx = i;\n  }\n  return\
    \ {m, idx};\n}\ntemplate <class T> T sum(const vector<T> &x) {\n  return accumulate(ALL(x),\
    \ T(0));\n}\n// last param -> T\ntemplate <class T> vector<T> makev(size_t a,\
    \ T b) { return vector<T>(a, b); }\ntemplate <class... Args> auto makev(size_t\
    \ sz, Args... args) {\n  return vector<decltype(makev(args...))>(sz, makev(args...));\n\
    }\n\nnamespace in {\ntemplate <class T> bool print(const T &a) {\n  cout << a;\n\
    \  return true;\n}\ntemplate <class T> bool print(const vector<T> &vec) {\n  for\
    \ (auto &a : vec) {\n    cout << a;\n    if (&a != &vec.back())\n      cout <<\
    \ ' ';\n  }\n  return false;\n}\ntemplate <class T> bool print(const vector<vector<T>>\
    \ &vv) {\n  for (auto &v : vv) {\n    for (auto &a : v) {\n      cout << a;\n\
    \      if (&a != &v.back())\n        cout << ' ';\n    }\n    if (&v != &vv.back())\n\
    \      cout << '\\n';\n  }\n  return false;\n}\n}; // namespace in\nvoid print()\
    \ { cout << '\\n'; }\ntemplate <class Head, class... Tail> void print(Head &&head,\
    \ Tail &&...tail) {\n  bool f = in::print(head);\n  if (sizeof...(tail) != 0)\
    \ {\n    cout << (f ? ' ' : '\\n');\n  }\n  print(std::forward<Tail>(tail)...);\n\
    }\n\n#define PRF(f)                                                          \
    \       \\\n  do {                                                           \
    \              \\\n    cout << ((f) ? \"Yes\" : \"No\") << '\\n';            \
    \                          \\\n    return;                                   \
    \                                 \\\n  } while (0)\n#define PR()            \
    \                                                       \\\n  do {           \
    \                                                              \\\n    cout <<\
    \ \"-1\\n\";                                                            \\\n \
    \   return;                                                                  \
    \  \\\n  } while (0)\n\nvoid solve() {}\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  cout << fixed << setprecision(20);\n  //*\n  solve();\n  /*/\n  ll _cases;\n\
    \  cin >> _cases;\n  while (_cases--) solve();\n  //*/\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp/template/template.cpp
  requiredBy: []
  timestamp: '2024-12-06 01:07:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp/template/template.cpp
layout: document
title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---
<link rel="stylesheet" type="text/css" href="../../css/common.css">

## 一括インクルード、 `std::` の省略

```cpp
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
// using cpp_int = boost::multiprecision::cpp_int;
```

コメントアウトはコンパイル時間の短縮のため

## 型の略記

```cpp
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vld = vector<ld>;
using vvld = vector<vld>;
using vvvld = vector<vvld>;
using vs = vector<string>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using pld = pair<ld, ld>;
using vpii = vector<pii>;
using vp = vector<pll>;
using vpdd = vector<pdd>;
using vpld = vector<pld>;
template <class T> using pqrev = priority_queue<T, vector<T>, greater<T>>;
```

`long long` ではなく、 `long` として扱われる。

## 定数

```cpp
constexpr ll INF = 4e+18;
constexpr ld EPS = 1e-12L;
constexpr ld PI = 3.14159265358979323846L;
```

`INF + INF` がオーバーフローしないように

## マクロ

```cpp
#define rep(i, n) for (ll i = 0, i##_end = (n); i < i##_end; i++)
#define repb(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define repr(i, a, b) for (ll i = (a), i##_end = (b); i < i##_end; i++)
#define reprb(i, a, b) for (ll i = (b) - 1, i##_end = (a); i >= i##_end; i--)
#define ALL(a) begin(a), end(a)
#define SZ(x) ((ll)(x).size())
#define PRF(f)                           \
  do {                                   \
    cout << ((f) ? "Yes" : "No") << '\n';\
    return;                              \
  } while (0)
#define PR()       \
  do {             \
    cout << "-1\n";\
    return;        \
  } while (0)
```

## ユーティリティ

```cpp
template <class S, class T> constexpr bool chmax(S &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class S, class T> constexpr bool chmin(S &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> T max(const vector<T> &x) { return *max_element(ALL(x)); }
template <class T> T min(const vector<T> &x) { return *min_element(ALL(x)); }
template <class T> pair<T, int> argmax(const vector<T> &x) {
  int idx = 0;
  T m = x[0];
  repr(i, 1, SZ(x)) {
    if (chmax(m, x[i]))
      idx = i;
  }
  return {m, idx};
}
template <class T> pair<T, int> argmin(const vector<T> &x) {
  int idx = 0;
  T m = x[0];
  repr(i, 1, SZ(x)) {
    if (chmin(m, x[i]))
      idx = i;
  }
  return {m, idx};
}
template <class T> T sum(const vector<T> &x) {
  return accumulate(ALL(x), T(0));
}
// last param -> T
template <typename T> vector<T> makev(size_t a, T b) { return vector<T>(a, b); }
template <typename... Args> auto makev(size_t sz, Args... args) {
  return vector<decltype(makev(args...))>(sz, makev(args...));
}
```

## デバッグ用

```cpp
template <class T>
constexpr T local([[maybe_unused]] const T &lcl, [[maybe_unused]] const T &oj) {
#ifdef OJ_LOCAL
  return lcl;
#else
  return oj;
#endif
}
```

## 出力

```cpp
namespace in {
template <typename T> bool print(const T &a) {
  cout << a;
  return true;
}
template <typename T> bool print(const vector<T> &vec) {
  for (auto &a : vec) {
    cout << a;
    if (&a != &vec.back())
      cout << ' ';
  }
  return false;
}
template <typename T> bool print(const vector<vector<T>> &vv) {
  for (auto &v : vv) {
    for (auto &a : v) {
      cout << a;
      if (&a != &v.back())
        cout << ' ';
    }
    if (&v != &vv.back())
      cout << '\n';
  }
  return false;
}
}; // namespace in
void print() { cout << '\n'; }
template <typename Head, typename... Tail>
void print(Head &&head, Tail &&...tail) {
  bool f = in::print(head);
  if (sizeof...(tail) != 0) {
    cout << (f ? ' ' : '\n');
  }
  print(std::forward<Tail>(tail)...);
}
```

## 本体

```cpp
void solve() {}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  //*
  solve();
  /*/
  ll _cases;
  cin >> _cases;
  while (_cases--) solve();
  //*/
}
```