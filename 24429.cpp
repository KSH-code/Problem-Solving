#include <bits/stdc++.h>

void solve(){
  int N; std::cin >> N;
  int arr[N+1][N+1];
  for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) std::cin >> arr[i][j];

  int q;std::cin >> q; q++;
  std::pair<int,int> check[q];
  for (int i = 0; i < q - 1; i++) std::cin >> check[i].first >> check[i].second;
  check[q-1] = {N,N};
  std::sort(check, check + q);

  int memo[N+1][N+1];
  int sx = 1, sy = 1;
  int result = arr[1][1];
  for (int i = 0; i < q; i++) {
    auto [ex, ey] = check[i];
    if (sx > ex || sy > ey) {
      std::cout << -1;
      return;
    }
    memo[sx][sy] = 0;
    for (int x = sx; x <= ex; x++) {
      for (int y = sy; y <= ey; y++) {
        if (x != sx || y != sy) memo[x][y] = 0;
        if (y-1 >= sy) memo[x][y] = std::max(memo[x][y], arr[x][y] + memo[x][y-1]);
        if (x-1 >= sx) memo[x][y] = std::max(memo[x][y], arr[x][y] + memo[x-1][y]);
      }
    }
    result += memo[ex][ey];
    sx = ex, sy = ey;
  }
  std::cout << result;
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
