#include <bits/stdc++.h>

long long memo[31][31][31];

int N,M,K;
long long dfs(int x, int m, int k) {
  if (k > K) return 0;
  if (x == N) return 1;

  auto &ref = memo[x][m][k];
  if (ref != -1) return ref;

  ref = dfs(x+1, m, k+1);
  for (int i = m+1; i <= M; i++) {
    ref += dfs(x+1, i, 1);
  }
  return ref;
}

void solve(){
  std::cin >> N >> M >> K;
  memset(memo, -1, sizeof memo);
  long long result = 0;
  for (int i = 1; i <= M; i++) {
    result += dfs(1, i, 1);
  }
  std::cout << result;
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
