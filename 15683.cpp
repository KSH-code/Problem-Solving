#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

int xxxx[6][4][4] = {
  {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
  {
    {-1, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0}
  },
  {
    {-1, 0, 1, 0},
    {0, 0, 0, 0},
    {-1, 0, 1, 0},
    {0, 0, 0, 0}
  },
  {
    {-1, 0, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 1, 0},
    {-1, 0, 0, 0}
  },
  {
    {-1, 0, 0, 0},
    {-1, 0, 1, 0},
    {0, 0, 1, 0},
    {-1, 0, 1, 0}
  },
  {
    {-1, 0, 1, 0},
    {-1, 0, 1, 0},
    {-1, 0, 1, 0},
    {-1, 0, 1, 0}
  }
};
int yyyy[6][4][4] = {
  {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
  {
    {0, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, -1}
  },
  {
    {0, 0, 0, 0},
    {0, 1, 0, -1},
    {0, 0, 0, 0},
    {0, 1, 0, -1}
  },
  {
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 0, -1},
    {0, 0, 0, -1}
  },
  {
    {0, 1, 0, -1},
    {0, 1, 0, 0},
    {0, 1, 0, -1},
    {0, 0, 0, -1}
  },
  {
    {0, 1, 0, -1},
    {0, 1, 0, -1},
    {0, 1, 0, -1},
    {0, 1, 0, -1}
  }
};

int N, M;
int map[10][10];
vector<pair<int,int>> cctv;

int dfs(int x, int direction, bool temp_visited[10][10]) {
  if (x == cctv.size()) {
    int result = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (!temp_visited[i][j]) result++;
      }
    }
    return result;
  }

  bool visited[10][10]; for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) visited[i][j] = temp_visited[i][j];

  int result = 9999;
  for (int i = 0; i < 4; i++) {
    auto [nx, ny] = cctv[x];
    int type = map[nx][ny];
    int px = xxxx[type][direction][i];
    int py = yyyy[type][direction][i];
    while (px || py) {
      nx += px;
      ny += py;
      if (nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] == 6) break;
      visited[nx][ny] = 1;
    }
  }
  for (int i = 0; i < 4; i++) {
    result = min(result, dfs(x + 1, i, visited));
  }
  return result;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      cin >> map[i][j];
      if (map[i][j] >= 1 && map[i][j] < 6) cctv.push_back({i, j});
    }
  }

  int result = 9999;
  for (int i = 0; i < 4; i++) {
    bool visited[10][10]; for (int j = 0; j < N; j++) for (int k = 0; k < M; k++) visited[j][k] = map[j][k] != 0;
    result = min(result, dfs(0, i, visited));
  }

  cout << result;
  return 0;
}
