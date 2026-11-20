#pragma once
#include "template/small_template.hpp"

// 個数
template<class T>
vector<pair<typename T::value_type, int>> element_count(const T &v) {
  vector<pair<typename T::value_type, int>> ret;
  int n = v.size();
  if (n == 0) {
    return ret;
  }
  T pre = v[0];
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (pre == v[i]) {
      cnt++;
    } else {
      ret.emplace_back(pre, cnt);
      pre = v[i];
      cnt = 1;
    }
  }
  ret.emplace_back(pre, cnt);
  return ret;
}