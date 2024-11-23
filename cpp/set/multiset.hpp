#pragma once
#include "random/xorshift.hpp"
#include "template/small_template.hpp"

/**
 * @brief 重複ありの集合
 * 挿入 O(log n)
 * 削除 O(log n)
 * 検索 O(log n)
 * 実装：Treap https://xuzijian629.hatenablog.com/entry/2018/12/08/000452
 * @tparam T 要素の型
 */
template <typename T = ll> class TreeMultiSet {
  static inline Xor64 rnd = Xor64(192865741288375612ull);
  struct Node {
    T k;
    size_t c = 1;  // 個数
    size_t cr = 1; // 部分木を合わせた個数
    ull p = rnd.get();
    Node *l = nullptr, *r = nullptr;
    Node(T key) : k(key) {}
  };
  friend ostream &operator<<(ostream &os, const Node &t) {
    os << "[" << &t << "](k=" << t.k << ", p=" << t.p << ", c=" << t.c
       << ", cr=" << t.cr << ", l=" << t.l << ", r=" << t.r << ")";
    return os;
  }
  using Tree = Node *;
  Tree root = nullptr;
  size_t n_ = 0;

  void update_cr(Tree t) {
    if (t) {
      t->cr = t->c;
      if (t->l) {
        t->cr += t->l->cr;
      }
      if (t->r) {
        t->cr += t->r->cr;
      }
    }
  }

  void split(Tree t, T key, Tree &l, Tree &r) {
    if (!t) {
      l = r = nullptr;
    } else if (key < t->k) {
      split(t->l, key, l, t->l);
      r = t;
    } else {
      split(t->r, key, t->r, r);
      l = t;
    }
    update_cr(t);
  }

  void merge(Tree &t, Tree l, Tree r) {
    if (!l || !r) {
      t = l ? l : r;
    } else if (l->p > r->p) {
      merge(l->r, l->r, r);
      t = l;
    } else {
      merge(r->l, l, r->l);
      t = r;
    }
    update_cr(t);
  }

  void insert(Tree &t, Tree item) {
    if (!t) {
      t = item;
    } else if (item->p > t->p) {
      split(t, item->k, item->l, item->r);
      t = item;
    } else {
      insert(item->k < t->k ? t->l : t->r, item);
    }
    update_cr(t);
  }

  void remove(Tree &t, T key) {
    if (t->k == key) {
      merge(t, t->l, t->r);
    } else {
      remove(key < t->k ? t->l : t->r, key);
    }
    update_cr(t);
  }

  // AOJ
  void aoj_dump(Tree &t, T l, T r) {
    if (t->l && t->k > l) {
      aoj_dump(t->l, l, r);
    }
    if (l <= t->k && t->k <= r) {
      for (size_t i = 0; i < t->c; i++) {
        cout << t->k << '\n';
      }
    }
    if (t->r && t->k < r) {
      aoj_dump(t->r, l, r);
    }
  }

  void print(Tree t) {
    if (t) {
      cout << (*t) << "\n";
      if (t->l) {
        print(t->l);
      }
      if (t->r) {
        print(t->r);
      }
    }
  }

  // 検証
  void verify(Tree t, size_t &n_v) {
    if (t) {
      n_v += t->c;
      size_t cr = t->c;
      if (t->l) {
        cr += t->l->cr;
      }
      if (t->r) {
        cr += t->r->cr;
      }
      if (cr != t->cr) {
        print(root);
        cout.flush();
        assert(false);
      }
      if (t->l) {
        verify(t->l, n_v);
      }
      if (t->r) {
        verify(t->r, n_v);
      }
    }
  }

  T find_by_order(Tree t, size_t k) {
    assert(t);
    size_t sz_l = t->l ? t->l->cr : 0;
    if (k < sz_l) {
      return find_by_order(t->l, k);
    } else if (k < sz_l + t->c) {
      return t->k;
    } else {
      return find_by_order(t->r, k - sz_l - t->c);
    }
  }

  void enumerate_in(vector<pair<T, size_t>> &v, Tree t, const T &l,
                    const T &r) {
    if (t->l && l < t->k) {
      enumerate_in(v, t->l, l, r);
    }
    if (l <= t->k && t->k < r) {
      v.emplace_back(t->k, t->c);
    }
    if (t->r && t->k < r - 1) {
      enumerate_in(v, t->r, l, r);
    }
  }

  void enumerate_all_in(vector<pair<T, size_t>> &v, Tree t) {
    if (t->l) {
      enumerate_all_in(v, t->l);
    }
    v.emplace_back(t->k, t->c);
    if (t->r) {
      enumerate_all_in(v, t->r);
    }
  }

public:
  TreeMultiSet() = default;

  /**
   * @brief 要素のn個追加
   *
   * @param key
   * @return size_t 追加後の同じ要素の数
   */
  size_t add(T key, size_t n = 1) {
    n_ += n;
    Tree t = root;
    bool found = false;
    while (t) {
      if (key == t->k) {
        found = true;
        break;
      }
      t = key < t->k ? t->l : t->r;
    }
    if (found) {
      t = root;
      while (t) {
        t->cr += n;
        if (key == t->k) {
          t->c += n;
          return t->c;
        }
        t = key < t->k ? t->l : t->r;
      }
    }
    insert(root, new Node(key));
    return n;
  }

  /**
   * @brief 指定した要素のn個削除
   * 要素がn個を下回る場合は何もしない
   *
   * @param key
   * @return bool 削除出来た場合true
   */
  bool remove(T key, size_t n = 1) {
    Tree t = root;
    bool found = false;
    while (t) {
      if (key == t->k) {
        if (t->c == n) {
          n_ -= n;
          remove(root, key);
        } else if (t->c > n) {
          n_ -= n;
          t->c -= n;
          t->cr -= n;
          found = true;
          break;
        } else {
          return false;
        }
        return true;
      }
      t = key < t->k ? t->l : t->r;
    }
    if (found) {
      t = root;
      while (t) {
        t->cr -= n;
        if (key == t->k) {
          t->c -= n;
          return true;
        }
        t = key < t->k ? t->l : t->r;
      }
    }
    return false;
  }

  /**
   * @brief 指定した要素の全削除
   *
   * @param key
   * @return size_t 削除した要素数
   */
  size_t remove_all(T key) {
    Tree t = root;
    while (t) {
      if (key == t->k) {
        size_t ret = t->c;
        n_ -= ret;
        remove(root, key);
        return ret;
      }
      t = key < t->k ? t->l : t->r;
    }
    return 0;
  }

  // 検索 個数を返す O(log n)
  size_t count(T key) {
    Tree t = root;
    while (t) {
      if (key == t->k) {
        return t->c;
      }
      t = key < t->k ? t->l : t->r;
    }
    return 0;
  }

  // 検索 ない場合、検索値より小さい中で最大の要素または無効値
  optional<T> find_lower(T key) {
    Tree t = root;
    Tree lower = nullptr;

    while (t) {
      if (key == t->k) {
        return key;
      } else if (key < t->k) {
        t = t->l;
      } else {
        lower = t;
        t = t->r;
      }
    }
    return lower ? optional(lower->k) : nullopt;
  }

  // 検索 ない場合、検索値より大きい中で最小の要素または無効値
  optional<T> find_upper(T key) {
    Tree t = root;
    Tree upper = nullptr;
    while (t) {
      if (key == t->k) {
        return key;
      } else if (key < t->k) {
        upper = t;
        t = t->l;
      } else {
        t = t->r;
      }
    }
    return upper ? optional(upper->k) : nullopt;
  }

  // 検索 順位(0-indexed)の区間を返す O(log n)
  // 存在しない場合、-1,-1
  pair<int, int> rank(T key) {
    Tree t = root;
    int rnk = 0;
    while (t) {
      if (key == t->k) {
        rnk += t->l ? t->l->cr : 0;
        return {rnk, rnk + t->c};
      } else if (key < t->k) {
        t = t->l;
      } else {
        rnk += t->c;
        rnk += t->l ? t->l->cr : 0;
        t = t->r;
      }
    }
    return {-1, -1};
  }

  T min() {
    Tree t = root;
    while (t->l) {
      t = t->l;
    }
    return t->k;
  }

  T max() {
    Tree t = root;
    while (t->r) {
      t = t->r;
    }
    return t->k;
  }

  // K番目の要素(0-indexed)
  T get_kth(size_t k) {
    assert(k < n_);
    return find_by_order(root, k);
  }

  // l <= k < r を満たす要素の列挙
  vector<pair<T, size_t>> enumerate(const T &l, const T &r) {
    vector<pair<T, size_t>> ret;
    if (root) {
      enumerate_in(ret, root, l, r);
    }
    return ret;
  }

  // 全要素の列挙
  vector<pair<T, size_t>> enumerate_all() {
    vector<pair<T, size_t>> ret;
    if (root) {
      enumerate_all_in(ret, root);
    }
    return ret;
  }

  // AOJ
  void aoj_dump(const T &l, const T &r) {
    if (root) {
      aoj_dump(root, l, r);
    }
  }

  size_t size() { return n_; }

  void verify() {
    if (root) {
      // 総数がn_に一致
      size_t n_v = 0;
      verify(root, n_v);
      assert(n_ == n_v);
    }
  }
};