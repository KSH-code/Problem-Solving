#include <bits/stdc++.h>

void solve(){
  int N; std::cin >> N;
  long long memo[N + 1]; memset(memo, 0, sizeof memo);
  memo[0] = memo[1] = 1;
  for (int i = 2; i <= N; i++) {
    memo[i] = memo[i - 1] + memo[i - 2];
  }
  std::cout << memo[N];
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
