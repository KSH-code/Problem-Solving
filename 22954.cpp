#include <bits/stdc++.h>

using pii = std::pair<int,int>;

const int MAX = 1e5;
int parents[MAX+1];
std::vector<std::vector<pii>> edges(MAX+1);
std::vector<std::vector<pii>> connected_edges(MAX+1);
int find(int x) {
  if (x == parents[x]) return x;
  return parents[x] = find(parents[x]);
}

void traverse(int x) {
  for (auto [nx, edge] : edges[x]) {
    if (find(x) == find(nx)) continue;
    parents[find(x)] = parents[find(nx)];
    connected_edges[x].push_back({nx,edge});
    traverse(nx);
  }
}

void solve(){
  int N, M; std::cin >> N >> M;
  for (int i = 1; i <= N; i++) parents[i] = i;
  for (int i = 1; i <= M; i++) {
    int a,b; std::cin >> a >> b;
    edges[a].push_back({b,i});
    edges[b].push_back({a,i});
  }
  std::set<int> p;
  for (int i = 1; i <= N; i++) {
    traverse(i);
    p.insert(find(i));
    if (p.size() > 2) {
      std::cout << -1;
      return;
    }
  }
  int found = 0;
  if (p.size() == 1) {
    for (int i = 1; i <= N; i++) {
      if (connected_edges[i].empty()) {
        found = i;
        break;
      }
    }
  }

  std::vector<int> A;
  std::vector<int> B;
  for (int i = 1; i <= N; i++) {
    if (find(i) == find(1) && found != i) A.push_back(i);
    else B.push_back(i);
  }
  if (A.size() == B.size() || A.empty() || B.empty()) {
    std::cout << -1;
    return;
  }
  std::cout << A.size() << ' ' << B.size() << '\n';
  for (auto x : A) std::cout << x << ' ';
  std::cout << '\n';
  for (auto x : A) {
    for (auto [nx, n] : connected_edges[x]) {
      if (find(nx) == find(x) && nx != found) std::cout << n << ' ';
    }
  }
  std::cout << '\n';
  for (auto x : B) std::cout << x << ' ';
  std::cout << '\n';
  for (auto x : B) {
    for (auto [nx, n] : connected_edges[x]) {
      if (find(nx) == find(x) && nx != found) std::cout << n << ' ';
    }
  }
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
