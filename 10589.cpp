#include <bits/stdc++.h>

void solve(){
  int N, M; std::cin >> N >> M;
  std::cout << N/2+M/2 << '\n';
  for (int i = 2; i <= M; i += 2) std::cout << 1 << ' ' << i << ' ' << N << ' ' << i << ' ' << '\n';
  for (int i = 2; i <= N; i += 2) std::cout << i << ' ' << 1 << ' ' << i << ' ' << M << ' ' << '\n';
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
