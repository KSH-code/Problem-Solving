#include <iostream>
#include <queue>
#include <string>
using namespace std;

int xxxx[] = {-1, 0, 1, 0};
int yyyy[] = {0, 1, 0, -1};

void solve(){
  int N, M; cin >> N >> M;

  bool lighted[N+1][N+1];
  for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) lighted[i][j] = false;

  vector<vector<int>> edges(101001);
  for (int i = 0; i < M; i++) {
    int x,y,xx,yy; cin >> x >> y >> xx >> yy;
    edges[x * 1000 + y].push_back(xx * 1000 + yy);
  }

  int count = 1;
  lighted[1][1] = true;
  while (1) {
    queue<pair<int, int>> q;
    bool visited[N+1][N+1];
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) visited[i][j] = false;
    visited[1][1] = true;
    q.push({1,1});
    int c=0;
    while (q.size()) {
      auto [x,y] = q.front(); q.pop();

      if (lighted[x][y]) {
        for (auto temp : edges[x * 1000 + y]) {
          int next_x = temp / 1000;
          int next_y = temp % 1000;
          if (lighted[next_x][next_y]) continue;

          lighted[next_x][next_y] = true;
          c++;
        }
        edges[x * 1000 + y].clear();
      }

      for (int i = 0; i < 4; i++) {
        int next_x = x + xxxx[i];
        int next_y = y + yyyy[i];
        if (next_x < 1 || next_x > N || next_y < 1 || next_y > N) continue;
        if (!lighted[x][y] || visited[next_x][next_y]) continue;

        visited[next_x][next_y] = true;
        q.push({next_x,next_y});
      }
    }

    if (!c) break;

    count += c;
  }

  cout << count;
}

int main(){
  cin.tie(0) -> sync_with_stdio(false);
  solve();
  return 0;
}
