#include <bits/stdc++.h>

void solve(){
  int N,A,B; std::cin >> N >> A >> B;
  int map[N][N]; memset(map, 0, sizeof map);
  map[0][0] = 1; A--;
  std::queue<std::pair<int,int>> q;
  q.push({0,0});
  int xxxx[] = {0,-1,0,1};
  int yyyy[] = {-1,0,1,0};
  while (q.size()) {
    auto [x,y] = q.front(); q.pop();
    for (int k = 0; k < 4; k++) {
      int nx = x + xxxx[k];
      int ny = y + yyyy[k];
      if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
      if (!A || map[nx][ny]) continue;

      map[nx][ny] = 1;
      q.push({nx,ny});
      A--;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      bool found = true;
      for (int k = 0; k < 4; k++) {
        int x = i + xxxx[k];
        int y = j + yyyy[k];
        if (x < 0 || y < 0 || x >= N || y >= N) {}
        else if (!B || map[x][y] == 1 || map[i][j]) found = false;
      }
      if (found && q.empty()) {
        q.push({i,j});
        map[i][j] = 2;
        B--;
      }
    }
  }
  while (q.size()) {
    auto [x,y] = q.front(); q.pop();
    for (int k = 0; k < 4; k++) {
      int nx = x + xxxx[k];
      int ny = y + yyyy[k];
      if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
      if (!B || map[nx][ny]) continue;

      bool found = true;
      for (int i = 0; i < 4; i++) {
        int x = nx + xxxx[i];
        int y = ny + yyyy[i];
        if (x < 0 || y < 0 || x >= N || y >= N) {}
        else if (map[x][y] == 1) found = false;
      }
      if (found) {
        map[nx][ny] = 2;
        q.push({nx,ny});
        B--;
      }
    }
  }
  if (A || B) std::cout << -1;
  else {
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
