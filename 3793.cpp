#include <bits/stdc++.h>

void solve(std::string X){
  std::string Y; std::cin >> Y;
  int N = Y.size(), M = X.size();
  int memo[M][N]; std::memset(memo, 0, sizeof memo);
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (X[i] == Y[j]) {
        if (i && j) memo[i][j] = memo[i-1][j-1];
        memo[i][j]++;
      } else {
        if (i) memo[i][j] = std::max(memo[i][j], memo[i-1][j]);
        if (j) memo[i][j] = std::max(memo[i][j], memo[i][j-1]);
      }
    }
  }
  std::cout << memo[M-1][N-1];
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  std::string X;
  while(std::cin>>X) {
    solve(X);
    std::cout << '\n';
  }
  return 0;
}
