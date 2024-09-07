#pragma once
#include "template/small_template.hpp"

// based on ACL
class DisjointSet {
  // root: -1 * 連結成分サイズ
  // otherwise: parent
  vector<int> ps;
  int num_groups;

public:
  DisjointSet(int n): ps(n, -1), num_groups(n) {}

  // a と b を結合する
  int unite(int a, int b) {
    int x = root(a), y = root(b);
    if (x == y) {
      return x;
    }
    if (-ps[x] < -ps[y]) {
      swap(x, y);
    }
    ps[x] += ps[y];
    ps[y] = x;
    num_groups--;
    return x;
  }

  // a と b が同じ木に属するか
  bool same(int a, int b) { return root(a) == root(b); }

  // a が属する木の根
  int root(int a) {
    if (ps[a] < 0) {
      return a;
    }
    return ps[a] = root(ps[a]);
  }

  // a が属する木のサイズ
  int size(int a) { return -ps[root(a)]; }

  // 森の木の数
  int getNum() { return num_groups; }
};