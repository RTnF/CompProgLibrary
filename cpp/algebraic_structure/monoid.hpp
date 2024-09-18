#pragma once
#include "template/small_template.hpp"

template<class T = ll>
struct MonoidMul {
  T x;
  MonoidMul(T x_): x(x_) {}
  MonoidMul(): MonoidMul(e()) {}
  static MonoidMul e() { return 1; }
  friend MonoidMul op(const MonoidMul &a, const MonoidMul &b) {
    return a.x * b.x;
  }
};
