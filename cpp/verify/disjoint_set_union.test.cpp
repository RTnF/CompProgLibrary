#define PROBLEM                                                                \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"
#include "set/disjoint_set_union.hpp"

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  auto ds = DisjointSetUnion(n);

  for (int i = 0; i < q; i++) {
    int com, x, y;
    cin >> com >> x >> y;

    if (com == 0) {
      ds.unite(x, y);
    } else {
      cout << (ds.same(x, y) ? 1 : 0) << endl;
    }
  }
}