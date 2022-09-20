#include <bits/stdc++.h>

struct Node {
  int x1, y1, d1;
  int x2, y2, d2;
  int count;
};

void solve(){
  int N; std::cin >> N;
  std::string maps[N]; for (auto &a : maps) std::cin >> a;
  bool visited[N][N][N][N][4][4]; memset(visited, 0, sizeof visited);
  std::queue<Node> q; q.push({N-1,0,0,N-1,0,1,0});
  int xxxx[] = {-1, 0, 1, 0};
  int yyyy[] = {0, 1, 0, -1};
  while (q.size()) {
    auto [x1, y1, d1, x2, y2, d2, c] = q.front(); q.pop();
    int nx1 = x1;
    int ny1 = y1;
    int nd1 = d1;
    int nx2 = x2;
    int ny2 = y2;
    int nd2 = d2;
    for (int i = -1; i <= 1; i+=2) {
      int nd1 = d1 + i; if (nd1 == -1) nd1 = 3; if (nd1 == 4) nd1 = 0;
      int nd2 = d2 + i; if (nd2 == -1) nd2 = 3; if (nd2 == 4) nd2 = 0;
      if (visited[nx1][ny1][nx2][ny2][nd1][nd2]) continue;
      visited[nx1][ny1][nx2][ny2][nd1][nd2] = true;
      q.push({nx1,ny1,nd1,nx2,ny2,nd2,c+1});
    }
    if (!(nx1 == 0 && ny1 == N-1)) {
      nx1 = nx1 + xxxx[nd1];
      ny1 = ny1 + yyyy[nd1];
      if (nx1 < 0 || ny1 < 0 || nx1 >= N || ny1 >= N || maps[nx1][ny1] == 'H') {
        nx1 -= xxxx[nd1];
        ny1 -= yyyy[nd1];
      }
    }
    if (!(nx2 == 0 && ny2 == N-1)) {
      nx2 = nx2 + xxxx[nd2];
      ny2 = ny2 + yyyy[nd2];
      if (nx2 < 0 || ny2 < 0 || nx2 >= N || ny2 >= N || maps[nx2][ny2] == 'H') {
        nx2 -= xxxx[nd2];
        ny2 -= yyyy[nd2];
      }
    }
    if (visited[nx1][ny1][nx2][ny2][nd1][nd2]) continue;
    if (nx1 == 0 && nx2 == 0 && ny1 == N-1 && ny2 == N-1) {
      std::cout << c+1;
      return;
    }
    visited[nx1][ny1][nx2][ny2][nd1][nd2] = true;
    q.push({nx1,ny1,nd1,nx2,ny2,nd2,c+1});
  }
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
