#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Node {
  int x;
  ll weight;
};
struct Compare {
  bool operator()(const Node &a, const Node &b) {
    return a.weight > b.weight;
  }
};

bool solve(){
  int N, M; cin >> N >> M;
  if (N+M==0) return false;

  int S,E; cin>>S>>E;
  vector<vector<pair<int,int>>> edges(N);
  for (int i = 0; i <M;i++) {
    int u,v,w; cin >> u >> v >> w;
    edges[u].push_back({v,w});
  }

  vector<vector<int>> parntes(N);

  priority_queue<Node, vector<Node>, Compare> q; q.push({S,0});

  ll distances[N]; memset(distances, -1, sizeof(distances)); distances[S]=0;
  bool visited[N][N]; memset(visited, 0, sizeof(visited));
  vector<vector<int>> results;
  while (q.size()) {
    auto [x, weight] = q.top(); q.pop();
    for (auto [nx, w] : edges[x]) {
      if (distances[nx] > weight + w) parntes[nx].clear();

      if (distances[nx] == -1 || distances[nx] >= weight + w) {
        if (visited[nx][x]) continue;
        visited[nx][x] = true;
        parntes[nx].push_back(x);
        distances[nx] = weight + w;
        q.push({nx, distances[nx]});
      }
    }
  }
  memset(visited, 0, sizeof(visited));
  queue<int> q2; q2.push(E);
  while (q2.size()) {
    auto p = q2.front(); q2.pop();
    for (auto x : parntes[p]) {
      if (visited[x][p]) continue;
      visited[x][p] = true;
      q2.push(x);
    }
  }
  memset(distances, -1, sizeof(distances));

  distances[S]=0;
  q.push({S,0});
  while(q.size()) {
    auto [x, weight] = q.top(); q.pop();
    for (auto [nx, w] : edges[x]) {
      if (visited[x][nx]) continue;

      if (distances[nx] == -1 || distances[nx] > weight+w) {
        distances[nx] = weight+w;
        q.push({nx, distances[nx]});
      }
    }
  }

  cout << distances[E];
  return true;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  while(solve()) cout <<'\n';

  return 0;
}
