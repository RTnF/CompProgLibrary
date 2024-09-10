#pragma once
#include "template/small_template.hpp"

// Treap
template<typename T = ll>
class TreapSet {
  struct Xor64 {
    ull a = 0xAF180B8D7E239CC1;
    ull next() {
      ull x = a;
      x ^= x << 3;
      x ^= x >> 35;
      x ^= x << 14;
      return a = x;
    }
  };
  static inline Xor64 rnd;
  struct Node {
    T key;
    int c = 1;
    ull priority = rnd.next();
    Node *l = nullptr, *r = nullptr;
    Node(T val): key(val) {}
  };
  using Tree = Node *;
  Tree root = nullptr;

  void split(Tree t, T key, Tree &l, Tree &r) {
    if (!t) {
      l = r = nullptr;
    } else if (key < t->key) {
      split(t->l, key, l, t->l), r = t;
    } else {
      split(t->r, key, t->r, r), l = t;
    }
  }

  void merge(Tree &t, Tree l, Tree r) {
    if (!l || !r) {
      t = l ? l : r;
    } else if (l->priority > r->priority) {
      merge(l->r, l->r, r), t = l;
    } else {
      merge(r->l, l, r->l), t = r;
    }
  }

  void insert(Tree &t, Tree item) {
    if (!t) {
      t = item;
    } else if (item->priority > t->priority) {
      split(t, item->key, item->l, item->r), t = item;
    } else {
      insert(item->key < t->key ? t->l : t->r, item);
    }
  }

  void erase(Tree &t, T key) {
    if (t->key == key) {
      merge(t, t->l, t->r);
    } else {
      erase(key < t->key ? t->l : t->r, key);
    }
  }

  bool find(Tree &t, T key) {
    if (!t) {
      return false;
    } else if (t->key == key) {
      return true;
    } else {
      return find(key < t->key ? t->l : t->r, key);
    }
  }

public:
  TreapSet() = default;
  void add(T key) { insert(root, new Node(key)); }
  void remove(T key) { erase(root, key); }
  bool count(T key) { return count(root, key); }
  T min() {
    Tree t = root;
    while (t->l) {
      t = t->l;
    }
    return t->key;
  }
};