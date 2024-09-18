#pragma once
#include "template/small_template.hpp"
#include "random/xorshift.hpp"

/**
 * @brief 重複ありの集合
 * 挿入 O(log n)
 * 削除 O(log n)
 * 検索 O(log n)
 * 実装：Treap https://xuzijian629.hatenablog.com/entry/2018/12/08/000452
 * @tparam T 要素の型
 */
template<typename T = ll>
class TreeMultiSet {
  static inline Xor64 rnd = Xor64(192865741288375612ull);
  struct Node {
    T k;
    int c = 1;
    ull p = rnd.get();
    Node *l = nullptr, *r = nullptr;
    Node(T key): k(key) {}
  };
  using Tree = Node *;
  Tree root = nullptr;
  int n = 0;

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
  }

  void remove(Tree &t, T key) {
    if (t->k == key) {
      merge(t, t->l, t->r);
    } else {
      remove(key < t->k ? t->l : t->r, key);
    }
  }

  // AOJ
  void dump(Tree &t, int l, int r) {
    if (t->l && t->k > l) {
      dump(t->l, l, r);
    }
    if (l <= t->k && t->k <= r) {
      for (int i = 0; i < t->c; i++) {
        cout << t->k << '\n';
      }
    }
    if (t->r && t->k < r) {
      dump(t->r, l, r);
    }
  }

public:
  TreeMultiSet() = default;

  /**
   * @brief 要素の追加
   * 
   * @param key 
   * @return int 追加後の同じ要素の数
   */
  int add(T key) {
    n++;
    Tree t = root;
    while (t) {
      if (key == t->k) {
        t->c++;
        return t->c;
      }
      t = key < t->k ? t->l : t->r;
    }
    insert(root, new Node(key));
    return 1;
  }

  /**
   * @brief 指定した要素の1個削除
   * 
   * @param key 
   * @return bool 削除出来た場合true
   */
  bool remove(T key) {
    Tree t = root;
    while (t) {
      if (key == t->k) {
        if (t->c > 1) {
          t->c--;
        } else {
          remove(root, key);
        }
        n--;
        return true;
      }
      t = key < t->k ? t->l : t->r;
    }
    return false;
  }

  /**
   * @brief 指定した要素の全削除
   * 
   * @param key 
   * @return int 削除した要素数
   */
  int removeAll(T key) {
    Tree t = root;
    while (t) {
      if (key == t->k) {
        int ret = t->c;
        n -= ret;
        remove(root, key);
        return ret;
      }
      t = key < t->k ? t->l : t->r;
    }
    return 0;
  }

  int count(T key) {
    Tree t = root;
    while (t) {
      if (key == t->k) {
        return t->c;
      }
      t = key < t->k ? t->l : t->r;
    }
    return 0;
  }

  T min() {
    Tree t = root;
    while (t->l) {
      t = t->l;
    }
    return t->k;
  }

  // AOJ
  void dump(int l, int r) {
    if (root) {
      dump(root, l, r);
    }
  }

  int size() { return n; }
};
