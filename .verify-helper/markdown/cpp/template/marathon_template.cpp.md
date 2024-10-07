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
    \ = vector<pdd>;\nusing vpld = vector<pld>;\ntemplate<typename T>\nusing pqrev\
    \ = priority_queue<T, vector<T>, greater<T>>;\n#define rep(i, n) for (int i =\
    \ 0, i##_end = (n); i < i##_end; i++)\n#define repb(i, n) for (int i = (n) - 1;\
    \ i >= 0; i--)\n#define repr(i, a, b) for (int i = (a), i##_end = (b); i < i##_end;\
    \ i++)\n#define reprb(i, a, b) for (int i = (b) - 1, i##_end = (a); i >= i##_end;\
    \ i--)\n#define ALL(a) (a).begin(), (a).end()\n#define SZ(x) ((int)(x).size())\n\
    constexpr int INF = 1e9;\nconstexpr double EPS = 1e-12;\ntemplate<typename S,\
    \ typename T>\ninline bool chmax(S &a, const T &b) {\n  if (a < b) {\n    a =\
    \ b;\n    return 1;\n  }\n  return 0;\n}\ntemplate<typename S, typename T>\ninline\
    \ bool chmin(S &a, const T &b) {\n  if (b < a) {\n    a = b;\n    return 1;\n\
    \  }\n  return 0;\n}\ntemplate<typename T>\nT max(const vector<T> &x) {\n  return\
    \ *max_element(ALL(x));\n}\ntemplate<typename T>\nT min(const vector<T> &x) {\n\
    \  return *min_element(ALL(x));\n}\ntemplate<typename T>\nT sum(const vector<T>\
    \ &x) {\n  return accumulate(ALL(x), T(0));\n}\nnamespace in {\n  template<typename\
    \ T>\n  bool print(const T &a) {\n    cout << a;\n    return true;\n  }\n  template<typename\
    \ T>\n  bool print(const vector<T> &vec) {\n    for (auto &a: vec) {\n      cout\
    \ << a;\n      if (&a != &vec.back())\n        cout << ' ';\n    }\n    return\
    \ false;\n  }\n  template<typename T>\n  bool print(const vector<vector<T>> &vv)\
    \ {\n    for (auto &v: vv) {\n      for (auto &a: v) {\n        cout << a;\n \
    \       if (&a != &v.back())\n          cout << ' ';\n      }\n      if (&v !=\
    \ &vv.back())\n        cout << '\\n';\n    }\n    return false;\n  }\n}; // namespace\
    \ in\nvoid print() { cout << '\\n'; }\ntemplate<typename Head, typename... Tail>\n\
    void print(Head &&head, Tail &&...tail) {\n  bool f = in::print(head);\n  if (sizeof...(tail)\
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
    \ s;\n\npublic:\n  Xor64(ull s_): s(s_) {}\n  // [0, 2**64)\n  ull get() {\n \
    \   ull x = s;\n    x ^= x << 7;\n    return s = x ^ (x >> 9);\n  }\n  // [min,\
    \ max)\n  int get_int(int mi, int ma) { return mi + get() % (ma - mi); }\n  //\
    \ [min, max)\n  ll get_ll(ll mi, ll ma) { return mi + get() % (ma - mi); }\n \
    \ // [0, 1)\n  double get_double() { return get() / pow(2.0, 64); }\n  // [min,\
    \ max)\n  double get_double(double mi, double ma) {\n    return mi + get_double()\
    \ * (ma - mi);\n  }\n  // normal\n  double get_normal() {\n    double x = get_double(),\
    \ y = get_double();\n    return sqrt(-2.0 * log(x)) * cos(2.0 * M_PI * y);\n \
    \ }\n} rnd(720759665484242684ull);\n\n#pragma endregion\n\nvoid solve() {}\n\n\
    int main() { solve(); }\n"
  code: "#pragma region template\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = int64_t;\nusing ull = uint64_t;\nusing ld = long double;\nusing vi\
    \ = vector<int>;\nusing vvi = vector<vi>;\nusing vvvi = vector<vvi>;\nusing vll\
    \ = vector<ll>;\nusing vvll = vector<vll>;\nusing vvvll = vector<vvll>;\nusing\
    \ vld = vector<ld>;\nusing vvld = vector<vld>;\nusing vvvld = vector<vvld>;\n\
    using vs = vector<string>;\nusing pii = pair<int, int>;\nusing pll = pair<ll,\
    \ ll>;\nusing pdd = pair<double, double>;\nusing pld = pair<ld, ld>;\nusing vpii\
    \ = vector<pii>;\nusing vp = vector<pll>;\nusing vpdd = vector<pdd>;\nusing vpld\
    \ = vector<pld>;\ntemplate<typename T>\nusing pqrev = priority_queue<T, vector<T>,\
    \ greater<T>>;\n#define rep(i, n) for (int i = 0, i##_end = (n); i < i##_end;\
    \ i++)\n#define repb(i, n) for (int i = (n) - 1; i >= 0; i--)\n#define repr(i,\
    \ a, b) for (int i = (a), i##_end = (b); i < i##_end; i++)\n#define reprb(i, a,\
    \ b) for (int i = (b) - 1, i##_end = (a); i >= i##_end; i--)\n#define ALL(a) (a).begin(),\
    \ (a).end()\n#define SZ(x) ((int)(x).size())\nconstexpr int INF = 1e9;\nconstexpr\
    \ double EPS = 1e-12;\ntemplate<typename S, typename T>\ninline bool chmax(S &a,\
    \ const T &b) {\n  if (a < b) {\n    a = b;\n    return 1;\n  }\n  return 0;\n\
    }\ntemplate<typename S, typename T>\ninline bool chmin(S &a, const T &b) {\n \
    \ if (b < a) {\n    a = b;\n    return 1;\n  }\n  return 0;\n}\ntemplate<typename\
    \ T>\nT max(const vector<T> &x) {\n  return *max_element(ALL(x));\n}\ntemplate<typename\
    \ T>\nT min(const vector<T> &x) {\n  return *min_element(ALL(x));\n}\ntemplate<typename\
    \ T>\nT sum(const vector<T> &x) {\n  return accumulate(ALL(x), T(0));\n}\nnamespace\
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
    \nstruct Timer {\n  chrono::high_resolution_clock::time_point start, now;\n  chrono::nanoseconds\
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
    class Xor64 {\n  ull s;\n\npublic:\n  Xor64(ull s_): s(s_) {}\n  // [0, 2**64)\n\
    \  ull get() {\n    ull x = s;\n    x ^= x << 7;\n    return s = x ^ (x >> 9);\n\
    \  }\n  // [min, max)\n  int get_int(int mi, int ma) { return mi + get() % (ma\
    \ - mi); }\n  // [min, max)\n  ll get_ll(ll mi, ll ma) { return mi + get() % (ma\
    \ - mi); }\n  // [0, 1)\n  double get_double() { return get() / pow(2.0, 64);\
    \ }\n  // [min, max)\n  double get_double(double mi, double ma) {\n    return\
    \ mi + get_double() * (ma - mi);\n  }\n  // normal\n  double get_normal() {\n\
    \    double x = get_double(), y = get_double();\n    return sqrt(-2.0 * log(x))\
    \ * cos(2.0 * M_PI * y);\n  }\n} rnd(720759665484242684ull);\n\n#pragma endregion\n\
    \nvoid solve() {}\n\nint main() { solve(); }"
  dependsOn: []
  isVerificationFile: false
  path: cpp/template/marathon_template.cpp
  requiredBy: []
  timestamp: '2024-09-16 23:22:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp/template/marathon_template.cpp
layout: document
redirect_from:
- /library/cpp/template/marathon_template.cpp
- /library/cpp/template/marathon_template.cpp.html
title: cpp/template/marathon_template.cpp
---
