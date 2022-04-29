#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node {
  int x;
  ll weight;
};
struct Edge {
  int v,w,idx;
};
struct Compare {
  bool operator()(const Node &a, const Node &b) {
    return a.weight > b.weight;
  }
};

void solve(){
  int N, M; cin >> N >> M;N++;
  assert(N>1);
  assert(M>1);

  int S=1,E=N-1;
  vector<vector<Edge>> edges(N);
  for (int i = 0; i <M;i++) {
    int u,v,w; cin >> u >> v >> w;
    edges[u].push_back({v,w,i});
    edges[v].push_back({u,w,i});
  }

  vector<vector<pair<int,int>>> parntes(N);

  priority_queue<Node, vector<Node>, Compare> q; q.push({S,0});

  ll distances[N]; memset(distances, -1, sizeof(distances)); distances[S]=0;
  vector<vector<int>> results;
  while (q.size()) {
    auto [x, weight] = q.top(); q.pop();
    for (auto [nx, w, idx] : edges[x]) {
      if (distances[nx] > weight + w) parntes[nx].clear();

      if (distances[nx] == -1 || distances[nx] > weight + w) {
        parntes[nx].push_back({x,idx});
        distances[nx] = weight + w;
        q.push({nx, distances[nx]});
      }
    }
  }

  bool blocked[M];
  memset(blocked, 0, sizeof(blocked));
  queue<int> q2; q2.push(E);
  while (q2.size()) {
    auto p = q2.front(); q2.pop();
    for (auto [x, idx] : parntes[p]) {
      blocked[idx] = true;
      q2.push(x);
    }
  }


  memset(distances, -1, sizeof(distances));
  distances[S]=0;
  q.push({S,0});
  while(q.size()) {
    auto [x, weight] = q.top(); q.pop();
    for (auto [nx, w, idx] : edges[x]) {
      if (blocked[idx]) continue;

      if (distances[nx] == -1 || distances[nx] > weight+w) {
        distances[nx] = weight+w;
        q.push({nx, distances[nx]});
      }
    }
  }

  cout << distances[E];
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  solve();

  return 0;
}
