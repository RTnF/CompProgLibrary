#pragma once
#include "template/small_template.hpp"

template<typename T>
int count(vector<T> v, T value, int idx_begin = 0, int idx_end = -1) {
  if (idx_end == -1) {
    idx_end = v.size();
  }
  int cnt = 0;
  for (int i = idx_begin; i < idx_end; i++) {
    if (v[i] == value) {
      cnt++;
    }
  }
  return cnt;
}