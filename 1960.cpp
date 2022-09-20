#include <bits/stdc++.h>

void solve(){
  int N; std::cin >> N;
  int row[N]; for (auto &a : row) std::cin >> a;
  int col[N]; for (auto &a : col) std::cin >> a;
  bool map[N][N]; memset(map, 0, sizeof map);
  for (int i = 0; i < N; i++) {
    bool visited[N]; memset(visited, 0, sizeof visited);
    while (row[i]) {
      int m = 0;
      int idx = 0;
      for (int j = 0; j < N; j++) {
        if (!visited[j] && m < col[j]) {
          m = col[j];
          idx = j;
        }
      }
      if (m) {
        row[i]--;
        col[idx]--;
        map[i][idx] = 1;
        visited[idx] = true;
      } else {
        std::cout << -1;
        return;
      }
    }
  }
  if (*std::max_element(col, col+N)) {
    std::cout << -1;
  } else {
    std::cout << 1 << '\n';
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        std::cout << map[i][j];
      }
      std::cout << '\n';
    }
  }
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
