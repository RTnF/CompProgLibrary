---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp/modint/modint.hpp
    title: "\u5270\u4F59\u3092\u53D6\u308A[0, mod)\u306B\u53CE\u3081\u308Bint"
  - icon: ':question:'
    path: cpp/template/small_template.hpp
    title: "\u5171\u901A\u30D8\u30C3\u30C0\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: cpp/verify/convolution_ll.test.cpp
    title: cpp/verify/convolution_ll.test.cpp
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: modint/modint.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"modint/modint.hpp\"\n\n// AtCoder Library\n\n//\
    \ @param m `1 <= m`\n// @return x mod m\nconstexpr ll safe_mod(ll x, ll m) {\n\
    \  x %= m;\n  if (x < 0)\n    x += m;\n  return x;\n}\n// @param b `1 <= b`\n\
    // @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g\nconstexpr\
    \ pair<ll, ll> inv_gcd(ll a, ll b) {\n  a = safe_mod(a, b);\n  if (a == 0)\n \
    \   return {b, 0};\n\n  // Contracts:\n  // [1] s - m0 * a = 0 (mod b)\n  // [2]\
    \ t - m1 * a = 0 (mod b)\n  // [3] s * |m1| + t * |m0| <= b\n  ll s = b, t = a;\n\
    \  ll m0 = 0, m1 = 1;\n\n  while (t) {\n    ll u = s / t;\n    s -= t * u;\n \
    \   m0 -= m1 * u; // |m1 * u| <= |m1| * s <= b\n\n    // [3]:\n    // (s - t *\
    \ u) * |m1| + t * |m0 - m1 * u|\n    // <= s * |m1| - t * u * |m1| + t * (|m0|\
    \ + |m1| * u)\n    // = s * |m1| + t * |m0| <= b\n\n    auto tmp = s;\n    s =\
    \ t;\n    t = tmp;\n    tmp = m0;\n    m0 = m1;\n    m1 = tmp;\n  }\n  // by [3]:\
    \ |m0| <= b/g\n  // by g != b: |m0| < b/g\n  if (m0 < 0)\n    m0 += b / s;\n \
    \ return {s, m0};\n}\n\n// @param n `0 <= n`\n// @param m `1 <= m`\n// @return\
    \ `(x ** n) % m`\nconstexpr long long pow_mod_constexpr(long long x, long long\
    \ n, int m) {\n  if (m == 1)\n    return 0;\n  unsigned int _m = (unsigned int)(m);\n\
    \  unsigned long long r = 1;\n  unsigned long long y = safe_mod(x, m);\n  while\
    \ (n) {\n    if (n & 1)\n      r = (r * y) % _m;\n    y = (y * y) % _m;\n    n\
    \ >>= 1;\n  }\n  return r;\n}\n\n// Compile time primitive root\n// @param m must\
    \ be prime\n// @return primitive root (and minimum in now)\nconstexpr int primitive_root_constexpr(int\
    \ m) {\n  if (m == 2)\n    return 1;\n  if (m == 167772161)\n    return 3;\n \
    \ if (m == 469762049)\n    return 3;\n  if (m == 754974721)\n    return 11;\n\
    \  if (m == 998244353)\n    return 3;\n  int divs[20] = {};\n  divs[0] = 2;\n\
    \  int cnt = 1;\n  int x = (m - 1) / 2;\n  while (x % 2 == 0)\n    x /= 2;\n \
    \ for (int i = 3; (long long)(i)*i <= x; i += 2) {\n    if (x % i == 0) {\n  \
    \    divs[cnt++] = i;\n      while (x % i == 0) {\n        x /= i;\n      }\n\
    \    }\n  }\n  if (x > 1) {\n    divs[cnt++] = x;\n  }\n  for (int g = 2;; g++)\
    \ {\n    bool ok = true;\n    for (int i = 0; i < cnt; i++) {\n      if (pow_mod_constexpr(g,\
    \ (m - 1) / divs[i], m) == 1) {\n        ok = false;\n        break;\n      }\n\
    \    }\n    if (ok)\n      return g;\n  }\n}\ntemplate <int m> constexpr int primitive_root\
    \ = primitive_root_constexpr(m);\n\n// @param n `1 <= n`\n// @return same with\
    \ bit::countr_zero\nconstexpr int countr_zero_constexpr(unsigned int n) {\n  int\
    \ x = 0;\n  while (!(n & (1 << x)))\n    x++;\n  return x;\n}\n\ntemplate <class\
    \ mint, int g = primitive_root<mint::mod()>> struct fft_info {\n  static constexpr\
    \ int rank2 = countr_zero_constexpr(mint::mod() - 1);\n  array<mint, rank2 + 1>\
    \ root;  // root[i]^(2^i) == 1\n  array<mint, rank2 + 1> iroot; // root[i] * iroot[i]\
    \ == 1\n\n  array<mint, max(0, rank2 - 2 + 1)> rate2;\n  array<mint, max(0, rank2\
    \ - 2 + 1)> irate2;\n\n  array<mint, max(0, rank2 - 3 + 1)> rate3;\n  array<mint,\
    \ max(0, rank2 - 3 + 1)> irate3;\n\n  fft_info() {\n    root[rank2] = mint(g).pow((mint::mod()\
    \ - 1) >> rank2);\n    iroot[rank2] = root[rank2].inv();\n    for (int i = rank2\
    \ - 1; i >= 0; i--) {\n      root[i] = root[i + 1] * root[i + 1];\n      iroot[i]\
    \ = iroot[i + 1] * iroot[i + 1];\n    }\n\n    {\n      mint prod = 1, iprod =\
    \ 1;\n      for (int i = 0; i <= rank2 - 2; i++) {\n        rate2[i] = root[i\
    \ + 2] * prod;\n        irate2[i] = iroot[i + 2] * iprod;\n        prod *= iroot[i\
    \ + 2];\n        iprod *= root[i + 2];\n      }\n    }\n    {\n      mint prod\
    \ = 1, iprod = 1;\n      for (int i = 0; i <= rank2 - 3; i++) {\n        rate3[i]\
    \ = root[i + 3] * prod;\n        irate3[i] = iroot[i + 3] * iprod;\n        prod\
    \ *= iroot[i + 3];\n        iprod *= root[i + 3];\n      }\n    }\n  }\n};\n\n\
    template <class mint> void butterfly(vector<mint> &a) {\n  int n = int(a.size());\n\
    \  int h = countr_zero((unsigned int)n);\n\n  static const fft_info<mint> info;\n\
    \n  int len = 0; // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\n  while\
    \ (len < h) {\n    if (h - len == 1) {\n      int p = 1 << (h - len - 1);\n  \
    \    mint rot = 1;\n      for (int s = 0; s < (1 << len); s++) {\n        int\
    \ offset = s << (h - len);\n        for (int i = 0; i < p; i++) {\n          auto\
    \ l = a[i + offset];\n          auto r = a[i + offset + p] * rot;\n          a[i\
    \ + offset] = l + r;\n          a[i + offset + p] = l - r;\n        }\n      \
    \  if (s + 1 != (1 << len))\n          rot *= info.rate2[countr_zero(~(unsigned\
    \ int)(s))];\n      }\n      len++;\n    } else {\n      // 4-base\n      int\
    \ p = 1 << (h - len - 2);\n      mint rot = 1, imag = info.root[2];\n      for\
    \ (int s = 0; s < (1 << len); s++) {\n        mint rot2 = rot * rot;\n       \
    \ mint rot3 = rot2 * rot;\n        int offset = s << (h - len);\n        for (int\
    \ i = 0; i < p; i++) {\n          auto mod2 = 1ULL * mint::mod() * mint::mod();\n\
    \          auto a0 = 1ULL * a[i + offset].get();\n          auto a1 = 1ULL * a[i\
    \ + offset + p].get() * rot.get();\n          auto a2 = 1ULL * a[i + offset +\
    \ 2 * p].get() * rot2.get();\n          auto a3 = 1ULL * a[i + offset + 3 * p].get()\
    \ * rot3.get();\n          auto a1na3imag = 1ULL * mint(a1 + mod2 - a3).get()\
    \ * imag.get();\n          auto na2 = mod2 - a2;\n          a[i + offset] = a0\
    \ + a2 + a1 + a3;\n          a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1\
    \ + a3));\n          a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\n         \
    \ a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\n        }\n        if\
    \ (s + 1 != (1 << len))\n          rot *= info.rate3[countr_zero(~(unsigned int)(s))];\n\
    \      }\n      len += 2;\n    }\n  }\n}\n\ntemplate <class mint> void butterfly_inv(vector<mint>\
    \ &a) {\n  int n = int(a.size());\n  int h = countr_zero((unsigned int)n);\n\n\
    \  static const fft_info<mint> info;\n\n  int len = h; // a[i, i+(n>>len), i+2*(n>>len),\
    \ ..] is transformed\n  while (len) {\n    if (len == 1) {\n      int p = 1 <<\
    \ (h - len);\n      mint irot = 1;\n      for (int s = 0; s < (1 << (len - 1));\
    \ s++) {\n        int offset = s << (h - len + 1);\n        for (int i = 0; i\
    \ < p; i++) {\n          auto l = a[i + offset];\n          auto r = a[i + offset\
    \ + p];\n          a[i + offset] = l + r;\n          a[i + offset + p] =\n   \
    \           (unsigned long long)(mint::mod() + l.get() - r.get()) *\n        \
    \      irot.get();\n          ;\n        }\n        if (s + 1 != (1 << (len -\
    \ 1)))\n          irot *= info.irate2[countr_zero(~(unsigned int)(s))];\n    \
    \  }\n      len--;\n    } else {\n      // 4-base\n      int p = 1 << (h - len);\n\
    \      mint irot = 1, iimag = info.iroot[2];\n      for (int s = 0; s < (1 <<\
    \ (len - 2)); s++) {\n        mint irot2 = irot * irot;\n        mint irot3 =\
    \ irot2 * irot;\n        int offset = s << (h - len + 2);\n        for (int i\
    \ = 0; i < p; i++) {\n          auto a0 = 1ULL * a[i + offset + 0 * p].get();\n\
    \          auto a1 = 1ULL * a[i + offset + 1 * p].get();\n          auto a2 =\
    \ 1ULL * a[i + offset + 2 * p].get();\n          auto a3 = 1ULL * a[i + offset\
    \ + 3 * p].get();\n\n          auto a2na3iimag =\n              1ULL * mint((mint::mod()\
    \ + a2 - a3) * iimag.get()).get();\n\n          a[i + offset] = a0 + a1 + a2 +\
    \ a3;\n          a[i + offset + 1 * p] =\n              (a0 + (mint::mod() - a1)\
    \ + a2na3iimag) * irot.get();\n          a[i + offset + 2 * p] =\n           \
    \   (a0 + a1 + (mint::mod() - a2) + (mint::mod() - a3)) * irot2.get();\n     \
    \     a[i + offset + 3 * p] =\n              (a0 + (mint::mod() - a1) + (mint::mod()\
    \ - a2na3iimag)) *\n              irot3.get();\n        }\n        if (s + 1 !=\
    \ (1 << (len - 2)))\n          irot *= info.irate3[countr_zero(~(unsigned int)(s))];\n\
    \      }\n      len -= 2;\n    }\n  }\n}\n\ntemplate <class mint>\nvector<mint>\
    \ convolution_naive(const vector<mint> &a, const vector<mint> &b) {\n  int n =\
    \ int(a.size()), m = int(b.size());\n  vector<mint> ans(n + m - 1);\n  if (n <\
    \ m) {\n    for (int j = 0; j < m; j++) {\n      for (int i = 0; i < n; i++) {\n\
    \        ans[i + j] += a[i] * b[j];\n      }\n    }\n  } else {\n    for (int\
    \ i = 0; i < n; i++) {\n      for (int j = 0; j < m; j++) {\n        ans[i + j]\
    \ += a[i] * b[j];\n      }\n    }\n  }\n  return ans;\n}\n\ntemplate <class mint>\n\
    vector<mint> convolution_fft(vector<mint> a, vector<mint> b) {\n  int n = int(a.size()),\
    \ m = int(b.size());\n  int z = (int)bit_ceil((unsigned int)(n + m - 1));\n  a.resize(z);\n\
    \  butterfly(a);\n  b.resize(z);\n  butterfly(b);\n  for (int i = 0; i < z; i++)\
    \ {\n    a[i] *= b[i];\n  }\n  butterfly_inv(a);\n  a.resize(n + m - 1);\n  mint\
    \ iz = mint(z).inv();\n  for (int i = 0; i < n + m - 1; i++)\n    a[i] *= iz;\n\
    \  return a;\n}\n\ntemplate <class mint>\nvector<mint> convolution(vector<mint>\
    \ &&a, vector<mint> &&b) {\n  int n = int(a.size()), m = int(b.size());\n  if\
    \ (!n || !m)\n    return {};\n\n  int z = (int)bit_ceil((unsigned int)(n + m -\
    \ 1));\n  assert((mint::mod() - 1) % z == 0);\n\n  if (min(n, m) <= 60)\n    return\
    \ convolution_naive(a, b);\n  return convolution_fft(a, b);\n}\n\ntemplate <unsigned\
    \ int mod = 998244353, class T>\nvector<T> convolution(const vector<T> &a, const\
    \ vector<T> &b) {\n  int n = int(a.size()), m = int(b.size());\n  if (!n || !m)\n\
    \    return {};\n\n  using Mint = ModInt<mod>;\n\n  int z = (int)bit_ceil((unsigned\
    \ int)(n + m - 1));\n  assert((Mint::mod() - 1) % z == 0);\n\n  vector<Mint> a2(n),\
    \ b2(m);\n  for (int i = 0; i < n; i++) {\n    a2[i] = Mint(a[i]);\n  }\n  for\
    \ (int i = 0; i < m; i++) {\n    b2[i] = Mint(b[i]);\n  }\n  auto c2 = convolution(std::move(a2),\
    \ std::move(b2));\n  vector<T> c(n + m - 1);\n  for (int i = 0; i < n + m - 1;\
    \ i++) {\n    c[i] = c2[i].get();\n  }\n  return c;\n}\n\nvector<ll> convolution_ll(const\
    \ vector<ll> &a, const vector<ll> &b) {\n  int n = int(a.size()), m = int(b.size());\n\
    \  if (!n || !m)\n    return {};\n\n  static constexpr ull MOD1 = 754974721; //\
    \ 2^24\n  static constexpr ull MOD2 = 167772161; // 2^25\n  static constexpr ull\
    \ MOD3 = 469762049; // 2^26\n  static constexpr ull M2M3 = MOD2 * MOD3;\n  static\
    \ constexpr ull M1M3 = MOD1 * MOD3;\n  static constexpr ull M1M2 = MOD1 * MOD2;\n\
    \  static constexpr ull M1M2M3 = MOD1 * MOD2 * MOD3;\n\n  static constexpr ull\
    \ i1 = inv_gcd(MOD2 * MOD3, MOD1).second;\n  static constexpr ull i2 = inv_gcd(MOD1\
    \ * MOD3, MOD2).second;\n  static constexpr ull i3 = inv_gcd(MOD1 * MOD2, MOD3).second;\n\
    \n  static constexpr int MAX_AB_BIT = 24;\n  assert(n + m - 1 <= (1 << MAX_AB_BIT));\n\
    \n  auto c1 = convolution<MOD1>(a, b);\n  auto c2 = convolution<MOD2>(a, b);\n\
    \  auto c3 = convolution<MOD3>(a, b);\n\n  vector<ll> c(n + m - 1);\n  for (int\
    \ i = 0; i < n + m - 1; i++) {\n    ull x = 0;\n    x += (c1[i] * i1) % MOD1 *\
    \ M2M3;\n    x += (c2[i] * i2) % MOD2 * M1M3;\n    x += (c3[i] * i3) % MOD3 *\
    \ M1M2;\n    // B = 2^63, -B <= x, r(real value) < B\n    // (x, x - M, x - 2M,\
    \ or x - 3M) = r (mod 2B)\n    // r = c1[i] (mod MOD1)\n    // focus on MOD1\n\
    \    // r = x, x - M', x - 2M', x - 3M' (M' = M % 2^64) (mod 2B)\n    // r = x,\n\
    \    //     x - M' + (0 or 2B),\n    //     x - 2M' + (0, 2B or 4B),\n    // \
    \    x - 3M' + (0, 2B, 4B or 6B) (without mod!)\n    // (r - x) = 0, (0)\n   \
    \ //           - M' + (0 or 2B), (1)\n    //           -2M' + (0 or 2B or 4B),\
    \ (2)\n    //           -3M' + (0 or 2B or 4B or 6B) (3) (mod MOD1)\n    // we\
    \ checked that\n    //   ((1) mod MOD1) mod 5 = 2\n    //   ((2) mod MOD1) mod\
    \ 5 = 3\n    //   ((3) mod MOD1) mod 5 = 4\n    ll diff = c1[i] - safe_mod((ll)(x),\
    \ (ll)(MOD1));\n    if (diff < 0)\n      diff += MOD1;\n    static constexpr ull\
    \ offset[5] = {0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};\n    x -= offset[diff %\
    \ 5];\n    c[i] = x;\n  }\n\n  return c;\n}"
  dependsOn:
  - cpp/modint/modint.hpp
  - cpp/template/small_template.hpp
  isVerificationFile: false
  path: cpp/fps/convolution.hpp
  requiredBy: []
  timestamp: '2024-11-24 09:02:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - cpp/verify/convolution_ll.test.cpp
documentation_of: cpp/fps/convolution.hpp
layout: document
redirect_from:
- /library/cpp/fps/convolution.hpp
- /library/cpp/fps/convolution.hpp.html
title: cpp/fps/convolution.hpp
---
