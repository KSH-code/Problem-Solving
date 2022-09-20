#include <bits/stdc++.h>

void solve(){
  int N, M; std::cin >> N >> M;

  std::multiset<int> A;
  std::multiset<int> B;
  for (int i = 0; i < N; i++) {
    int a; std::cin >> a;
    A.insert(a);
  }
  for (int i = 0; i < M; i++) {
    int b; std::cin >> b;
    B.insert(b);
  }

  long long result = 0;
  if (A.size() < B.size()) std::swap(A, B);
  assert(A.size() >= B.size());
  for (auto b : B) {
    auto it = A.upper_bound(b);
    if (A.end() == it) --it;
    if (it != A.begin() && std::abs(*it - b) >= std::abs(*std::prev(it) - b)) --it;
    result += std::abs(*it - b);
    A.erase(it);
  }
  std::cout << result;
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
