#include <iostream>
#include <string>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;

const int N = 5;
string map[N];

int xxxx[] = {-1, 0, 1, 0};
int yyyy[] = {0, 1, 0, -1};

pair<int,int> positions[25];
pair<int,int> selected_positions[7];

bool check() {
  int count = 0;
  for (int i = 0; i < 7; i++) {
    auto [x, y] = selected_positions[i];
    if (map[x][y] == 'S') count++;
  }
  if (count < 4) return false;

  bool visited[7] = {false};
  queue<pair<int,int>> q;
  q.push(selected_positions[0]);
  while (q.size()) {
    auto [x, y] = q.front(); q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + xxxx[i];
      int ny = y + yyyy[i];
      if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
      int index = -1;
      for (int j = 0; j < 7; j++) if (nx == selected_positions[j].first && ny == selected_positions[j].second) index = j;
      if (index == -1 || visited[index]) continue;

      visited[index] = true;
      q.push({nx, ny});
    }
  }
  for (int i = 0; i < 7; i++) if (!visited[i]) return false;

  return true;
}

int solve(int x, int count){
  if (count == 7) return check();

  int result = 0;
  for (int i = x; i < 25; i++) {
    selected_positions[count] = positions[i];
    result += solve(i + 1, count + 1);
  }

  return result;
}

int main (){
  cin.tie(0) -> sync_with_stdio(0);
  for (int i = 0; i < N; i++) cin >> map[i];
  for (int i = 0; i < N; i++)  for (int j = 0; j < N; j++) positions[i * N + j] = {i, j};

  int result = solve(0, 0);

  cout << result;
  return 0;
}
