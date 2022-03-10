#include <iostream>
#include <queue>
#include <string>
using namespace std;

int xxxx[] = {-1, 0, 1, 0};
int yyyy[] = {0, 1, 0, -1};

struct Node {
  int x, y, count;
};

void solve(){
  int N, M, P; cin >> N >> M >> P;

  int counts[100];
  for (int i = 1; i <= P; i++) cin >> counts[i];

  string map[N]; for (int i = 0; i < N; i++) cin >> map[i];


  bool visited[N][M]; for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) visited[i][j] = false;
  while (1) {
    bool changed = false;
    for (int p = 1; p <= P; p++) {
      queue<Node> q;
      for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        if (!visited[i][j] && map[i][j] == p + '0') {
          q.push({i, j, 0});
          visited[i][j] = true;
        }
      }

      while (q.size()) {
        auto [x, y, count] = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
          int next_x = x + xxxx[i];
          int next_y = y + yyyy[i];
          int next_count = count + 1;
          if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M || map[next_x][next_y] != '.' || counts[p] < next_count) continue;
          map[next_x][next_y] = map[x][y];
          changed = true;
          q.push({next_x, next_y, next_count});
        }
      }
    }

    if (!changed) break;
  }

  int results[10] = {0};
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (map[i][j] >= '1' && map[i][j] <= '9') results[map[i][j]-'0']++;
    }
  }

  for (int i = 1; i <= P; i++) cout << results[i] << ' ';
}

int main(){
  cin.tie(0) -> sync_with_stdio(false);
  solve();
  return 0;
}
