#define PROBLEM "https://yukicoder.me/problems/no/3030"
#include "number_theory/is_prime.hpp"

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  while (n--) {
    ull x;
    cin >> x;
    cout << x << ' ' << is_prime(x) << '\n';
  }
}