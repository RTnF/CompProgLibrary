---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ja.wikipedia.org/wiki/Xorshift
  bundledCode: "#line 1 \"cpp/template/marathon_template.cpp\"\n#pragma region template\n\
    #include <bits/stdc++.h>\nusing namespace std;\nusing ll = int64_t;\nusing ull\
    \ = uint64_t;\nusing ld = long double;\nusing vi = vector<int>;\nusing vvi = vector<vi>;\n\
    using vvvi = vector<vvi>;\nusing vll = vector<ll>;\nusing vvll = vector<vll>;\n\
    using vvvll = vector<vvll>;\nusing vld = vector<ld>;\nusing vvld = vector<vld>;\n\
    using vvvld = vector<vvld>;\nusing vs = vector<string>;\nusing pii = pair<int,\
    \ int>;\nusing pll = pair<ll, ll>;\nusing pdd = pair<double, double>;\nusing pld\
    \ = pair<ld, ld>;\nusing vpii = vector<pii>;\nusing vp = vector<pll>;\nusing vpdd\
    \ = vector<pdd>;\nusing vpld = vector<pld>;\ntemplate <typename T> using pqrev\
    \ = priority_queue<T, vector<T>, greater<T>>;\n#define rep(i, n) for (int i =\
    \ 0, i##_end = (n); i < i##_end; i++)\n#define repb(i, n) for (int i = (n) - 1;\
    \ i >= 0; i--)\n#define repr(i, a, b) for (int i = (a), i##_end = (b); i < i##_end;\
    \ i++)\n#define reprb(i, a, b) for (int i = (b) - 1, i##_end = (a); i >= i##_end;\
    \ i--)\n#define ALL(a) (a).begin(), (a).end()\n#define SZ(x) ((int)(x).size())\n\
    constexpr int INF = 1e9;\nconstexpr double EPS = 1e-12;\ntemplate <typename S,\
    \ typename T> inline bool chmax(S &a, const T &b) {\n  if (a < b) {\n    a = b;\n\
    \    return 1;\n  }\n  return 0;\n}\ntemplate <typename S, typename T> inline\
    \ bool chmin(S &a, const T &b) {\n  if (b < a) {\n    a = b;\n    return 1;\n\
    \  }\n  return 0;\n}\ntemplate <typename T> T max(const vector<T> &x) { return\
    \ *max_element(ALL(x)); }\ntemplate <typename T> T min(const vector<T> &x) { return\
    \ *min_element(ALL(x)); }\ntemplate <typename T> T sum(const vector<T> &x) {\n\
    \  return accumulate(ALL(x), T(0));\n}\nnamespace in {\ntemplate <typename T>\
    \ bool print(const T &a) {\n  cout << a;\n  return true;\n}\ntemplate <typename\
    \ T> bool print(const vector<T> &vec) {\n  for (auto &a : vec) {\n    cout <<\
    \ a;\n    if (&a != &vec.back())\n      cout << ' ';\n  }\n  return false;\n}\n\
    template <typename T> bool print(const vector<vector<T>> &vv) {\n  for (auto &v\
    \ : vv) {\n    for (auto &a : v) {\n      cout << a;\n      if (&a != &v.back())\n\
    \        cout << ' ';\n    }\n    if (&v != &vv.back())\n      cout << '\\n';\n\
    \  }\n  return false;\n}\n}; // namespace in\nvoid print() { cout << '\\n'; }\n\
    template <typename Head, typename... Tail>\nvoid print(Head &&head, Tail &&...tail)\
    \ {\n  bool f = in::print(head);\n  if (sizeof...(tail) != 0) {\n    cout << (f\
    \ ? ' ' : '\\n');\n  }\n  print(std::forward<Tail>(tail)...);\n}\n\nstruct Timer\
    \ {\n  chrono::high_resolution_clock::time_point start, now;\n  chrono::nanoseconds\
    \ nano;\n  ll threshold = 1930000000; // 1.93 s\n  Timer() { reset(); }\n  void\
    \ reset() { start = chrono::high_resolution_clock::now(); }\n  ll get_ns() {\n\
    \    now = chrono::high_resolution_clock::now();\n    nano = chrono::duration_cast<chrono::nanoseconds>(now\
    \ - start);\n    return nano.count();\n  }\n  int get_us() { return get_ns() /\
    \ 1000; }\n  int get_ms() { return get_ns() / 1000000; }\n  int get_s() { return\
    \ get_ns() / 1000000000; }\n  ll get_remain_ns() { return threshold - get_ns();\
    \ }\n  int get_remain_us() { return get_remain_ns() / 1000; }\n  int get_remain_ms()\
    \ { return get_remain_ns() / 1000000; }\n  int get_remain_s() { return get_remain_ns()\
    \ / 1000000000; }\n  int get_limit_ms() { return threshold / 1000000; }\n  bool\
    \ intime() { return get_ns() <= threshold; }\n} timer;\n\n// https://ja.wikipedia.org/wiki/Xorshift\n\
    class Xor64 {\n  ull s;\n\npublic:\n  Xor64(ull s_) : s(s_) {}\n  // [0, 2**64)\n\
    \  ull get() {\n    ull x = s;\n    x ^= x << 7;\n    return s = x ^ (x >> 9);\n\
    \  }\n  // [min, max)\n  int get_int(int mi, int ma) { return mi + get() % (ma\
    \ - mi); }\n  // [min, max)\n  ll get_ll(ll mi, ll ma) { return mi + get() % (ma\
    \ - mi); }\n  // [0, 1)\n  double get_double() { return get() / pow(2.0, 64);\
    \ }\n  // [min, max)\n  double get_double(double mi, double ma) {\n    return\
    \ mi + get_double() * (ma - mi);\n  }\n  // normal\n  double get_normal() {\n\
    \    double x = get_double(), y = get_double();\n    return sqrt(-2.0 * log(x))\
    \ * cos(2.0 * M_PI * y);\n  }\n} rnd(720759665484242684ull);\n\n#pragma endregion\n\
    \nvoid solve() {}\n\nint main() { solve(); }\n"
  code: "#pragma region template\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = int64_t;\nusing ull = uint64_t;\nusing ld = long double;\nusing vi\
    \ = vector<int>;\nusing vvi = vector<vi>;\nusing vvvi = vector<vvi>;\nusing vll\
    \ = vector<ll>;\nusing vvll = vector<vll>;\nusing vvvll = vector<vvll>;\nusing\
    \ vld = vector<ld>;\nusing vvld = vector<vld>;\nusing vvvld = vector<vvld>;\n\
    using vs = vector<string>;\nusing pii = pair<int, int>;\nusing pll = pair<ll,\
    \ ll>;\nusing pdd = pair<double, double>;\nusing pld = pair<ld, ld>;\nusing vpii\
    \ = vector<pii>;\nusing vp = vector<pll>;\nusing vpdd = vector<pdd>;\nusing vpld\
    \ = vector<pld>;\ntemplate <typename T> using pqrev = priority_queue<T, vector<T>,\
    \ greater<T>>;\n#define rep(i, n) for (int i = 0, i##_end = (n); i < i##_end;\
    \ i++)\n#define repb(i, n) for (int i = (n) - 1; i >= 0; i--)\n#define repr(i,\
    \ a, b) for (int i = (a), i##_end = (b); i < i##_end; i++)\n#define reprb(i, a,\
    \ b) for (int i = (b) - 1, i##_end = (a); i >= i##_end; i--)\n#define ALL(a) (a).begin(),\
    \ (a).end()\n#define SZ(x) ((int)(x).size())\nconstexpr int INF = 1e9;\nconstexpr\
    \ double EPS = 1e-12;\ntemplate <typename S, typename T> inline bool chmax(S &a,\
    \ const T &b) {\n  if (a < b) {\n    a = b;\n    return 1;\n  }\n  return 0;\n\
    }\ntemplate <typename S, typename T> inline bool chmin(S &a, const T &b) {\n \
    \ if (b < a) {\n    a = b;\n    return 1;\n  }\n  return 0;\n}\ntemplate <typename\
    \ T> T max(const vector<T> &x) { return *max_element(ALL(x)); }\ntemplate <typename\
    \ T> T min(const vector<T> &x) { return *min_element(ALL(x)); }\ntemplate <typename\
    \ T> T sum(const vector<T> &x) {\n  return accumulate(ALL(x), T(0));\n}\nnamespace\
    \ in {\ntemplate <typename T> bool print(const T &a) {\n  cout << a;\n  return\
    \ true;\n}\ntemplate <typename T> bool print(const vector<T> &vec) {\n  for (auto\
    \ &a : vec) {\n    cout << a;\n    if (&a != &vec.back())\n      cout << ' ';\n\
    \  }\n  return false;\n}\ntemplate <typename T> bool print(const vector<vector<T>>\
    \ &vv) {\n  for (auto &v : vv) {\n    for (auto &a : v) {\n      cout << a;\n\
    \      if (&a != &v.back())\n        cout << ' ';\n    }\n    if (&v != &vv.back())\n\
    \      cout << '\\n';\n  }\n  return false;\n}\n}; // namespace in\nvoid print()\
    \ { cout << '\\n'; }\ntemplate <typename Head, typename... Tail>\nvoid print(Head\
    \ &&head, Tail &&...tail) {\n  bool f = in::print(head);\n  if (sizeof...(tail)\
    \ != 0) {\n    cout << (f ? ' ' : '\\n');\n  }\n  print(std::forward<Tail>(tail)...);\n\
    }\n\nstruct Timer {\n  chrono::high_resolution_clock::time_point start, now;\n\
    \  chrono::nanoseconds nano;\n  ll threshold = 1930000000; // 1.93 s\n  Timer()\
    \ { reset(); }\n  void reset() { start = chrono::high_resolution_clock::now();\
    \ }\n  ll get_ns() {\n    now = chrono::high_resolution_clock::now();\n    nano\
    \ = chrono::duration_cast<chrono::nanoseconds>(now - start);\n    return nano.count();\n\
    \  }\n  int get_us() { return get_ns() / 1000; }\n  int get_ms() { return get_ns()\
    \ / 1000000; }\n  int get_s() { return get_ns() / 1000000000; }\n  ll get_remain_ns()\
    \ { return threshold - get_ns(); }\n  int get_remain_us() { return get_remain_ns()\
    \ / 1000; }\n  int get_remain_ms() { return get_remain_ns() / 1000000; }\n  int\
    \ get_remain_s() { return get_remain_ns() / 1000000000; }\n  int get_limit_ms()\
    \ { return threshold / 1000000; }\n  bool intime() { return get_ns() <= threshold;\
    \ }\n} timer;\n\n// https://ja.wikipedia.org/wiki/Xorshift\nclass Xor64 {\n  ull\
    \ s;\n\npublic:\n  Xor64(ull s_) : s(s_) {}\n  // [0, 2**64)\n  ull get() {\n\
    \    ull x = s;\n    x ^= x << 7;\n    return s = x ^ (x >> 9);\n  }\n  // [min,\
    \ max)\n  int get_int(int mi, int ma) { return mi + get() % (ma - mi); }\n  //\
    \ [min, max)\n  ll get_ll(ll mi, ll ma) { return mi + get() % (ma - mi); }\n \
    \ // [0, 1)\n  double get_double() { return get() / pow(2.0, 64); }\n  // [min,\
    \ max)\n  double get_double(double mi, double ma) {\n    return mi + get_double()\
    \ * (ma - mi);\n  }\n  // normal\n  double get_normal() {\n    double x = get_double(),\
    \ y = get_double();\n    return sqrt(-2.0 * log(x)) * cos(2.0 * M_PI * y);\n \
    \ }\n} rnd(720759665484242684ull);\n\n#pragma endregion\n\nvoid solve() {}\n\n\
    int main() { solve(); }"
  dependsOn: []
  isVerificationFile: false
  path: cpp/template/marathon_template.cpp
  requiredBy: []
  timestamp: '2024-10-20 00:05:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp/template/marathon_template.cpp
