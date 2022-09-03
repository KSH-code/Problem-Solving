#include <bits/stdc++.h>

void solve() {
  int N, K;
  std::cin >> N >> K;
  for (int i = 1; i <= N - K; i++) {
    std::cout << i-1 << ' ' << i << '\n';
  }
  for (int i = N - K + 1; i < N; i++) {
    std::cout << 0 << ' ' << i << '\n';
  }
}

int main(){
  solve();
  return 0;
}
