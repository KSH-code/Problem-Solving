#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  int N, M; cin >> N >> M;

  int counts[N+1];

  for (int i = 0; i<=N; i++) counts[i] = 0;

  vector<vector<int>> edges(N+1);
  for (int i = 0; i < M; i++) {
    int s, e; cin >> e >> s;
    edges[s].push_back(e);
  }
  for (int i = 1; i <= N; i++) {
    bool visited[N + 1]; for (int j = 0; j <= N; j++) visited[j] = false;
    visited[i] = true;
    queue<int> q;
    q.push(i);

    while (q.size()) {
      int x = q.front();
      for (int next_x : edges[x]) {
        if (visited[next_x]) continue;
        visited[next_x] = true;
        counts[next_x]++;
        counts[i]++;
        q.push(next_x);
      }
      q.pop();
    }
  }

  int result = 0;
  for (int i = 1; i <= N; i++) {
    if (counts[i] == N - 1) result++;
  }

  cout << result;

  return 0;
}
