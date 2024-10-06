#pragma once
#include "template/small_template.hpp"

/**
 * @brief 剰余を取り[0, mod)に収めるint
 * based on ACL
 * @tparam mod 素数に限る
 */
template <uint32_t mod, enable_if_t<(2 <= mod)> * = nullptr> class ModInt {
  uint32_t x;

public:
  constexpr ModInt() : x(0) {}
  template <class T, enable_if_t<is_signed_v<T>> * = nullptr>
  constexpr ModInt(T x_) : x(x_ < 0 ? x_ % (ll)mod + (ll)mod : x_ % (ll)mod) {}
  template <class U, enable_if_t<!is_signed_v<U>> * = nullptr>
  constexpr ModInt(U x_) : x(x_ % mod) {}

  uint32_t get() const { return x; }
  template <class T, enable_if_t<is_signed_v<T>> * = nullptr>
  constexpr void set(T x_) {
    x = x_ < 0 ? x_ % (ll)mod + (ll)mod : x_ % (ll)mod;
  }
  template <class U, enable_if_t<!is_signed_v<U>> * = nullptr>
  constexpr void set(U x_) {
    x = x_ % mod;
  }

  constexpr ModInt operator++(int) {
    ModInt y = *this;
    ++*this;
    return y;
  }
  constexpr ModInt &operator++() {
    x = x == mod - 1 ? 0u : x + 1;
    return *this;
  }
  constexpr ModInt operator--(int) {
    ModInt y = *this;
    --*this;
    return y;
  }
  constexpr ModInt &operator--() {
    x = x == 0u ? mod - 1 : x - 1;
    return *this;
  }
  constexpr ModInt &operator+=(const ModInt &y) {
    x += y.x;
    if (x >= mod) {
      x -= mod;
    }
    return *this;
  }
  constexpr ModInt &operator-=(const ModInt &y) {
    x -= y.x;
    if (x >= mod) {
      x += mod;
    }
    return *this;
  }
  constexpr ModInt &operator*=(const ModInt &y) {
    x = (ull)x * (ull)y.x % mod;
    return *this;
  }
  constexpr ModInt &operator/=(const ModInt &y) { return *this *= y.inv(); }
  constexpr ModInt operator+() const { return *this; }
  constexpr ModInt operator-() const { return ModInt(mod - x); }

  constexpr ModInt pow(ll n) const {
    if (n < 0) {
      return pow(-n).inv();
    }
    ModInt y = *this, r = 1;
    while (n) {
      if (n & 1) {
        r *= y;
      }
      y *= y;
      n >>= 1;
    }
    return r;
  }
  constexpr ModInt inv() const {
    assert(x);
    return pow(mod - 2);
  }

  constexpr friend ModInt operator+(const ModInt &a, const ModInt &b) {
    return ModInt(a) += b;
  }
  constexpr friend ModInt operator-(const ModInt &a, const ModInt &b) {
    return ModInt(a) -= b;
  }
  constexpr friend ModInt operator*(const ModInt &a, const ModInt &b) {
    return ModInt(a) *= b;
  }
  constexpr friend ModInt operator/(const ModInt &a, const ModInt &b) {
    return ModInt(a) /= b;
  }
  constexpr friend bool operator==(const ModInt &a, const ModInt &b) {
    return a.x == b.x;
  }
  constexpr friend bool operator!=(const ModInt &a, const ModInt &b) {
    return a.x != b.x;
  }

  friend istream &operator>>(istream &is, ModInt &m) {
    ll y;
    is >> y;
    m.set(y);
    return is;
  }
  friend ostream &operator<<(ostream &os, const ModInt &m) {
    os << m.x;
    return os;
  }
};

using mint = ModInt<998244353u>;
using mint17 = ModInt<1000000007u>;

mint factorial(int n) {
  assert(0 <= n);
  static int sz_ini = 100000;
  static int sz = 1;
  static vector<mint> fac(1, 1);
  int sz_new = sz < sz_ini ? sz_ini : n + 1;
  if (sz_new > sz) {
    fac.resize(sz_new);
    for (int i = sz; i < sz_new; i++) {
      fac[i] = fac[i - 1] * i;
    }
    sz = sz_new;
  }
  return fac[n];
}

mint factorial_inv(int n) {
  assert(0 <= n);
  static int sz_ini = 100000;
  static int sz = 1;
  static vector<mint> fac_inv(1, 1);
  int sz_new = sz < sz_ini ? sz_ini : n + 1;
  if (sz_new > sz) {
    fac_inv.resize(sz_new);
    for (int i = sz; i < sz_new; i++) {
      fac_inv[i] = fac_inv[i - 1] / i;
    }
    sz = sz_new;
  }
  return fac_inv[n];
}

// combination
mint C(int n, int k) {
  assert(0 <= n);
  assert(0 <= k);
  assert(k <= n);
  return factorial(n) * factorial_inv(k) * factorial_inv(n - k);
}