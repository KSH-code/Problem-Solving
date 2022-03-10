#include <iostream>
#include <queue>
#include <string>
using namespace std;

int xxxx[] = {-1, 0, 1, 0};
int yyyy[] = {0, 1, 0, -1};

bool visited[2000][2000];

void solve(){
  int N, M; cin >> N >> M;
  int start_x, start_y;
  string map[N]; for (int i = 0; i < N; i++) cin >> map[i];

  queue<pair<int, int>> q;
  queue<pair<int, int>> result_q;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (map[i][j] != 'X') q.push({i, j});
      if (map[i][j] == 'L') start_x = i, start_y = j;
    }
  }
  visited[start_x][start_y] = true;
  result_q.push({start_x, start_y});

  int ans = 1;
  while (1) {
    queue<pair<int, int>> temp_q;
    queue<pair<int, int>> temp_result;

    while (q.size()) {
      auto [x, y] = q.front(); q.pop();

      for (int i = 0; i < 4; i++) {
        int next_x = x + xxxx[i];
        int next_y = y + yyyy[i];
        if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M || map[next_x][next_y] != 'X') continue;

        map[next_x][next_y] = '.';
        temp_q.push({next_x, next_y});
      }
    }

    while (result_q.size()) {
      auto [x, y] = result_q.front(); result_q.pop();

      for (int i = 0; i < 4; i++) {
        int next_x = x + xxxx[i];
        int next_y = y + yyyy[i];
        if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M || visited[next_x][next_y]) continue;

        visited[next_x][next_y] = true;
        if (map[next_x][next_y] == '.') {
          result_q.push({next_x, next_y});
        } else if (map[next_x][next_y] == 'L') {
          cout << ans;
          return;
        } else {
          temp_result.push({next_x, next_y});
        }
      }
    }

    q = temp_q;
    result_q = temp_result;
    ans++;
  }
}

int main(){
  cin.tie(0) -> sync_with_stdio(false);
  solve();
  return 0;
}
