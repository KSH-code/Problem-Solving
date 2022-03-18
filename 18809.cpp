#include <iostream>
#include <queue>
using namespace std;

int map[51][51];
int N, M, G, R;

pair<int,int> positions[99];
int positions_count = 0;

const int GREEN = 3, RED = 4, FLOWER = 5;
int colors[99];

int xxxx[] = {-1, 0, 1, 0};
int yyyy[] = {0, 1, 0, -1};

int count(){
  pair<int,int> current_map[N][M];
  for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) current_map[i][j] = {map[i][j],123456};

  queue<pair<int,int>> q;
  for (int i = 0; i < positions_count; i++){
    if (!colors[i]) continue;

    int color = colors[i];
    q.push({positions[i].first, positions[i].second});
    current_map[positions[i].first][positions[i].second] = {color,0};
  }

  int result = 0;
  while (q.size()) {
    auto [x, y] = q.front(); q.pop();
    auto [state, count] = current_map[x][y];
    if (state != GREEN && state != RED) continue;

    int oc = state == GREEN ? RED : GREEN;
    for (int i = 0; i < 4; i++) {
      int nx = x + xxxx[i];
      int ny = y + yyyy[i];
      int nc = count + 1;

      if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

      if (current_map[nx][ny].second == nc && current_map[nx][ny].first == oc) {
        current_map[nx][ny] = {FLOWER, 0};
        result++;
        continue;
      }

      if (current_map[nx][ny].first == 0 || current_map[nx][ny].second <= nc) continue;

      current_map[nx][ny] = {state,nc};
      q.push({nx, ny});
    }
  }

  return result;
}

int dfs(int x, int g, int r){
  if (g + r == 0) return count();
  if (x == positions_count) return 0;

  int result = 0;
  for (int i = x; i < positions_count; i++){
    if (g) {
      colors[i] = GREEN;
      result = max(result, dfs(i + 1, g - 1, r));
      colors[i] = 0;
    }

    if (r) {
      colors[i] = RED;
      result = max(result, dfs(i + 1, g, r - 1));
      colors[i] = 0;
    }
  }

  return result;
}

int main(){
  cin.tie(0) -> sync_with_stdio(false);

  cin >> N >> M >> G >> R;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      cin >> map[i][j];
      if (map[i][j] == 2) {
        positions[positions_count++] = {i, j};
      }
    }

  cout << dfs(0, G, R);
  return 0;
}
