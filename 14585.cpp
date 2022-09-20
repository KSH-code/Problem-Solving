#include <bits/stdc++.h>

void solve(){
  int N, M; std::cin >> N >> M;
  int arr[301][301]; memset(arr, 0, sizeof arr);
  for (int i = 0; i < N; i++) {
    int a,b; std::cin >> a >> b;
    arr[a][b] = M;
  }
  int result = 0;
  int memo[301][301]; memset(memo, 0, sizeof memo);

  for (int i = 0; i <= 300; i++) {
    for (int j = 0; j <= 300; j++) {
      if (i) memo[i][j] = std::max(memo[i][j], memo[i-1][j]);
      if (j) memo[i][j] = std::max(memo[i][j], memo[i][j-1]);
      if (arr[i][j]) memo[i][j] += arr[i][j] - (i + j);
      result = std::max(result, memo[i][j]);
    }
  }
  std::cout << result;
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
