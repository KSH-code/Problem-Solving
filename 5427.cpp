#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node {
  int x, y, count;
};

void solve(){
  int N, M; cin >> M >> N;
  string map[N]; for (int i = 0; i < N; i++) cin >> map[i];

  int start_x = -1, start_y = -1;

  int visited[1001][1001] = {0};
  int fires[1001][1001];

  for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) fires[i][j] = visited[i][j] = 1e10;

  queue<Node> queue;
  for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
    if (map[i][j] == '@') start_x = i, start_y = j;
    else if (map[i][j] == '*') {
      queue.push({i, j, 0});
      fires[i][j] = 0;
    }

  while (queue.size()) {
    auto [x, y, count] = queue.front();

    queue.pop();

    int xxxx[] = {-1, 0, 1, 0};
    int yyyy[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
      int next_x = x + xxxx[i];
      int next_y = y + yyyy[i];
      int next_count = count + 1;
      if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M || fires[next_x][next_y] <= next_count || map[next_x][next_y] == '#') continue;

      fires[next_x][next_y] = next_count;
      queue.push({next_x, next_y, next_count});
    }
  }
  visited[start_x][start_y] = 0;
  queue.push({start_x, start_y, 0});

  while (queue.size()) {
    auto [x, y, count] = queue.front();
    queue.pop();

    if (fires[x][y] <= count) continue;

    int xxxx[] = {-1, 0, 1, 0};
    int yyyy[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
      int next_x = x + xxxx[i];
      int next_y = y + yyyy[i];
      int next_count = count + 1;
      if (next_x >= N || next_y >= M || next_x < 0 || next_y < 0) {
        cout << next_count << '\n';
        return;
      }
      if (fires[next_x][next_y] <= next_count || visited[next_x][next_y] != 1e10 || map[next_x][next_y] == '#') continue;
      visited[next_x][next_y] = next_count;
      queue.push({next_x, next_y, next_count});
    }
  }

  cout << "IMPOSSIBLE" << '\n';
}

int main(){
  cin.tie(0) -> sync_with_stdio(false);
  int T; cin >> T; while(T--) solve();
  return 0;
}
