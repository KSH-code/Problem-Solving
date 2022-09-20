#include <bits/stdc++.h>

const int MAX = 1e5;
int N, X, Z;

using ll = long long;
using pii = std::pair<ll,ll>;
ll dis[25][25];
ll memo[1<<22][22];
ll distances[MAX+1];
int in;
int gogo[22];
std::vector<std::vector<std::pair<int,int>>> edges(MAX+1);
void go(int x, int cur) {
  memset(distances, -1, sizeof distances);
  std::priority_queue<pii, std::vector<pii>, std::greater<pii>> q;
  q.push({0, x}); distances[x] = 0;
  while (q.size()) {
    auto [w, x] = q.top(); q.pop();
    if (distances[x] != w) continue;
    for (auto [nx, nw]: edges[x]) {
      auto &ref = distances[nx];
      if (ref == -1 || ref > w + nw) {
        ref = nw + w;
        q.push({ref, nx});
      }
    }
  }
  for (int i = 0; i < in; i++) {
    dis[cur][i] = distances[gogo[i]];
  }
}

ll dfs(int x, int mark) {
  if (x+1 == in) {
    if (mark == (1<<in)-1) return 0;
    return -2;
  }
  auto &ref = memo[mark][x];
  if (ref != -1) return ref;
  ref = -2;
  for (int b = 0; b < in; b++) {
    if (mark & 1 << b) continue;
    if (dis[x][b] <= 0) continue;
    if (dfs(b, 1 << b | mark) <= -1) continue;
    if (ref <= -1) ref = dfs(b, 1 << b | mark) + dis[x][b];
    ref = std::min(ref, dfs(b, 1 << b | mark) + dis[x][b]);
  }
  return ref;
}

void solve(){
  int M; std::cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int u,v,w; std::cin>>u>>v>>w;
    edges[u].push_back({v,w});
    edges[v].push_back({u,w});
  }
  std::cin >> X >> Z;
  gogo[in++] = X;
  int c; std::cin >> c;
  for (int i = 0; i < c; i++) {
    int z; std::cin >> z;
    gogo[in++] = z;
  }
  gogo[in++] = Z;
  for (int i = 0; i < in; i++) go(gogo[i], i);
  memset(memo, -1, sizeof memo);
  std::cout << std::max(-1LL, dfs(0, 1));
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
