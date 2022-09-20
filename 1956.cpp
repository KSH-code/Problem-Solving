#include <bits/stdc++.h>

void solve(){
  int N, M; std::cin >> N >> M;
  int t[N+1]; memset(t, -1, sizeof t);
  int dis[N+1][N+1]; memset(dis, -1, sizeof dis);
  while (M--) {
    int a,b,c; std::cin >> a >> b >> c;
    auto &ref = dis[a][b];
    if (ref == -1) ref = c;
    ref = std::min(c, ref);
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (int k = 1; k <= N; k++) {
        if (dis[j][i] > -1 && dis[i][k] > -1) {
          if (dis[j][k] == -1) dis[j][k] = dis[j][i] + dis[i][k];
          dis[j][k] = std::min(dis[j][k], dis[j][i] + dis[i][k]);
        }
      }
    }
  }
  int result = -1;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i != j && dis[i][j] > -1 && dis[j][i] > -1) {
        if (result == -1) result = dis[i][j] + dis[j][i];
        result = std::min(result, dis[i][j] + dis[j][i]);
      }
    }
  }
  std::cout << result;
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
