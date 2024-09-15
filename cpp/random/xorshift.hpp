#pragma once
#include "template/small_template.hpp"

template<typename T>
struct IRandom {
  virtual T next() = 0;
};

struct Xor64: IRandom<ull> {
  ull a = 0xAF180B8D7E239CC1;
  ull next() {
    ull x = a;
    x ^= x << 3;
    x ^= x >> 35;
    x ^= x << 14;
    return a = x;
  }
};