layout: document
title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---
<link rel="stylesheet" type="text/css" href="../../css/common.css">

## エディタ用折りたたみ

```cpp
#pragma region template
#pragma endregion
```

## 一括インクルード、 `std::` の省略

```cpp
#include <bits/stdc++.h>
using namespace std;
```

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
```

`long long` ではなく、 `long` として扱われる。

## 定数

```cpp
constexpr int INF = 1e9;
constexpr double EPS = 1e-12;
```

`INF + INF` がオーバーフローしないように

## マクロ

```cpp
#define rep(i, n) for (int i = 0, i##_end = (n); i < i##_end; i++)
#define repb(i, n) for (int i = (n) - 1; i >= 0; i--)
#define repr(i, a, b) for (int i = (a), i##_end = (b); i < i##_end; i++)
#define reprb(i, a, b) for (int i = (b) - 1, i##_end = (a); i >= i##_end; i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((int)(x).size())
template <typename T> using pqrev = priority_queue<T, vector<T>, greater<T>>;
```

## ユーティリティ

```cpp
template <typename S, typename T> constexpr bool chmax(S &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename S, typename T> constexpr bool chmin(S &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T> T max(const vector<T> &x) { return *max_element(ALL(x)); }
template <typename T> T min(const vector<T> &x) { return *min_element(ALL(x)); }
template <typename T> pair<T, int> argmax(const vector<T> &x) {
  int idx = 0;
  T m = x[0];
  repr(i, 1, SZ(x)) {
    if (chmax(m, x[i]))
      idx = i;
  }
  return {m, idx};
}
template <typename T> pair<T, int> argmin(const vector<T> &x) {
  int idx = 0;
  T m = x[0];
  repr(i, 1, SZ(x)) {
    if (chmin(m, x[i]))
      idx = i;
  }
  return {m, idx};
}
template <typename T> T sum(const vector<T> &x) {
  return accumulate(ALL(x), T(0));
}
// last param -> T
template <typename T> vector<T> makev(size_t a, T b) { return vector<T>(a, b); }
template <typename... Args> auto makev(size_t sz, Args... args) {
  return vector<decltype(makev(args...))>(sz, makev(args...));
}
```

## 出力

```cpp
template <typename S, typename T> inline bool chmax(S &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename S, typename T> inline bool chmin(S &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T> T max(const vector<T> &x) { return *max_element(ALL(x)); }
template <typename T> T min(const vector<T> &x) { return *min_element(ALL(x)); }
template <typename T> T sum(const vector<T> &x) {
  return accumulate(ALL(x), T(0));
}
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

## タイマー

```cpp
struct Timer {
  chrono::high_resolution_clock::time_point start, now;
  chrono::nanoseconds nano;
  ll threshold = 1930000000; // 1.93 s
  Timer() { reset(); }
  void reset() { start = chrono::high_resolution_clock::now(); }
  ll get_ns() {
    now = chrono::high_resolution_clock::now();
    nano = chrono::duration_cast<chrono::nanoseconds>(now - start);
    return nano.count();
  }
  int get_us() { return get_ns() / 1000; }
  int get_ms() { return get_ns() / 1000000; }
  int get_s() { return get_ns() / 1000000000; }
  ll get_remain_ns() { return threshold - get_ns(); }
  int get_remain_us() { return get_remain_ns() / 1000; }
  int get_remain_ms() { return get_remain_ns() / 1000000; }
  int get_remain_s() { return get_remain_ns() / 1000000000; }
  int get_limit_ms() { return threshold / 1000000; }
  bool intime() { return get_ns() <= threshold; }
} timer;
```

## 乱数

```cpp
// https://ja.wikipedia.org/wiki/Xorshift
class Xor64 {
  ull s;

public:
  Xor64(ull s_) : s(s_) {}
  // [0, 2**64)
  ull get() {
    ull x = s;
    x ^= x << 7;
    return s = x ^ (x >> 9);
  }
  // [min, max)
  int get_int(int mi, int ma) { return mi + get() % (ma - mi); }
  // [min, max)
  ll get_ll(ll mi, ll ma) { return mi + get() % (ma - mi); }
  // [0, 1)
  double get_double() { return get() / pow(2.0, 64); }
  // [min, max)
  double get_double(double mi, double ma) {
    return mi + get_double() * (ma - mi);
  }
  // normal
  double get_normal() {
    double x = get_double(), y = get_double();
    return sqrt(-2.0 * log(x)) * cos(2.0 * M_PI * y);
  }
} rnd(720759665484242684ull);
```

## 本体

```cpp
void solve() {}

int main() { solve(); }
```