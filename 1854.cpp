#include <iostream>
#include <queue>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
struct Node {
  int x;
  ll weight;
};
const int MAX = 1e3+1;

struct Compare {
  bool operator()(const Node &a, const Node &b) {
    return a.weight > b.weight;
  }
};

bool visited[MAX];
void solve(){
  int N, M, K; cin >> N >> M >> K;
  vector<vector<pair<int,int>>> edges(N+1);
  for (int i = 0; i <M;i++) {
    int u,v,w; cin >> u >> v >> w;
    edges[u].push_back({v,w});
  }

  priority_queue<Node, vector<Node>, Compare> pq;
  priority_queue<ll> weights[N+1]; weights[1].push(0); pq.push({1,0});
  while (pq.size()) {
    auto [x, weight] = pq.top(); pq.pop();
    for (auto [nx, w] : edges[x]) {
      ll nw=w+weight;
      if (weights[nx].size()<K) {
        weights[nx].push(nw);
        pq.push({nx, nw});
      } else if (weights[nx].top() > nw) {
        weights[nx].pop();
        weights[nx].push(nw);
       pq.push({nx, nw});
      }
    }
  }
  for (int i = 1; i<=N; i++) {
    cout << (weights[i].size() == K ? weights[i].top() : -1) << '\n';
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  solve();
  return 0;
}
