#include <bits/stdc++.h>

void solve(){
  int N, M; std::cin >> N >> M;
  std::vector<std::vector<std::pair<int,int>>> edges(N+1);
  while (M--) {
    int a,b,c; std::cin >> a >> b >> c;
    edges[a].push_back({c,b});
    edges[b].push_back({c,a});
  }
  for (int i = 1; i <= N; i++) std::sort(edges[i].begin(), edges[i].end());
  std::tuple<int,int,int> visited[N+1]; for (int i = 1; i <= N; i++) visited[i] = {0,0,0};
  visited[1] = {1,-1,1};
  std::queue<int> q; q.push(1);
  std::vector<std::vector<std::pair<int,int>>> edges(N+1);
  while (q.size()) {
    auto x = q.front();
  }
  while (q.size()) {
    auto x = q.front(); q.pop();
    auto [aa,bb,cc] = visited[x];
    for (int i = 0; i < edges[x].size(); i++) {
      auto [a,color,count] = visited[nx];
      auto [a,color,count] = visited[nx];
      if (!a || (color > c && count == cc + 1 && checked[nx])) {
        q.push(nx);
        visited[nx] = {x, c, cc+1};
      }
    }
  }
  int cur = N;
  std::stack<int> results;
  while (1) {
    auto [a,b,c] = visited[cur];
    results.push(b);
    cur = a;
    if (cur == 1) break;
  }
  std::cout << results.size() << '\n';
  while (results.size()) {
    std::cout << results.top() << ' ';
    results.pop();
  }
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
